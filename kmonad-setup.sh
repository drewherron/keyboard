#!/usr/bin/env bash

# Installs and sets up KMonad, ensuring /dev/uinput permissions.
# Safe to run multiple times; updates or skips steps if they're done.
# Some parts require sudo (don't run entire script under sudo).

set -euo pipefail

USER_HOME="$HOME"
KMONAD_REPO="https://github.com/kmonad/kmonad.git"
KEYBOARD_REPO="https://github.com/drewherron/keyboard.git"
SRC_DIR="$HOME/src"
PROJECTS_DIR="$HOME/Projects"
UINPUT_RULE="/etc/udev/rules.d/99-uinput.rules"

echo "=== KMonad Setup Script ==="

###############################################################################
# 1) Ensure ~/src and ~/Projects exist
###############################################################################
echo "1) Checking for $SRC_DIR and $PROJECTS_DIR..."
mkdir -p "$SRC_DIR"
mkdir -p "$PROJECTS_DIR"
echo "   - Confirmed directories exist."

###############################################################################
# 2) Clone or update KMonad
###############################################################################
echo "2) Setting up KMonad in $SRC_DIR..."
cd "$SRC_DIR"

if [ -d "kmonad/.git" ]; then
  echo "   - kmonad repo found, pulling latest changes."
  cd kmonad
  git pull --rebase
else
  echo "   - kmonad repo not found, cloning now."
  git clone "$KMONAD_REPO" kmonad
  cd kmonad
fi

###############################################################################
# 3) Build/Install KMonad via stack
###############################################################################
echo "3) Building/Installing KMonad (stack install)..."
stack install
echo "   - KMonad installed to ~/.local/bin (by default)."

###############################################################################
# 4) Fix /dev/uinput permissions (Using "uinput" group per KMonad FAQ)
###############################################################################
echo "4) Setting up /dev/uinput with group 'uinput'..."

# Create the uinput group if it doesn't exist
if getent group uinput >/dev/null; then
  echo "   - 'uinput' group already exists."
else
  echo "   - Creating 'uinput' group (requires sudo)."
  sudo groupadd uinput
fi

# Also ensure 'input' group exists if needed
if ! getent group input >/dev/null; then
  echo "   - 'input' group does not exist; creating now (requires sudo)."
  sudo groupadd input
fi

# Add current user to both input and uinput
NEEDS_LOGOUT=false
if groups "$USER" | grep -q "\binput\b"; then
  echo "   - $USER is already in 'input' group."
else
  echo "   - Adding $USER to 'input' group (requires sudo)."
  sudo usermod -aG input "$USER"
  NEEDS_LOGOUT=true
fi
if groups "$USER" | grep -q "\buinput\b"; then
  echo "   - $USER is already in 'uinput' group."
else
  echo "   - Adding $USER to 'uinput' group (requires sudo)."
  sudo usermod -aG uinput "$USER"
  NEEDS_LOGOUT=true
fi
if $NEEDS_LOGOUT; then
  echo "   - NOTE: You must log out and log back in for group changes to take effect."
fi

# Create or update 99-uinput.rules
if [ -f "$UINPUT_RULE" ]; then
  echo "   - $UINPUT_RULE already exists; leaving it in place."
  echo "   - If you still get permission errors, confirm it matches the FAQ approach."
else
  echo "   - Creating $UINPUT_RULE (requires sudo)."
  cat << EOF | sudo tee "$UINPUT_RULE" >/dev/null
KERNEL=="uinput", MODE="0660", GROUP="uinput", OPTIONS+="static_node=uinput"
EOF
  echo "   - Reloading udev rules..."
  sudo udevadm control --reload-rules
  sudo udevadm trigger
fi

# Force re-create /dev/uinput so it's under the new rule
echo "Reloading 'uinput' module to ensure correct device permissions..."
# Try to remove if possible, but don’t bail if it fails.
sudo modprobe -r uinput 2>/dev/null || true

# Always attempt to load
sudo modprobe uinput
echo "  /dev/uinput reloaded. Current permissions:"
ls -l /dev/uinput || echo "  Could not locate /dev/uinput."

echo "   - /dev/uinput 'uinput' group setup complete."

###############################################################################
# 5) Clone or update keyboard repo
###############################################################################
echo "5) Setting up 'keyboard' repo in $PROJECTS_DIR..."
cd "$PROJECTS_DIR"

if [ -d "keyboard/.git" ]; then
  echo "   - keyboard repo found, pulling latest."
  cd keyboard
  git pull --rebase
else
  echo "   - keyboard repo not found, cloning now."
  git clone "$KEYBOARD_REPO" keyboard
  cd keyboard
fi

###############################################################################
# 6) stow kmonad
###############################################################################
echo "6) Stowing kmonad dotfiles..."
if command -v stow >/dev/null; then
  stow kmonad
  echo "   - kmonad stowed successfully."
else
  echo "   - ERROR: 'stow' command not found. Please install it, then re-run."
  exit 1
fi

###############################################################################
# 7) Reload and enable kmonad.service
###############################################################################
echo "7) Refreshing systemd (user) and enabling kmonad.service..."
systemctl --user daemon-reload || true

if systemctl --user is-enabled kmonad.service >/dev/null 2>&1; then
  echo "   - kmonad.service already enabled."
else
  systemctl --user enable kmonad.service
  echo "   - kmonad.service enabled."
fi

echo "   - Starting kmonad.service..."
if ! systemctl --user start kmonad.service; then
  echo "   - Could not start kmonad.service (possibly /dev/uinput permissions)."
fi

echo "=== Setup Complete ==="
echo "If you were newly added to the 'input' group, please log out and log back in."
echo "You may also want to reboot to ensure the 'uinput' rule applies at startup."

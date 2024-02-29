#!/bin/bash

# This version requires the clmk-dh file in the same directory
# If the full install script works, delete this (and clmk-dh?)

# Determine the directory where the script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
LAYOUT_FILE="clmk-dh"

# Paths
LAYOUT_SRC="${SCRIPT_DIR}/${LAYOUT_FILE}"
LAYOUT_DEST="/usr/share/X11/xkb/symbols/${LAYOUT_FILE}"
EVDEV_XML="/usr/share/X11/xkb/rules/evdev.xml"

# Copy the layout file
sudo cp "$LAYOUT_SRC" "$LAYOUT_DEST"

# Backup the original evdev.xml if a backup doesn't already exist
if [ ! -f "${EVDEV_XML}.bak" ]; then
    sudo cp "$EVDEV_XML" "${EVDEV_XML}.bak"
fi

# Define the layout entry as a variable
LAYOUT_ENTRY="
  <layout>
    <configItem>
      <name>clmk-dh</name>
      <shortDescription>clmk-dh</shortDescription>
      <description>Colemak DH (Custom)</description>
      <languageList>
        <iso639Id>eng</iso639Id>
      </languageList>
    </configItem>
  </layout>"

# Use awk to insert the layout entry before the last </layoutList> tag
if ! grep -q "<name>clmk-dh</name>" "$EVDEV_XML"; then
    sudo awk -v layout_entry="$LAYOUT_ENTRY" '/<\/layoutList>/ { print layout_entry; found=1 } 1' "$EVDEV_XML" > evdev.xml.tmp && sudo mv evdev.xml.tmp "$EVDEV_XML"
fi

echo "Custom keyboard layout installed. You may need to log out and back in for changes to take effect."

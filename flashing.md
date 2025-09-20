# QMK Flashing Guide (Linux)

## Steps to flash compiled firmware

1. **Put keyboard in bootloader mode**
   - Hold physical reset button or boot key.

2. **Check connected device**
   ```bash
   lsusb
   ```
   Look for something like: `ID 0483:df11 STMicroelectronics STM Device in DFU Mode`

3. **Flash the firmware**
   ```bash
   sudo dfu-util -a 0 -d 0483:DF11 -s 0x08000000 -D path/to/firmware.bin
   ```

4. **Reconnect keyboard**
   - Unplug and plug back in
   - Keyboard should boot with new firmware

## Notes
- The device ID `0483:DF11` is for STM32 DFU bootloader (common on QMK keyboards)
- Use `sudo dfu-util -l` to list all DFU devices if needed
- Firmware files are typically named like: `keyboard_revision_keymap_date.bin`

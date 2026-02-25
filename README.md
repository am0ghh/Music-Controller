# ESP32 BLE Music Controller

A hardware-based HID (Human Interface Device) controller that utilizes an ESP32 and Bluetooth Low Energy (BLE) to function as a wireless media remote.

## Overview
This project emulates a native Bluetooth keyboard to provide tactile, wireless control over media playback on iOS, Android, and desktop devices without requiring custom host-side software.

## Features
* Wireless HID Interface - Functions as a plug-and-play Bluetooth keyboard
* Tactile Media Control - Physical buttons for Play/Pause, Next Track, and Previous Track
* Active-Low Logic - Utilizes internal INPUT_PULLUP resistors for a simplified wiring layout
* Software Debouncing - Integrated timing logic to prevent erratic signaling from mechanical switch noise
* Validated Hardware - Professional schematic designed and verified for electrical integrity in KiCad 8.0

## Components Required
* ESP32 DevKit V1 (WROOM-32D)
* 3x Tactile Push Buttons
* 3x 100kΩ Resistors (Optional current limiters)
* Breadboard
* Jumper Wires

## Wiring Schematic


## Pin Connections
Buttons (Active-Low):
* Play/Pause: GPIO 13 -> Button -> GND
* Next Track (Skip): GPIO 12 -> Button -> GND
* Previous Track (Rewind): GPIO 14 -> Button -> GND

## How It Works
* Initialization: Upon boot, the ESP32 initializes the BLE stack and begins advertising as a HID device.
* HID Communication: When a button is pressed, the ESP32 sends a specific HID Usage ID (e.g., KEY_MEDIA_PLAY_PAUSE) to the connected host.
* Input Handling: The code polls digital pins for a LOW state. Once detected, it executes the command and enters a debounce loop until the button is released to prevent duplicate commands.

## Installation
1. Install PlatformIO in VS Code
2. Install required library: ESP32 BLE Keyboard
3. Upload the code to your ESP32 DevKit
4. Pair the device via Bluetooth settings on your phone or PC
5. Test playback on any media application (Spotify, YouTube, etc.)

## Video Demonstration
https://www.youtube.com/watch?v=QvqF_MR-02k

## Usage
* Press D13 to Toggle Play/Pause
* Press D12 to Skip to the next track
* Press D14 to Rewind to the previous track

## Code
See main.cpp

## Future Improvements
* Volume Control - Add a rotary encoder for tactile volume adjustment
* Visual Feedback - Integrate an OLED display to show connection status and current track info
* Power Management - Implement deep sleep modes to extend battery life for portable use
* Custom Key Mapping - Develop a companion app or web interface to remap button functions

## License
MIT License

## Author
am0ghh

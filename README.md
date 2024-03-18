# AVROTA: Arduino Programming Over Bluetooth Using ESP32

## Introduction

AVROTA (Arduino Via Remote OTA) offers a seamless way to program Arduino boards over Bluetooth, utilizing the power and versatility of the ESP32. This project enables wireless programming of Arduino devices without the need for a physical connection, simplifying the development process for projects where the Arduino is embedded or hard to reach.

## Features

- **Wireless Programming**: Program your Arduino wirelessly using Bluetooth, eliminating the need for physical access.
- **ESP32 as a Bridge**: Leverages the ESP32's Bluetooth capabilities to bridge communication between your computer and the Arduino.
- **Broad Compatibility**: Supports a range of Arduino boards, with instructions for Uno and Mega (with considerations for different bootloader protocols).
- **Custom Protocol Handling**: Implements protocol handling for both STK500v1 (Uno) and STK500v2 (Mega), ensuring compatibility across devices.
- **Easy to Use**: Simple setup and operation, making wireless programming accessible to hobbyists and professionals alike.

## Hardware Requirements

- ESP32 Development Board
- Arduino Board (Uno, Mega, or other supported models)
- Jumper Wires for Connections

## Software Requirements

- Arduino IDE or PlatformIO
- ESP32 Arduino Core
- Bluetooth Serial Library for ESP32

## Setup and Configuration

### Hardware Setup

1. Connect the ESP32's TX0 to the Arduino's RX pin.
2. Connect the ESP32's RX0 to the Arduino's TX pin.
3. Connect a GPIO pin from the ESP32 to the Arduino's RESET pin for automatic resetting (see the code for configuring this pin).
4. Ensure both the ESP32 and Arduino share a common ground.

### Software Setup

#### ESP32

1. Install the Arduino IDE and ESP32 Arduino Core.
2. Load the provided ESP32 sketch, which sets up the Bluetooth Serial bridge and handles the reset for initiating the Arduino's bootloader.
3. Update the GPIO pin number in the sketch if you're using a different pin for the Arduino's reset.
4. Upload the sketch to the ESP32.

#### Arduino

1. Prepare your Arduino sketch in the Arduino IDE or PlatformIO.
2. Ensure the selected board and port correspond to your Arduino model.

#### Computer or Bluetooth Device

1. Pair with the ESP32 over Bluetooth, which will appear as "ESP32 Serial Bridge".
2. Once paired, select the new COM port associated with the ESP32 Bluetooth connection as your Arduino's port in the IDE.

## Programming Your Arduino

After completing the setup, upload sketches to your Arduino board directly from the Arduino IDE or PlatformIO, just as if you were connected via a USB cable, but wirelessly through the ESP32 bridge.

## Troubleshooting

- Ensure your ESP32 and Arduino are correctly powered and connected.
- Verify the correct COM port is selected in your development environment.
- If using an Arduino Mega, adjust for the STK500v2 protocol and ensure baud rates are matched.

## Contributing

Contributions to AVROTA are welcome! Whether it's feature enhancements, bug fixes, or documentation improvements, please feel free to fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
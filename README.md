# 🔊 Bluetooth-Controlled Buzzer using Arduino

This project demonstrates how to control a buzzer wirelessly using an Arduino and an HC-05 Bluetooth module. A smartphone can send commands to the Arduino via Bluetooth to turn the buzzer ON or OFF.

## 🚀 Features

- Wireless control of a buzzer using Bluetooth
- Uses HC-05 module and SoftwareSerial for communication
- Simple command-based ON/OFF functionality
- Compatible with any Bluetooth terminal app

## 🛠️ Hardware Required

- Arduino Uno (or compatible board)
- HC-05 Bluetooth Module
- Buzzer
- Jumper Wires
- Breadboard

## 🔌 Circuit Connections

### HC-05 Bluetooth Module
| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| TXD       | Pin 11 (RX on Arduino) |
| RXD       | Pin 10 (TX on Arduino) *(use a voltage divider to drop 5V to 3.3V)* |

### Buzzer
- Positive leg → Pin 8  
- Negative leg → GND

## 📱 How to Use

1. Upload the code to your Arduino board.
2. Connect your smartphone to the HC-05 via Bluetooth (default password: `1234` or `0000`).
3. Open a Bluetooth terminal app (like **Serial Bluetooth Terminal** on Android).
4. Send:
   - `1` → to **turn ON** the buzzer
   - `0` → to **turn OFF** the buzzer

## 📚 Libraries Used

- `SoftwareSerial` – for serial communication with the HC-05 Bluetooth module

## 🧠 How It Works

- The Arduino listens for serial data via the HC-05.
- If it receives `'1'`, it activates the buzzer using the `tone()` function.
- If it receives `'0'`, it stops the buzzer using `noTone()`.

## 🔒 Notes

- Make sure your HC-05 is in data mode (not AT mode).
- Use a voltage divider (e.g., 1kΩ and 2kΩ resistors) between Arduino TX and HC-05 RX to prevent damage.




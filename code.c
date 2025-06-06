#include <SoftwareSerial.h>

// Create software serial object to communicate with HC-05
SoftwareSerial BTSerial(11, 10);  // Pin 11 is Rx, Pin 10 is Tx

// Define pin for buzzer
#define BUZZER_PIN 8

void setup() {
  // Begin serial communication with Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  Serial.println("Initializing Bluetooth Module in Data Mode");

  // Begin the software serial port and set data rate at 9600 to communicate with HC-05
  BTSerial.begin(9600);
  Serial.println("Bluetooth Module Initialized in Data Mode");

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);  // Ensure the buzzer is off initially
}

void loop() {
  // Check if data is available from the Serial Monitor (sending to Bluetooth module)
  if (Serial.available()) {
    char data = Serial.read();  // Read the data from Serial Monitor
    BTSerial.write(data);       // Send data to HC-05
  }

  // Check if data is available from Bluetooth (sending to Serial Monitor)
  if (BTSerial.available()) {
    char data = BTSerial.read();  // Read data from HC-05
    Serial.write(data);           // Send data to Serial Monitor

    // If the received data is '1', turn on the buzzer for 1 second
    if (data == '1') {
      tone(BUZZER_PIN, 1000);  // Turn on buzzer // Turn off buzzer
    }
    // If the received data is '0', turn off the buzzer
    else if (data == '0') {
      noTone(BUZZER_PIN);  // Turn off buzzer immediately
    }
  }
}

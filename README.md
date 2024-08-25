# SimpleArduinoEncryption

**Version:** 1.0.0  
**Author:** Ajang Rahmat  
**Maintainer:** Ajang Rahmat (<ajangrahmat@gmail.com>)  
**Category:** Encryption  
**URL:** [GitHub Repository](https://github.com/kelasrobot/SimpleArduinoEncryption)

## Description

SimpleArduinoEncryption is a lightweight Arduino library for encrypting and decrypting data using XOR encryption. It also supports converting between byte arrays and hexadecimal strings, making it easier to transmit encrypted data.

## Features

- Simple XOR-based encryption and decryption
- Convert byte arrays to hexadecimal strings and vice versa
- Suitable for small embedded systems like Arduino

## Installation

1. Download the latest release from the [GitHub Repository](https://github.com/kelasrobot/SimpleArduinoEncryption).
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library**.
3. Select the downloaded `.zip` file to install the library.

Alternatively, you can clone the repository directly into your `libraries` folder:

## Usage

### Basic Example

### Encryption Example

```cpp
#include "SimpleArduinoEncryption.h"

// Encryption keys
const byte ENCRYPTION_KEYS[] = {0xAA, 0xBB, 0xCC, 0xCB};
const size_t NUM_KEYS = sizeof(ENCRYPTION_KEYS) / sizeof(ENCRYPTION_KEYS[0]);

// Initialize encryption object with keys
SimpleArduinoEncryption encryption(ENCRYPTION_KEYS, NUM_KEYS);

void setup() {
  Serial.begin(9600);

  // String to encrypt
  String messageString = "123.5#121.56#ON";
  Serial.print("Original String: ");
  Serial.println(messageString);

  // Convert String to char array
  size_t length = messageString.length();
  char message[length + 1];
  messageString.toCharArray(message, sizeof(message));

  // Encrypt message
  encryption.encrypt(message);

  // Convert encrypted byte array to hexadecimal string
  char hexStr[length * 2 + 1];
  SimpleArduinoEncryption::bytesToHex((const byte*)message, length, hexStr);

  Serial.print("Encrypted String (Hex): ");
  Serial.println(hexStr);
}

void loop() {
  // No activity in loop
}
```

### Decryption Example

```cpp
#include "SimpleArduinoEncryption.h"

// Encryption keys
const byte ENCRYPTION_KEYS[] = {0xAA, 0xBB, 0xCC, 0xCB};
const size_t NUM_KEYS = sizeof(ENCRYPTION_KEYS) / sizeof(ENCRYPTION_KEYS[0]);

// Initialize encryption object with keys
SimpleArduinoEncryption encryption(ENCRYPTION_KEYS, NUM_KEYS);

void setup() {
  Serial.begin(9600);

  // Replace this with the encrypted string from the encryption example
  const char* encryptedHex = "9B89FFE59F98FDF99B95F9FD89F482";

  // Calculate buffer length and allocate memory
  size_t length = strlen(encryptedHex) / 2;
  byte message[length + 1];

  // Convert hexadecimal string to bytes
  SimpleArduinoEncryption::hexToBytes(encryptedHex, message, length);

  // Print encrypted data in hex format
  Serial.print("Encrypted String (Hex): ");
  SimpleArduinoEncryption::printHex(message, length);

  // Decrypt the message
  encryption.decrypt((char*)message);
  String decryptedString = String((char*)message);

  Serial.print("Decrypted String: ");
  Serial.println(decryptedString);
}

void loop() {
  // No activity in loop
}
```
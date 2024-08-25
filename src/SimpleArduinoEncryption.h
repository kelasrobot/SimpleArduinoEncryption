#ifndef SIMPLE_ARDUINO_ENCRYPTION_H
#define SIMPLE_ARDUINO_ENCRYPTION_H

#include <Arduino.h>

class SimpleArduinoEncryption {
public:
  SimpleArduinoEncryption(const byte* keys, size_t numKeys);

  void encrypt(char* data);
  void decrypt(char* data);

  static void bytesToHex(const byte* data, size_t length, char* hexStr);
  static void hexToBytes(const char* hexStr, byte* buffer, size_t bufferSize);
  static void printHex(const byte* data, size_t length);

private:
  const byte* keys_;
  size_t numKeys_;

  void xorEncryptDecryptBytes(byte* data, size_t length);
};

#endif // SIMPLE_ARDUINO_ENCRYPTION_H

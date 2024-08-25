#include "SimpleArduinoEncryption.h"

// Konstruktor
SimpleArduinoEncryption::SimpleArduinoEncryption(const byte* keys, size_t numKeys)
  : keys_(keys), numKeys_(numKeys) {}

// Enkripsi
void SimpleArduinoEncryption::encrypt(char* data) {
  xorEncryptDecryptBytes((byte*)data, strlen(data));
}

// Dekripsi
void SimpleArduinoEncryption::decrypt(char* data) {
  xorEncryptDecryptBytes((byte*)data, strlen(data));
}

// XOR enkripsi dan dekripsi byte array
void SimpleArduinoEncryption::xorEncryptDecryptBytes(byte* data, size_t length) {
  for (size_t i = 0; i < length; i++) {
    byte key = keys_[i % numKeys_];
    data[i] ^= key;
  }
}

// Konversi byte array ke string heksadesimal tanpa spasi
void SimpleArduinoEncryption::bytesToHex(const byte* data, size_t length, char* hexStr) {
  for (size_t i = 0; i < length; ++i) {
    sprintf(hexStr + 2 * i, "%02X", data[i]);
  }
  hexStr[2 * length] = '\0';  // Null-terminate the string
}

// Konversi string heksadesimal ke byte array
void SimpleArduinoEncryption::hexToBytes(const char* hexStr, byte* buffer, size_t bufferSize) {
  size_t length = strlen(hexStr);
  for (size_t i = 0; i < length / 2 && i < bufferSize; ++i) {
    sscanf(hexStr + 2 * i, "%2hhx", &buffer[i]);
  }
}

// Print data dalam format heksadesimal
void SimpleArduinoEncryption::printHex(const byte* data, size_t length) {
  for (size_t i = 0; i < length; ++i) {
    Serial.print(data[i], HEX);
    if (i < length - 1) {
      Serial.print(" ");
    }
  }
  Serial.println();
}

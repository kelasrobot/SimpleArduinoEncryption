#include "SimpleArduinoEncryption.h"

// Kunci enkripsi yang digunakan
const byte ENCRYPTION_KEYS[] = {0xAA, 0xBB, 0xCC, 0xCB};
const size_t NUM_KEYS = sizeof(ENCRYPTION_KEYS) / sizeof(ENCRYPTION_KEYS[0]);

// Inisialisasi objek enkripsi dengan kunci
SimpleArduinoEncryption encryption(ENCRYPTION_KEYS, NUM_KEYS);

void setup() {
  Serial.begin(9600);

  // String yang akan dienkripsi
  String messageString = "123.5#121.56#ON";
  Serial.print("Original String: ");
  Serial.println(messageString);

  // Konversi String ke array char
  size_t length = messageString.length();
  char message[length + 1];  // Tambahkan satu untuk null terminator
  messageString.toCharArray(message, sizeof(message));  // Salin data dari String ke char array

  // Enkripsi pesan
  encryption.encrypt(message);

  // Konversi byte array hasil enkripsi ke string heksadesimal
  char hexStr[length * 2 + 1];  // Buffer untuk string hex
  SimpleArduinoEncryption::bytesToHex((const byte*)message, length, hexStr);

  Serial.print("Encrypted String (Hex): ");
  Serial.println(hexStr);  // Cetak string hex tanpa spasi
}

void loop() {
  // Tidak ada aktivitas di loop
}
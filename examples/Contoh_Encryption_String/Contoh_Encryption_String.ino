#include <SimpleArduinoEncryption.h>

// Kunci enkripsi yang digunakan
const byte ENCRYPTION_KEYS[] = {0xAA, 0xBB, 0xCC, 0xCB};
const size_t NUM_KEYS = sizeof(ENCRYPTION_KEYS) / sizeof(ENCRYPTION_KEYS[0]);

// Inisialisasi objek enkripsi dengan kunci
SimpleArduinoEncryption encryption(ENCRYPTION_KEYS, NUM_KEYS);

void setup() {
  Serial.begin(9600);

  // Ganti string ini dengan hasil enkripsi dari Sketch Enkripsi
  const char* encryptedHex = "9B89FFE59F98FDF99B95F9FD89F482";

  // Hitung panjang buffer dan alokasikan memori
  size_t length = strlen(encryptedHex) / 2;
  byte message[length + 1]; // Tambahkan satu untuk null terminator

  // Konversi string hex ke bytes
  SimpleArduinoEncryption::hexToBytes(encryptedHex, message, length);

  // Dekode hasil enkripsi menjadi string
  message[length] = '\0'; // Tambahkan null terminator untuk string

  Serial.print("Encrypted String (Hex): ");
  SimpleArduinoEncryption::printHex(message, length);

  // Dekripsi pesan
  encryption.decrypt((char*)message);
  String decryptedString = String((char*)message);

  Serial.print("Decrypted String: ");
  Serial.println(decryptedString);
}

void loop() {
  // Tidak ada aktivitas di loop
}

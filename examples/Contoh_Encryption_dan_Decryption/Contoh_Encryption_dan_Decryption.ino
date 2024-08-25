#include <SimpleArduinoEncryption.h>

const byte ENCRYPTION_KEYS[] = {0xAA, 0xBB, 0xCC, 0xCB};
const size_t NUM_KEYS = sizeof(ENCRYPTION_KEYS) / sizeof(ENCRYPTION_KEYS[0]);

SimpleArduinoEncryption encryption(ENCRYPTION_KEYS, NUM_KEYS);

void setup() {
  Serial.begin(9600);

  char message[] = "123.5#121.56#ON";
  Serial.print("Original String: ");
  Serial.println(message);
  
  encryption.encrypt(message);
  
  // Print hasil enkripsi dalam format heksadesimal tanpa spasi
  size_t length = strlen(message);
  char hexStr[length * 2 + 1];
  SimpleArduinoEncryption::bytesToHex((const byte*)message, length, hexStr);
  
  Serial.print("Encrypted String (Hex): ");
  Serial.println(hexStr);  // Print hex string tanpa spasi
}

void loop() {
  // Tidak ada aktivitas di loop
}

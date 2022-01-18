#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_1_PIN        10

byte n;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_init();
}

void loop(){
  if (mfrc522.PICC_ReadCardSerial()) {
    Serial.print("UID KTP anda : ");
    for(int i = 0; i<7; i++){
      Serial.print(mfrc522.uid.uidByte[i]);
      Serial.print(" : ");
    }
  }
  delay(1000);
}

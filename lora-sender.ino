#include <SPI.h>
#include <LoRa.h>
void setup() {
  Serial.begin(9600);
  while (!Serial);  //  Set loRa frequency 
  //  433E6 for Asia
  //  866E6 for Europe
  //  915E6 for North America 
  LoRa.setPins(D8, 0, D1);
  if (!LoRa.begin(866E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("serial started");
}
void loop() {
    String name = "your_name";
    String data = "my name is " + String(name);
    Serial.println("Sending data: ");
    Serial.println(data);
    LoRa.beginPacket();
    LoRa.print(data);
    LoRa.endPacket();  
    delay(5000);
}

#include <SPI.h>
#include <LoRa.h>



#define ss 5
#define rst 0
#define dio0 2



int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa On");
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSpreadingFactor(9);
  LoRa.setCodingRate4(5);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setGain(6);
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      char r = (char)LoRa.read();
      Serial.print(r);
      
    }

    // print RSSI of packet
    
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  if (Serial.available()) {
	  String input = Serial.readString();
    LoRa.beginPacket();
    LoRa.print(input);
    LoRa.endPacket();
  }
}
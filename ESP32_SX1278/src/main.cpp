#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

void onReceive(int packetSize);

BluetoothSerial SerialBT;
 
#define ss 5
#define rst 0
#define dio0 2
 
void setup() {
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.begin(115200);
  while (!Serial);
 
  Serial.println("LoRa Receiver Callback");
  SerialBT.println("LoRa Receiver Callback");
 
  LoRa.setPins(ss, rst, dio0);
 
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    SerialBT.println("Starting LoRa failed!");
    while (1);
  }
 
  // register the receive callback
  LoRa.onReceive(onReceive);
 
  // put the radio into receive mode
  LoRa.receive();
}
 
void loop() {
  // do nothing
}
 
void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");
  SerialBT.print("Received packet '");
 
  // read packet
  for (int i = 0; i < packetSize; i++) {
    char m = (char)LoRa.read();
    Serial.print(m);
    SerialBT.print(m);
  }
 
  // print RSSI of packet
  // String r = LoRa.packetRssi();
  // Serial.print("' with RSSI ");
  // SerialBT.println(r);
  // Serial.print("' with RSSI ");
  // SerialBT.println(r);
}
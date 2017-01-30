#include <OneWire.h> //import library to communicate with temp probe

const int tempProbePin = 3; //connect data line of temp probe to pin 3

OneWire tempProbe(tempProbePin); //instantiate a OneWire object

void setup() {
  Serial.begin(9600); //start serial communication
  Serial.println("Initializing temp probe...");
  delay(2000);
  Serial.println("Temp probe online!");
}

void loop() {
  float temperature = getTemp(); //run getTemp() to collect data from probe and store it
  Serial.println(temperature); //print to serial monitor
}

float getTemp() { //credit to http://bildr.org/2011/07/ds18b20-arduino/
  byte data[12];
  byte address[8];

  if(!tempProbe.search(address)) {
    tempProbe.reset_search();
    return -1000;
  }

  if(OneWire::crc8(address, 7) != address[7]) {
    Serial.println("CRC is not valid");
    return -1000;
  }

  if(address[0] != 0x10 && address[0] != 0x28) {
    Serial.println("Device not recognized");
    return -1000;
  }

  tempProbe.reset();
  tempProbe.select(address);
  tempProbe.write(0x44, 1);

  delay(750);

  byte present = tempProbe.reset();
  tempProbe.select(address);
  tempProbe.write(0xBE);

  for(int i = 0; i < 9; i++) {
    data[i] = tempProbe.read();
  }

  tempProbe.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);
  float tempSum = tempRead / 16;

  return tempSum;
}


// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
int i , k;
byte x[4]={1,1,1,1};
byte y[4]={0,0,0,0};
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
i=0;
k=0;}

void loop() {
  Wire.beginTransmission(11); // transmit to device #8
  Wire.write(x,4);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
  

delay(1000);
  Wire.beginTransmission(11); // transmit to device #8
  Wire.write(y,4);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
delay(1000);

 }

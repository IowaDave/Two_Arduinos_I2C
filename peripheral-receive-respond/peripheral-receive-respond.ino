// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

byte x; // value to be received from controller

void setup() {
  Wire.begin(8);                // join I2C bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { 
    // loop through all but the final
    // however, we're getting only 1
    // so I expect this block to be skipped
    x = Wire.read(); // receive byte as a byte
//    Serial.print(c);         // print the character
  }
  x = Wire.read();    // receive byte as an byte
//  Serial.println(x);         // print the integer
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  byte doubleX = x * 2; // double it
  Wire.write(doubleX); // respond with message of 1 byte
  // as expected by controller
}

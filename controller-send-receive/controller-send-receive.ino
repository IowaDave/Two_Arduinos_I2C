// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

byte x, y;

void setup() {
  Serial.begin(9600);
  
  Wire.begin(); // join I2C bus (address optional for master)
  
  srand(analogRead(A7));
}


void loop() {
  // generate a random integer 0 .. 99
  x = rand() % 100;

  Serial.print("Sending: ");
  Serial.println(x);

  // send it to peripheral
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // send a stop
//  delay(100); // why not?  arbitrary wait

  // request a response
  Wire.requestFrom(8, 1);    // request 1 byte from slave device #8
  while (Wire.available()) { // slave may send less than requested
    y = Wire.read(); // receive a byte as byte
  }
  Serial.print("Received: ");
  Serial.println(y);         // print the character
  Serial.println();  
  
  delay(1000);
}

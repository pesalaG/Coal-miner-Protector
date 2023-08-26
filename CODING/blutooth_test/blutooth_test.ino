#include "Arduino.h"
#include <SoftwareSerial.h>
 
const byte rxPin = 3;
const byte txPin = 4;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX
 
void setup() {
// define pin modes for tx, rx:
pinMode(rxPin, INPUT);
pinMode(txPin, OUTPUT);
BTSerial.begin(9600);

}
 

String message = " great ";
 
void loop() {
 
    delay(100);
    BTSerial.print(message); // send back to bluetooth terminal

  }
  
 



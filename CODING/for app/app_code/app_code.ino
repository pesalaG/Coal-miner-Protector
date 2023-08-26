#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "Arduino.h"
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht = DHT(DHTPIN, DHTTYPE);
const int AOUTpin=A0;
const byte rxPin = 3;
const byte txPin = 4;
SoftwareSerial BTSerial(rxPin, txPin);
bool configReceived = false; // Flag variable to check if configuration is received
float temp_lim = 50.0;
float hum_lim = 50.0;
float CO_lim = 5000.0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);
  pinMode(AOUTpin, INPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  dht.begin();
}

void loop() {
  

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  //int gas_ppm = analogRead(AOUTpin);
  delay(1000);

  if (isnan(h) || isnan(t)) {
    return;
  }

  if (BTSerial.available() && !configReceived) {
    
    temp_lim = BTSerial.parseFloat(); // Read temperature limit from Bluetooth
    hum_lim = BTSerial.parseFloat();  // Read humidity limit from Bluetooth
//    CO_lim = BTSerial.parseFloat();   // Read CO limit from Bluetooth    
    configReceived = true;
  }

//  BTSerial.print("temperature limit = ");
//  BTSerial.println(temp_lim);
//  BTSerial.print("humidity limit = ");
//  BTSerial.println(hum_lim);
//  BTSerial.print("CO limit = ");
//  BTSerial.println(CO_lim);
//  BTSerial.print("Temperature: ");
  BTSerial.print(t);
  BTSerial.print("°C");
  BTSerial.print("|");
  BTSerial.print(h);
  BTSerial.println("%");
  //BTSerial.print("|");
  //BTSerial.println(gas_ppm);
  

  if ((t > temp_lim) || (h < hum_lim)) {
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(13, LOW);
    delay(100);
     
  } else {
    digitalWrite(13, LOW);
    delay(10);
  }
}

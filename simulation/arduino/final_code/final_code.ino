/* Arduino example code for DHT11, DHT22/AM2302 and DHT21/AM2301 temperature and humidity sensors. More info: www.www.makerguides.com */

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include "Arduino.h"
#include <SoftwareSerial.h>

// Set DHT pin:
#define DHTPIN 2
// set blutooth 
const byte rxPin = 3;
const byte txPin = 4;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

// Set DHT type, uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);
const int AOUTpin=A0;

float temp_lim;
float hum_lim;
float CO_lim;



void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);
  pinMode(AOUTpin,INPUT);
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);

  // Setup sensor:
  dht.begin();


  if (BTSerial.available()){
  

// char dec = BTSerial.read();
// if(dec=="c"){
//  BTSerial.println(dec);
    temp_lim = BTSerial.read();
    CO_lim = BTSerial.read();
    hum_lim = BTSerial.read();
   }
}


void loop() {
  // Wait a few seconds between measurements:
  delay(200);


  //float temp_lim = 40.0;
  //float CO_lim = 500.0;
  //float hum_lim = 50;


  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();

    
  int gas_ppm = analogRead(AOUTpin);//sensor value of mq7 sensor

  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) ) {
  
    return;
  }
if (BTSerial.available()){
  

// char dec = BTSerial.read();
// if(dec=="c"){
//  BTSerial.println(dec);
  // float temp_lim = BTSerial.read();
//   char CO_lim = BTSerial.read();
//   char hum_lim = BTSerial.read();
// }
  BTSerial.print("temp_lim");
  BTSerial.println(temp_lim);
  BTSerial.print("hum_lim");
   BTSerial.println(hum_lim);
  BTSerial.print("CO_lim");
  BTSerial.println(CO_lim);
  BTSerial.print("Temperature: ");
  BTSerial.print(t);
  BTSerial.print(", | humidity: ");
  BTSerial.print(h);
  BTSerial.print(", | CO in ppm: ");
  BTSerial.println(gas_ppm);


} 
  

  if((t>temp_lim)||(gas_ppm>CO_lim)||(h<hum_lim)){
    digitalWrite(13,HIGH);
      delay(1000);
  }

  else{
      digitalWrite(13,LOW);
      delay(10);
  }
  

}
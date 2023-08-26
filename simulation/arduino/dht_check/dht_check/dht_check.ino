/* Arduino example code for DHT11, DHT22/AM2302 and DHT21/AM2301 temperature and humidity sensors. More info: www.www.makerguides.com */

// Include the libraries:
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Set DHT pin:
#define DHTPIN 2

// Set DHT type, uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Begin serial communication at a baud rate of 9600:

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  // Setup sensor:
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements:
  delay(5000);



  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();


  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) ) {
   digitalWrite(12,HIGH);
    delay(2000);
    digitalWrite(12,LOW);
    delay(1000);    
    return;
  }

  
if(t>45.0){
   digitalWrite(13,HIGH);
    delay(2000);
    digitalWrite(13,LOW);
    delay(1000);  
}
  

}

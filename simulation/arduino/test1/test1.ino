void setup() {

  pinMode(2, INPUT); //Pin 2 as INPUT via sensor

  pinMode(13, OUTPUT); //PIN 13 as OUTPUT to buzzer

}

void loop() {                                    

  if (digitalRead(2) == HIGH)  {

     digitalWrite(13, HIGH);  // turns the Buzz ON

     delay(100);                       // wait for 100 msecond

     digitalWrite(13, LOW);   // turns the Buzz OFF

     delay(100);                       // wait for 100 msecond

  }
}  

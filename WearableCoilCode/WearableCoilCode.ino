int psen = A3;
int coil = 5;
int leds = 10;
int bright;
int psenval;

unsigned long prevMillis;
long interval = 1500;
int coilState = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  //initialize digital pin LED_BUILTIN as an output.
  pinMode(coil, OUTPUT);
  pinMode(leds, OUTPUT);
  //Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  unsigned long currentMillis = millis();

//  delay(100);

  psenval = analogRead(psen);

 // Serial.println(psenval);

  if (psenval > 300) {
    bright = map(psenval, 200, 700, 0, 255);
    digitalWrite(leds, bright);
    //digitalWrite(coil, coil);   // turn the LED on (HIGH is the voltage level)

    if (currentMillis - prevMillis >= interval) {
     // Serial.println("coil active");
      prevMillis = currentMillis;

      if (coilState == LOW){
        coilState = HIGH;
        }else{
          coilState = LOW;
          }
          digitalWrite(coil, coilState);
    }
  }
  else
  {
    digitalWrite(leds, LOW);
  }
}

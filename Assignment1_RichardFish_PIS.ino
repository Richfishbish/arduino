
#include <ezButton.h>

#define SWITCH_OFF  0
#define SWITCH_ON  1

int switchState = SWITCH_OFF; // this is controlling lights and sound

ezButton button(2); // create ezButton object that attach to pin 2;

 // initial tempo
int tempo = 200;
// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;


int LED1 = 6;
int LED2 = 5;
int LED3 = 4;
int LED4 = 3;

void setup() {
//lightssss

   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
// declare the switch pin as an input
pinMode(2, INPUT);

//sensorrrr pg. 75
 button.setDebounceTime(50); // debounce time is 50 milliseconds
 while (millis() < 5000){
  sensorValue = analogRead(A0);
  if (sensorValue > sensorHigh){
    sensorHigh = sensorValue;
  }
  if(sensorValue < sensorLow){
    sensorLow = sensorValue;
  }
 }
}

void loop() {

  sensorValue = analogRead(A0);
  tempo = map(sensorValue, sensorLow, sensorHigh, 200, 500);
  button.loop(); // MUST call the loop() function first
  
    // if the LED is off turn it on and vice-versa:
    if (switchState == LOW) {
      switchState = HIGH;
    } else {
      switchState = LOW;
    }

  if (button.isPressed()) {
    // change state of switch
    if (switchState == SWITCH_OFF)
      switchState = SWITCH_ON;
    else
      switchState = SWITCH_OFF;
  }
  if (switchState == SWITCH_OFF) {
  // when button not pressed
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  }
else {

  tone(8, 100, tempo);
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay (tempo);

  tone(8, 115, tempo);
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay (tempo);
  
  tone(8, 160, tempo);
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay (tempo);
  
  tone(8, 180, tempo); //
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay (tempo);
 loop();
}

// read the value of the switch. digitalRead() checks to see if there is voltage on the pin or not
switchState = digitalRead(2);



  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);

  // map the sensor values to a wide range of pitches
  int tempo = map(sensorValue, sensorLow, sensorHigh, 50, 4000); 
}
 

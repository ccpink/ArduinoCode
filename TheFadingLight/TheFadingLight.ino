/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 0;
int fadeInc = 5;    // how many points to increment the fade of the light
int fadeDec = -5;  // how many points to decrement the fade of the light
int incBtn = 3; //Button that increments
int decBtn = 2; //Button that decremements

int incReading;
int decReading;

// the setup routine runs once when you press reset:
void setup() {
  //BTN that increments fade amount
  pinMode(incBtn, INPUT);
  //BTN that decrememtns fade amount
  pinMode(decBtn, INPUT);
  
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  //Serial Testing
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  incReading = digitalRead(incBtn);
  decReading = digitalRead(decBtn);

 
  if(incReading == HIGH){
    brightness = brightness - 5;
    Serial.println("Incremementing Fade");
  }
  else if(decReading == HIGH){
    brightness = brightness + 5;
    Serial.println("Decrementing Fade");
  }

  
   // set the brightness of pin 9:
  analogWrite(led, brightness);

  // wait for 30 milliseconds to see the dimming effect
  delay(5);
}

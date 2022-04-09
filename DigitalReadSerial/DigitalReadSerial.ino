/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int pin13 = 13
int pin12 = 12;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);

  if(buttonState == 1){
    digitalWrite(pin12, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(pin13, LOW);    // turn the LED off by making the voltage LOW
  } else {
    digitalWrite(pin12, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(pin13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  
  delay(1);        // delay in between reads for stability
}

/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:

int greenPin = 12;
int pushButton = 2;

int lightOn = HIGH;
int lightOff = LOW;

// the setup routine runs once when you press reset:
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pushButton, INPUT);
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  if(buttonState == 1){
    Serial.println("Changin States");
    Serial.println(digitalRead(LED_BUILTIN));
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(greenPin, LOW);
  }else {
     digitalWrite(LED_BUILTIN, LOW);
     digitalWrite(greenPin, HIGH);  
  }
  
  // print out the state of the button:
  //Serial.println(buttonState);
  
  delay(1);        // delay in between reads for stability
}

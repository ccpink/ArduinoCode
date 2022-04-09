/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 got help from this 
 https://maker.pro/arduino/tutorial/how-to-set-up-pan-tilt-camera-stand-with-arduino-uno-and-joystick-module
 This example code is in the public domain.
  
 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/
#include <Servo.h>

//Servo Pin Numbers
const int baseServoPin = 11;       
const int baseTiltServoPin = 10;  
const int middleTiltServoPin = 9;       
const int baseWristServoPin = 6;  
const int baseWristTiltServoPin = 5;       
const int handCloseServoPin = 3;      

//Potetiono Meters 
#define potServo1 A0
#define potServo2 A1
#define potServo3 A2
#define potServo4 A3
#define potServo5 A4
#define potServo6 A5

int xValue;
int yValue;

int servoVal;           // variable to read the value from the analog pin

//Create the servos objects
Servo baseServo;  
Servo tiltServo;  
Servo middleTiltServo;  
Servo baseWristServo;  
Servo BaseWristTiltServo;  
Servo handCloseServo;  

void setup() {

  // Servo  
  baseServo.attach(baseServoPin);  // attaches the servo
  tiltServo.attach(baseTiltServoPin);  // attaches the servo
  middleTiltServo.attach(middleTiltServoPin);  // attaches the servo
  baseWristServo.attach(baseWristServoPin);  // attaches the servo
  BaseWristTiltServo.attach(baseWristTiltServoPin);  // attaches the servo
  handCloseServo.attach(handCloseServoPin);  // attaches the servo


  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){
  
  servoMovement(baseServo, potServo1);
  servoMovement(tiltServo, potServo2);

}

void servoMovement(Servo servo, int pot){
  int servoVal;           
  servoVal = analogRead(pot);          
  servoVal = map(servoVal, 0, 1023, 0, 180); //full 180 movement     
  Serial.println(servoVal);

  servo.write(servoVal); 
}

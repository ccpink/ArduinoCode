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
const int hozServoPin = 11;       
const int verServoPin = 10;      

//Joystick Horizontal and Verticle 
#define joyX A0
#define joyY A1

int xValue;
int yValue;

int servoVal;           // variable to read the value from the analog pin

//Create the servos objects
Servo hozServo;  
Servo verServo;  



void setup() {

  // Servo  
  hozServo.attach(hozServoPin);  // attaches the servo
  verServo.attach(verServoPin);  // attaches the servo

  // Inizialize Serial
  Serial.begin(9600);
}


void loop(){

    // Display the raw data of the joystick
     Serial.println ("XValue----");
    servoVal = analogRead(joyX);          
    servoVal = map(servoVal, 0, 1023, 0, 180); //full 180 movement     
    Serial.println(servoVal);
    
    Serial.println ("YValue----");
    servoVal = analogRead(joyY);           
    servoVal = map(servoVal, 0, 1023, 70, 180); // Only 110 movement   
    Serial.println(servoVal);

    // Read the horizontal joystick value  
    servoVal = analogRead(joyX);          
    servoVal = map(servoVal, 0, 1023, 0, 180); //full 180 movement     

    //Make the horizontal servo move
    hozServo.write(servoVal);                            

    // Read the Verticle joystick value  
    servoVal = analogRead(joyY);           
    servoVal = map(servoVal, 0, 1023, 70, 180); // Only 110 movement    

    //Make the Verticle Servo Move
    verServo.write(servoVal);                           // set the position of the servo

    delay(25);                                       // waits between value reads

}

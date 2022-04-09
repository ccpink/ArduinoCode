#include <Servo.h>
//Servo which is in controll of the Motor.
Servo myservo;
//Integer to hold the value we recieve over communication
int number;

void setup () {
  Serial.begin(9600);
  myservo.attach(14); // Use PWM pin 14 to control Sabertooth.
}

void loop() {  
  
  if (Serial.available()) {
    //Receive the serial communciation
        number = Serial.parseInt();
        //Error testing code that can be used
        Serial.print("The following char was received: ");
        Serial.println(nr, DEC);
  
  if(number == 0){
    Serial.println("Stopping the Motor");
    // 90 means stopping the motor.
    myservo.write(90);
  }else if(number == 1){
    // 0 means full power in one direction.
    // Actually the minimum value for me is around 30.
    // A smaller value won't drive the motor.
    Serial.println("Power in one direction");
    myservo.write(30);
  } else if(number == 2){
    // 180 means full power in the other direction.
    // Actually the maximum value for me is around 160.
    // A larger value won't drive the motor either.
    Serial.println("Power in the other direction");
    myservo.write(160);
  }else{
    // 90 means stopping the motor.
    Serial.println("Stopping the motor because none of the above worked.");
    myservo.write(90);
   }
   
   }else{
    Serial.println("Serial not available.");
    }
}

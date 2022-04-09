#include <Servo.h>
Servo myservo;
String a = "op";
void setup () {
  myservo.attach(1); // Use PWM pin 14 to control Sabertooth.
  Serial.begin(9600);
}

void loop() {  

  String ans = Serial.readString();
  if(ans == a){
    Serial.println("okkkk");
  // 0 means full power in one direction.
  // Actually the minimum value for me is around 30.
  // A smaller value won't drive the motor.
  myservo.write(30);
  delay(2000);
 
  // 90 means stopping the motor.
  myservo.write(90);
  delay(2000);  
   
  // 180 means full power in the other direction.
  // Actually the maximum value for me is around 160.
  // A larger value won't drive the motor either.
  myservo.write(160);
  delay(2000);
  }
}

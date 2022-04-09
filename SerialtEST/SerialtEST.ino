#include <Servo.h>

const int pin1 = 1;

String a = "op";
String b = "cl";
String c = "rv";

Servo myservo;

int incomedate = 0;
void setup() {
 Serial.begin(9600); //设置串口波特率9600

 myservo.attach(pin1); // Use PWM pin 14 to control
 
 
}

void loop() {
  if(Serial.available()){
   String ans = Serial.readString();

  if(ans == a){
    Serial.println("Stopping the Motor");
    // 90 means stopping the motor.
   digitalWrite(pin1, HIGH);
  myservo.write(30);
  delay(2000);
   
  }
  if(ans == b){
    // 0 means full power in one direction.
    // Actually the minimum value for me is around 30.
    // A smaller value won't drive the motor.
    Serial.println("Power in one direction");
   // myservo.write(0);
    
    digitalWrite(pin1, LOW);
    
    
  } 

     
    
   }
   
   
//   if (incomedate == '1')
//   {
//     //若接收到1则执行
//     pinMode(13, OUTPUT);
//     digitalWrite(13, HIGH); //亮灯    
//     Serial.println("received"); //向树莓派发送信息
//   }else{
//      Serial.println("not recieved"); //向树莓派发送信息
//    
//    }
   //delay(5);
 }

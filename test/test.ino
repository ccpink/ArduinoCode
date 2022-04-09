String a = "0";
String b = "1";
String c = "2";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  
 
  // put your main code here, to run repeatedly:
  String ans = Serial.readString();
  if(ans == a){
    Serial.println("0 recieved");

  } 
  else if(ans == b){
    Serial.println("1 recieved");
    
  } 
  else if(ans == c){
     Serial.println("2 recieved");
      
  }
  
}

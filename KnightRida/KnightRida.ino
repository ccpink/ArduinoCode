
int myPins[] = {13,12,11,10,9,8,7,6,5,4};
int previousPin = 0;

void setup() {
  Serial.begin(9600);
 //Inialise all pins
    for (byte i = 0; i < 10; i = i + 1) {
      pinMode(myPins[i], OUTPUT);
    }
}

void loop() {

previousPin = 0;

 for (int i = 0; i < 10; i = i + 1) {
      digitalWrite(myPins[i], HIGH);  
      digitalWrite(previousPin, LOW);
      previousPin = myPins[i]; 
      Serial.println(previousPin);
      delay(100);
      
    }
  
  for (int i = 9; i >= 0; i = i - 1) {
      digitalWrite(myPins[i], HIGH);   
      digitalWrite(previousPin, LOW);
      previousPin = myPins[i]; 
      Serial.println(previousPin);
      delay(100);
   }
 

}

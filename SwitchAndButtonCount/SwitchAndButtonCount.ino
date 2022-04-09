/*
  //Help found here
  //https://www.arduino.cc/en/tutorial/switch

*/


int inputPin = 2;         
int ledPin = 13;       

int state = HIGH;      
int reading;           
int previous = LOW; 
int timesPressed = 0;

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the aoutput flickers

// the setup routine runs once when you press reset:
void setup() {
  
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Times pressed equals " + timesPressed);
}

void loop() {
 reading = digitalRead(inputPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH){
      state = LOW;
      timesPressed ++;
    }
    else{
      state = HIGH;
      timesPressed ++;
    } 

    Serial.println(timesPressed);
    
    time = millis();    
  }

  digitalWrite(ledPin, state);

  previous = reading;
  
}

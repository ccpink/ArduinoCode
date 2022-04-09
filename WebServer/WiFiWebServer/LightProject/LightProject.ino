int lightPin = 19;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(lightPin);
  value = map(value, 0, 1023, 1023, 0);
  Serial.println("Analog value : ");
  Serial.println(value);
  delay(250);
}

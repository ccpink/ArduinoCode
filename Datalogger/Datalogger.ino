//Include DHT, LCD AND SD libraries
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
#include <SPI.h>
#include <SD.h>

// define the DHT Pin
const int chipSelect = 4;
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);

  dht.begin();

  //read lcd
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on

  // Print a message on both lines of the LCD.
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Starting Program");
  
  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print("Please wait");
  
  Serial.print("Initializing SD card...");

  // Check for SD card is available
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  
}


void loop() {  
  delay(10000);
  String dataString = "";
  // read humidity
  float h = dht.readHumidity();
  
  //Check statement
  //Serial.print("Humidity :" + String(h));
  
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);

  dataString += String(f);
  dataString += ",";
  dataString += String(h);

  lcd.clear();

  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Humidity: " + String(h));

  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print("Fahr: " + String(f));

  //Test datastring output
  //Serial.println(dataString);
  //Check statement
  //Serial.println(" Temp(F) :" + String(f));

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

}

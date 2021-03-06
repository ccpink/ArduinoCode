/*
  LiquidCrystal Library - Serial Input

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch displays text sent over the serial port
 (e.g. from the Serial Monitor) on an attached LCD.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalSerialDisplay

*/

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Enter a sentence.");
  lcd.setCursor(0,0);
  lcd.print("Enter a sentence");
  }

char rx_byte = 0;
String rx_str = "";

void loop() {
  
  if (Serial.available() > 0) {    
    rx_byte = Serial.read();       
    
    if (rx_byte != '\n') {
      lcd.clear();
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.println(rx_str);
      lcd.setCursor(0,1);
      lcd.print(rx_str);
      rx_str = "";                
      Serial.println("");
      Serial.println("Enter a sentence.");
    }
  }

    lcd.scrollDisplayLeft();
    delay(150);
}

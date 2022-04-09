/*
 * 7-segment display with 74HC595 shift register
 * 4-Digit counter example.
 * Common anode 7-segment display is used.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 */
  
// shift register pin definitions

#define latchPin = 10;
#define clockPin  11   // clock pin
#define dataPin   12   // data pin
 
// common pins of the four digits definitions
#define Dig1    2
#define Dig2    3
#define Dig3    4
#define Dig4    5
 
// variable declarations
byte current_digit;
int  count = 0;
void disp(byte number, bool dec_point = 0);
 
void setup()
{
  pinMode(Dig1, OUTPUT);
  pinMode(Dig2, OUTPUT);
  pinMode(Dig3, OUTPUT);
  pinMode(Dig4, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
  disp_off();  // turn off the display
 
  // Timer1 module overflow interrupt configuration
  TCCR1A = 0;
  TCCR1B = 1;  // enable Timer1 with prescaler = 1 ( 16 ticks each 1 µs)
  TCNT1  = 0;  // set Timer1 preload value to 0 (reset)
  TIMSK1 = 1;  // enable Timer1 overflow interrupt
}
 
ISR(TIMER1_OVF_vect)   // Timer1 interrupt service routine (ISR)
{
  disp_off();  // turn off the display
 
  switch (current_digit)
  {
    case 1:
      disp(count / 1000);   // prepare to display digit 1 (most left)
      digitalWrite(Dig1, HIGH);  // turn on digit 1
      break;
 
    case 2:
      disp( (count / 100) % 10 );   // prepare to display digit 2
      digitalWrite(Dig2, HIGH);     // turn on digit 2
      break;
 
    case 3:
      disp( (count / 10) % 10 );   // prepare to display digit 3
      digitalWrite(Dig3, HIGH);    // turn on digit 3
      break;
 
    case 4:
      disp(count % 10);   // prepare to display digit 4 (most right)
      digitalWrite(Dig4, HIGH);  // turn on digit 4
  }
 
  current_digit = (current_digit % 4) + 1;
}
 
// main loop
void loop()
{
    count++;  // increment 'count' by 1
    if(count > 9999)
      count = 0;
    delay(1000);  // wait 200 milliseconds
  
}
 
void disp(byte number, bool dec_point)
{
  switch (number)
  {
    case 0:  // print 0
      shiftOut(dataPin, clockPin, MSBFIRST, 0x02 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 1:  // print 1
      shiftOut(dataPin, clockPin, MSBFIRST, 0x9E | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 2:  // print 2
      shiftOut(dataPin, clockPin, MSBFIRST, 0x24 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 3:  // print 3
      shiftOut(dataPin, clockPin, MSBFIRST, 0x0C | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 4:  // print 4
      shiftOut(dataPin, clockPin, MSBFIRST, 0x98 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 5:  // print 5
      shiftOut(dataPin, clockPin, MSBFIRST, 0x48 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 6:  // print 6
      shiftOut(dataPin, clockPin, MSBFIRST, 0x40 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
    
    case 7:  // print 7
      shiftOut(dataPin, clockPin, MSBFIRST, 0x1E | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 8:  // print 8
      shiftOut(dataPin, clockPin, MSBFIRST, !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
      break;
 
    case 9:  // print 9
      shiftOut(dataPin, clockPin, MSBFIRST, 0x08 | !dec_point);
      digitalWrite(clockPin, HIGH);
      digitalWrite(clockPin, LOW);
  }
}
 
void disp_off()
{
   digitalWrite(Dig1, LOW);
   digitalWrite(Dig2, LOW);
   digitalWrite(Dig3, LOW);
   digitalWrite(Dig4, LOW);
}
 

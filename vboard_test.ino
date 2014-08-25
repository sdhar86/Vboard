#include "SPI.h" // necessary library

word outputValue = 0; // a word is a 16-bit number
byte data = 0; // and a byte is an 8-bit number
int i = 0;


void setup()
{
  //set pin(s) to input and output
  pinMode(10, OUTPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
}

void loop()
 {
   
    outputValue = 4095;
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
 }
  
  


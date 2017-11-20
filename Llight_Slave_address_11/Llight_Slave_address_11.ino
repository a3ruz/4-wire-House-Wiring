// Include the required Wire library for I2C
#include <Wire.h>
#define LIGHT1 2
#define LIGHT2 3 
#define LIGHT3 4 
#define LIGHT4 5

#define STATUS 11

bool STATE[4]={0,0,0,0};


void toggle ( int x)
{
  if (digitalRead(x)==HIGH)
  digitalWrite(x,LOW);
  else
  digitalWrite(x,HIGH);
   x=10;
}
void setup() {
  //  Outputs
  pinMode (LIGHT1, OUTPUT);
  pinMode (LIGHT2, OUTPUT);
  pinMode (LIGHT3, OUTPUT);
  pinMode (LIGHT4, OUTPUT);
  
  pinMode (STATUS, OUTPUT);
  //  Slave on address 9
  
  Wire.begin(11); 
   Serial.begin(9600);

}

void receiveEvent(int bytes) {
  int i=0;
  while (Wire.available()) { // slave may send less than requested
     digitalWrite(STATUS,HIGH);
     STATE[i]=Wire.read(); //// receive a byte as character  
    Serial.println(STATE[i]);         // print the character
  i++;
   digitalWrite(STATUS,LOW); 
}
}
void loop() {
   Wire.onReceive(receiveEvent); //// function to trigger when something is received.
   
   digitalWrite(LIGHT1,STATE[0]);
   digitalWrite(LIGHT2,STATE[1]);
   digitalWrite(LIGHT3,STATE[2]);
   digitalWrite(LIGHT4,STATE[3]);
  }


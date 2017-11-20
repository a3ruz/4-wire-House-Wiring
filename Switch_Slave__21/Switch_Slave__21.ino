#include <elapsedMillis.h>

#include <OneButton.h>

#include <Wire.h>


#define SLAVEADDRESS 21 // change the switch slave adress here 

#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5
#define LDR A0
#define LM35 A1
#define STATUS 12
#define RED 10
#define GREEN 9
#define BLUE 11

OneButton Button1(SW1,false);
OneButton Button2(SW2,false);
OneButton Button3(SW3,false);
OneButton Button4(SW4,false);

elapsedMillis timeElapsed;
elapsedMillis sensedelay;


int checkbutton(int x);
byte t_read[4]={0,0,0,0} ;
byte s_read[6]={0,0,0,0,0};

int RGB[3];
bool act_RGB=0;
int iR,iG,iB;
void sense();
 void fade();

void doubleclick1();
void doubleclick2();
void doubleclick3();
void doubleclick4();


void setup() {
  
Serial.begin(9600);
pinMode(STATUS,OUTPUT);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);

 pinMode(SW1,INPUT);
 pinMode(SW2,INPUT);
 pinMode(SW3,INPUT);
 pinMode(SW4,INPUT);

 pinMode(LDR,INPUT);
  pinMode(LM35,INPUT);
 
  Wire.begin(SLAVEADDRESS);                // join i2c bus with address #21
  Wire.onRequest(transmit); // register event

}

void applyRGB();
void receiveEvent(int bytes) {
  int i=0;
  while (Wire.available()) { // slave may send less than requested
     digitalWrite(STATUS,HIGH);
     RGB[i]=Wire.read(); //// receive a byte as character  
    Serial.println(RGB[i]);         // print the character
  i++;
   digitalWrite(STATUS,LOW); 
act_RGB=1;
}
}

void loop() {
Serial.print(s_read[0]);
Serial.print("    ");
 Serial.println(s_read[5]);
 digitalWrite(13,1);
 Wire.onReceive(receiveEvent);
 sense();
 if(act_RGB==0&&(timeElapsed > 3000))
 fade();
applyRGB();
 digitalWrite(13,0);
 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void transmit() {
digitalWrite(STATUS,HIGH);
  Wire.write(s_read,6);
  //Resetting 
  s_read[1]=0;
  s_read[2]=0;
  s_read[3]=0;
  s_read[4]=0;
digitalWrite(STATUS,LOW);
}

void sense()
{

  if(sensedelay>500)
  {
  s_read[0]=map(analogRead(LDR),0,1000,0,255); //map,0,1023 ,0,255
 s_read[5]=(analogRead(LM35)* 0.48828125);
 sensedelay=0;
  }   
  Button1.tick();
  Button2.tick();
  Button3.tick();
  Button4.tick();
 
    Button1.attachDoubleClick(doubleclick1);
    Button2.attachDoubleClick(doubleclick2);
    Button3.attachDoubleClick(doubleclick3);
    Button4.attachDoubleClick(doubleclick4);   


}

void doubleclick1()
{
  s_read[1]=1;
} 

void doubleclick2()
{
  s_read[2]=1;
} 

void doubleclick3()
{
  s_read[3]=1;
} 

void doubleclick4()
{
  s_read[4]=1;
} 


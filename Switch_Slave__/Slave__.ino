#include <OneButton.h>

#include <Wire.h>

#define SLAVEADDRESS 21 // change the switch slave adress here 

#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5
#define LDR A0



OneButton Button1(SW1,false);
OneButton Button2(SW2,false);
OneButton Button3(SW3,false);
OneButton Button4(SW4,false);


int checkbutton(int x);
byte t_read[4]={0,0,0,0} ;
byte s_read[5]={0,0,0,0,0};
int ls[4]={0,0,0,0};

void sense();


void doubleclick1();
void doubleclick2();
void doubleclick3();
void doubleclick4();


void setup() {
  
Serial.begin(9600);
 pinMode(SW1,INPUT);
 pinMode(SW2,INPUT);
 pinMode(SW3,INPUT);
 pinMode(SW4,INPUT);
 pinMode(A0,INPUT);
 
  Wire.begin(SLAVEADDRESS);                // join i2c bus with address #21
  Wire.onRequest(transmit); // register event

}

void loop() {
 digitalWrite(13,1);
 sense();

 digitalWrite(13,0);
 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void transmit() {

  Wire.write(s_read,5);
  //Resetting 
  s_read[1]=0;
  s_read[2]=0;
  s_read[3]=0;
  s_read[4]=0;
}

void sense()
{

  s_read[0]=map(analogRead(LDR),0,1023 ,0,255);
 
      
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


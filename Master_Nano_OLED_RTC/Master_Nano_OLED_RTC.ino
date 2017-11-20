#include <Wire.h>
//#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"

/////////////////OLED and RTC 
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int thour,tmin,tsec;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

byte flash = 0;
////////////////////////////

/*LIGHT CONTROL */
#define L_SLAVE_1 11  
#define L_SLAVE_2 12

/*SWITCH*/
#define S_SLAVE_1 21
#define S_SLAVE_2 22

//Device last stage

int slave_n,switch_n,device_n;
byte slave_reads[2][6];

byte Tdevice[8];

void read_all_slaves();
void set_toggle();
void toggle_control();
void force_control();
void toggle();

bool l_slave_array[2][4];

///////////////////////////////////



//////////////////////////////

void slave_write();



////// OLED FUNCTIONS/////
//void time_update();
//void oled_start();
//////////////

void setup() {
  Serial.begin(9600);
  Serial.println("SERIAL COMMUNICATION STARTED");
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.println("I2C BUS INITIATED");  // start serial for output
 //oled_start();
 //Serial.println("OLED INITIATED");
 
}

void loop() {
  //Serial.println(millis());
 // time_update();
  read_all_slaves();
  set_toggle();
toggle_control();
  toggle();
  force_control();
  l_slavewrite(); // Write to the light slaves 
  delay(50);
  //delay(1000);
}





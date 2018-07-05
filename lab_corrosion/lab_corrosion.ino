// Institution: Queensland University of Technology
// Author: Andrew Collison
// Supervisour: Assoc Prof. Geoffery Will
/* The driving code for an arduino motor driver and data logger
 *  used to raise and lower corrosion samples out of a solution
 *  to control and monitor the corrosion rate of various samples
 *  in a lab based environment
 */

#include <Wire.h> // Also pre-installed
#include "RTClib.h"
#include <TimeLib.h>

RTC_DS1307 RTC; // RTC clock module

//set motor pins
int d1 = 2;
int d2 = 3;
int motor_speed = 9;

int dir; // Motor direction 
int spd = 255; // Motor Speed 
int sample_pos = 0; // 0 = sample raised. 1= sample lowerd

void RTC_setup(){
  RTC.begin();
  // Check to see if the RTC is keeping time.  If it is, load the time from your computer.
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // This will reflect the time that your sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void motor_control(dir, spd){
  if(dir == 0){ // Set forward direction
    digitalWrite(d1, HIGH);
    digitalWrite(d2, LOW);
    digitalWrite(motor_speed, spd);
    } 
   if(dir == 1){ // Set reverse direction
    digitalWrite(d1, LOW);
    digitalWrite(d2, HIGH);
    digitalWrite(motor_speed, spd);
    }
}

void get_time_RTC(){
DateTime now = RTC.now();
  int cyear = now.year();
  int cmonth = now.month();
  int cday = now.day();  
  int chour = now.hour();
  int cminute = now.minute();
  int csecond = now.second();
  
  // Fotmat date in and array {day/month/year H:M:S}
  int dt_now[6] = {cday, cmonth, cyear, chour, cminute, csecond}
  
  return dt_now;  
}


void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(motor_speed, OUTPUT);

  Wire.begin(); // IIC communications
  Serial.begin(9600); // Serial communications 

  RTC_setup();  
}

void loop() {
  // put your main code here, to run repeatedly:




}

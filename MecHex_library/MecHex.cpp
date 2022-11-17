//include libraries
#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include "MecHex.h"

//constructor function
MecHex::MecHex(){
}

//function to setup the driver
//this sets up the servo driver object created by the adafruit library earlier
//You need to know the servo frequency and the oscillator frequency
//For 9g microservo, the frequency is typically about 50hz
//For this driver, the oscillator frequency is about 25 megahertz, so anything around that works
void MecHex::HexSetup(){
 pwm.begin();
pwm.setOscillatorFrequency(27000000);
pwm.setPWMFreq(50);
//sets up other servos
servo16.attach(9);
servo17.attach(10);
}
int MecHex::HexRead(int servoNum){
return servoPos[servoNum+1];
}

//Servo drive function
void MecHex::HexWrite (int servoNum,int angle){
servoPos[servoNum+1]=angle;
  if(servoNum>=0 && servoNum<16){
  int servoPulse=map(angle,0,180,110,480);
  pwm.setPWM(servoNum,0,servoPulse);
  }
if (servoNum==16){
  servo16.write(angle);
}
if (servoNum==17){
  servo17.write(angle);
}
}

#ifndef MecHex_h
#define MecHex_h

//include necessary libraries
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//create class MecHex
class MecHex
{
  public:
  //constructor
  MecHex();
  //functions
  void HexWrite(int servoNum,int angle);
  int HexRead(int servoNum);
  void HexSetup();
  private:
  //create an instance of the servo driver through adafruit library
  Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver(0x40);
  //create additional servos
  Servo servo16;
  Servo servo17;
  int servoPos[18];
};
#endif

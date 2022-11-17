//Note that this library is specifically made for MEC101 Team 14 Hexapod
//It is assumed that all servos are 9g microservos
//This library will NOT always work with other servos
//This library also assumes that you are using a PCA9685 driver
//It assumes driver is attached at typical I2C on Arduino Uno
//Pinout is: 0-15 are on the pca driver, 16 and 17 are Arduino 9 and 10, respectively
//This controls up to 18 servos
//ALL LIBRARIES MUST BE INCLUDED
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <MecHex.h>

//create hexapod object
MecHex myHex;

void setup() {
Serial.begin(9600);
//initialize
myHex.HexSetup();
}

void loop() {
  //This function "writes" to the servos
  //Easy to use, just like Servo.h library essentially!
  //first argument is the servo number you want to control (from 0-17)
  //second argument is the angle you want the servo to be (0-180)
myHex.HexWrite(11,0);
myHex.HexWrite(16,0);
myHex.HexWrite(0,90);

//you can also read the angle of a servo
Serial.println(myHex.HexRead(0));
Serial.println(myHex.HexRead(16));

}

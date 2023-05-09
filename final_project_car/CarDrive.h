//CarDrive.h - Library headder for controling the drive functions of the ELEGOO Smart Car
//Created by Brian Davis, April 2023


#ifndef CarDrive_h //prevents the library from being included more than once
#define CarDrive_h //defines the library

#include "Arduino.h" //includes the arduino core library

class CarDrive //defines "CarDrive" class
{
  public: //specifies function acess
    CarDrive(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4); //allows for input to specify pins used to control the motors
    //declares directional functions:
    void forward();
    void back();
    void turnLeft();
    void turnRight();
    void Stop();
  private: //specifies function acess
    //declares integer variables
    int _ENA;
    int _ENB;
    int _IN1;
    int _IN2;
    int _IN3;
    int _IN4;
};

#endif

#include "Arduino.h"
#include "CarDrive.h"

CarDrive::CarDrive(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4)
{
  //sets variables equal to inputed values:
  _ENA = ENA;
  _ENB = ENB;
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  _IN4 = IN4;

  //sets pin modes to output:
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);
  pinMode(_IN3, OUTPUT);
  pinMode(_IN4, OUTPUT);
  pinMode(_ENA, OUTPUT);
  pinMode(_ENB, OUTPUT);

  //enables drive motors:
  digitalWrite(_ENA, HIGH);
  digitalWrite(_ENB, HIGH);
}

//directional drive controls are declared as functions:

void CarDrive::forward( )
{
  digitalWrite(_IN1,HIGH);//Left wheel forward
  digitalWrite(_IN2,LOW); 
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH); //Right wheel forward
}

void CarDrive::back( )
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH); //Left wheel back
  digitalWrite(_IN3,HIGH);//Right wheel back
  digitalWrite(_IN4,LOW); 
}

void CarDrive::turnLeft( )
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH); //Left wheel forward
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH); //Right wheel back
}

void CarDrive::turnRight( )
{
  digitalWrite(_IN1,HIGH);//Left wheel back
  digitalWrite(_IN2,LOW); 
  digitalWrite(_IN3,HIGH);//Right wheel forward
  digitalWrite(_IN4,LOW); 
}

void CarDrive::Stop()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,LOW); //Left wheel stop
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,LOW); //Right wheel stop
}

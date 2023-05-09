//Created by Brian Davis, April 2023


#include "CarDrive.h" //includes custom drive library
#include <IRremote.h> //includes publicly available libraries for IR control
#include <Servo.h> //includes publicly available libraries for Servo control
#define IR_RECEIVE_PIN 12 //defines pin connected to IR reciever

//correlates IR reading values (remote button presses) to specific commands:
#define IR_forward 70 //forward button
#define IR_back 21 //back button
#define IR_left 68 //left button
#define IR_right 67 //right button
#define IR_stop 64 //center button
#define IR_launch 74 //# button

CarDrive motor(5, 6, 7, 8, 9, 11); //declares pins of drive motors

int LaunchRelay=2; //declares pin connected to the catapult relay

Servo ReloadServo; // create servo object to control a servo

void setup() {
  Serial.begin(9600); //start serial monitor
  IrReceiver.begin(IR_RECEIVE_PIN); //IR reciever setup
  pinMode(LaunchRelay, OUTPUT); //setup relay as output
  ReloadServo.attach(3); // attach the servo to pin 3
  ReloadServo.write(180); // sets servo to home position
}
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) { //correlates IR inputs to commands
      case IR_forward: {
        Serial.println("forward");
        motor.forward(); // Move forward
        delay(100);
        motor.Stop();    // Stop
        break;
      }
      case IR_back: {
        Serial.println("back");
        motor.back();    // Move backward
        delay(100);
        motor.Stop();    // Stop
        break;
      }
      case IR_left: {
        Serial.println("left");
        motor.turnLeft();  // Turn left
        delay(100);
        motor.Stop();    // Stop
        break;
      }
      case IR_right: {
        Serial.println("right");
        motor.turnRight(); // Turn right
        delay(100);
        motor.Stop();    // Stop
        break;
      }
      case IR_stop: {
        Serial.println("stop");
        motor.Stop();    // Stop
        break;
      }      
      case IR_launch: {
        Serial.println("launch");
        digitalWrite(LaunchRelay,HIGH);
        delay(50);
        digitalWrite(LaunchRelay,LOW);
        delay(100);
        ReloadServo.write(50); // set the servo position to 50 degrees
        delay(1500);
        ReloadServo.write(180); // return the servo back to home position
        delay(1500);
        break;
      }
      default: { //for IR readings not assigned to a command
        Serial.println("input not recognized");
        }
    }
  }
}

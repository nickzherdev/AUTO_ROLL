/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-stepper-motor-28byj-48-uln2003/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  Based on Stepper Motor Control - one revolution by Tom Igoe
*/

#include <AccelStepper.h>

//const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// Define step constants
#define FULLSTEP 4
#define HALFSTEP 8
 
// Define Motor Pins (3 Motors used)

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

#define motorPin1  22     // Blue   - 28BYJ48 pin 1
#define motorPin2  1     // Pink   - 28BYJ48 pin 2
#define motorPin3  3    // Yellow - 28BYJ48 pin 3
#define motorPin4  21    // Orange - 28BYJ48 pin 4

#define motorPin5  32     // Blue   - 28BYJ48 pin 1
#define motorPin6  33     // Pink   - 28BYJ48 pin 2
#define motorPin7  25     // Yellow - 28BYJ48 pin 3
#define motorPin8  26     // Orange - 28BYJ48 pin 4
 
// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);
AccelStepper stepper3(HALFSTEP, IN1, IN3, IN2, IN4);

void setup()
{
  // 1 revolution Motor 1 CW
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(300.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(2048);  
  
  // 1 revolution Motor 2 CCW
  stepper2.setMaxSpeed(1000.0);
  stepper2.setAcceleration(300.0);
  stepper2.setSpeed(200);
  stepper2.moveTo(-2048); 

  // 1 revolution Motor 3 CCW
  stepper3.setMaxSpeed(1000.0);
  stepper3.setAcceleration(300.0);
  stepper3.setSpeed(200);
  stepper3.moveTo(-2048); 
 
}

void loop()
{
  //Change direction at the limits
  if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());
  if (stepper2.distanceToGo() == 0) 
    stepper2.moveTo(-stepper2.currentPosition());
  if (stepper3.distanceToGo() == 0) 
    stepper3.moveTo(-stepper3.currentPosition());
  
  stepper1.run();
  stepper2.run();
  stepper3.run();

}

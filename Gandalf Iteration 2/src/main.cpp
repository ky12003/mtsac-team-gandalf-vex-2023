/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cloud                                            */
/*    Created:      Fri Sep 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Intake.h"
#include "vex.h"
#include "DrivingFunctions.h"
#include "Routines.h"
#include "Autonomous.h"
#include "robot-config.h"
#include "PID.h"

using namespace vex;
competition Competition;




//PID constants
double kP = 0.0;
double kD = 0.0;
double kI = 0.0;

double turnKP = 0.0;
double turnKD = 0.0;
double turnKI = 0.0;

//autonomous settings(adjustable values)
int targetValue = 10;
int targetTurnValue = 0;

int error; //encoderValue - targetValue = position
int previousError = 0; //error 20ms ago
int derivative; //error - previous error = speed(position's rate of change)
int totalError = 0; //totalError + error

int turnError; //encoderValue - targetValue = position
int turnPreviousError = 0; //error 20ms ago
int turnDerivative; //error - previous error = speed(position's rate of change)
int turnTotalError = 0; //totalError + error

bool resetEncoders = false;

//boolean used to turn on/off PID during usercontrol/autonmonous
bool enableDrivingPID = true;

int drivingPID(){
  while(enableDrivingPID){

    if (resetEncoders) {
      resetEncoders = false;
      left_all.setPosition(0, rev);
      right_all.setPosition(0, rev);
    }

    //position of the two front motors
    int leftFrontPosition = left_front.position(rev);
    int rightFrontPosition = right_front.position(rev);

    /////////////////////////////////////////////////////////////////////////////////////////////////  
    //                              Lateral Movement PID                                           //
    ///////////////////////////////////////////////////////////////////////////////////////////////// 

    //average position of the two front motors
    int averagePosition = (leftFrontPosition + rightFrontPosition)/2;

    //
    error = averagePosition - targetValue;

    //derivative
    derivative = error - previousError;

    //integral
    totalError += error;

    double lateralMotorPower = (error * kP) + (derivative * kD); // + (totalError * kD)

    /////////////////////////////////////////////////////////////////////////////////////////////////  
    //                              Directional Movement PID                                       //
    ///////////////////////////////////////////////////////////////////////////////////////////////// 

    //average position of the two front motors
    int turnDifference = (leftFrontPosition - rightFrontPosition)/2;

    //
    turnError = turnDifference - targetValue;

    //derivative
    turnDerivative = turnError - turnPreviousError;

    //integral
    turnTotalError += turnError;

    double turnMotorPower = (error * turnKP) + (derivative * turnKD); // + (totalError * turnKI)


    /////////////////////////////////////////////////////////////////////////////////////////////////

    left_all.spin(forward, lateralMotorPower + turnMotorPower, pct); 
    right_all.spin(forward, lateralMotorPower + turnMotorPower, pct); 


    previousError = error;
    turnPreviousError = turnError;
    vex::task::sleep(20);

  }
  return 1;
}


//autonomous routines go here
void autonomouscontrol(){
  /*
  enableDrivingPID = true;
  vex::task pathCorrection(drivingPID);

  resetEncoders = true;
  targetValue = 100;
  targetTurnValue = 5;

  vex::task::sleep(1000);

  resetEncoders = true;
  targetValue = 100;
  targetTurnValue = 5;
  */
  auto_straight(80);
}

//manual control of robot (tank drive)
void usercontrol(){
  enableDrivingPID = false;
    while (1){
      //ArcadeDrive();
      TankDrive();
    }
   }

int main() {
  
  vexcodeInit();
  Competition.drivercontrol(usercontrol);
  Competition.autonomous(autonomouscontrol);
}

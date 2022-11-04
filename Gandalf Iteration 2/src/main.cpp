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
#include "Roller.h"
#include "Launcher.h"
#include "pneumatics.h"

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



//autonomous routines go here
void autonomouscontrol(){
  RoutineOne();
}

//manual control of robot (tank drive)
void usercontrol(){
  enableDrivingPID = false;
    while (1){
      //ArcadeDrive();
      TankDrive();
      intake_toggle();
      fly_wheel_toggle();
      expansion_toggle();
      //run_roller();

    }
   }

int main() {
  
  vexcodeInit();
  Competition.drivercontrol(usercontrol);
  Competition.autonomous(autonomouscontrol);
}

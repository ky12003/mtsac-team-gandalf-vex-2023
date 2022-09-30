#include "vex.h"


#ifndef AUNTON_FUNCTIONS
#define AUNTON_FUNCTIONS

//DRIVE
void moveForward(double distanceInches, double velocityPercent); // DRIVE FORWARD
void turnInPlace(double turnDegrees, double velocityPercent); // turn the robot in-place clockwise/counterclockwise 
void doIntake(double timeMSec, double velocityPercent); // turn the intake for a certain amount of time
void shootDisks(double timeMSec, double velocityPercent); // turn flywheels to shoot the disks out

void InertialTurn(turnType dir, double speed, double DEGREES, double timeout);



#endif



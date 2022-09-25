#include "vex.h"


#ifndef AUNTON_FUNCTIONS
#define AUNTON_FUNCTIONS

void turnClockwise(double turnDegree);

void turnCounterclockwise(double turnDegree);

//Drive forward
void moveForward(double revolutionCount, double velocityPercent);

void InertialTurn(turnType dir, double speed, double DEGREES, double timeout);



#endif



#include "vex.h"


#ifndef AUNTON_FUNCTIONS
#define AUNTON_FUNCTIONS

void turn_clockwise(double turnDegree);

void turn_counterclockwise(double turnDegree);

//Drive forward
void travelForward(double distanceCM);

void InertialTurn(turnType dir, double speed, double DEGREES, double timeout);


#endif



#include "vex.h"
#include "Routines.h"
#include "Autonomous.h"
#include "intake.h"
#include "PID.h"
#
/**********************************************************
calibrated code
  turn_left(0.96,100,2); //turn left 90 degrees
  turn_left(-0.98,100,2); //turn right 90 degrees
  // move_forward( disMeters, velPct, timeout)
  //turn_left( degrees, velPct, timeout)

  //turn_left(120,50,2); //turn left 90
  //move_forward(0.67, 50, 2);  //forward 1 squard


*/


//Routine 1 Box routine
void RoutineOne()
{
  //while(1)
  //move_forward_alt_test();
  //auto_straight(80);
  //inertial_turn(1080);// degrees + is right

  
  //move_forward_PID(30, 2); //speed then feet
  inertial_turn (-90);      //turn + is turn right - is turn left
  // move_forward_PID(30, 2); //speed then feet
  // inertial_turn (90); 
  // move_forward_PID(30, 2); //speed then feet
  // inertial_turn (90); 
  // move_forward_PID(30, 2); //speed then feet
  // inertial_turn (90); 

  //move_forward_PID(20, 3);//speed in pct then distance 1 disMeter is actually ~1 foot
  //inertial_turn (1080);
}

void RoutineTwo()
{
  move_forward(0.12, 50, 2);
  turn_left(-120,50,2); //turn right 90
  move_forward(0.67, 50, 2);
  turn_left(-120,50,2); //turn right 90
  move_forward(0.12, 50, 2);

}

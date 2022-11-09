#include "vex.h"
#include "Routines.h"
#include "Autonomous.h"
#include "intake.h"
#include "PID.h"
#include "Roller.h"
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
  // run_roller_blue(); 
  // move_back_PID(30,0.5);
  // inertial_turn (180);
  // move_forward_PID(30,1);
  // inertial_turn (-90);
  // move_forward_PID(30,1.5);
  // run_roller_blue(); 


  
  move_forward_PID(30, 1); //speed then feet
  inertial_turn (90); 
  move_forward_PID(30, 1); //speed then feet
  inertial_turn (90); 
  move_forward_PID(30, 1); //speed then feet
  inertial_turn (90); 
  move_forward_PID(30, 1); //speed then feet
  inertial_turn (90); 
  //inertial_turn(-360);

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

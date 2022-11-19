#include "vex.h"
#include "Routines.h"
#include "Autonomous.h"
#include "intake.h"
#include "PID.h"
#include "Roller.h"
#include "Launcher.h"
#include "Pneumatics.h"
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
  // while(true)
  // test_current_hue();

  retract_feeder();
  run_roller_red_safe(); 
  move_back(0.525, 60, 2);
  inertial_turn(90);
  move_back_PID(20, 3.5);
  fly_wheel_one_forward(45);
  fly_wheel_two_forward(45);
  inertial_turn(-5);
  vex::task::sleep( 4000 );
  extend_feeder();
  vex::task::sleep( 1500 );
  retract_feeder();
  fly_wheel_one.setBrake(coast);
  fly_wheel_two.setBrake(coast);
  // vex::task::sleep( 1500 );
  // extend_feeder();
  // vex::task::sleep( 1500 );
  // retract_feeder();
  // vex::task::sleep( 1500 );
  
}

void RoutineTwo()
{
  move_forward(0.12, 50, 2);
  turn_left(-120,50,2); //turn right 90
  move_forward(0.67, 50, 2);
  turn_left(-120,50,2); //turn right 90
  move_forward(0.12, 50, 2);
}

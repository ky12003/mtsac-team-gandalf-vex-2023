#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

//Drivetrain motors

motor left_front(PORT11,ratio6_1, true);
motor left_middle(PORT12,ratio6_1,false);
motor left_back(PORT13,ratio6_1,true);

motor right_front(PORT18,ratio6_1,true);
motor right_middle(PORT19,ratio6_1,false);
motor right_back(PORT20,ratio6_1,true);



motor_group left_all(left_front,left_middle,left_back);
motor_group right_all(right_front,right_middle,right_back);

motor fly_wheel_one(PORT7,ratio18_1,true);
motor fly_wheel_two(PORT8,ratio18_1,false);

motor intake(PORT13,ratio36_1,true);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
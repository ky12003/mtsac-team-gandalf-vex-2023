#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

//drivetrain motors
motor FrontLeftBottom(PORT19, ratio18_1, true);
motor FrontLeftTop(PORT20, ratio18_1, false);

motor FrontRightTop(PORT12, ratio18_1, false); 
motor FrontRightBottom(PORT11, ratio18_1, true);

motor BackRightTop(PORT18, ratio18_1, true); 
motor BackRightBottom(PORT16, ratio18_1, false);

motor BackLeftTop(PORT8, ratio18_1, false); 
motor BackLeftBottom(PORT6, ratio18_1, true);



motor_group leftDrive(FrontLeftTop, FrontLeftBottom, BackLeftTop, BackLeftBottom, BackLeftTop);
motor_group rightDrive(FrontRightTop, FrontRightBottom, BackRightTop, BackRightBottom, BackRightTop);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}

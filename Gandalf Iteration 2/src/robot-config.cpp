#include "vex.h"
using namespace vex;
//PORT1:
//PORT2:
//PORT3:
//PORT4:
//PORT5:
//PORT6:
//PORT7:  fly_wheel_one
//PORT8:  fly_wheel_two
//PORT9:
//PORT10: inertial sensor
//PORT11: left_front
//PORT12: left_middle
//PORT13: left_back
//PORT14: intake
//PORT15: roller
//PORT16:
//PORT17:
//PORT18: right_front
//PORT19: right_middle
//PORT20: right_back

//ThreeWireA: Feeder
//ThreeWireB: Expansion
//ThreeWireC:
//ThreeWireD:
//ThreeWireE:
//ThreeWireF:
//ThreeWireG:
//ThreeWireH:

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

//Drivetrain motors

motor left_front(PORT11,ratio6_1, true);
motor left_middle(PORT12,ratio6_1,false);
motor left_back(PORT13,ratio6_1,true);

motor right_front(PORT18,ratio6_1,false);
motor right_middle(PORT19,ratio6_1,true);
motor right_back(PORT20,ratio6_1,false);

motor_group left_all(left_front,left_middle,left_back);
motor_group right_all(right_front,right_middle,right_back);

motor fly_wheel_one(PORT7,ratio18_1,true);
motor fly_wheel_two(PORT8,ratio18_1,false);

motor intake(PORT14,ratio18_1,true);

motor roller(PORT15,ratio18_1,true);//need to check motor setting

inertial inertial_sensor(PORT10);

digital_out feeder = digital_out(Brain.ThreeWirePort.A);
digital_out expansion = digital_out(Brain.ThreeWirePort.B);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}
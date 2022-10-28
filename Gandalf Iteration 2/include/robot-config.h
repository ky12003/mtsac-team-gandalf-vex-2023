

using namespace vex;

extern brain Brain;

extern controller controller1;

//Drivetrain motors

extern motor left_front;
extern motor left_middle;
extern motor left_back;

extern motor right_front;
extern motor right_middle;
extern motor right_back;

extern motor_group left_all;
extern motor_group right_all;

extern motor_group intake;
extern motor intake_1;
extern motor intake_2;


extern motor fly_wheel_one;
extern motor fly_wheel_two;

extern motor roller;

extern inertial inertial_sensor;
extern digital_out feeder;
extern digital_out expansion;

extern optical optical_sensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

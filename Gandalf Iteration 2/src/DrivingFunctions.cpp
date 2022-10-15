#include "intake.h"
#include "DrivingFunctions.h"
#include "vex.h"
#include "launcher.h"
#include "robot-config.h"

void ArcadeDrive()
{

 if (controller1.ButtonR1.pressing())
 {
   run_intake();
 } 
 else if (controller1.ButtonR2.pressing())
 {
  run_intake_reverse();
 } 
 else 
 {
   intake.stop();
 }  

 if(abs(controller1.Axis3.value()) > 5 || abs(controller1.Axis1.value()) > 5)
 {
    left_all.spin(forward, (controller1.Axis3.value() + controller1.Axis1.value() ), pct);
    right_all.spin(forward, (controller1.Axis3.value() - controller1.Axis1.value() ), pct);
  } 
  else 
  {
    // left_back.setBrake(brake);
    // left_middle.setBrake(brake);
    // right_back.setBrake(brake);
    // left_front.setBrake(brake);
    // right_front.setBrake(brake);
    // right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
  }
 
 if(controller1.ButtonL1.pressing())
 {
   fly_wheel_one_reverse();
   fly_wheel_two_reverse();
 }else{
   fly_wheel_one_forward();
   fly_wheel_two_forward();
 }

}

void TankDrive()
{
  //detects input from two controller joysticks and spins motors
  if(abs(controller1.Axis3.value()) > 5 || abs(controller1.Axis2.value()) > 5) {
    left_all.spin(forward,controller1.Axis3.value(), pct); 
    right_all.spin(forward,controller1.Axis2.value() , pct); 
  } else {
    // left_back.setBrake(brake);
    // left_middle.setBrake(brake);
    // right_back.setBrake(brake);
    // left_front.setBrake(brake); 
    // right_front.setBrake(brake);
    // right_middle.setBrake(brake);

    //stops if no input
    left_all.stop();
    right_all.stop();
  }
}
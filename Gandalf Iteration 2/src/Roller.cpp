#include "vex.h"
#include "robot-config.h"
#include "Autonomous.h"

void run_roller_blue() {
  inertial_sensor.resetRotation();
  while(optical_sensor.isNearObject()==false)
  {
    left_all.spin(forward, 10, pct);
    right_all.spin(forward, 10, pct);
    printf ("Currently moving forward\n ");
  }
  left_all.spinFor(fwd, 15 , degrees );
  right_all.spinFor(fwd, 15 , degrees );
  if((optical_sensor.hue() >100 )&&(optical_sensor.isNearObject()))
  return;
  while(optical_sensor.hue() < 100) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = <100
      //blue = >100
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());
      printf ("seeing red ");
      roller.spin(forward, 100, pct);
      left_all.spin(forward, 10, pct);
      right_all.spin(forward, 10, pct);

      }      
      //stops when color detected is no longer the undesired color

    }
    //when not near any object, program outputs "Not detecting"
    roller.spinFor(fwd, 30, deg);
    printf ("Not detecting\n");
    roller.stop(brake);
    left_back.setBrake(brake);
    left_middle.setBrake(brake);
    right_back.setBrake(brake);
    left_front.setBrake(brake);
    right_front.setBrake(brake);
    right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
  }

void run_roller_red() {
  inertial_sensor.resetRotation();
  while(optical_sensor.isNearObject()==false)
  {
    left_all.spin(forward, 10, pct);
    right_all.spin(forward, 10, pct);
  }
  left_all.spinFor(fwd, 10 , degrees );
  right_all.spinFor(fwd, 10 , degrees );
  if((optical_sensor.hue() <100 )&&(optical_sensor.isNearObject()))
  return;
  while(optical_sensor.hue() > 100) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = <100
      //blue = >100
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());
      printf ("seeing blue ");
      roller.spin(forward, 100, pct);
      left_all.spin(forward, 10, pct);
      right_all.spin(forward, 10, pct);

      }      
      //stops when color detected is no longer the undesired color

    }
    //when not near any object, program outputs "Not detecting"
    roller.spinFor(fwd, 30, deg);
    printf ("Not detecting\n");
    roller.stop(brake);
    left_back.setBrake(brake);
    left_middle.setBrake(brake);
    right_back.setBrake(brake);
    left_front.setBrake(brake);
    right_front.setBrake(brake);
    right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
  }

void run_roller_blue_safe(){
  inertial_sensor.resetRotation();
  while(optical_sensor.isNearObject()==false)
  {
    left_all.spin(forward, 10, pct);
    right_all.spin(forward, 10, pct);
    printf ("Currently moving forward\n ");
  }
  left_all.spinFor(fwd, 10 , degrees );
  right_all.spinFor(fwd, 10 , degrees );
  if((optical_sensor.hue() >100 )&&(optical_sensor.isNearObject()))
  run_roller_red();
  while(optical_sensor.hue() < 100) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = <100
      //blue = >100
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());
      printf ("seeing red ");
      roller.spin(forward, 100, pct);
      left_all.spin(forward, 10, pct);
      right_all.spin(forward, 10, pct);

      }      
      //stops when color detected is no longer the undesired color

    }
    //when not near any object, program outputs "Not detecting"
    roller.spinFor(fwd, 30, deg);
    printf ("Not detecting\n");
    roller.stop(brake);
    left_back.setBrake(brake);
    left_middle.setBrake(brake);
    right_back.setBrake(brake);
    left_front.setBrake(brake);
    right_front.setBrake(brake);
    right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
    int error = inertial_sensor.rotation(deg);
    inertial_turn(-error);
  }

void run_roller_red_safe(){
  inertial_sensor.resetRotation();
  while(optical_sensor.isNearObject()==false)
  {
    left_all.spin(forward, 10, pct);
    right_all.spin(forward, 10, pct);
  }
  left_all.spinFor(fwd, 10 , degrees );
  right_all.spinFor(fwd, 10 , degrees );
  if((optical_sensor.hue() <100 )&&(optical_sensor.isNearObject()))
  run_roller_blue();
  while(optical_sensor.hue() > 100) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = <100
      //blue = >100
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());
      printf ("seeing blue ");
      roller.spin(forward, 100, pct);
      left_all.spin(forward, 10, pct);
      right_all.spin(forward, 10, pct);

      }      
      //stops when color detected is no longer the undesired color

    }
    //when not near any object, program outputs "Not detecting"
    roller.spinFor(fwd, 30, deg);
    printf ("Not detecting\n");
    roller.stop(brake);
    left_back.setBrake(brake);
    left_middle.setBrake(brake);
    right_back.setBrake(brake);
    left_front.setBrake(brake);
    right_front.setBrake(brake);
    right_middle.setBrake(brake);
    left_all.stop();
    right_all.stop();
    int error = inertial_sensor.rotation(deg);
    inertial_turn(-error);
  }


void run_roller_reverse()
{
  roller.spin(reverse, 100, pct);
}

void test_current_hue()
{
  printf ("Hue: ");
  printf ("%.2f\n", optical_sensor.hue());
}
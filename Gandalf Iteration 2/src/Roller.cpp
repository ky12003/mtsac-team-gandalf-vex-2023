#include "vex.h"
#include "robot-config.h"

void run_roller_blue() {
  while(optical_sensor.hue() >= 50 && optical_sensor.hue() <= 250) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = 3-40
      //blue = 50-250
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());

      if (optical_sensor.hue() >= 50 && optical_sensor.hue() <= 250){
        roller.spin(forward, 100, pct);
        left_all.spin(forward, 40, pct);
        right_all.spin(forward, 40, pct);

      }      
      //stops when color detected is no longer the undesired color
      else {
        roller.stop(brake);
      }

    }
    //when not near any object, program outputs "Not detecting"
    else{
      printf ("Not detecting\n");
      roller.stop(brake);
    }

  }
}

void run_roller_red() {
  while(optical_sensor.hue() >= 3 && optical_sensor.hue() <= 40) {
    if (optical_sensor.isNearObject()) {
      
      //prints the detected object's color hue value
      //red = 3-40
      //blue = 50-250
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());

      //checks if red then spins to blue
      //use this to SPIN TO RED
      //COMMENT OUT when not being used
    //////////////////////////////////////////////////////////////////////////////////

      if (optical_sensor.hue() >= 3 && optical_sensor.hue() <= 40){
        roller.spin(forward, 100, pct);
        left_all.spin(forward, 40, pct);
        right_all.spin(forward, 40, pct);
      }
      
    //////////////////////////////////////////////////////////////////////////////////
      
      //stops when color detected is no longer the undesired color
      else {
        roller.stop(brake);
      }

    }
    //when not near any object, program outputs "Not detecting"
    else{
      printf ("Not detecting\n");
      roller.stop(brake);
    }

  }
}

void run_roller_reverse()
{
  roller.spin(reverse, 100, pct);
}
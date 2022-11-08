#include "vex.h"
#include "robot-config.h"

void run_roller_blue() {
  for(int i = 0; i < 2; i++){
  while(optical_sensor.hue() >=90  && optical_sensor.hue() <= 200) {
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

      if (optical_sensor.hue() >= 90 && optical_sensor.hue() <= 200){
        roller.spin(forward, 100, pct);
        left_all.spin(forward, 15, pct);
        right_all.spin(forward, 15, pct);
      }
      
    //////////////////////////////////////////////////////////////////////////////////
      
      //stops when color detected is no longer the undesired color
      else {
        roller.stop(brake);
        left_all.stop(brake);
        right_all.stop(brake);
      }
    }
  }
roller.stop(brake);
left_all.stop(brake);
right_all.stop(brake);
}
}

void run_roller_red() {
  // while(1==1){
  //     printf ("Hue: ");
  //     printf ("%.2f\n", optical_sensor.hue());
  // }
  for(int i = 0; i < 2; i++){
  while(optical_sensor.hue() >=3  && optical_sensor.hue() <= 87) {
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

      if (optical_sensor.hue() >= 3 && optical_sensor.hue() <= 87){
        roller.spin(forward, 100, pct);
        left_all.spin(forward, 15, pct);
        right_all.spin(forward, 15, pct);
      }
      
    //////////////////////////////////////////////////////////////////////////////////
      
      //stops when color detected is no longer the undesired color
      else {
        roller.stop(brake);
        left_all.stop(brake);
        right_all.stop(brake);
      }
    }
  }
roller.stop(brake);
left_all.stop(brake);
right_all.stop(brake);
}
}

void run_roller_reverse()
{
  roller.spin(reverse, 100, pct);
}
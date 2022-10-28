#include "vex.h"
#include "robot-config.h"

void run_roller() {
  if (1==1) {
    if (optical_sensor.isNearObject()) {
      
      printf ("Hue: ");
      printf ("%.2f\n", optical_sensor.hue());

    }else{
      printf ("Not detecting");
    }
  }

  //FOR ROLLING TO RED
  
  // while (true) {
  //   if (optical_sensor.isNearObject()){
  //     if (optical_sensor.hue() >= 200 && optical_sensor.hue() <= 240){
  //       roller.spin(forward, 50, pct);
  //     } else {
  //       roller.stop(brake);
  //     }
  //   }
  // }

  //FOR ROLLING TO BLUE

  // while (true) {
  //   if (optical_sensor.isNearObject()){
  //     if (optical_sensor.hue() >= 200 && optical_sensor.hue() <= 240){
  //       roller.spin(forward, 50, pct);
  //     } else {
  //       roller.stop(brake);
  //     }
  //   }
  // }

}

void run_roller_reverse()
{
  roller.spin(reverse, 100, pct);
}
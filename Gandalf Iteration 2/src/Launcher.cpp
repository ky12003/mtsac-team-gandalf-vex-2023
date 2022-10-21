#include "vex.h"
#include "robot-config.h"

void fly_wheel_one_forward()
{
  fly_wheel_one.spin(fwd, 450, pct);
}

void fly_wheel_two_forward()
{
  fly_wheel_two.spin(fwd, 450, pct);
}

void fly_wheel_one_reverse()
{
  fly_wheel_one.spin(reverse, 100, pct);
}

void fly_wheel_two_reverse()
{
  fly_wheel_two.spin(reverse, 100, pct);
}

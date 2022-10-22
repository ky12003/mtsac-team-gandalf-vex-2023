#include "vex.h"
#include "robot-config.h"
void run_roller()
{
  roller.spin(fwd, 10, pct); 
}

void run_roller_reverse()
{
  roller.spin(reverse, 10, pct);
}
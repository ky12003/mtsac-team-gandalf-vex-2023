#include "vex.h"
#include "robot-config.h"

void run_intake()
{
  intake.spin(fwd, 100, pct);
}

void run_intake_reverse()
{
  intake.spin(reverse, 200, pct);
}


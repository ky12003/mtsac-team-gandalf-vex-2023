#include "vex.h"
#include "robot-config.h"

//intakes at full power
void run_intake()
{
  intake.spin(fwd, 100, pct);
}

//outtakes at full power
void run_intake_reverse()
{
  intake.spin(reverse, 200, pct);
}


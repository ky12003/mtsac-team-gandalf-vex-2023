#include "vex.h"
#include "robot-config.h"

void extend_feeder()
{
  feeder.set(true);
}
void retract_feeder()
{
  feeder.set(false);
}
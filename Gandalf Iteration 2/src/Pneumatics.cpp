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
void extend_expansion()
{
  expansion.set(true);
}
void retract_expansion()
{
  expansion.set(false);
}
void expansion_toggle()
{
  bool expansion_toggle = false;
  bool expansion_stopper = false;
  if (controller1.ButtonA.pressing()){
    if (!expansion_stopper)
    {
      expansion_toggle = !expansion_toggle;
      expansion_stopper = true;
    } else {
      expansion_stopper = false;
    }


  } if (expansion_toggle)
      extend_expansion();
    else
      retract_expansion();


}
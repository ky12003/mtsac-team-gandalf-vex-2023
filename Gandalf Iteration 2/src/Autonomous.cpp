#include "vex.h"
#include "robot-config.h"

const int PCT_TO_RPM = 6;
const float rev_to_meters = 2.894;

//pause
void timeOut(int timeSeconds)
{
    left_all.setTimeout(timeSeconds, sec);
    right_all.setTimeout(timeSeconds, sec);
}

//moves forward by input meters at set speed and then times out
void move_forward(double disMeters, double velPct, int timeout)
{
    timeOut(timeout);
    disMeters = disMeters * rev_to_meters;
    velPct = velPct * PCT_TO_RPM;
    right_all.spinFor(fwd, double(disMeters), rev, double(velPct), rpm, false);
    left_all.spinFor(fwd, double(disMeters), rev, double(velPct), rpm, true);
    timeOut(0);
}

//turns left input degrees at set speed then times out
void turn_left(double degrees, double velPct, int timeout)
{
    timeOut(timeout);
    degrees = degrees / 360;
    degrees = degrees * 0.270* 3.1415 * rev_to_meters;
    right_all.spinFor(fwd, double(degrees), rev, double(velPct), rpm, false);
    left_all.spinFor(reverse, double(degrees), rev, double(velPct), rpm, true);
    timeOut(0);
}













// void correct_error()
// {
//   double leftEncoder = left_front.position(rev);
//   double rightEncoder = right_front.position(rev);
//   double error = fabs(rightEncoder - leftEncoder); 
//   if (leftEncoder > rightEncoder)
//    {
//       error = fabs(rightEncoder - leftEncoder);
//       right_all.spin(fwd, 100-error,rpm);
//       left_all.spin(fwd,100,rpm);
//   }else if (leftEncoder > rightEncoder)
//    {
//       error = fabs(rightEncoder - leftEncoder);
//       left_all.spin(fwd, 100-error,rpm);
//       right_all.spin(fwd,100,rpm);
//   }

  

//    printf("left rotations: %2f         right rotationsL %2f \n", leftEncoder, rightEncoder);
// }

// //using encoders to ensure straight
// void move_forward_alt(double disMeters, double velPct, int timeout)
// {
//     right_all.spinFor(fwd, double(disMeters)/10, rev, double(velPct), rpm, false);
//     left_all.spinFor(fwd, double(disMeters)/10, rev, double(velPct), rpm, true);
//     //double outSideError = fabs(left_front.position(rev)-right_front.position(rev));
//     //double outSideLeft = left_front.position(rev);
//     //double outSideRight = right_front.position(rev);
//     correct_error();
//     //if(outSideLeft < outSideRight)
//     //{left_all.spin(fwd,100,rpm); right_all.spin(fwd,100*())}
// }

// int left_speed = 50;
// int right_speed = 25;

// void move_forward_alt_test()
// {
//   left_all.spin(fwd,left_speed,rpm);
//   right_all.spin(fwd,right_speed,rpm);
//   if(left_front.position(rev)<right_front.position(rev))
//   {
//     left_speed++; 
//   } else if (left_front.position(rev)>right_front.position(rev))
//   {
//     right_speed++;
//   }
// }

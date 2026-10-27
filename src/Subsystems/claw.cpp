#include "Subsystems/claw.h"

pros::Motor claw(1, pros::MotorGear::green);

void clawMove(int x){
    claw.move(x);
}

#include "Subsystems/lift.h"
pros::MotorGroup lift4b({12,-19},pros::MotorGearset::green); // green carts for now - also its around 2 rotations ish
//pros::Rotation lift4bRot(19); 

void lift(int x){
   lift4b.move(x);  
}
#include "Subsystems/toggle.h"

pros::Motor tog(-9);

void toggle(int x){
    tog.move(x);
}


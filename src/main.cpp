#include "main.h"
#include "rw-config.h"
#include "Subsystems/lift.h"


//rw pid loop
int error = 0, target = 0;
void runPIDlift(void* x){
    while(true){
        double pos = lift4b.get_position(); //param is index default is 0
		pid.setTarget(target);
        double output = pid.update(pos); // upd with error
        lift(output);
        pros::delay(25); 
    }
}


void initialize(){

	runPreAutonomous();
pros::Task liftPid(runPIDlift,(void*)0);}

void disabled(){}

void competition_initialize(){}

void autonomous() {runAutonomous();}

void opcontrol() {runDriver();}




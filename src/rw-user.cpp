#include "rw-config.h"
#include "Subsystems/lift.h"
#include "Subsystems/claw.h"




// Modify autonomous, driver, or pre-auton code below. src/main.cpp calls these.

void runAutonomous() {
  // Runs the routine picked on the Brain screen (or with the controller arrows while disabled).
  // Add routines to the list in runPreAutonomous() below.
  runSelectedAuton();
}

// Controller sticks read -127 to 127; RW's driver functions take -100 to 100
double stick(pros::controller_analog_e_t axis) {
  return controller_1.get_analog(axis) * 100.0 / 127.0;
}

void runDriver() {
  stopChassis(pros::MotorBrake::coast);
  heading_correction = false;

  
	bool previn = false;
	bool prevout = false;

  while (true) {

    driverArcade(stick(pros::E_CONTROLLER_ANALOG_LEFT_Y), stick(pros::E_CONTROLLER_ANALOG_RIGHT_X)); //split arcade
    // Tune feel with driver_curve and driver_deadband in src/rw-config.cpp

    // Example mechanism: R1 runs the intake, R2 runs it backward
    // if (controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    //   intake_motor.move_voltage(12000);
    // } else if (controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    //   intake_motor.move_voltage(-12000);
    // } else {
    //   intake_motor.brake();
    // }

    bool up = controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool down = controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    bool in = controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool out = controller_1.get_digital(pros::E_CONTROLLER_DIGITAL_L2);


    if(up){
			target += 100;
      pros::delay(50);
		}

		if(down){
			target -= 100;
			pros::delay(50);
		}

    if(in) {
      previn = !previn;
      prevout = false;
      pros::delay(250);
    }
    if(previn){
      clawMove(75);
    } else if(!prevout && !previn) {
      clawMove(0);
    }

    if(out) {
      prevout = !prevout;
      previn = false;
      pros::delay(250);
    }
    if(prevout){
      clawMove(-100);
    } else if(!prevout && !previn){
      clawMove(0);
    }


    pros::delay(25);
  }
}

void runPreAutonomous() {
  // Calibrate the inertial sensor and wait for it (about 2 seconds)
  inertial_sensor.reset(true);

  // X-drive or mecanum: useHolonomicDrive(left_front, right_front, left_back, right_back);
  // H-drive: useHDrive(strafe_motor);   (see the docs: Guide > Drive Types)

  // odom tracking (picks the setup from using_horizontal_tracker / using_vertical_tracker)
  startOdometry();

  // Optional: MCL uses the distance sensors to keep odometry from drifting while driving.
  // Needs field-centered coordinates, so start each auton with setPose() at the real field position.
  // startMcl();

  // Autonomous routines for the selector, in the order they appear on the Brain screen
  addAuton("Tuning Test", exampleAuton);
  addAuton("Odom Test", exampleAuton2);
  addAuton("Async Example", asyncExample);
  addAuton("Path Example", pathExample);
  addAuton("Profiled Example", profiledExample);
  addAuton("Drive Calibration", calibrateDrive);  // For the simulator (see the docs: Simulator > Calibrating)
  startAutonSelector();
}



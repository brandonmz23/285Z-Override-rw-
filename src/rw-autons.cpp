#include "rw-config.h"
#include "main.h"
#include "Subsystems/claw.h"
#include "Subsystems/toggle.h"
#include <chrono>
#include <thread>

// IMPORTANT: Remember to add respective function declarations to include/rw-config.h
// Then add each routine to the auton selector with addAuton() in runPreAutonomous() (src/rw-user.cpp)
// Format: returnType functionName() { code }

void exampleAuton() {
  // Use this for tuning linear and turn pid
  driveTo(60, 3000);
  turnToAngle(90, 2000);
  turnToAngle(135, 2000);
  turnToAngle(150, 2000);
  turnToAngle(160, 2000);
  turnToAngle(165, 2000);
  turnToAngle(0, 2000);
  driveTo(-60, 3000);
}

void exampleAuton2() {
  moveToPoint(24, 24, 1, 2000, false);
  moveToPoint(48, 48, 1, 2000, true);
  moveToPoint(24, 24, -1, 2000, true);
  moveToPoint(0, 0, 1, 2000, true);
  correct_angle = 0;
  driveTo(24, 2000, false, 8);
  turnToAngle(90, 800, false);
  turnToAngle(180, 800, true);
}

/*
 * asyncExample
 * Shows background motions: start a move, run the intake while it drives, and stop it early with a sensor.
 */
void asyncExample() {
//   setPose(0, 0, 0);

//   // Start driving in the background, then start the intake 12 inches into the move
//   runAsync([]{ moveToPoint(0, 48, 1, 3000); });
//   waitUntilTraveled(12);
//   intake_motor.move_voltage(12000);

//   // Stop the move early once the intake sensor sees an object
//   while (isMotionRunning() && intake_distance.get() >= 50) {
//     pros::delay(5);
//   }
//   cancelMotion();
//   waitForMotion();
//   intake_motor.brake();

//   // Turn around and drive back
//   runAsync([]{
//     turnToAngle(180, 1500);
//     moveToPoint(0, 0, 1, 3000);
//   });
//   waitForMotion();

    //measureDriveFeedforward();
   // measureImuScale(10);

  //turnToAngle(90,1000);

  //  setPose(-62,-7,90);
  // moveToPoint(-48,-7,1,1000);

  setPose(-62,5,90);
  toggle(127);
  pros::delay(500);
  clawMove(127);
  moveToPoint(-48,5,1,1000);
  toggle(0);
  turnToAngle(180,1500,true);
  target = 600;
  pros::delay(500);
  moveToPoint(-48,-18,1,1000,true);

  target = 0;
  pros::delay(700);
  clawMove(-127);
  pros::delay(500);
  clawMove(0);
  //resetPositionBack(); // reset y using the back distance sensor may not work
  moveToPoint(-48,-12,-1,1000,true);

  // turnToPoint(-24,-24, 1,1000);
  turnToAngle(125,1000);
  driveProfiled(18,1000);
  
  
  clawMove(127);
  driveProfiled(10,1000,true, 4 ); //driveProfiled(5,1000,1,true, 4 ); alt
  target = 800;
  pros::delay(500);
  moveToPoint(-24,-24, 1,1000);
  // turnToPoint(-47,-24, 1,1000);
  turnToAngle(0,1000,3);
  moveToPoint(-42,-24, 1,1000);
  pros::delay(200);
  target = 300;
  pros::delay(300);
  clawMove(-127);
  pros::delay(300);
  moveToPoint(-24,-24, -1,1000);
  target = 0;
  turnToPoint(-44,-44, 1,1000);
  clawMove(127);
  moveToPoint(-44,-44, 1,1000);
  driveProfiled(8,1000,true, 4 ); //driveProfiled(5,1000,1,true, 4 ); alt //10
  turnToPoint(-47,-24, 1,1000);
  target = 1300;
  moveToPoint(-47,-32, 1,1000);
  pros::delay(300);
  target = 1000;
  clawMove(-127);
  moveToPoint(-47,-58, -1,1000);
  turnToAngle(0,1000);
  moveToPoint(-60,-58, 1,1000);







  

  
  // moveToPoint(-24,-24, -1,1000, true);
  // turnToPoint(-46,-46, 1,1000);
  // moveToPoint(-42,-42, 1,1000);

}


void UTright(){
  setPose(0,0,90);
  clawMove(100);
  moveToPoint(10,0,1,1000, true, 12);
  pros::delay(500);
  target = 1500;
  pros::delay(500);
  target = -50;
  pros::delay(500);
  moveToPoint(-1,0,-1,1000,true, 12);
  moveToPoint(10,0,1,1000,true, 12);
  moveToPoint(-1,0,-1,1000,true, 12);
  setPose(0,0,90);
  clawMove(100);
  target = 600;
  moveToPoint(14,0,1,1000,true, 10);
  turnToAngle(180,500,true, 8);
  moveToPoint(14,-28,1,500,false, 6);
  pros::delay(650);
  moveToPoint(14,-25,-1, 1000, true,8);
  target = 0;
  pros::delay(600);
  clawMove(-127);
  pros::delay(700);
  moveToPoint(14,-12,-1,1000,true, 6);


  //turnToPoint(32,-32, 1, 1000); // angle it to 45
  turnToAngle(120,5000);
  clawMove(127);
  //driveProfiled(25,1000, true, 12);
  moveToPoint(32,-32, 1, 550,10); 
  driveProfiled(10,1500, true, 6);
  pros::delay(500);
  // target = 800; 
  // pros::delay(500);
  // //driveProfiled(3,200, true, 10);
  // turnToAngle(0,500,true, 6);
  // // driveProfiled(16, 1000, true, 12);
  // setPose(0,0,270);
  // moveToPoint(-16,-2, 1, 1000,10); 
  // pros::delay(150);
  // target = 300;
  // pros::delay(300);
  // clawMove(-127);
  // pros::delay(300);
  // driveProfiled(-5, 5000);

  // setPose(0,0,180);
  // target = 0;
  // turnToAngle(90,100);
  // pros::delay(300);

  // moveToPoint(0,0, 1, 550,12); 
  // moveToPoint(6,0, 1, 550,12); 
  // moveToPoint(-999,0, 1, 550,12); 
  // moveToPoint(6,0, 1, 550,12); 

  
  




 

}



void UTskills(){
  setPose(0,0,90);
  clawMove(120);
  moveToPoint(10,0,1,1000, true, 12);
  // pros::delay(500);
  // target = 800;
  // pros::delay(500);
  // target= 400;
  for(int x = 1800; x > 0; x-=10){
    target = x; 
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  pros::delay(500);
  target = -50;
  pros::delay(500);
  moveToPoint(-1,0,-1,1000,true, 12);
  moveToPoint(10,0,1,1000,true, 12);
  moveToPoint(-1,0,-1,1000,true, 12);
  setPose(0,0,90);
  clawMove(100);
  target = 400;
  moveToPoint(14,0,1,1000,true, 10);
  turnToAngle(180,500,true, 8);
  moveToPoint(14,-30,1,1000,true, 6);
  pros::delay(300);
  setPose(14,-28,180);
  pros::delay(650);
  moveToPoint(14,-27,-1, 1000, true,8);
  clawMove(75);
  target = 80;
  pros::delay(600);
  clawMove(-127);
  pros::delay(700); 
  moveToPoint(14,-12,-1,1000,true, 6);
  turnToAngle(120,5000);
  clawMove(127);
  moveToPoint(32,-32, 1, 550,10); 
  driveProfiled(10,1500, true, 6);
  pros::delay(500); 
  driveProfiled(10,500, true, 12);

  //extend from auto
  turnToAngle(270,1000,true, 8);
  pros::delay(500); 
  setPose(0,0,270);
  target = 800; 
  pros::delay(300);
  moveToPoint(-20,0, 1, 800,true, 8); 
  pros::delay(300);
  target = 300;
  pros::delay(300);
  clawMove(-127);
  pros::delay(2000);
  driveProfiled(-30,2000, true, 12);
  turnToAngle(0,1000,true, 8);
  driveProfiled(30,2000, true, 12);



  // setPose(0,0,270);
  // moveToPoint(12,0, 1, 800,true, 8); 
  // turnToAngle(120,5000);


}

/*
 * pathExample
 * Drives a smooth S-curve with pure pursuit, then backs along it with RAMSETE.
 * Paths use field coordinates, so the auton starts with setPose().
 */
void pathExample() {
  // setPose(-36, -60, 0);
  // Path out = pathFromPoints({{-36, -60}, {-36, -32}, {-12, -22}, {12, -30}, {34, -24}});
  // followPath(out, 5000);
  // Path back = pathFromPoints({{34, -24}, {12, -30}, {-12, -22}, {-36, -32}, {-36, -52}});
  // followPathRamsete(back, 5000, true);

  setPose(0,0,90);
  // clawMove(100);
  moveToPoint(12,0,1,1000, true, 12);
  pros::delay(1500);
  target = 2000;
  pros::delay(1500);
  target = 0;
  pros::delay(500);
  moveToPoint(-3,0,-1,1000,true, 12);
  moveToPoint(12,0,1,1000,true, 12);
  moveToPoint(-3,0,-1,1000,true, 12);

}

/*
 * profiledExample
 * Straight drives and turns with motion profiles: they speed up and slow down smoothly.
 */
void profiledExample() {
  driveProfiled(36, 3000);
  turnProfiled(90, 2000);
  driveProfiled(24, 3000);
  turnProfiled(0, 2000);
  driveProfiled(-36, 3000);
}

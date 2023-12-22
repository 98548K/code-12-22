/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FR                   motor         19              
// BR                   motor         13              
// FL                   motor         8               
// BL                   motor         16              
// Inertial_sensor      inertial      2               
// example_motor        motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

/*our autonomous*/

void Drive(double dist, double speed) {
  FR.setVelocity(speed, pct);
  FL.setVelocity(speed, pct);
  BR.setVelocity(speed, pct);
  BL.setVelocity(speed, pct);
  
  FR.spinFor(fwd, dist, turns, false);
  FL.spinFor(fwd, dist, turns, false);
  BR.spinFor(fwd, dist, turns, false);
  BL.spinFor(fwd, dist, turns);
}
void back(double dist, double speed) {
  FR.setVelocity(speed, pct);
  FL.setVelocity(speed, pct);
  BR.setVelocity(speed, pct);
  BL.setVelocity(speed, pct);
  
  FR.spinFor(reverse, dist, turns, false);
  FL.spinFor(reverse, dist, turns, false);
  BR.spinFor(reverse, dist, turns, false);
  BL.spinFor(reverse, dist, turns);
}
void autonomous(void) {

  Drive(5, 25);
  wait(20, msec);
  FR.spinFor(fwd, 5, turns, false);
  BR.spinFor(fwd, 5, turns, false);
  FL.spinFor(reverse, 5, turns, false);
  BL.spinFor(reverse, 5, turns);
  wait(20, msec);
  back(5,25);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol() {

  double avg_strafe = 0;
  double right = 0;
  double left = 0;

  FR.spin(fwd);
  FL.spin(fwd);
  BR.spin(fwd);
  BL.spin(fwd);

  while (1) {

    //Get values from controller

    right = Controller1.Axis2.value();
    left = Controller1.Axis3.value();

    avg_strafe = (Controller1.Axis4.value() + Controller1.Axis1.value()) / 2.0;

    FR.setVelocity(right - avg_strafe, pct);
    FL.setVelocity(left + avg_strafe, pct);
    BR.setVelocity(right + avg_strafe, pct);
    BL.setVelocity(left - avg_strafe, pct);

    wait(20, msec);

  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

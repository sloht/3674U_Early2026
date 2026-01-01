/**
 * @file auton_selector_examples.cpp
 * @brief Example implementations of autonomous routines for the selector
 * 
 * This file demonstrates how to create different autonomous routines
 * and register them with the autonomous selector.
 */

#include "main.h"
#include "globals.hpp"

// Example 1: Simple Blue Alliance Routine
void auton_blue_simple() {
    // Move forward
    chassis.moveToPose(24, 0, 0, 2000);
    
    // Turn and move to goal
    chassis.turnToHeading(90, 1000);
    chassis.moveToPose(24, 24, 90, 2000);
}

// Example 2: Blue Alliance with Intake
void auton_blue_with_intake() {
    // Move and intake
    intake.move(127);
    chassis.moveToPose(36, 0, 0, 3000);
    
    // Stop intake and move to goal
    intake.move(0);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPose(36, 36, 90, 2000);
}

// Example 3: Red Alliance Routine
void auton_red_simple() {
    // Move forward (mirrored)
    chassis.moveToPose(24, 0, 0, 2000);
    
    // Turn opposite direction
    chassis.turnToHeading(270, 1000);
    chassis.moveToPose(24, -24, 270, 2000);
}

// Example 4: Red Alliance with Outtake
void auton_red_with_outtake() {
    // Approach goal
    chassis.moveToPose(24, 0, 0, 2000);
    
    // Outtake
    outtake.move(127);
    pros::delay(500);
    outtake.move(0);
    
    // Back away
    chassis.moveToPose(12, 0, 180, 1500);
}

// Example 5: Skills Routine (no goal dependency)
void auton_skills() {
    // Move forward
    chassis.moveToPose(48, 0, 0, 3000);
    chassis.waitUntilDone();
    
    // Turn around
    chassis.turnToHeading(180, 1500);
    chassis.waitUntilDone();
    
    // Move back
    chassis.moveToPose(0, 0, 180, 3000);
    chassis.waitUntilDone();
}

// Example 6: Path-following Routine
void auton_path_follow() {
    // This would use a pre-defined path
    // chassis.follow(example_path, 15, 4000, false);
    
    // Alternative: Simple square movement
    for (int i = 0; i < 4; i++) {
        chassis.moveToPose(24, 0, i * 90, 2000);
        chassis.turnToHeading((i + 1) * 90, 1000);
    }
}

// Example 7: Aggressive Tuning Routine
void auton_aggressive_tuning() {
    // Fast movement with aggressive motors
    chassis.moveToPose(48, 0, 0, 1500, {.maxSpeed = 127});
    chassis.turnToHeading(90, 800, {.maxSpeed = 120});
    chassis.moveToPose(48, 36, 90, 1500, {.maxSpeed = 127});
}

// Example 8: Defensive/Safe Routine  
void auton_safe_tuning() {
    // Slower, more controlled movement
    chassis.moveToPose(24, 0, 0, 3000, {.maxSpeed = 80});
    chassis.turnToHeading(90, 1500, {.maxSpeed = 60});
    chassis.moveToPose(24, 24, 90, 3000, {.maxSpeed = 80});
}

// Example 9: No-Movement Routine (for testing)
void auton_do_nothing() {
    // Useful for field testing when you don't want the robot to move
    pros::delay(15000); // Just wait for the match to end
}

// Example 10: Mixed Strategy Routine
void auton_mixed_strategy() {
    // Try blue side first
    auton_blue_simple();
    pros::delay(500);
    
    // Then move to scoring position
    chassis.moveToPose(0, 0, 0, 2000);
}

/*
 * INTEGRATION EXAMPLE
 * 
 * In your initialize() function:
 * 
 *   void initialize() {
 *       pros::lcd::initialize();
 *       chassis.calibrate();
 *       
 *       lemlib::AutonSelector::initialize();
 *       
 *       // Add all available routines
 *       lemlib::AutonSelector::addRoutine("Blue Safe", auton_blue_simple);
 *       lemlib::AutonSelector::addRoutine("Blue Intake", auton_blue_with_intake);
 *       lemlib::AutonSelector::addRoutine("Red Safe", auton_red_simple);
 *       lemlib::AutonSelector::addRoutine("Red Outtake", auton_red_with_outtake);
 *       lemlib::AutonSelector::addRoutine("Skills", auton_skills);
 *       lemlib::AutonSelector::addRoutine("Path Follow", auton_path_follow);
 *       lemlib::AutonSelector::addRoutine("Aggressive", auton_aggressive_tuning);
 *       lemlib::AutonSelector::addRoutine("Safe", auton_safe_tuning);
 *       lemlib::AutonSelector::addRoutine("Nothing", auton_do_nothing);
 *   }
 * 
 * In your autonomous() function:
 * 
 *   void autonomous() {
 *       auto selectedRoutine = lemlib::AutonSelector::getSelectedRoutine();
 *       selectedRoutine();
 *   }
 */

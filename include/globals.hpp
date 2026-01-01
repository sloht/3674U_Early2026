#pragma once

#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"

extern pros::Controller controller;

extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

extern pros::Imu imu;

extern pros::Rotation horizontalEnc;
extern pros::Rotation verticalEnc;
extern lemlib::TrackingWheel horizontal;
extern lemlib::TrackingWheel vertical;

extern pros::MotorGroup intake;
extern pros::Motor outtake;
extern pros::adi::Pneumatics MatchLoad1;
extern pros::adi::Pneumatics MatchLoad2;
extern pros::adi::Pneumatics Wing;

extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::OdomSensors sensors;
extern lemlib::ExpoDriveCurve throttleCurve;
extern lemlib::ExpoDriveCurve steerCurve;
extern lemlib::Chassis chassis;

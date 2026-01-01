#include "globals.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({8, 10, 14}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({-1, -2, -3}, pros::MotorGearset::blue);

// Inertial Sensor
pros::Imu imu(9);

// tracking wheels
pros::Rotation horizontalEnc(15);
pros::Rotation verticalEnc(5);
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -5.75);
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, -2.5);

pros::MotorGroup intake({12, -13}, pros::MotorGearset::green);
pros::Motor outtake(11, pros::MotorGearset::green);
pros::adi::Pneumatics MatchLoad1('A', false);
pros::adi::Pneumatics MatchLoad2('B', false);
pros::adi::Pneumatics Wing('C', false);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors,
                              &rightMotors,
                              12,
                              lemlib::Omniwheel::NEW_325,
                              450,
                              2);

// lateral motion controller
lemlib::ControllerSettings linearController(10,
                                            0,
                                            3,
                                            3,
                                            1,
                                            100,
                                            3,
                                            500,
                                            20);

// angular motion controller
lemlib::ControllerSettings angularController(2,
                                             0,
                                             10,
                                             3,
                                             1,
                                             100,
                                             3,
                                             500,
                                             0);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, nullptr, &horizontal, nullptr, &imu);

// input curves
lemlib::ExpoDriveCurve throttleCurve(3, 10, 1.019);
lemlib::ExpoDriveCurve steerCurve(3, 10, 1.019);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

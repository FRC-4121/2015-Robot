#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	RobotDrive *robotDrive;
	Talon *frontLeftMotor, *frontRightMotor, *rearLeftMotor, *rearRightMotor;
	Joystick *stickL, *stickR;
	Gyro *rioGyro;


public:
	Chassis();
	void InitDefaultCommand();
	void autoDriveSystem(float, float);
	void driveWithJoystick(Joystick *stickL, Joystick *stickR);
	void StopEverything();
};

#endif

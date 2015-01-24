#ifndef Chassis_H
#define Chassis_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Chassis: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *frontLeftTalon, *frontRightTalon, *rearLeftTalon, *rearRightTalon;
	RobotDrive *robotDrive;
//	Gyro *gyro;
	Accelerometer *accel;

	int chassisDriveStyle;

public:
	Chassis();
	void InitDefaultCommand();
	void DriveWithJoystick(Joystick *stickL, Joystick *stickR);
	void DriveForwardAutonomous();
	void DriveBackwardAutonomous();
	void SlideLeftAutonomous();
	void SlideRightAutonomous();
	void DriveAutonomous(float x, float y, float r);
	void StopAutonomous();
	void CycleDrive();
};

#endif

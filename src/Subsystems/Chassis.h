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
	Talon *frontLeftTalon, *frontRightTalon, *rearLeftTalon, *rearRightTalon;

public:
	Chassis();
	void InitDefaultCommand();
	void DriveWithJoystick(Joystick *stickL, Joystick *stickR);
};

#endif

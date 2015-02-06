#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driveStickR, *driveStickL;
	Gyro *gyro;
public:
	OI();
	//Sensors
	Gyro* getGyro();
	//Right JoyStick
	Joystick* getDriveStickR();
	JoystickButton *toggleButton; // Button 1 is the trigger for toggling the drive state
	JoystickButton *lifterSolenoidLower, *lifterSolenoidRaise;
	JoystickButton *gripperSolenoidExtend, *gripperSolenoidRetract;
	JoystickButton *stopEverything;

	//Left Joystick
	Joystick* getDriveStickL();
};

#endif

#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driveStickR, *driveStickL, *controlXBox;

public:
	OI();
	//Right JoyStick
	Joystick* getDriveStickR();
	JoystickButton *toggleButton; // Button 1 is the trigger for toggling the drive state

	//Left Joystick
	Joystick* getDriveStickL();



	//X Box
	Joystick* getControlXBox();
};

#endif

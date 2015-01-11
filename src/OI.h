#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driveStickR, *driveStickL;

public:
	OI();
	//Right JoyStick
	Joystick* getDriveStickR();
	//Left Joystick
	Joystick* getDriveStickL();
};

#endif

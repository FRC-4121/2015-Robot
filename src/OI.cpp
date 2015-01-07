#include "OI.h"
#include "Robotmap.h"

OI::OI()
{
	// Process operator interface input here.

	//Right Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);

	//Left Joystick
	driveStickR = new Joystick(JOYSTICKRIGHT);
}

Joystick* OI::getDriveStickL() {
	return driveStickR;
}

Joystick* OI::getDriveStickR() {
	return driveStickL;
}

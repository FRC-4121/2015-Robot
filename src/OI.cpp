#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	//Right Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);
	toggleButton = new JoystickButton(driveStickL, TRIGGER_fTOGGLE);

	//Left Joystick
	driveStickR = new Joystick(JOYSTICKRIGHT);


}

Joystick* OI::getDriveStickL() {
	return driveStickR;
}

Joystick* OI::getDriveStickR() {
	return driveStickL;
}

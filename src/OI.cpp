#include <Commands/cmdToggleDriveStyle.h>
#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	//Left Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);
	//creates toggle drive button on left joystick
	toggleButton = new JoystickButton(driveStickL, TRIGGER_fTOGGLE);
	// when this button is pressed the data is sent to the toggle Drive command where it will be used accordingly
	toggleButton->WhenPressed(new cmdToggleDriveStyle());




	//Right Joystick
	driveStickR = new Joystick(JOYSTICKRIGHT);



}

//will return the location of the data of the user input at the left joystick
Joystick* OI::getDriveStickL() {
	return driveStickL;
}

//will return the location of the data of the user input at the left joystick
Joystick* OI::getDriveStickR() {
	return driveStickR;
}

#include <Commands/cmdToggleDriveStyle.h>
#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.

	//	Sensors
	//creates a new instance of Gyro
	gyro = new Gyro(0);


	//Encoder
	frontLeftEncoder = new Encoder(0,1,true);
	frontLeftEncoder->SetDistancePerPulse(0.075);
	frontRightEncoder= new Encoder(2,3,true);
	frontRightEncoder->SetDistancePerPulse(0.075);
	backRightEncoder= new Encoder(4,5,true);
	backRightEncoder->SetDistancePerPulse(0.075);
	backLeftEncoder= new Encoder(6,7,true);
	backLeftEncoder->SetDistancePerPulse(0.075);


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
Gyro* OI::getGyro()
{
	return gyro;
}


Encoder* OI::getFrontLeftEncoder()
{
	return frontLeftEncoder;
}
Encoder* OI::getFrontRightEncoder()
{
	return frontRightEncoder;
}
Encoder* OI::getBackLeftEncoder()
{
	return backLeftEncoder;
}
Encoder* OI::getBackRightEncoder()
{
	return backRightEncoder;
}


Joystick* OI::getDriveStickL()
{
	return driveStickL;
}

//will return the location of the data of the user input at the left joystick
Joystick* OI::getDriveStickR()
{
	return driveStickR;
}

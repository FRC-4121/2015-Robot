#include <Commands/cmdToggleDriveStyle.h>
#include <Commands/ExtendGripperCommand.h>
#include <Commands/RetractGripperCommand.h>
#include <Commands/ExtendLoaderCommand.h>
#include <Commands/RetractLoaderCommand.h>
#include <Commands/LowerToteCommand.h>
#include <Commands/cmdStopPneumatics.h>
#include <Commands/cmdResetGyro.h>
#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.

	//	Sensors
	//creates a new instance of Gyro
	gyro = new Gyro(0);


	//Encoder
	frontLeftEncoder = new Encoder(2,3,true);
	frontLeftEncoder->SetDistancePerPulse(0.075);
	frontRightEncoder= new Encoder(0,1,true);
	frontRightEncoder->SetDistancePerPulse(0.075);
	backRightEncoder= new Encoder(4,5,true);
	backRightEncoder->SetDistancePerPulse(0.075);
	backLeftEncoder= new Encoder(6,7,true);
	backLeftEncoder->SetDistancePerPulse(0.075);


	//Left Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);
	//creates toggle drive button on left joystick
	toggleButton = new JoystickButton(driveStickL, L_TRIGGER);
	// when this button is pressed the data is sent to the toggle Drive command where it will be used accordingly
	toggleButton->WhenPressed(new cmdToggleDriveStyle());

	//Stop Everything
		stopPneumatics = new JoystickButton (driveStickL, L_LEFT_SIDE_DOWN_fSTOP_PNEUMATICS);
		stopPneumatics->WhenPressed(new cmdStopPneumatics());

	//toteLifterSolenoid
		lifterSolenoidLower = new JoystickButton(driveStickL, L_THUMB_BUTTON_DOWN_fLOWER_LIFTER);
		lifterSolenoidLower->WhenPressed(new cmdExtendLoaderCommand);
		lifterSolenoidRaise = new JoystickButton(driveStickL, L_THUMB_BUTTON_UP_fRAISE_LIFTER);
		lifterSolenoidRaise->WhenPressed(new cmdRetractLoaderCommand());

	//toteGripperSolenoid
		gripperSolenoidExtend = new JoystickButton(driveStickL, L_THUMB_BUTTON_RIGHT_fEXTEND_GRIPPER);
		gripperSolenoidExtend->WhenPressed(new cmdExtendGripperCommand());
		gripperSolenoidRetract = new JoystickButton(driveStickL, L_THUMB_BUTTON_LEFT_fRETRACT_GRIPPER);
		gripperSolenoidRetract->WhenPressed(new cmdRetractGripperCommand());


//Right Joystick
	driveStickR = new Joystick(JOYSTICKRIGHT);

	//Reset Gyro
	gyroReset= new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fGYRO_RESET);
	gyroReset->WhenPressed(new cmdResetGyro());

	//Lower Tote (Lowers Lifter and Extends Gripper via Limit Switch)
	toteLower = new JoystickButton(driveStickR, R_THUMB_BUTTON_DOWN_fLOWER_TOTE);
	toteLower->WhenPressed(new cmdLowerToteCommand(3));


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

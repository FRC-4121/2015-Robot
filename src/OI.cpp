#include <Commands/cmdToggleDriveStyle.h>
#include <Commands/cmdTogglePolar.h>
#include <Commands/ExtendGripperCommand.h>
#include <Commands/RetractGripperCommand.h>
#include <Commands/ExtendLoaderCommand.h>
#include <Commands/RetractLoaderCommand.h>
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

//XBOX Controller
	xboxController= new Joystick(XBOXCONTROLLER);
	xbox_toggleMechanumButton = new JoystickButton(xboxController, XBOX_LSTICKPRESS_fTOGGLE_MECHANUM);
	xbox_toggleMechanumButton->WhenPressed(new cmdToggleDriveStyle());
	xbox_lifterSolenoidLower = new JoystickButton(xboxController, XBOX_A_fLOWER_LIFTER);
	xbox_lifterSolenoidLower->WhenPressed(new cmdExtendLoaderCommand);
	xbox_lifterSolenoidRaise = new JoystickButton(xboxController, XBOX_Y_fRAISE_LIFTER);
	xbox_lifterSolenoidRaise->WhenPressed(new cmdRetractLoaderCommand());
	xbox_gripperSolenoidExtend = new JoystickButton(xboxController, XBOX_B_fEXTEND_GRIPPER);
	xbox_gripperSolenoidExtend->WhenPressed(new cmdExtendGripperCommand());
	xbox_gripperSolenoidRetract = new JoystickButton(xboxController, XBOX_X_fRETRACT_GRIPPER);
	xbox_gripperSolenoidRetract->WhenPressed(new cmdRetractGripperCommand());
	xbox_gyroReset= new JoystickButton(xboxController, XBOX_RSTICKPRESS_fRESET_GYRO);
	xbox_gyroReset->WhenPressed(new cmdResetGyro());




//Left Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);
	//creates toggle drive button on left joystick
	toggleMechanumButton = new JoystickButton(driveStickL, L_LEFT_SIDE_UP_fTOGGLE_MECHANUM);
	// when this button is pressed the data is sent to the toggle Drive command where it will be used accordingly
	toggleMechanumButton->WhenPressed(new cmdToggleDriveStyle());

	togglePolarButton = new JoystickButton(driveStickL, L_LEFT_SIDE_DOWN_fTOGGLE_POLAR);
	togglePolarButton->WhenPressed(new cmdTogglePolar());

	//Stop Everything
		stopPneumatics = new JoystickButton (driveStickL, L_RIGHT_SIDE_UP_fSTOP_PNEUMATICS);
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
	gyroReset= new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fRESET_GYRO);
	gyroReset->WhenPressed(new cmdResetGyro());

	//Load Totes (Feeder)
	feederForward= newJoystickButton(driveStickR, R_THUMB_BUTTON_RIGHT_fFORWARD_FEEDER);
	feederForward->WhenPressed(new ActivateLoader());
	feederReverse= newJoystickButton(driveStickR, R_THUMB_BUTTON_LEFT_fREVERSE_FEEDER);
	feederReverse->WhenPressed(new DeactivateLoader());




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

Joystick* OI::getControllerXbox()
{
	return xboxController;
}

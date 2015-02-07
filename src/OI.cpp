#include <Commands/cmdToggleDriveStyle.h>
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
	gyro->InitGyro();
	gyro->SetSensitivity(.0125);
	gyro->Reset(); // Resets the gyro's heading


//Left Joystick
	driveStickL = new Joystick(JOYSTICKLEFT);

	//Toggle Drive Style
		//creates toggle drive button on left joystick
		toggleButton = new JoystickButton(driveStickL, L_LEFT_SIDE_UP_fTOGGLE);
		// when this button is pressed the data is sent to the toggle Drive command where it will be used accordingly
		toggleButton->WhenPressed(new cmdToggleDriveStyle());

	//Stop Everything
		stopPneumatics = new JoystickButton (driveStickL, L_LEFT_SIDE_DOWN_fSTOP_PNEUMATICS);
		stopPneumatics->WhenPressed(new cmdStopPneumatics());

	//toteLifterSolenoid
		lifterSolenoidLower = new JoystickButton(driveStickL, L_THUMB_BUTTON_DOWN_fLOWER_LIFTER);
		lifterSolenoidLower->WhenPressed(new cmdExtendLoaderCommand(2));
		lifterSolenoidRaise = new JoystickButton(driveStickL, L_THUMB_BUTTON_UP_fRAISE_LIFTER);
		lifterSolenoidRaise->WhenPressed(new cmdRetractLoaderCommand());

	//toteGripperSolenoid
		gripperSolenoidExtend = new JoystickButton(driveStickL, L_THUMB_BUTTON_RIGHT_fEXTEND_GRIPPER);
		gripperSolenoidExtend->WhenPressed(new cmdExtendGripperCommand());
		gripperSolenoidRetract = new JoystickButton(driveStickL, L_THUMB_BUTTON_LEFT_fRETRACT_GRIPPER);
		gripperSolenoidRetract->WhenPressed(new cmdRetractGripperCommand());


//Right Joystick
	driveStickR = new Joystick(JOYSTICKRIGHT);
	gyroReset= new JoystickButton(driveStickR, R_LEFT_SIDE_UP_fGYRO_RESET);
	gyroReset->WhenPressed(new cmdResetGyro());


}

//will return the location of the data of the user input at the left joystick
Gyro* OI::getGyro()
{
	return gyro;
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

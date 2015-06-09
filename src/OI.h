#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *driveStickR, *driveStickL,*xboxController;;
	Gyro *gyro;
public:
	OI();
	//Sensors
	Gyro* getGyro();
	Encoder *frontLeftEncoder, *frontRightEncoder, *backLeftEncoder,*backRightEncoder, *getFrontLeftEncoder(), *getFrontRightEncoder(), *getBackLeftEncoder(), *getBackRightEncoder();


	//Right JoyStick
	Joystick* getDriveStickR();
	JoystickButton *toggleMechanumButton, *xbox_toggleMechanumButton; // Button 1 is the trigger for toggling the drive state
	JoystickButton *togglePolarButton;
	JoystickButton *lifterSolenoidLower, *lifterSolenoidRaise, *xbox_lifterSolenoidLower, *xbox_lifterSolenoidRaise;
	JoystickButton *gripperSolenoidExtend, *gripperSolenoidRetract, *xbox_gripperSolenoidExtend, *xbox_gripperSolenoidRetract;
	JoystickButton *stopPneumatics;
	JoystickButton *gyroReset, *xbox_gyroReset;
	JoystickButton *feederForward, *feederReverse;
//	JoystickButton *toteLower;

	//Left Joystick
	Joystick* getDriveStickL();

	//XBOX Controller
	Joystick* getControllerXbox();
};

#endif

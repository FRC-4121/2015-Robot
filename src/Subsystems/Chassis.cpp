#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoystick.h"

Chassis::Chassis() : Subsystem("Chassis")
{
	//This is the Chassis Constructor.
		robotDrive = new RobotDrive(frontLeftMotor, rearLeftMotor, frontRightMotor, rearRightMotor);

		frontLeftMotor = new Talon(DRIVEMOTORFRONTLEFT);
		frontRightMotor = new Talon(DRIVEMOTORFRONTRIGHT);
		rearLeftMotor = new Talon(DRIVEMOTORREARLEFT);
		rearRightMotor = new Talon(DRIVEMOTORREARRIGHT);

#warning need to add GRyo
		rioGyro = NULL;

}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new cmdDriveWithJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::driveWithJoystick(Joystick *stickL, Joystick *stickR) {
	//Purpose:
		//Using the driver station joysticks to drive the robot.
	//Inputs:   Are Instances of the Joystick class.

	//true precision drive
	//false standard drive

#warning need to add GRyo
	robotDrive->MecanumDrive_Cartesian(stickR->GetX(), stickR->GetY(), stickL->GetX());//, rioGyro->Gyro());
}

void Chassis::autoDriveSystem(float left, float right) {
	// Purpose:
		//To drive the Robot in autounomous mode.
	//Inputs: left,right - takes a floating point value from -1 to 1, with 1 indicating full speed and .5 half speed.
	robotDrive->TankDrive(left, right);
}

void Chassis::StopEverything(){
	frontLeftMotor->Set(0);
	frontRightMotor->Set(0);
	rearLeftMotor->Set(0);
	rearRightMotor->Set(0);
}

#include "Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "../Commands/DriveWithJoysticks.h"

Chassis::Chassis() : Subsystem("Chassis"){
	frontLeftTalon = new Talon(FRONT_LEFT_TALON);
	frontRightTalon = new Talon(FRONT_RIGHT_TALON);
	rearLeftTalon = new Talon(REAR_LEFT_TALON);
	rearRightTalon = new Talon(REAR_RIGHT_TALON);
	robotDrive = new RobotDrive(frontLeftTalon, frontRightTalon, rearLeftTalon, rearRightTalon);
	gyro = new Gyro(1); // Adds the gyro


	TankDriveState = true;

	gyro->SetSensitivity(.007);
	gyro->Reset(); // Resets the gyro's heading

	accel = new BuiltInAccelerometer();
}

void Chassis::InitDefaultCommand(){

	SetDefaultCommand(new DriveWithJoysticks());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::DriveWithJoystick(Joystick *stickL, Joystick *stickR) {
	//Purpose:
	//Using the driver station joysticks to drive the robot.
	//Inputs:   Are Instances of the Joystick class.

	//true precision drive
	//false standard drive
	if (TankDriveState)
	{
		robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyro->GetAngle());
	}
	else
	{
		robotDrive->TankDrive(stickL, stickR, FALSE);
	}
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
}
void Chassis::ToggleDrive()
{
       TankDriveState=!TankDriveState;
}
void Chassis::DriveForwardAutonomous()
{
	robotDrive->MecanumDrive_Cartesian(0, .5, 0, gyro->GetAngle());
}
void Chassis::DriveBackwardAutonomous()
{
	robotDrive->MecanumDrive_Cartesian(0, -.5, 0, gyro->GetAngle());
}
void Chassis::SlideLeftAutonomous()
{
	robotDrive->MecanumDrive_Cartesian(-.5, 0, 0, gyro->GetAngle());
}
void Chassis::SlideRightAutonomous()
{
	robotDrive->MecanumDrive_Cartesian(.5, 0, 0, gyro->GetAngle());
}


void Chassis::StopAutonomous()
{
	robotDrive->MecanumDrive_Cartesian(0, 0, 0, gyro->GetAngle());
}


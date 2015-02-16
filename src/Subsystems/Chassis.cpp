#include "../CommandBase.h"
#include <Commands/cmdDriveWithJoysticks.h>
#include "Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "OI.h"

Chassis::Chassis() : Subsystem("Chassis")
{

	//creating four new instances of motor controllers that dictate the four mecanum wheels
	frontLeftTalon = new Talon(FRONT_LEFT_TALON);
	frontRightTalon = new Talon(FRONT_RIGHT_TALON);
	rearLeftTalon = new Talon(REAR_LEFT_TALON);
	rearRightTalon = new Talon(REAR_RIGHT_TALON);

	//Robot drive based on a definition of the motor configuration of each motor controller for the wheels
	robotDrive = new RobotDrive(frontLeftTalon, rearLeftTalon, frontRightTalon, rearRightTalon);

	//start off in tank drive
	mecanumDriveState = true;
	polarDriveState=false;
	gyroAngle= CommandBase::oi->getGyro()->GetAngle();

	//creates a new instance of Accelerometer
	accel = new BuiltInAccelerometer();

	robotDrive->SetSafetyEnabled(false);
	robotDrive->SetMaxOutput(.7);
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new cmdDriveWithJoysticks());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::DriveWithJoystick(Joystick *stickL, Joystick *stickR)
{
	//Purpose:
	//Using the driver station joysticks to drive the robot.
	//Inputs:   Are Instances of the Joystick class.

	//if the robot is currently in tank drive this will change the style to mecanum relying on x and y

	if(polarDriveState)
	{
		gyroAngle=0;
	}
	else
	{
		gyroAngle= CommandBase::oi->getGyro()->GetAngle();
	}

	if (mecanumDriveState)
	{
		robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyroAngle);
		//the start to the speed control loop kind of
		/*
		if(stickR->GetX()!=oi->getFrontLeftEncoder()->GetRate())
		{

		}
		if(stickR->GetY()!=(oi->getFrontLeftEncoder()->GetRate()/ //tangent of the roller angle))
		{

		}
		 */
	}

	//else if the robot is currently in mecanum relying on x and y drive this will change the style to tank
	else
	{
		//Left stick is reversed because of the motor directions needed to make mecanum work properly.
		robotDrive->TankDrive(-(stickL->GetY()), (stickR->GetY()),false);//stickR, stickL, true)
	}
	//mecanum drive based on angles
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());





}
void Chassis::ToggleDrive()
{
	//makes the boolean the opposite of what it previously was
	//ex: if TankDriveState is true, this line of code will make it !(not) true so false
	mecanumDriveState=!mecanumDriveState;
}
void Chassis::TogglePolar()
{
	polarDriveState=!polarDriveState;
}


void Chassis::AutoDrive(float x, float y, float z)
{
	robotDrive->MecanumDrive_Cartesian(x, y, z, CommandBase::oi->getGyro()->GetAngle());
}
/*
void Chassis::DriveForwardAutonomous()
{
	//drives the robot forward at half speed
	robotDrive->MecanumDrive_Cartesian(0, .5, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::DriveBackwardAutonomous()
{
	//drives the robot backward at half speed
	robotDrive->MecanumDrive_Cartesian(0, -.5, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::SlideLeftAutonomous()
{
	//slides the robot left at half speed
	robotDrive->MecanumDrive_Cartesian(-.5, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}
void Chassis::SlideRightAutonomous()
{
	//slides the robot right at half speed
	robotDrive->MecanumDrive_Cartesian(.5, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}

 */
void Chassis::StopAutonomous()
{
	//stops the motion of the robot
	robotDrive->MecanumDrive_Cartesian(0, 0, 0, CommandBase::oi->getGyro()->GetAngle());
}
bool Chassis::GetDriveState()
{
	return mecanumDriveState;
}


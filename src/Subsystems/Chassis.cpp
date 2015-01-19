#include "Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "../Commands/DriveWithJoysticks.h"

Chassis::Chassis() : Subsystem("Chassis")
{

	//creating four new instances of motor controllers that dictate the four mecanum wheels
	frontLeftTalon = new Talon(FRONT_LEFT_TALON);
	frontRightTalon = new Talon(FRONT_RIGHT_TALON);
	rearLeftTalon = new Talon(REAR_LEFT_TALON);
	rearRightTalon = new Talon(REAR_RIGHT_TALON);

	//Robot drive based on a definition of the motor configuration of each motor controller for the wheels
	robotDrive = new RobotDrive(frontLeftTalon, frontRightTalon, rearLeftTalon, rearRightTalon);

	//creates a new instance of Gyro
	gyro = new Gyro(1);

    //start off in tank drive
	TankDriveState = true;

	gyro->SetSensitivity(.007);
	gyro->Reset(); // Resets the gyro's heading

	//creates a new instance of Accelerometer
	accel = new BuiltInAccelerometer();
}

void Chassis::InitDefaultCommand()
{

	SetDefaultCommand(new DriveWithJoysticks());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::DriveWithJoystick(Joystick *stickL, Joystick *stickR)
{
	//Purpose:
	//Using the driver station joysticks to drive the robot.
	//Inputs:   Are Instances of the Joystick class.

	//if the robot is currently in tank drive this will change the style to mecanum relying on x and y
	if (TankDriveState)
	{
		robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyro->GetAngle());
	}
	//else if the robot is currently in mecanum relying on x and y drive this will change the style to tank
	{
		robotDrive->TankDrive(stickL, stickR, FALSE);
	}
	//mecanum drive based on angles
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
}
void Chassis::ToggleDrive()
{
		//makes the boolean the opposite of what it previously was
		//ex: if TankDriveState is true, this line of code will make it !(not) true so false
       TankDriveState=!TankDriveState;
}
void Chassis::DriveForwardAutonomous()
{
	//drives the robot forward at half speed
	robotDrive->MecanumDrive_Cartesian(0, .5, 0, gyro->GetAngle());
}
void Chassis::DriveBackwardAutonomous()
{
	//drives the robot backward at half speed
	robotDrive->MecanumDrive_Cartesian(0, -.5, 0, gyro->GetAngle());
}
void Chassis::SlideLeftAutonomous()
{
	//slides the robot left at half speed
	robotDrive->MecanumDrive_Cartesian(-.5, 0, 0, gyro->GetAngle());
}
void Chassis::SlideRightAutonomous()
{
	//slides the robot right at half spped
	robotDrive->MecanumDrive_Cartesian(.5, 0, 0, gyro->GetAngle());
}


void Chassis::StopAutonomous()
{
	//stops the motion of the robot
	robotDrive->MecanumDrive_Cartesian(0, 0, 0, gyro->GetAngle());
}


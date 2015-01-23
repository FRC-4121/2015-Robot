#include <Commands/cmdDriveWithJoysticks.h>
#include "Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#inlcude "../OI.h"

Chassis::Chassis() : Subsystem("Chassis")
{

	//creating four new instances of motor controllers that dictate the four mecanum wheels
	frontLeftTalon = new Talon(FRONT_LEFT_TALON);
	frontRightTalon = new Talon(FRONT_RIGHT_TALON);
	rearLeftTalon = new Talon(REAR_LEFT_TALON);
	rearRightTalon = new Talon(REAR_RIGHT_TALON);

	//Robot drive based on a definition of the motor configuration of each motor controller for the wheels
	robotDrive = new RobotDrive(frontLeftTalon, rearLeftTalon, frontRightTalon, rearRightTalon);

	//creates a new instance of Gyro
//	gyro = new Gyro(CHASSIS_GYRO_AN_0);

	//start off in mecanum drive
	chassisDriveStyle = MECANUM_DRIVE;

//	gyro->SetSensitivity(.007);
//	gyro->Reset(); // Resets the gyro's heading

	//creates a new instance of Accelerometer
	accel = new BuiltInAccelerometer();
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
	SmartDashboard::PutNumber("chassisGyro Angle:", (double) CommandBase::chassisGyro->GetAngle());
	SmartDashboard::PutNumber("chassisGyro Rate:", (double) CommandBase::chassisGyro->GetRate());

	switch(chassisDriveStyle)
	{
		case MECANUM_DRIVE:
			robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), CommandBase::chassisGyro->GetAngle());//gyro->GetAngle());
			break;
		case TANK_DRIVE:
			robotDrive->TankDrive(stickL, stickR, true);
			break;
		case ARCADE_DRIVE:
			robotDrive->ArcadeDrive(stickR, true);
			break;
		default:
			SmartDashboard::PutString("chassisDriveStyle:", "INVALID_DRIVE_STATE");
			robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), CommandBase::chassisGyro->GetAngle());//gyro->GetAngle());
			break;
	}
	//mecanum drive based on angles
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
}
void Chassis::CycleDrive()
{
	//makes the boolean the opposite of what it previously was
	//ex: if TankDriveState is true, this line of code will make it !(not) true so false
	chassisDriveStyle++;

	if(INVALID_DRIVE_STYLE <= chassisDriveStyle)
	{
		chassisDriveStyle = MECANUM_DRIVE;
	}

	SmartDashboard::PutNumber("TankDriveState:", chassisDriveStyle);
}
void Chassis::DriveForwardAutonomous()
{
	//drives the robot forward at half speed
	robotDrive->MecanumDrive_Cartesian(0, .5, 0, CommandBase::chassisGyro->GetAngle());
}
void Chassis::DriveBackwardAutonomous()
{
	//drives the robot backward at half speed
	robotDrive->MecanumDrive_Cartesian(0, -.5, 0, CommandBase::chassisGyro->GetAngle());
}
void Chassis::SlideLeftAutonomous()
{
	//slides the robot left at half speed
	robotDrive->MecanumDrive_Cartesian(-.5, 0, 0, CommandBase::chassisGyro->GetAngle());
}
void Chassis::SlideRightAutonomous()
{
	//slides the robot right at half speed
	robotDrive->MecanumDrive_Cartesian(.5, 0, 0, CommandBase::chassisGyro->GetAngle());
}


void Chassis::StopAutonomous()
{
	//stops the motion of the robot
	robotDrive->MecanumDrive_Cartesian(0, 0, 0, CommandBase::chassisGyro->GetAngle());
}


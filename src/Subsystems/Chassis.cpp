#include "Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "../Commands/DriveWithJoysticks.h"
#include "../Commands/toggleDriveStyleCommand.h"

Chassis::Chassis() :
		Subsystem("Chassis")
{
	frontLeftTalon = new Talon(FRONT_LEFT_TALON);
	frontRightTalon = new Talon(FRONT_RIGHT_TALON);
	rearLeftTalon = new Talon(REAR_LEFT_TALON);
	rearRightTalon = new Talon(REAR_RIGHT_TALON);


	robotDrive = new RobotDrive(frontLeftTalon, frontRightTalon, rearLeftTalon, rearRightTalon);
<<<<<<< HEAD
	gyro = new Gyro(1);


=======
	gyro = new Gyro(1); // Adds the gyro
>>>>>>> parent of cf5d25c... Update Chassis.cpp
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	gyro->SetSensitivity(.007);


	gyro->Reset();
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
<<<<<<< HEAD

	if(toggleDriveStyleCommand::DriveStyle = "Cartesian"){
		robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyro->GetAngle());
	} else if(toggleDriveStyleCommand::DriveStyle = "Tank") {
		// Tank Drive
	}
//	robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
=======
	robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyro->GetAngle());
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
>>>>>>> parent of cf5d25c... Update Chassis.cpp
}

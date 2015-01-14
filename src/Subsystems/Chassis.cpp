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
}

void Chassis::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	gyro->SetSensitivity(.007);
	gyro->Reset(); // Resets the gyro's heading
	Accelerometer *accel;
	accel = new BuiltInAccelerometer(Accelerometer::kRange_4G);
	SmartDashboard::PutNumber("Heading - Gyro", gyro->GetAngle()); // Pushes the gyro angle to the smartdashboard
	SmartDashboard::PutNumber("Accelerometer - X axis", accel->GetX()); //
	SmartDashboard::PutNumber("Accelerometer - Y axis", accel->GetY()); // Sends internal acceleratomer levels to the smartdashboard
	SmartDashboard::PutNumber("Accelerometer - Z axis", accel->GetZ()); //
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
	robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), gyro->GetAngle());
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
}

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
	accel = BuiltInAccelerometer(Accelerometer:kRange_4G); // Creates the internal accelerometer class
	static const float kP = 0.03;
	// driveStyle = "";
}

void Chassis::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

	gyro->SetSensitivity(.007);
	gyro->Reset(); // Resets the gyro's heading
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
	robotDrive->MecanumDrive_Cartesian(stickR->GetX(),stickR->GetY(), stickL->GetX(), ( kP * gyro->GetAngle());
	//robotDrive->MecanumDrive_Polar(stickR->GetMagnitude(), stickR->GetDirectionDegrees(), stickL->GetMagnitude());
	SmartDashboard.putNumber("Heading - Gyro", gyro->GetAngle()); // Pushes the gyro angle to the smartdashboard
	SmartDashboard.putNumber("Accelerometer - X axis", accel->getX()); //
	SmartDashboard.putNumber("Accelerometer - Y axis", accel->getY()); // Sends internal acceleratomer levels to the smartdashboard
	Smartdashboard.putNumber("Accelerometer - Z axis", accel->getZ()); //
}

#include "ToggleDrive.h"

cmdToggleDrive::cmdToggleDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(Chassis);
	Requires(Chassis);
}

// Called just before this Command runs the first time
void cmdToggleDrive::Initialize() {	
}

// Called repeatedly when this Command is scheduled to run
void cmdToggleDrive::Execute() {
	Chassis->ToggleDrive();//driveWithJoystick(oi->getDriveStickL(), oi->getDriveStickR());
	Chassis->driveWithJoystick(oi->getDriveStickL(), oi->getDriveStickR());
}

// Make this return true when this Command no longer needs to run execute()
bool cmdToggleDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cmdToggleDrive::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdToggleDrive::Interrupted() {
}

#include <Commands/DriveWithJoystick.h>

cmdDriveWithJoystick::cmdDriveWithJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(chassis);
}

// Called just before this Command runs the first time
void cmdDriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdDriveWithJoystick::Execute()
{

	chassis->driveWithJoystick(oi->getDriveStickL(), oi->getDriveStickR());
}

// Make this return true when this Command no longer needs to run execute()
bool cmdDriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void cmdDriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdDriveWithJoystick::Interrupted()
{

}

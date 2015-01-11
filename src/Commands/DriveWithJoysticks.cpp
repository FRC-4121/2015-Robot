#include "DriveWithJoysticks.h"
//rstywhymnrsdtjurtsymurnjswhna
DriveWithJoysticks::DriveWithJoysticks()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute()
{
	chassis->DriveWithJoystick(oi->getDriveStickL(), oi->getDriveStickR());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoysticks::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted()
{

}

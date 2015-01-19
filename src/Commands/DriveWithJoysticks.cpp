#include "DriveWithJoysticks.h"
//rstywhymnrsdtjurtsymurnjswhna
DriveWithJoysticks::DriveWithJoysticks()
{
	// Requires the subsystem chassis
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute()
{
	//points to chassis' function that will use the positions of each joystick to either drive tank or mecanum style
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

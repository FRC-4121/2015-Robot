#include <Commands/cmdDriveWithJoysticks.h>
//rstywhymnrsdtjurtsymurnjswhna
cmdDriveWithJoysticks::cmdDriveWithJoysticks()
{
	// Requires the subsystem chassis
	Requires(mecanumChassis);
}

// Called just before this Command runs the first time
void cmdDriveWithJoysticks::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdDriveWithJoysticks::Execute()
{
	//points to chassis' function that will use the positions of each joystick to either drive tank or mecanum style
	mecanumChassis->DriveWithJoystick(oi->getDriveStickL(), oi->getDriveStickR());
}

// Make this return true when this Command no longer needs to run execute()
bool cmdDriveWithJoysticks::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void cmdDriveWithJoysticks::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdDriveWithJoysticks::Interrupted()
{

}

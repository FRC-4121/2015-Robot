#include "AutoForward.h"

AutoForward::AutoForward()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumChassis);

}

// Called just before this Command runs the first time
void AutoForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoForward::Execute()
{
	mecanumChassis->AutoDrive(0, -0.5, 0);//tells chassis to go forward at half speed
}

// Make this return true when this Command no longer needs to run execute()
bool AutoForward::IsFinished()
{
	bool retVal= false;
	if(132<=oi->getFrontLeftEncoder()->GetDistance())//drives 9'6" at the moment since pulse proportion is done in inches
	{
		retVal=true;
	}
	else
	{
		retVal=false;
	}
	return retVal;
}

// Called once after isFinished returns true
void AutoForward::End()
{

	mecanumChassis->StopAutonomous();//stop all auto movement forward
	oi->getFrontLeftEncoder()->Reset(); //reset the distance measured by encoder to zero

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForward::Interrupted()
{

}

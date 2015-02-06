#include "AutoBackward.h"

AutoBackward::AutoBackward()
{

	Requires(mecanumChassis);

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoBackward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoBackward::Execute()
{
	mecanumChassis->AutoDrive(0, -.5, 0);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoBackward::IsFinished()
{
	bool retVal= false;
	if(48<=oi->getFrontLeftEncoder()->GetDistance())//drives four feet at the moment since pulse proportion is done in inches
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
void AutoBackward::End()
{
	mecanumChassis->StopAutonomous();//stop all auto movement forward
	oi->getFrontLeftEncoder()->Reset();//reset the distance measured by encoder to zero
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBackward::Interrupted()
{

}

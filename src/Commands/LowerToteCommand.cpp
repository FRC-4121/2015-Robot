#include "LowerToteCommand.h"
#include "../Subsystems/Lifter.h"

cmdLowerToteCommand::cmdLowerToteCommand(double timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SetTimeout (timeout);
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void cmdLowerToteCommand::Initialize()
{
	printf("Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void cmdLowerToteCommand::Execute()
{
	toteLifter->LowerLifter();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdLowerToteCommand::IsFinished()
{
	return toteLifter->ReadDropToteReedSwitch();
}

bool cmdLowerToteCommand::IsTimedOut(){
	return true;
}


// Called once after isFinished returns true
void cmdLowerToteCommand::End()
{
	toteLifter->ExtendGripper();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdLowerToteCommand::Interrupted()
{
	printf("Interrupted\n");
}

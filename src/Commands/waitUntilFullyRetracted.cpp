#include "waitUntilFullyRetracted.h"
#include "../Robotmap.h"

waitUntilFullyRetracted::waitUntilFullyRetracted()
{
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void waitUntilFullyRetracted::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void waitUntilFullyRetracted::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool waitUntilFullyRetracted::IsFinished()
{
	return toteLifter->ReadFullyRetractedSwitch();
}

// Called once after isFinished returns true
void waitUntilFullyRetracted::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void waitUntilFullyRetracted::Interrupted()
{

}

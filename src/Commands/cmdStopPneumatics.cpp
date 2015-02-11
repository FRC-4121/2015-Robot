#include "cmdStopPneumatics.h"
#include "../Subsystems/Lifter.h"

cmdStopPneumatics::cmdStopPneumatics()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void cmdStopPneumatics::Initialize()
{
	printf("Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void cmdStopPneumatics::Execute()
{
	toteLifter->StopLifter();
	toteLifter->StopGripper();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdStopPneumatics::IsFinished()
{
	printf("IsFinished\n");
			return true;
}

// Called once after isFinished returns true
void cmdStopPneumatics::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdStopPneumatics::Interrupted()
{
	printf("Interrupted\n");
}

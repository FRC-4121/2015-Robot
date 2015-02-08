#include "ExtendGripperCommand.h"
#include "../Subsystems/Lifter.h"


cmdExtendGripperCommand::cmdExtendGripperCommand()
{
	// Use requires() here to declare subsystem dependencies
		Requires(toteLifter);
}

// Called just before this Command runs the first time
void cmdExtendGripperCommand::Initialize()
{
	printf("Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void cmdExtendGripperCommand::Execute()
{
	toteLifter->ExtendGripper();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdExtendGripperCommand::IsFinished()
{
	printf("IsFinished\n");
	return true;
}

// Called once after isFinished returns true
void cmdExtendGripperCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdExtendGripperCommand::Interrupted()
{
	printf("Interrupted\n");
}

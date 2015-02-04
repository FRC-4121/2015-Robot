#include "RetractGripperCommand.h"
#include "../Subsystems/Lifter.h"
#include "../CommandBase.h"

cmdRetractGripperCommand::cmdRetractGripperCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void cmdRetractGripperCommand::Initialize()
{
	printf("Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void cmdRetractGripperCommand::Execute()
{
	toteLifter->RetractGripper();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdRetractGripperCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdRetractGripperCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdRetractGripperCommand::Interrupted()
{

}

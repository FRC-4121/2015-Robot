#include "RetractLoaderCommand.h"
#include "../Subsystems/Lifter.h"
#include "../CommandBase.h"

cmdRetractLoaderCommand::cmdRetractLoaderCommand() {
	// Use requires() here to declare subsystem dependencies
	//requires(examplesubsystem)
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void cmdRetractLoaderCommand::Initialize() {
	printf("Initialize\n");
	//SetTimeout(5);
	//loaderRelay->On();
}

// Called repeatedly when this Command is scheduled to run
void cmdRetractLoaderCommand::Execute() {

	toteLifter->RaiseLifter();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdRetractLoaderCommand::IsFinished() {
	return TRUE;
}

// Called once after isFinished returns true
void cmdRetractLoaderCommand::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdRetractLoaderCommand::Interrupted() {
}

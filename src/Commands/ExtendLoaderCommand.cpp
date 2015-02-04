#include "ExtendLoaderCommand.h"
#include "../Subsystems/Lifter.h"

cmdExtendLoaderCommand::cmdExtendLoaderCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(toteLifter);
}

// Called just before this Command runs the first time
void cmdExtendLoaderCommand::Initialize() {
	printf("Initialize\n");
}

// Called repeatedly when this Command is scheduled to run
void cmdExtendLoaderCommand::Execute() {

	toteLifter->LowerLifter();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdExtendLoaderCommand::IsFinished() {
	printf("IsFinished\n");
	return true;//loaderSubsystem->ReadLoaderExtendLimitSwitch();//IsTimedOut();
}

// Called once after isFinished returns true
void cmdExtendLoaderCommand::End() {
	
	//loaderSubsystem->StopLoader();
//	extendRelay->Off();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdExtendLoaderCommand::Interrupted() {
	printf("Interrupted\n");
//	extendRelay->Off();
}

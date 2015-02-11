#include "ExtendLoaderCommand.h"
#include "../Subsystems/Lifter.h"

<<<<<<< HEAD
cmdExtendLoaderCommand::cmdExtendLoaderCommand() {
=======
cmdExtendLoaderCommand::cmdExtendLoaderCommand(){
>>>>>>> origin/encoder
	// Use requires() here to declare subsystem dependencies
	Requires(toteLifter);
}

<<<<<<< HEAD
// Called just before this Command runs the first time
void cmdExtendLoaderCommand::Initialize() {
	printf("Initialize\n");
=======

// Called just before this Command runs the first time
void cmdExtendLoaderCommand::Initialize() {
	printf("Initialize\n");
	SetTimeout (2);
>>>>>>> origin/encoder
}

// Called repeatedly when this Command is scheduled to run
void cmdExtendLoaderCommand::Execute() {

	toteLifter->LowerLifter();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdExtendLoaderCommand::IsFinished() {
	printf("IsFinished\n");
<<<<<<< HEAD
	return true;//loaderSubsystem->ReadLoaderExtendLimitSwitch();//IsTimedOut();
=======
	return true;//
>>>>>>> origin/encoder
}

// Called once after isFinished returns true
void cmdExtendLoaderCommand::End() {
<<<<<<< HEAD
	
	//loaderSubsystem->StopLoader();
//	extendRelay->Off();
=======

>>>>>>> origin/encoder
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdExtendLoaderCommand::Interrupted() {
	printf("Interrupted\n");
//	extendRelay->Off();
}

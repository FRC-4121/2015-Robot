#include "DeactivateLoader.h"

cmdDeactivateLoader::cmdDeactivateLoader() {
	// Use requires() here to declare subsystem dependencies
	//requires(examplesubsystem)
}

// Called just before this Command runs the first time
void cmdDeactivateLoader::Initialize() {
	printf("Initialize\n");
	
}

// Called repeatedly when this Command is scheduled to run
void cmdDeactivateLoader::Execute() {
	loaderSubsystem->StopEverything();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdDeactivateLoader::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void cmdDeactivateLoader::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdDeactivateLoader::Interrupted() {
}




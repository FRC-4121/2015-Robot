#include "ActivateLoader.h"

cmdActivateLoader::cmdActivateLoader() {
	// Use requires() here to declare subsystem dependencies
	Requires(loaderSubsystem);
}

// Called just before this Command runs the first time
void cmdActivateLoader::Initialize() {
	
	
}

// Called repeatedly when this Command is scheduled to run
void cmdActivateLoader::Execute() {
	loaderSubsystem->RunLoader();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdActivateLoader::IsFinished() {
	//printf("IsFinished\n");
	return TRUE;
}

// Called once after isFinished returns true
void cmdActivateLoader::End() {
	printf("End\n");
	//winchSubsystem->Release();
	//loaderSubsystem->StopEverything();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdActivateLoader::Interrupted() {
	printf("Interrupted\n");
	//loaderSubsystem->StopEverything();
}




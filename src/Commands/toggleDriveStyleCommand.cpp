#include "toggleDriveStyleCommand.h"

toggleDriveStyleCommand::toggleDriveStyleCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void toggleDriveStyleCommand::Initialize(){
	double n = 0;
	char DriveStyle = "";
}

// Called repeatedly when this Command is scheduled to run
void toggleDriveStyleCommand::Execute(){
	if(n == 0){
		DriveStyle = "Tank";
		n + 1;
		return;
	} else if (n == 1) {
		DriveStyle = "Cartesian";
		n = 0;
		return;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool toggleDriveStyleCommand::IsFinished()
{
	return DriveStyle;
}

// Called once after isFinished returns true
void toggleDriveStyleCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void toggleDriveStyleCommand::Interrupted()
{

}

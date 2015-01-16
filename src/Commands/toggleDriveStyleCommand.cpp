#include "toggleDriveStyleCommand.h"
#include "..\Subsystems\Chassis.h"


	ToggleDrive::ToggleDrive()
	{
	// Use requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
		Requires(chassis);
	}


	// Called just before this Command runs the first time
	void ToggleDrive::Initialize()
	{

	}


	// Called repeatedly when this Command is scheduled to run
	void ToggleDrive::Execute()
	{
		chassis->ToggleDrive();
	}


	// Make this return true when this Command no longer needs to run execute()
	bool ToggleDrive::IsFinished() {
	return false;
	}


	// Called once after isFinished returns true
	void ToggleDrive::End() {
	}


	// Called when another command which requires one or more of the same
	// subsystems is scheduled to run
	void ToggleDrive::Interrupted() {
	}

#include "toggleDriveStyleCommand.h"
#include "..\Subsystems\Chassis.h"


	ToggleDrive::ToggleDrive()
	{

		//requires the subsystem chassis'
		Requires(chassis);
	}


	// Called just before this Command runs the first time
	void ToggleDrive::Initialize()
	{

	}


	// Called repeatedly when this Command is scheduled to run
	void ToggleDrive::Execute()
	{
		//points to chassis' function to switch the drive style from mecanum to tank or vice versa
		chassis->ToggleDrive();
	}


	// Make this return true when this Command no longer needs to run execute()
	bool ToggleDrive::IsFinished() {
	return true;
	}


	// Called once after isFinished returns true
	void ToggleDrive::End() {
	}


	// Called when another command which requires one or more of the same
	// subsystems is scheduled to run
	void ToggleDrive::Interrupted() {
	}

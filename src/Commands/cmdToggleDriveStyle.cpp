#include <Commands/cmdToggleDriveStyle.h>
#include "..\Subsystems\Chassis.h"


	cmdToggleDriveStyle::cmdToggleDriveStyle()
	{

		//requires the subsystem chassis'
		Requires(mecanumChassis);
	}


	// Called just before this Command runs the first time
	void cmdToggleDriveStyle::Initialize()
	{

	}


	// Called repeatedly when this Command is scheduled to run
	void cmdToggleDriveStyle::Execute()
	{
		//points to chassis' function to switch the drive style from mecanum to tank or vice versa
		mecanumChassis->CycleDrive();
	}


	// Make this return true when this Command no longer needs to run execute()
	bool cmdToggleDriveStyle::IsFinished() {
	return true;
	}


	// Called once after isFinished returns true
	void cmdToggleDriveStyle::End() {
	}


	// Called when another command which requires one or more of the same
	// subsystems is scheduled to run
	void cmdToggleDriveStyle::Interrupted() {
	}

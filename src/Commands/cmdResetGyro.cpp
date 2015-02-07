#include <Commands/cmdResetGyro.h>
#include "CommandBase.h"


cmdResetGyro::cmdResetGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void cmdResetGyro::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdResetGyro::Execute()
{
	CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading
}

// Make this return true when this Command no longer needs to run execute()
bool cmdResetGyro::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdResetGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdResetGyro::Interrupted()
{

}

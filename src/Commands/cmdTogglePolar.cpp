#include "cmdTogglePolar.h"
#include "..\Subsystems\Chassis.h"

cmdTogglePolar::cmdTogglePolar()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(mecanumChassis);
}

// Called just before this Command runs the first time
void cmdTogglePolar::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdTogglePolar::Execute()
{
	mecanumChassis->TogglePolar();
}

// Make this return true when this Command no longer needs to run execute()
bool cmdTogglePolar::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdTogglePolar::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdTogglePolar::Interrupted()
{

}

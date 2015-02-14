#include "cmdToggleAirTanks.h"
#include "../Subsystems/ReservoirChange.h"

cmdToggleAirTanks::cmdToggleAirTanks()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(reservoirChanger);
}

// Called just before this Command runs the first time
void cmdToggleAirTanks::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdToggleAirTanks::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool cmdToggleAirTanks::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void cmdToggleAirTanks::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdToggleAirTanks::Interrupted()
{

}

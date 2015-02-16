#include "cmdToggleReservoir.h"
#include "../Subsystems/ReservoirChange.h"

cmdToggleReservoir::cmdToggleReservoir()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(reservoirChanger);
}

// Called just before this Command runs the first time
void cmdToggleReservoir::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdToggleReservoir::Execute()
{
	if(reservoirChanger->GetReservoirSolenoidState==-1)
	{
		reservoirChanger->UseSecondReservoir();
	}
	else
	{
		reservoirChanger->UseFirstReservoir();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool cmdToggleReservoir::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdToggleReservoir::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdToggleReservoir::Interrupted()
{

}

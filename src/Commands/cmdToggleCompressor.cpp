#include "cmdToggleCompressor.h"
#include "../Subsystems/ReservoirChange.h"

cmdToggleCompressor::cmdToggleCompressor()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(reservoirChanger);
}

// Called just before this Command runs the first time
void cmdToggleCompressor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void cmdToggleCompressor::Execute()
{
	if(reservoirChanger->GetCompressorSolenoidState==-1)
		{
			reservoirChanger->FillSecondReservoir();
		}
		else
		{
			reservoirChanger->FillFirstReservoir();
		}
}

// Make this return true when this Command no longer needs to run execute()
bool cmdToggleCompressor::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void cmdToggleCompressor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdToggleCompressor::Interrupted()
{

}

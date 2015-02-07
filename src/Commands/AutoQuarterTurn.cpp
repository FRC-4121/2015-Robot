#include "AutoQuarterTurn.h"

AutoQuarterTurn::AutoQuarterTurn()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumChassis);

}

// Called just before this Command runs the first time
void AutoQuarterTurn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoQuarterTurn::Execute()
{
	//clockwise turn
	do
	{
		mecanumChassis->AutoDrive(0,0,1);

	}while(CommandBase::oi->getGyro()->GetAngle()<90);



	//counterclockwise code
	/*
	 * do
	{
		mecanumChassis->AutoDrive(0,0,-1);

	}while(gyro->GetAngle()<270);
	 */

	CommandBase::oi->getGyro()->Reset();//reset heading to zero so that it can drive forward normally

}

// Make this return true when this Command no longer needs to run execute()
bool AutoQuarterTurn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoQuarterTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoQuarterTurn::Interrupted()
{

}

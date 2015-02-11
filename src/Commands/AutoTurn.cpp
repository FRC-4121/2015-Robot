#include "AutoTurn.h"

AutoTurn::AutoTurn(float x, float y, float z, float angle)
{
	xaxis=x;
	yaxis=y;
	zaxis=z;
	stopAngle=angle;
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumChassis);

}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
	//clockwise turn

	mecanumChassis->AutoDrive(xaxis,yaxis,zaxis);



	//counterclockwise code
	/*
	 * 		mecanumChassis->AutoDrive(0,0,.5);
		*/


}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{

	if(CommandBase::oi->getGyro()->GetAngle()<stopAngle)
	{
		return false;
	}
	else
	{
		return true;
	}

	/*
	 * //counterclockwise code
	*
	 * if(gyro->GetAngle()<270)
	 * {
	 * return true;
	 * }
	 * else
	 * 	{
	 * 			return false;
	 * 				}
	 */

}

// Called once after isFinished returns true
void AutoTurn::End()
{
	CommandBase::oi->getGyro()->Reset();//reset heading to zero so that it can drive forward normally

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{

}

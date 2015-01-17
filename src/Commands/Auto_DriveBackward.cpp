#include "Auto_DriveBackward.h"

Auto_DriveBackward::Auto_DriveBackward()
{

	timer= new Timer ();


	timerStarted = false;

	Requires(chassis);

}

// Called just before this Command runs the first time
void Auto_DriveBackward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto_DriveBackward::Execute()
{
	if (false == timerStarted)
		{
			timer->Start();
			timerStarted = true;
		}

		chassis->DriveBackwardAutonomous();


}

// Make this return true when this Command no longer needs to run execute()
bool Auto_DriveBackward::IsFinished()
{
	if(timer->Get()==10)
		{
		return true;
		}
	else
		return false;
}

// Called once after isFinished returns true
void Auto_DriveBackward::End()
{
	timerStarted = false;
		timer->Stop();
		timer->Reset();
		chassis->StopAutonomous();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_DriveBackward::Interrupted()
{

}

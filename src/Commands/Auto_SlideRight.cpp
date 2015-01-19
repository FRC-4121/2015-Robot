#include "Auto_SlideRight.h"

Auto_SlideRight::Auto_SlideRight()
{
	timer= new Timer ();


		timerStarted = false;

		Requires(chassis);
}

// Called just before this Command runs the first time
void Auto_SlideRight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto_SlideRight::Execute()
{
	if (false == timerStarted)
		{
			timer->Start();
			timerStarted = true;
		}

		chassis->SlideRightAutonomous();


}

// Make this return true when this Command no longer needs to run execute()
bool Auto_SlideRight::IsFinished()
{
	if(timer->Get()==10)
			{
			return true;
			}
		else
			return false;
}

// Called once after isFinished returns true
void Auto_SlideRight::End()
{
	timerStarted = false;
		timer->Stop();
		timer->Reset();
		chassis->StopAutonomous();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_SlideRight::Interrupted()
{

}

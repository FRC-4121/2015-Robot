#include <Commands/Auto_SlideLeft.h>
#include "Auto_DriveForward.h"
#include "..\Subsystems\Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "../Commands/DriveWithJoysticks.h"

Auto_Forward_SlideLeft::Auto_Forward_SlideLeft()
{
	 timer= new Timer ();


		timerStarted = false;

		Requires(chassis);

}

// Called just before this Command runs the first time
void Auto_Forward_SlideLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto_Forward_SlideLeft::Execute()
{
	if (false == timerStarted)
		{
			timer->Start();
			timerStarted = true;
		}

		chassis->SlideLeftAutonomous();

}

// Make this return true when this Command no longer needs to run execute()
bool Auto_Forward_SlideLeft::IsFinished()
{
	if(timer->Get()==10)
			{
			return true;
			}
		else
			return false;

}

// Called once after isFinished returns true
void Auto_Forward_SlideLeft::End()
{
	timerStarted = false;
		timer->Stop();
		timer->Reset();
		chassis->StopAutonomous();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_Forward_SlideLeft::Interrupted()
{

}

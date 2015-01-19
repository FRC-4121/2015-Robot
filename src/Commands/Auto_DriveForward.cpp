#include "Auto_DriveForward.h"
#include "..\Subsystems\Chassis.h"
#include "../RobotMap.h"
#include "RobotDrive.h"
#include "../Commands/DriveWithJoysticks.h"



autoDriveForward::autoDriveForward()
{



    timer= new Timer ();


	timerStarted = false;

	Requires(chassis);

}

// Called just before this Command runs the first time
void autoDriveForward::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run

void autoDriveForward::Execute()
{
	if (false == timerStarted)
	{
		timer->Start();
		timerStarted = true;
	}

	chassis->DriveForwardAutonomous();

}

// Make this return true when this Command no longer needs to run execute()

bool autoDriveForward::IsFinished()
{

	if(timer->Get()==10)
		{
		return true;
		}
	else
		return false;
}

// Called once after isFinished returns true
void autoDriveForward::End()
{
	timerStarted = false;
	timer->Stop();
	timer->Reset();
	chassis->StopAutonomous();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoDriveForward::Interrupted()
{

}

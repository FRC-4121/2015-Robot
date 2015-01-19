#include "Auto_DriveBackward.h"

Auto_DriveBackward::Auto_DriveBackward()
{
	//create a new Timer with initial time zero
	timer= new Timer ();

	//Create boolean to test whether the timer has started
	timerStarted = false;

	//Needs functions in the chassis subsystem to run
	Requires(chassis);

}

// Called just before this Command runs the first time
void Auto_DriveBackward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Auto_DriveBackward::Execute()
{
	//this if check will only start the timer once during run time by setting the boolean to true
	if (false == timerStarted)
		{
			timer->Start();
			timerStarted = true;
		}
	//points to the function in chassis that drive the robot backwards at half speed
		chassis->DriveBackwardAutonomous();


}

// Make this return true when this Command no longer needs to run execute()
bool Auto_DriveBackward::IsFinished()
{
	//if check: once the timer has reached/surpassed a certain time it will move the program to the End() function
	if(3<=timer->Get())
		{
		return true;
		}
	//else it will allow the Execute() to keep running
	else
		return false;
}

// Called once after isFinished returns true
void Auto_DriveBackward::End()
{
	//stops the robot's wheels from moving
	chassis->StopAutonomous();
	//resets the timer boolean to false so it can be started next time Execute() loops
	timerStarted = false;
	//Stops the timer
	timer->Stop();
	//Resets timer to zero
	timer->Reset();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auto_DriveBackward::Interrupted()
{

}

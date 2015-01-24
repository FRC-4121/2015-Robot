#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include  "Commands/autoDriveForward.h"
#include  "Commands/autoSlideRight.h"
#include  "Commands/autoDriveBackward.h"
#include  "Commands/autoSlideLeft.h"


class Robot: public IterativeRobot
{
private:
	Command *autonomousForwardCommand, *autonomousRightCommand, *autonomousBackwardCommand, *autonomousLeftCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();

		autonomousForwardCommand = new autoDriveForward();
		autonomousRightCommand= new autoSlideRight();
		autonomousBackwardCommand= new autoDriveBackward();
		autonomousLeftCommand= new autoSlideLeft();





		lw = LiveWindow::GetInstance();
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//if (autonomousCommand != NULL)
		//	autonomousCommand->Start();
		if (autonomousForwardCommand != NULL)
		{
			autonomousForwardCommand->Start();
		}
		if (autonomousRightCommand != NULL)
		{
			autonomousRightCommand->Start();
		}
		if (autonomousBackwardCommand != NULL)
		{
			autonomousBackwardCommand->Start();
		}
		if (autonomousLeftCommand != NULL)
		{
			autonomousLeftCommand->Start();
		}


	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
//		autonomousForwardCommand->Run();
//		autonomousRightCommand->Run();
//		autonomousBackwardCommand->Run();
//		autonomousLeftCommand->Run();

	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//if (autonomousCommand != NULL)
		//autonomousCommand->Cancel();
		if (autonomousForwardCommand != NULL)
		{
			autonomousForwardCommand->Cancel();
		}
		if (autonomousRightCommand != NULL)
		{
			autonomousRightCommand->Cancel();
		}
		if (autonomousBackwardCommand != NULL)
		{
			autonomousBackwardCommand->Cancel();
		}
		if (autonomousLeftCommand != NULL)
		{
			autonomousLeftCommand->Cancel();
		}
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);


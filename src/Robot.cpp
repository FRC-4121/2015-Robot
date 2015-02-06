#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/cmdStopPneumatics.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *stopPneumaticsCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();

		stopPneumaticsCommand= new cmdStopPneumatics();

		CommandBase::oi->getGyro()->SetSensitivity(.007);//.0125);
		CommandBase::oi->getGyro()->InitGyro();
		CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		stopPneumaticsCommand->Start();
		//if (autonomousCommand != NULL)
			//autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		stopPneumaticsCommand->Start();
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
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


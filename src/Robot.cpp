#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/AutoGrabTurnRZone.h"
#include "Commands/AutoGrabTurnLZone.h"
#include "Commands/AutoGrabTrashStackTurnLZone.h"
#include "Commands/AutoGrabAllTotes.h"
#include "CommandBase.h"
#include "Commands/cmdStopPneumatics.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *stopPneumaticsCommand;
	LiveWindow *lw;
	SendableChooser *chooser;


	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();

//		stopPneumaticsCommand= new cmdStopPneumatics();

//		CommandBase::oi->getGyro()->SetSensitivity(.007);//.0125);
//		CommandBase::oi->getGyro()->InitGyro();
//		CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading


		//autonomousCommand= new AutoGrabTurnRZone();

		chooser= new SendableChooser();
		chooser->AddDefault("Grab Tote Spin Right Move to Auto Zone", new AutoGrabTurnRZone());
		chooser->AddObject("Grab Tote Spin Left Move to Auto Zone", new AutoGrabTurnLZone());
//		chooser->AddObject("Grab Trash Stack Spin Left Move to Auto Zone", new AutoGrabTrashStackTurnLZone());
//		chooser->AddObject("stack all totees", new AutoGrabAllTotes());
		SmartDashboard::PutData("Autonomous Modes", chooser);


	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{

		CommandBase::oi->getGyro()->SetSensitivity(.007);//.0125);
		CommandBase::oi->getGyro()->InitGyro();
		CommandBase::oi->getGyro()->Reset(); // Resets the gyro's heading
		autonomousCommand=(Command *)chooser-> GetSelected();

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
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


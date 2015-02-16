#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/AutoGrabTurnRZone.h"
#include "Commands/AutoGrabTurnLZone.h"
#include "Commands/AutoGrabTrashStackTurnLZone.h"
#include "CommandBase.h"
#include "Commands/cmdStopPneumatics.h"
#include "Commands/cmdToggleCompressor.h"
#include "Commands/cmdToggleReservoir.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *stopPneumaticsCommand;
	LiveWindow *lw;
	SendableChooser *autonomousChooser, *reservoirChooser;
	Compressor *mainCompressor;


	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();

		CommandBase::toteLifter->ExtendGripper();
		CommandBase::toteLifter->LowerLifter();
		CommandBase::reservoirChanger->UseFirstReservoir();
		CommandBase::reservoirChanger->FillSecondReservoir();


		//autonomousCommand= new AutoGrabTurnRZone();

		autonomousChooser= new SendableChooser();
		autonomousChooser->AddDefault("Grab Tote Spin Right Move to Auto Zone", new AutoGrabTurnRZone());
		autonomousChooser->AddObject("Grab Tote Spin Left Move to Auto Zone", new AutoGrabTurnLZone());
		autonomousChooser->AddObject("Grab Trash Stack Spin Left Move to Auto Zone", new AutoGrabTrashStackTurnLZone());
		SmartDashboard::PutData("Autonomous Modes", autonomousChooser);

		reservoirChooser= new SendableChooser();
		reservoirChooser->AddDefault("Use First Reservoir/ Fill Second Reservoir");
		reservoirChooser->AddObject("Use First Reservoir/ Fill First Reservoir", new cmdToggleCompressor);



	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{

		CommandBase::reservoirChanger->UseFirstReservoir();
		CommandBase::reservoirChanger->FillSecondReservoir();

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

		CommandBase::reservoirChanger->UseFirstReservoir();
		CommandBase::reservoirChanger->FillSecondReservoir();
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


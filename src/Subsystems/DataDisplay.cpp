#include "DataDisplay.h"
#include "../RobotMap.h"
#include "OI.h"
#include "../CommandBase.h"
#include <Commands/DataDashboardCommand.h>
#include "Subsystems/Lifter.h"

DataDisplay::DataDisplay() :
		Subsystem("DataDisplay")
{

}

void DataDisplay::InitDefaultCommand()
{

		// Set the default command for a subsystem here.
	SetDefaultCommand(new DataDashboardCommand());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void  DataDisplay::DisplayAll()
{
	if(CommandBase::toteLifter->GetGripperSolenoidState()==0)
	{
		SmartDashboard::PutString("Gripper Solenoid State", "Off");
	}
	else if(CommandBase::toteLifter->GetGripperSolenoidState()==1)
	{
		SmartDashboard::PutString("Gripper Solenoid State", "Forward");
	}
	else
	{
		SmartDashboard::PutString("Gripper Solenoid State", "Reverse");
	}


	if(CommandBase::toteLifter->GetLifterSolenoidState()==0)
	{
		SmartDashboard::PutString("Lifter Solenoid State", "Off");
	}
	else if(CommandBase::toteLifter->GetLifterSolenoidState()==1)
	{
		SmartDashboard::PutString("Lifter Solenoid State", "Forward");
	}
	else
	{
		SmartDashboard::PutString("Lifter Solenoid State", "Reverse");
	}

	SmartDashboard::PutNumber("Gyro: ", CommandBase::oi->getGyro()->GetAngle());
	SmartDashboard::PutBoolean("Mecanum Drive", CommandBase::mecanumChassis->GetDriveState());
	//SmartDashboard::PutBoolean("Solenoid Extended", CommandBase::loaderSubsystem->GetSolenoidState());
	//NEED A BOOLEAN (SolenoidState) AND BOOLEAN METHOD (GetSolenoidState()) IN THE LOADER SUBSYSTEM SO THAT WE CAN TELL WHEN THE SOLENOID IS EXTENDED OR NOT
	SmartDashboard::PutNumber("Front Left Encoder Speed:", CommandBase::oi->getFrontLeftEncoder()->GetRate());
	SmartDashboard::PutNumber("Front Right Encoder Speed:", CommandBase::oi->getFrontRightEncoder()->GetRate());
	SmartDashboard::PutNumber("Back Left Encoder Speed:", CommandBase::oi->getBackLeftEncoder()->GetRate());
	SmartDashboard::PutNumber("Back Right Encoder Speed:", CommandBase::oi->getBackRightEncoder()->GetRate());

}

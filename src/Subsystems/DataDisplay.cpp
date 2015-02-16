#include "DataDisplay.h"
#include "../RobotMap.h"
#include "OI.h"
#include "../CommandBase.h"
#include <Commands/DataDashboardCommand.h>
#include "Subsystems/Lifter.h"
#include "Subsystems/ReservoirChange.h"

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

	SmartDashboard::PutNumber("Gyro: ", CommandBase::oi->getGyro()->GetAngle());
	SmartDashboard::PutBoolean("Mecanum Drive", CommandBase::mecanumChassis->GetDriveState());
	//SmartDashboard::PutBoolean("Solenoid Extended", CommandBase::loaderSubsystem->GetSolenoidState());
	//NEED A BOOLEAN (SolenoidState) AND BOOLEAN METHOD (GetSolenoidState()) IN THE LOADER SUBSYSTEM SO THAT WE CAN TELL WHEN THE SOLENOID IS EXTENDED OR NOT
	SmartDashboard::PutNumber("Front Left Encoder Speed:", CommandBase::oi->getFrontLeftEncoder()->GetRate());
	SmartDashboard::PutNumber("Front Right Encoder Speed:", CommandBase::oi->getFrontRightEncoder()->GetRate());
	SmartDashboard::PutNumber("Back Left Encoder Speed:", CommandBase::oi->getBackLeftEncoder()->GetRate());
	SmartDashboard::PutNumber("Back Right Encoder Speed:", CommandBase::oi->getBackRightEncoder()->GetRate());
	SmartDashboard::PutNumber("Gripper Solenoid State:", CommandBase::toteLifter->GetGripperSolenoidState());
	SmartDashboard::PutNumber("Lifter Solenoid State:", CommandBase::toteLifter->GetLifterSolenoidState());
	SmartDashboard::PutNumber("Compressor Solenoid State:", CommandBase::reservoirChanger->GetCompressorSolenoidState());
	SmartDashboard::PutNumber("Reservoir Solenoid State:", CommandBase::reservoirChanger->GetReservoirSolenoidState());
}

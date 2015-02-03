#include "DataDisplay.h"
#include "../RobotMap.h"
#include "OI.h"
#include "../CommandBase.h"
#include <Commands/DataDashboardCommand.h>

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


}

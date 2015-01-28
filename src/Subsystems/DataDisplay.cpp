#include "DataDisplay.h"
#include "../RobotMap.h"
#include "OI.h"
#include "../CommandBase.h"
DataDisplay::DataDisplay() :
		Subsystem("ExampleSubsystem")
{

}

void DataDisplay::InitDefaultCommand()
{

		// Set the default command for a subsystem here.
//	SetDefaultCommand(new MySpecialCommand());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DisplayAll()
{

	SmartDashboard::PutNumber("Gyro: ", CommandBase::oi->getGyro()->GetAngle());

}

#include <Subsystems/LoaderSubsystem.h>
#include "../RobotMap.h"

LoaderSubsystem::LoaderSubsystem() : Subsystem("LoaderSubsystem") {
	//this is the constructor
	feederMotor = new Victor(FEEDERMOTOR);
}

void LoaderSubsystem::InitDefaultCommand() {

}

void LoaderSubsystem::RunLoader() {
		feederMotor->Set(-.8, 0);
}

void LoaderSubsystem::Eject(){
		feederMotor->Set(.9, 0);
}

void LoaderSubsystem::StopEverything(){
	feederMotor->Set(-0, 0);
}


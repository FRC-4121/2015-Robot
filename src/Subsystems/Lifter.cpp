#include <Subsystems/Lifter.h>
#include "../Robotmap.h"
#include "DoubleSolenoid.h"
Lifter::Lifter() : Subsystem("LoaderSubsystem") {
	//this is the constructor

	lifterSol = new DoubleSolenoid(1, 0);
	gripperSol= new DoubleSolenoid(2, 3);
	fullyRetractedSwitch= new DigitalInput(LOADER_FULLY_RETRACT_REED_SWITCH_I);


}
    
void Lifter::InitDefaultCommand() {
}

void  Lifter::RaiseLifter(){
	lifterSol->Set(lifterSol->kReverse);
	lifterSolenoidState=-1;
}

void  Lifter::LowerLifter(){
	lifterSol->Set(lifterSol->kForward);
	lifterSolenoidState=1;
}

void  Lifter::StopLifter(){
	lifterSol->Set(lifterSol->kOff);
	lifterSolenoidState=0;
}


DoubleSolenoid::Value Lifter::GetLifterPosition(){
 	return lifterSol->Get();
}


bool Lifter::GetLifterSolenoidState()
{
	return lifterSolenoidState;
}

void  Lifter::RetractGripper(){
	gripperSol->Set(gripperSol->kReverse);
	gripperSolenoidState=-1;
}

void  Lifter::ExtendGripper(){
	gripperSol->Set(gripperSol->kForward);
	gripperSolenoidState=1;
}

void  Lifter::StopGripper(){
	gripperSol->Set(gripperSol->kOff);
	gripperSolenoidState=0;
}

DoubleSolenoid::Value Lifter::GetGripperPosition(){
	return gripperSol->Get();
}

bool Lifter::GetGripperSolenoidState()
{
	return gripperSolenoidState;
}


bool Lifter::ReadFullyRetractedSwitch(){
	return fullyRetractedSwitch->Get();
}



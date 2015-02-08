#include <Subsystems/Lifter.h>
#include "../Robotmap.h"
#include "DoubleSolenoid.h"
Lifter::Lifter() : Subsystem("LoaderSubsystem") {
	//this is the constructor

	lifterSol = new DoubleSolenoid(1, 0);
	gripperSol= new DoubleSolenoid(2, 3);
	counter=0;
	dropToteReedSwitch = new DigitalInput(DROP_TOTE_REED_SWITCH_I);
}
    
void Lifter::InitDefaultCommand() {
}

void  Lifter::RaiseLifter(){
	lifterSol->Set(lifterSol->kReverse);
}

void  Lifter::LowerLifter(){
	lifterSol->Set(lifterSol->kForward);
}

void  Lifter::StopLifter(){
	lifterSol->Set(lifterSol->kOff);
}

DoubleSolenoid::Value Lifter::GetLifterPosition(){
	return lifterSol->Get();
}

void  Lifter::RetractGripper(){
	gripperSol->Set(gripperSol->kReverse);
}

void  Lifter::ExtendGripper(){
	gripperSol->Set(gripperSol->kForward);
}

void  Lifter::StopGripper(){
	gripperSol->Set(gripperSol->kOff);
}

bool Lifter::ReadDropToteReedSwitch(){
	return dropToteReedSwitch->Get();
}

DoubleSolenoid::Value Lifter::GetGripperPosition(){
	return gripperSol->Get();
}



#include <Subsystems/Lifter.h>
#include "../Robotmap.h"
#include "DoubleSolenoid.h"
Lifter::Lifter() : Subsystem("LoaderSubsystem") {
	//this is the constructor

	lifterSol = new DoubleSolenoid(1, 0);
	gripperSol= new DoubleSolenoid(2, 3);
	counter=0;


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

bool Lifter::GetGripperSolenoidState()
{
	return gripperSolenoidState;
}


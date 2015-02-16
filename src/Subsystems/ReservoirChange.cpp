#include "ReservoirChange.h"
#include "../RobotMap.h"
#include "DoubleSolenoid.h"

ReservoirChange::ReservoirChange() : Subsystem("ReservoirChangeSubsystem")
{
	compressorSol= new DoubleSolenoid(4, 5);
	reservoirSol= new DoubleSolenoid(6, 7);
}

void ReservoirChange::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ReservoirChange::FillFirstReservoir()
{
	compressorSol->Set(compressorSol->kReverse);
	compressorSolenoidState=-1;
}
void ReservoirChange::FillSecondReservoir()
{
	compressorSol->Set(compressorSol->kForward);
	compressorSolenoidState=1;
}
void ReservoirChange::FillNeitherReservoir()
{
	compressorSol->Set(compressorSol->kOff);
	compressorSolenoidState=0;
}

int ReservoirChange::GetCompressorSolenoidState()
{
	return compressorSolenoidState;
}

void ReservoirChange::UseFirstReservoir()
{
	reservoirSol->Set(reservoirSol->kReverse);
	reservoirSolenoidState=-1;
}
void ReservoirChange::UseSecondReservoir()
{
	reservoirSol->Set(reservoirSol->kForward);
	reservoirSolenoidState=1;
}
void ReservoirChange::UseNeitherReservoir()
{
	reservoirSol->Set(reservoirSol->kOff);
	reservoirSolenoidState=0;
}
int ReservoirChange::GetReservoirSolenoidState()
{
	return reservoirSolenoidState;
}

#ifndef ReservoirChange_H
#define ReservoirChange_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ReservoirChange: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	DoubleSolenoid *compressorSol, *reservoirSol;
	int compressorSolenoidState, reservoirSolenoidState;
public:
	ReservoirChange();
	void InitDefaultCommand();
	void FillFirstReservoir();
	void FillSecondReservoir();
	void FillNeitherReservoir();
	void UseFirstReservoir();
	void UseSecondReservoir();
	void UseNeitherReservoir();
};

#endif

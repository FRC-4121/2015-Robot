#ifndef LOADER_SUBSYSTEM_H
#define LOADER_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Stahl -Suck it James
 */
class Lifter: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities


	DoubleSolenoid *lifterSol, *gripperSol;
	int gripperSolenoidState, lifterSolenoidState;

public:
	Lifter();
	void InitDefaultCommand();
//	bool ReadLoaderRetractLimitSwitch();
//	bool ReadLoaderExtendLimitSwitch();
	void RaiseLifter();
	void LowerLifter();
	void StopLifter();
	bool GetLifterSolenoidState();
	void RetractGripper();
	void ExtendGripper();
	void StopGripper();
	bool GetGripperSolenoidState();
};

#endif

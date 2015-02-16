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
	DigitalInput *fullyRetractedSwitch;
	int gripperSolenoidState, lifterSolenoidState;

public:
	Lifter();
	void InitDefaultCommand();
//	bool ReadLoaderRetractLimitSwitch();
//	bool ReadLoaderExtendLimitSwitch();
	void RaiseLifter();
	void LowerLifter();
	void StopLifter();
	DoubleSolenoid::Value GetLifterPosition();
	bool GetLifterSolenoidState();
	void RetractGripper();
	void ExtendGripper();
	void StopGripper();
	DoubleSolenoid::Value GetGripperPosition();
	bool GetGripperSolenoidState();
	bool ReadFullyRetractedSwitch();
};

#endif

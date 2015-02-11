#ifndef LOADER_SUBSYSTEM_H
#define LOADER_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Vaughn
 */
class Lifter: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

<<<<<<< HEAD
	DigitalInput *retractLimitSwitch, *extendLimitSwitch;
=======
	DigitalInput *dropToteReedSwitch;
>>>>>>> origin/encoder
	DoubleSolenoid *lifterSol, *gripperSol;
	int counter;

public:
	Lifter();
	void InitDefaultCommand();
//	bool ReadLoaderRetractLimitSwitch();
//	bool ReadLoaderExtendLimitSwitch();
	void RaiseLifter();
	void LowerLifter();
	void StopLifter();
	DoubleSolenoid::Value GetLifterPosition();
	void RetractGripper();
	void ExtendGripper();
	void StopGripper();
<<<<<<< HEAD
=======
	bool ReadDropToteReedSwitch();
>>>>>>> origin/encoder
	DoubleSolenoid::Value GetGripperPosition();
};

#endif

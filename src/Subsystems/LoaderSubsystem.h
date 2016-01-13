#ifndef LOADER_SUBSYSTEM_H
#define LOADER_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Stahl -Suck it James
 */
class LoaderSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Victor *feederMotor;

public:
	LoaderSubsystem();
	void InitDefaultCommand();
	void RunLoader();
	void Eject();
	void StopEverything();

};

#endif

#ifndef DataDisplay_H
#define DataDisplay_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DataDisplay: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DataDisplay();
	void InitDefaultCommand();
	void DisplayAll();
};

#endif

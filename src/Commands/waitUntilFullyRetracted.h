#ifndef waitUntilFullyRetracted_H
#define waitUntilFullyRetracted_H

#include "../CommandBase.h"
#include "WPILib.h"

class waitUntilFullyRetracted: public CommandBase
{
private:
	DigitalInput *fullyRetracted;
public:
	waitUntilFullyRetracted();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

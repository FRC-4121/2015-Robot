#ifndef AutoForward_H
#define AutoForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoForward: public CommandBase
{
private:
	float distance;
public:
	AutoForward(float d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

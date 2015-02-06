#ifndef AutoBackward_H
#define AutoBackward_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoBackward: public CommandBase
{
public:
	AutoBackward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

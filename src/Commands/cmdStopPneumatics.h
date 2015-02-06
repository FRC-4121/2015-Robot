#ifndef cmdStopEverything_H
#define cmdStopEverything_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdStopPneumatics: public CommandBase
{
public:
	cmdStopPneumatics();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

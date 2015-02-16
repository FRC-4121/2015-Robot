#ifndef cmdToggleReservoir_H
#define cmdToggleReservoir_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdToggleReservoir: public CommandBase
{
public:
	cmdToggleReservoir();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

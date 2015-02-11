#ifndef AutoQuarterTurn_H
#define AutoQuarterTurn_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoQuarterTurn: public CommandBase
{
public:
	AutoQuarterTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

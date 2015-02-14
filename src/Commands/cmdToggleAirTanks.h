#ifndef cmdToggleAirTanks_H
#define cmdToggleAirTanks_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdToggleAirTanks: public CommandBase
{
public:
	cmdToggleAirTanks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

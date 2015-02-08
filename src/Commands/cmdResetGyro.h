#ifndef cmdResetGyro_H
#define cmdResetGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdResetGyro: public CommandBase
{
public:
	cmdResetGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

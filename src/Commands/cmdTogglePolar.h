#ifndef cmdTogglePolar_H
#define cmdTogglePolar_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdTogglePolar: public CommandBase
{
public:
	cmdTogglePolar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

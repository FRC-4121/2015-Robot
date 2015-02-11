#ifndef LowerToteCommand_H
#define LowerToteCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdLowerToteCommand: public CommandBase
{
public:
	cmdLowerToteCommand(double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	bool IsTimedOut();
	void End();
	void Interrupted();

};

#endif

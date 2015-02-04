#ifndef RetractGripperCommand_H
#define RetractGripperCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdRetractGripperCommand: public CommandBase
{
public:
	cmdRetractGripperCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

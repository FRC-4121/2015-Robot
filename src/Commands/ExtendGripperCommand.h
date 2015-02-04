#ifndef ExtendGripperCommand_H
#define ExtendGripperCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdExtendGripperCommand: public CommandBase
{
public:
	cmdExtendGripperCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

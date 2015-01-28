#ifndef DataDashboardCommand_H
#define DataDashboardCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class DataDashboardCommand: public CommandBase
{
public:
	DataDashboardCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef toggleDriveStyleCommand_H
#define toggleDriveStyleCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class toggleDriveStyleCommand: public CommandBase {
public:
	toggleDriveStyleCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	static char DriveStyle;
};

#endif

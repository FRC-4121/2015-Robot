#ifndef Auto_DriveBackward_H
#define Auto_DriveBackward_H

#include "../CommandBase.h"
#include "WPILib.h"

class autoDriveBackward: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	autoDriveBackward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

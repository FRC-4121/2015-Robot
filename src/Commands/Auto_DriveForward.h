#ifndef Auto_DriveForward_H
#define Auto_DriveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class autoDriveForward: public CommandBase
{
private:


	bool timerStarted;
	Timer *timer;


public:
	autoDriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

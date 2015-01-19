#ifndef Auto_DriveForward_H
#define Auto_DriveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class Auto_DriveForward: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	Auto_DriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

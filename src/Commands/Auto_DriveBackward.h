#ifndef Auto_DriveBackward_H
#define Auto_DriveBackward_H

#include "../CommandBase.h"
#include "WPILib.h"

class Auto_DriveBackward: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	Auto_DriveBackward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef cmdAutoSlideLeft_H
#define cmdAutoSlideLeft_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdAutoSlideLeft: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	cmdAutoSlideLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

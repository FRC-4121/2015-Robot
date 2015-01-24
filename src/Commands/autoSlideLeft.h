#ifndef autoSlideLeft_H
#define autoSlideLeft_H

#include "../CommandBase.h"
#include "WPILib.h"

class autoSlideLeft: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	autoSlideLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

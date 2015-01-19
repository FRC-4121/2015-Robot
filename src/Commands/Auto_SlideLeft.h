#ifndef Auto_Forward_SlideLeft_H
#define Auto_Forward_SlideLeft_H

#include "../CommandBase.h"
#include "WPILib.h"

class Auto_Forward_SlideLeft: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	Auto_Forward_SlideLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

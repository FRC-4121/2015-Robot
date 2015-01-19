#ifndef Auto_SlideRight_H
#define Auto_SlideRight_H

#include "../CommandBase.h"
#include "WPILib.h"

class Auto_SlideRight: public CommandBase
{
private:
	bool timerStarted;
	Timer *timer;
public:
	Auto_SlideRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

#ifndef Delay_H
#define Delay_H

#include "../CommandBase.h"
#include "WPILib.h"

class Delay: public CommandBase
{
private:
	float delayTime;
	Timer *timer;
public:
	Delay(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

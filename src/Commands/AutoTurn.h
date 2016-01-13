#ifndef AutoTurn_H
#define AutoTurn_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
private:
	float xaxis, yaxis, zaxis, stopAngle;
public:
	AutoTurn(float x, float y, float z, float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

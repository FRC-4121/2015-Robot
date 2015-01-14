#ifndef cmdDriveWithJoystick_H
#define cmdDriveWithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdDriveWithJoystick: public CommandBase
{
public:
	cmdDriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

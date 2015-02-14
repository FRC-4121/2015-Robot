#ifndef AutoGrabTrashStackTurnLZone_H
#define AutoGrabTrashStackTurnLZone_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoGrabTrashStackTurnLZone: public CommandGroup
{
private:
	DigitalInput *fullyRetracted;
public:
	AutoGrabTrashStackTurnLZone();
};

#endif

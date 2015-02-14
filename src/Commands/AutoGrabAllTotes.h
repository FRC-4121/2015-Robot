#ifndef AutoGrabAllTotes_H
#define AutoGrabAllTotes_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoGrabAllTotes: public CommandGroup
{
private:
	DigitalInput *loaderFullyRetracted;

public:
	AutoGrabAllTotes();
};

#endif

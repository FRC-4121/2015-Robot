#ifndef cmdToggleCompressor_H
#define cmdToggleCompressor_H

#include "../CommandBase.h"
#include "WPILib.h"

class cmdToggleCompressor: public CommandBase
{
public:
	cmdToggleCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

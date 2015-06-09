#ifndef ACTIVATE_LOADER_H
#define ACTIVATE_LOADER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vaughn
 */
class cmdActivateLoader: public CommandBase {
public:
	cmdActivateLoader();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

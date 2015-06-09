#ifndef DEACTIVATE_LOADER_H
#define DEACTIVATE_LOADER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Vaughn
 */
class cmdDeactivateLoader: public CommandBase {
public:
	cmdDeactivateLoader();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

#ifndef RETRACT_LOADER_COMMAND_H
#define RETRACT_LOADER_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class cmdRetractLoaderCommand: public CommandBase {
public:
	cmdRetractLoaderCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

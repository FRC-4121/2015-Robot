#ifndef EXTEND_LOADER_COMMAND_H
#define EXTEND_LOADER_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class cmdExtendLoaderCommand: public CommandBase {
public:
	cmdExtendLoaderCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

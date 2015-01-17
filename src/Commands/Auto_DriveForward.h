#ifndef AUTO_DRIVEFORWARD_H
#define AUTO_DRIVEFORWARD_H

#include "../CommandBase.h"

/**
 *
 *
 *
 */
class autoDriveForward: public CommandBase {
private:
	int driveTime;
	//bool isForward;
public:
	autoDriveForward();
  void Initialize();
	void Execute();
	bool IsFinished();
	void End();
  void Interrupted();
};

#endif

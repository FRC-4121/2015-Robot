#include <Commands/waitUntilFullyRetracted.h>
#include "AutoGrabTrashStackTurnLZone.h"
#include "Commands/AutoForward.h"
#include "Commands/RetractLoaderCommand.h"
#include "Commands/RetractGripperCommand.h"
#include "Commands/AutoTurn.h"
#include "Commands/ExtendGripperCommand.h"
#include "Commands/ExtendLoaderCommand.h"
#include "Commands/Delay.h"
#include "../Robotmap.h"

AutoGrabTrashStackTurnLZone::AutoGrabTrashStackTurnLZone()
{


	//need to do limit switch to know when loader fully retracted before driving forward to tote

	AddSequential(new cmdRetractGripperCommand());//clamp onto bin

	AddSequential(new Delay(1));

	AddSequential(new cmdRetractLoaderCommand());//lift the bin
	AddSequential(new waitUntilFullyRetracted());//checks if loader fully retracted


	AddParallel(new AutoForward(24));//drives forward with bin till overtop the tote

	AddParallel(new cmdExtendLoaderCommand()); //drop loader to the ground

	AddSequential(new cmdExtendGripperCommand());//drop bin onto tote

	AddSequential(new Delay(3));

	AddSequential(new cmdRetractGripperCommand());//clamp on to new tote base

	AddSequential(new Delay(1));

	AddParallel(new cmdRetractLoaderCommand());//lift the tote
	AddSequential(new AutoTurn(0,0,-0.5, -80));//turn left

	AddSequential(new AutoForward(132));//drive to auto zone;
}

#include "AutoGrabTrashStackTurnLZone.h"
#include "Commands/AutoForward.h"
#include "Commands/RetractLoaderCommand.h"
#include "Commands/RetractGripperCommand.h"
#include "Commands/AutoTurn.h"
#include "Commands/ExtendGripperCommand.h"
#include "Commands/ExtendLoaderCommand.h"

AutoGrabTrashStackTurnLZone::AutoGrabTrashStackTurnLZone()
{
	AddSequential(new cmdRetractGripperCommand());//clamp onto bin

		AddSequential(new cmdRetractLoaderCommand());//lift the bin

		AddSequential(new AutoForward(24));//drives forward with bin till overtop the tote

		AddSequential(new cmdExtendGripperCommand());//drop bin onto tote

		AddSequential(new cmdExtendLoaderCommand()); //drop loader to the ground

		AddSequential(new cmdRetractGripperCommand());//clamp on to new tote base

		AddParallel(new cmdRetractLoaderCommand());//lift the tote
		AddSequential(new AutoTurn(0,0,-0.5, -90));//turn left

		AddSequential(new AutoForward(132));//drive to auto zone;



}

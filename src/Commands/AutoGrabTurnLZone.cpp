#include "AutoGrabTurnLZone.h"
#include "Commands/AutoForward.h"
#include "Commands/RetractLoaderCommand.h"
#include "Commands/RetractGripperCommand.h"
#include "Commands/AutoTurn.h"

AutoGrabTurnLZone::AutoGrabTurnLZone()
{
	AddSequential(new cmdRetractGripperCommand());//clamp onto tote or bin

	AddParallel(new cmdRetractLoaderCommand());//lift the tote or bin while turning 90 degrees

	AddSequential(new AutoTurn(0,0,-.5,-80));//the direction it rotates depends on where we start


	AddSequential(new AutoForward(124));//drive the 9'6" forward over ramp

	//Unsure if we need to drop tote into the zone for points or if we can hold it for points
	/*
	AddSequential(new cmdExtendLoaderCommand());//lower the tote or bin

	AddSequential(new cmdExtendGripperCommand());//release the gripper so tote or bin falls to the ground
	 */
}



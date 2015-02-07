#include "AutonomousRoutine.h"
#include "Commands/AutoForward.h"
#include "Commands/AutoQuarterTurn.h"
#include "Commands/cmdRetractLoaderCommand.h"
#include "Commands/cmdRetractGripperCommand.h"



AutonomousRoutine::AutonomousRoutine()
{


	AddSequential(new cmdRetractGripperCommand());//clamp onto tote or bin

	AddParallel(new cmdRetractLoaderCommand());//lift the tote or bin while turning 90 degrees
	AddSequential(new AutoQuarterTurn());//the direction it rotates depends on where we start
										//(depends on which code is commented out in the command)

	AddSequential(new AutoForward());//drive the 9'6" forward over ramp

	//Unsure if we need to drop tote into the zone for points or if we can hold it for points
	/*
	AddSequential(new cmdExtendLoaderCommand());//lower the tote or bin

	AddSequential(new cmdExtendGripperCommand());//release the gripper so tote or bin falls to the ground
	 */
}

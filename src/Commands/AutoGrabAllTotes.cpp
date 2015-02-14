#include <Commands/waitUntilFullyRetracted.h>
#include "AutoGrabAllTotes.h"
#include "Commands/AutoForward.h"
#include "Commands/RetractLoaderCommand.h"
#include "Commands/RetractGripperCommand.h"
#include "Commands/AutoTurn.h"
#include "Commands/ExtendGripperCommand.h"
#include "Commands/ExtendLoaderCommand.h"
#include "../Robotmap.h"

AutoGrabAllTotes::AutoGrabAllTotes()
{
	//THIS PROGRAM WILL ONLY WORK IF WE START AT THE RIGHT MOST BIN TOTE LOCATION WHEN LOOKING AT THE FIELD THROUGH THE DRIVER STATION
	//need to do limit switch to know when loader fully retracted before driving forward to next tote
	loaderFullyRetracted = new DigitalInput(LOADER_FULLY_RETRACT_REED_SWITCH_I);

	AddSequential(new cmdRetractGripperCommand());//clamp onto 1st tote or bin

	AddSequential(new cmdRetractLoaderCommand());//lift the tote or bin
	AddSequential(new waitUntilFullyRetracted());//checks if loader fully retracted

	AddSequential(new AutoForward(89));//drive to the next tote

	AddParallel(new cmdExtendLoaderCommand()); //drop loader to the ground

	AddSequential(new cmdExtendGripperCommand());//drop tote onto tote



	AddSequential(new cmdRetractGripperCommand());//clamp on to 2nd tote base

	AddSequential(new cmdRetractLoaderCommand());//lift the tote
	AddSequential(new waitUntilFullyRetracted());//checks if loader fully retracted

	AddSequential(new AutoForward(89));//drive to the next tote

	AddParallel(new cmdExtendLoaderCommand()); //drop loader to the ground

	AddSequential(new cmdExtendGripperCommand());//drop tote onto tote




	AddSequential(new cmdRetractGripperCommand());//clamp on to 3rd tote base

	AddParallel(new cmdRetractLoaderCommand());//lift the tote as you turn 90 degrees to the right
	AddSequential(new AutoTurn(0,0,0.5,80));

	AddSequential(new AutoForward(132));//drive the 9'6" forward over ramp into AutoZone and VICTORY!!!!!!!!!!!!!!



}

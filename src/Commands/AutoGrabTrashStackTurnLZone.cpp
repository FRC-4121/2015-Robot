#include "Commands/waitUntilFullyRetracted.h"
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

	AddSequential(new cmdRetractGripperCommand());//switch solenoid to start clamping onto tote

	AddSequential(new Delay(1));//wait until fully retracted

	AddSequential(new cmdRetractLoaderCommand());//lift the bin

	AddSequential(new waitUntilFullyRetracted());//checks if loader fully retracted

	AddSequential(new AutoForward(24));//drives forward with bin till overtop the tote

	AddSequential(new cmdExtendLoaderCommand()); //drop loader to the ground
	AddSequential(new cmdExtendGripperCommand());//drop bin onto tote

	AddSequential(new Delay(3));//wait until loader fully dropped

	AddSequential(new cmdRetractGripperCommand());//switch solenoid to start clamping onto new tote base

	AddSequential(new Delay(1));//wait until fully clamped

	AddSequential(new cmdRetractLoaderCommand());//lift the tote while turning left
	AddSequential(new AutoTurn(0,0,-0.5, -80));

	AddSequential(new AutoForward(132));//drive to auto zone and VICTORY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Chassis.h"
#include "Commands/Scheduler.h"
#include "Subsystems/DataDisplay.h"
//#include "Subsystems/AxisCamera.h"


// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
Chassis* CommandBase::mecanumChassis = NULL;
DataDisplay* CommandBase::driverDisplay = NULL;
Lifter* CommandBase::toteLifter = NULL;
SendableChooser* CommandBase::chooser= NULL;
ReservoirChange CommandBase::reservoirChanger=NULL;


CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	oi = new OI();
	mecanumChassis = new Chassis();
	driverDisplay = new DataDisplay();
	toteLifter = new Lifter();

}

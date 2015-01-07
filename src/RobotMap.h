#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;


//#########  User Input Devices #########
#define JOYSTICKLEFT  	(1)
#define JOYSTICKRIGHT 	(2)
#define JOYSTICKCAMERA  (3)


//######### Joystick Buttons  #########
//#define TRIGGER (1)

typedef enum{
	TRIGGER = 1, // Button Number 1
	THUMB_BUTTON_DOWN, // Button Number 2
	THUMB_BUTTON_UP,//button 3
	THUMB_BUTTON_LEFT,//button 4
	THUMB_BUTTON_RIGHT, // Button Number 5
	LEFT_SIDE_UP,//button6
	LEFT_SIDE_DOWN,//button 7
	FRONT_SIDE_LEFT,// 8
	FRONT_SIDE_RIGHT,//9
	RIGHT_SIDE_DOWN, // Button Number 10
	RIGHT_SIDE_UP,
	NUM_OF_JOYSTICK_BUTTONS
} JOYSTICE_BUTTONS_T;

typedef enum{
	ENGAGE_WINCH = 1,
	DISENGAGE_WINCH,
	SOLENOID_3,
	EXTEND_LOADER_RELAY,
	RETRACT_LOADER_RELAY,
	SOLENOID_6,
	SOLENOID_7,
	SOLENOID_8,
}SOLENOID_t;



typedef enum{
	RELAY_1 = 1,
	RELAY_2,
	COMPRESSOR_RELAY,
	RELAY_4,
	RELAY_5,
	RELAY_6,
	RELAY_7,
	RELAY_8,
}RELAY_t;

typedef enum{

	LOADER_RETRACT_LIMIT_SWITCH_I = 1,
	LOADER_EXTEND_LIMIT_SWITCH_I,
	WINCH_RETRACT_LIMIT_SWITCH_I,
	WINCH_EXTEND_LIMIT_SWITCH_I,
	COMPRESSOR_PRESSURE_SWITCH,
	DIO6,
	DIO7,
	DIO8,
	DIO9,
	DIO10,
	DIO11,
	DIO12,
	DIO13,
	DIO14
}DIGITAL_IO_T;


//######### Motors #########
//#define DRIVEMOTORRIGHT (2)
//#define DRIVEMOTORLEFT  (1)
//#define WINCHMOTOR		(4)
//#define FEEDERMOTOR 	(3)

typedef enum{
	WINCHMOTOR = 1,
	FEEDERMOTOR,
	DRIVEMOTORFRONTLEFT,
	DRIVEMOTORFRONTRIGHT,
	DRIVEMOTORREARLEFT,
	DRIVEMOTORREARRIGHT,
	DRIVECAMERAVERTCALMOTOR,
	DRIVECAMERAHORIZONTALMOTOR

}PWM_CHANNELS_t;


#endif

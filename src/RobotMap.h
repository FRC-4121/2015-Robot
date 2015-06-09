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


#define JOYSTICKLEFT (0)
#define JOYSTICKRIGHT (1)
#define XBOXCONTROLLER (2)

typedef enum
{
	FEEDERMOTOR,
	FRONT_LEFT_TALON = 0,
	FRONT_RIGHT_TALON,
	REAR_LEFT_TALON,
	REAR_RIGHT_TALON,
}TALON_CONTRLERS_t;


typedef enum{
	//the name of each type should follow this format
//	Joystick(R/L)_ButtonName_fButtonFunction - The f is NOT a typo
	L_TRIGGER=1,//button 1
	L_THUMB_BUTTON_DOWN_fLOWER_LIFTER, // Button Number 2
	L_THUMB_BUTTON_UP_fRAISE_LIFTER,//button 3
	L_THUMB_BUTTON_LEFT_fRETRACT_GRIPPER,//button 4
	L_THUMB_BUTTON_RIGHT_fEXTEND_GRIPPER, // Button Number 5
	L_LEFT_SIDE_UP_fTOGGLE_MECHANUM,//button 6
	L_LEFT_SIDE_DOWN_fTOGGLE_POLAR,//button 7
	L_FRONT_SIDE_LEFT,// 8
	L_FRONT_SIDE_RIGHT,//9
	L_RIGHT_SIDE_DOWN, // Button Number 10
	L_RIGHT_SIDE_UP_fSTOP_PNEUMATICS,
	L_NUM_OF_JOYSTICK_BUTTONS
} JOYSTICK_LEFT_BUTTONS_t;

typedef enum{
	//the name of each type should follow this format
//	Joystick(R/L)_ButtonName_fButtonFunction - The f is NOT a typo
	R_TRIGGER=1,//button 1
	R_THUMB_BUTTON_DOWN, // Button Number 2
	R_THUMB_BUTTON_UP,//button 3
	R_THUMB_BUTTON_LEFT_fREVERSE_FEEDER,//button 4
	R_THUMB_BUTTON_RIGHT_fFORWARD_FEEDER, // Button Number 5
	R_LEFT_SIDE_UP_fRESET_GYRO,//button 6
	R_LEFT_SIDE_DOWN,//button 7
	R_FRONT_SIDE_LEFT,// 8
	R_FRONT_SIDE_RIGHT,//9
	R_RIGHT_SIDE_DOWN, // Button Number 10
	R_RIGHT_SIDE_UP,
	R_NUM_OF_JOYSTICK_BUTTONS
} JOYSTICK_RIGHT_BUTTONS_t;

typedef enum{
//the name of each type should follow this format
//	Joystick(R/L)_ButtonName_fButtonFunction - The f is NOT a typo
	XBOX_A_fLOWER_LIFTER=1,//button 1
	XBOX_B_fEXTEND_GRIPPER, // Button Number 2
	XBOX_X_fRETRACT_GRIPPER,//button 3
	XBOX_Y_fRAISE_LIFTER,//button 4
	XBOX_LB, // Button Number 5
	XBOX_RB,//button 6
	XBOX_BACK,//button 7
	XBOX_START,// 8
	XBOX_LSTICKPRESS_fTOGGLE_MECHANUM,//9
	XBOX_RSTICKPRESS_fRESET_GYRO, // Button Number 10
	XBOX_NUM_OF_BUTTONS
} XBOX_CONTROLLER_BUTTONS_t;


typedef enum{

	DIO0 = 0,
	DIO1,
	DIO2,
	DIO3,
	DIO4,
	DIO5,
	DIO6,
	DIO7,
	DIO8,
	LOADER_FULLY_RETRACT_REED_SWITCH_I,
}DIGITAL_IO_T;


#endif

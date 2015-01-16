#ifndef TOGGLE_DRIVE_STYLE_COMMAND_H
#define TOGGLE_DRIVE_STYLE_COMMAND_H
#include "../CommandBase.h"


	/**
	 *
	 *
	 * @author 322Programmer
	 */
	class ToggleDrive: public CommandBase
	{

		public:
		ToggleDrive();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
	};


	#endif

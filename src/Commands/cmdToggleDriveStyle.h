#ifndef TOGGLE_DRIVE_STYLE_COMMAND_H
#define TOGGLE_DRIVE_STYLE_COMMAND_H
#include "../CommandBase.h"


	/**
	 *
	 *
	 * @author 322Programmer
	 */
	class cmdToggleDriveStyle: public CommandBase
	{

		public:
		cmdToggleDriveStyle();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
	};


	#endif

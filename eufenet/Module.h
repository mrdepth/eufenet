#pragma once
#include "item.h"

namespace eufenet {

	public ref class Module: public Item
	{
	public:
		enum class Slot
		{
			SLOT_NONE,
			SLOT_HI,
			SLOT_MED,
			SLOT_LOW,
			SLOT_RIG,
			SLOT_SUBSYSTEM,
			SLOT_STRUCTURE
		};

		enum class State
		{
			STATE_OFFLINE,
			STATE_ONLINE,
			STATE_ACTIVE,
			STATE_OVERLOADED
		};
		
		enum class Hardpoint
		{
			HARDPOINT_NONE = 0,
			HARDPOINT_LAUNCHER,
			HARDPOINT_TURRET
		};

		Module(const Module% other);
		Module(eufe::Module* module);
		virtual ~Module(void);
	};

}
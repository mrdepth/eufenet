#pragma once
#include "item.h"
#include "Charge.h"

namespace eufenet {

	ref class Ship;

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

		Slot getSlot();
		Hardpoint getHardpoint();
		bool canHaveState(State state);
		State getState();
		void setState(State state);

		Charge^ setCharge(TypeID typeID);
		void clearCharge();
		Charge^ getCharge();
		array<TypeID>^ getChargeGroups();
		int getChargeSize();
		void removeCharge();
		bool requireTarget();
		void setTarget(Ship^ target);
		void clearTarget();
		Ship^ getTarget();
		float getReloadTime();
		
		//Calculations
		
		float getCycleTime();
		float getRawCycleTime();
		
		int getCharges();
		int getShots();
		float getCapUse();
		
		float getVolley();
		float getDps();
		float getMaxRange();
		float getFalloff();
		float getTrackingSpeed();
		
		float getLifeTime();
	};

}
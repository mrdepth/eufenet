#pragma once
#include "item.h"
#include "Charge.h"

namespace eufenet {
	ref class Ship;
	public ref class Drone: public Item
	{
	public:
		Drone(const Drone% other);
		Drone(eufe::Drone* drone);
		
		void setTarget(Ship^ target);
		void clearTarget();
		Ship^ getTarget();

		bool dealsDamage();
		Charge^ getCharge();
		
		void setActive(bool active);
		bool isActive();
		
		//Calculations
		
		float getCycleTime();
		
		float getVolley();
		float getDps();
		float getMaxRange();
		float getFalloff();
		float getTrackingSpeed();
	};

}
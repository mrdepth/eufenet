#pragma once
#include "item.h"

namespace eufenet {

	public ref class Drone: public Item
	{
	public:
		Drone(const Drone% other);
		Drone(eufe::Drone* drone);
		virtual ~Drone(void);
	};

}
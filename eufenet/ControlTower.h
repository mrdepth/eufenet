#pragma once
#include "item.h"

namespace eufenet {

	public ref class ControlTower: public Item
	{
	public:
		ControlTower(const ControlTower% other);
		ControlTower(eufe::ControlTower* controlTower);
		virtual ~ControlTower(void);
	};

}
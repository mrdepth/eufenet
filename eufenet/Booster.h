#pragma once
#include "item.h"

namespace eufenet {

	public ref class Booster : public Item
	{
	public:
		Booster(const Booster% other);
		Booster(eufe::Booster* booster);
		int getSlot();
	};

}
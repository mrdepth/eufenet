#pragma once
#include "item.h"

namespace eufenet {

	public ref class Implant: public Item
	{
	public:
		Implant(const Implant% other);
		Implant(eufe::Implant* implant);
		int getSlot();
	};

}
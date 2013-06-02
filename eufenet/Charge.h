#pragma once
#include "item.h"

namespace eufenet {

	public ref class Charge : public Item
	{
	public:
		Charge(const Charge% other);
		Charge(eufe::Charge* charge);
		virtual ~Charge(void);
	};

}
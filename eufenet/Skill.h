#pragma once
#include "item.h"

namespace eufenet {

	public ref class Skill: public Item
	{
	public:
		Skill(const Skill% other);
		Skill(eufe::Skill* skill);
	};

}
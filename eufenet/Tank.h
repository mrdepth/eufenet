#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class Tank
	{
	public:
		Tank(const Tank% other);
		Tank(eufe::Tank tank);
		float armorRepair;
		float hullRepair;
		float shieldRepair;
		float passiveShield;
	};

}
#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class HitPoints
	{
	public:
		HitPoints(const HitPoints% other);
		HitPoints(eufe::HitPoints hitPoints);
		float armor;
		float hull;
		float shield;
	};

}
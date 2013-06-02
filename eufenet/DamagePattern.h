#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class DamagePattern
	{
	public:
		DamagePattern(eufe::DamagePattern damagePattern);
		eufe::DamagePattern getDamagePattern();
	private:
		//eufe::DamagePattern damagePattern_;
	};

}
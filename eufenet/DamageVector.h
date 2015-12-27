#pragma once
#include <eufe.h>
namespace eufenet {

	public ref class DamageVector
	{
	public:
		DamageVector(eufe::DamageVector damageVector);
		eufe::DamageVector getDamageVector();
	private:
		//eufe::DamageVector damageVector_;
	};

}
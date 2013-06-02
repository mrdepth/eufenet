#include "stdafx.h"
#include "Tank.h"

using namespace eufenet;

Tank::Tank(const Tank% other)
{
	armorRepair = other.armorRepair;
	hullRepair = other.hullRepair;
	shieldRepair = other.shieldRepair;
	passiveShield = other.passiveShield;
}

Tank::Tank(eufe::Tank tank)
{
	armorRepair = tank.armorRepair;
	hullRepair = tank.hullRepair;
	shieldRepair = tank.shieldRepair;
	passiveShield = tank.passiveShield;
}

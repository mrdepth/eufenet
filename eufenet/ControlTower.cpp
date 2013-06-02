#include "stdafx.h"
#include "ControlTower.h"

using namespace eufenet;

ControlTower::ControlTower(const ControlTower% other): Item(other)
{
}

ControlTower::ControlTower(eufe::ControlTower* controlTower): Item(controlTower)
{
}


ControlTower::~ControlTower(void)
{
}

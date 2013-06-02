#include "stdafx.h"
#include "Implant.h"

using namespace eufenet;

Implant::Implant(const Implant% other): Item(other)
{
}

Implant::Implant(eufe::Implant* implant): Item(implant)
{
}


int Implant::getSlot()
{
	return dynamic_cast<eufe::Implant*>(item_)->getSlot();
}


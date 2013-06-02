#include "stdafx.h"
#include "Booster.h"

using namespace eufenet;

Booster::Booster(const Booster% other): Item(other)
{
}

Booster::Booster(eufe::Booster* booster): Item(booster)
{
}


int Booster::getSlot()
{
	return dynamic_cast<eufe::Booster*>(item_)->getSlot();
}

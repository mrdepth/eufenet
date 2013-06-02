#include "stdafx.h"
#include "Charge.h"

using namespace eufenet;

Charge::Charge(const Charge% other): Item(other)
{
}

Charge::Charge(eufe::Charge* charge): Item(charge)
{
}


Charge::~Charge(void)
{
}

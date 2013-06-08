#include "stdafx.h"
#include "Module.h"
#include "Ship.h"

using namespace eufenet;

Module::Module(const Module% other): Item(other)
{
}

Module::Module(eufe::Module* module): Item(module)
{
}



Module::Slot Module::getSlot()
{
	return (Slot) dynamic_cast<eufe::Module*>(item_)->getSlot();
}

Module::Hardpoint Module::getHardpoint()
{
	return (Hardpoint) dynamic_cast<eufe::Module*>(item_)->getHardpoint();
}

bool Module::canHaveState(State state)
{
	return dynamic_cast<eufe::Module*>(item_)->canHaveState((eufe::Module::State) state);
}

Module::State Module::getState()
{
	return (State) dynamic_cast<eufe::Module*>(item_)->getState();
}

void Module::setState(State state)
{
	dynamic_cast<eufe::Module*>(item_)->setState((eufe::Module::State) state);
}

Charge^ Module::setCharge(TypeID typeID)
{
	eufe::Charge* charge = dynamic_cast<eufe::Module*>(item_)->setCharge(typeID);
	return charge ? gcnew Charge(charge) : nullptr;
}

void Module::clearCharge()
{
	dynamic_cast<eufe::Module*>(item_)->clearCharge();
}

Charge^ Module::getCharge()
{
	eufe::Charge* charge = dynamic_cast<eufe::Module*>(item_)->getCharge();
	return charge ? gcnew Charge(charge) : nullptr;
}

array<TypeID>^ Module::getChargeGroups()
{
	std::vector<TypeID> chargeGroups = dynamic_cast<eufe::Module*>(item_)->getChargeGroups();
	array<TypeID>^ arr = gcnew array<TypeID> (chargeGroups.size());

	int n = 0;

	std::vector<TypeID>::const_iterator i, end = chargeGroups.end();
	for (i = chargeGroups.begin(); i != end; i++)
		arr[n++] = *i;
	return arr;
}

int Module::getChargeSize()
{
	return dynamic_cast<eufe::Module*>(item_)->getChargeSize();
}

void Module::removeCharge()
{
	dynamic_cast<eufe::Module*>(item_)->removeCharge();
}

bool Module::requireTarget()
{
	return dynamic_cast<eufe::Module*>(item_)->requireTarget();
}

void Module::setTarget(Ship^ target)
{
	dynamic_cast<eufe::Module*>(item_)->setTarget(dynamic_cast<eufe::Ship*>(target->getItem()));
}

void Module::clearTarget()
{
	dynamic_cast<eufe::Module*>(item_)->clearTarget();
}

Ship^ Module::getTarget()
{
	eufe::Ship* ship = dynamic_cast<eufe::Module*>(item_)->getTarget();
	return ship ? gcnew Ship(ship) : nullptr;
}

float Module::getReloadTime()
{
	return dynamic_cast<eufe::Module*>(item_)->getReloadTime();
}

		
//Calculations
		
float Module::getCycleTime()
{
	return dynamic_cast<eufe::Module*>(item_)->getCycleTime();
}

float Module::getRawCycleTime()
{
	return dynamic_cast<eufe::Module*>(item_)->getRawCycleTime();
}

		
int Module::getCharges()
{
	return dynamic_cast<eufe::Module*>(item_)->getCharges();
}

int Module::getShots()
{
	return dynamic_cast<eufe::Module*>(item_)->getShots();
}

float Module::getCapUse()
{
	return dynamic_cast<eufe::Module*>(item_)->getCapUse();
}

		
float Module::getVolley()
{
	return dynamic_cast<eufe::Module*>(item_)->getVolley();
}

float Module::getDps()
{
	return dynamic_cast<eufe::Module*>(item_)->getDps();
}

float Module::getMaxRange()
{
	return dynamic_cast<eufe::Module*>(item_)->getMaxRange();
}

float Module::getFalloff()
{
	return dynamic_cast<eufe::Module*>(item_)->getFalloff();
}

float Module::getTrackingSpeed()
{
	return dynamic_cast<eufe::Module*>(item_)->getTrackingSpeed();
}

		
float Module::getLifeTime()
{
	return dynamic_cast<eufe::Module*>(item_)->getLifeTime();
}

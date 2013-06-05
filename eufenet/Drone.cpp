#include "stdafx.h"
#include "Drone.h"
#include "Ship.h"

using namespace eufenet;

Drone::Drone(const Drone% other): Item(other)
{
}

Drone::Drone(eufe::Drone* drone): Item(drone)
{
}


void Drone::setTarget(Ship^ target)
{
	dynamic_cast<eufe::Drone*>(item_)->setTarget(dynamic_cast<eufe::Ship*>(target->getItem()));
}

void Drone::clearTarget()
{
	dynamic_cast<eufe::Drone*>(item_)->clearTarget();
}

Ship^ Drone::getTarget()
{
	auto ship = dynamic_cast<eufe::Drone*>(item_)->getTarget();
	return ship ? gcnew Ship(ship) : nullptr;
}


bool Drone::dealsDamage()
{
	return dynamic_cast<eufe::Drone*>(item_)->dealsDamage();
}

Charge^ Drone::getCharge()
{
	auto charge = dynamic_cast<eufe::Drone*>(item_)->getCharge();
	return charge ? gcnew Charge(charge) : nullptr;
}

		
void Drone::setActive(bool active)
{
	dynamic_cast<eufe::Drone*>(item_)->setActive(active);
}

bool Drone::isActive()
{
	return dynamic_cast<eufe::Drone*>(item_)->isActive();
}

		
//Calculations
		
float Drone::getCycleTime()
{
	return dynamic_cast<eufe::Drone*>(item_)->getCycleTime();
}

		
float Drone::getVolley()
{
	return dynamic_cast<eufe::Drone*>(item_)->getVolley();
}

float Drone::getDps()
{
	return dynamic_cast<eufe::Drone*>(item_)->getDps();
}

float Drone::getMaxRange()
{
	return dynamic_cast<eufe::Drone*>(item_)->getMaxRange();
}

float Drone::getFalloff()
{
	return dynamic_cast<eufe::Drone*>(item_)->getFalloff();
}

float Drone::getTrackingSpeed()
{
	return dynamic_cast<eufe::Drone*>(item_)->getTrackingSpeed();
}


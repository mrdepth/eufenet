#include "stdafx.h"
#include "Drone.h"

using namespace eufenet;

Drone::Drone(const Drone% other): Item(other)
{
}

Drone::Drone(eufe::Drone* drone): Item(drone)
{
}


Drone::~Drone(void)
{
}

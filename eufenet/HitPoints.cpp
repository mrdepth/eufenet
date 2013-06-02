#include "stdafx.h"
#include "HitPoints.h"

using namespace eufenet;

HitPoints::HitPoints(const HitPoints% other)
{
	armor = other.armor;
	hull = other.hull;
	shield = other.shield;
}

HitPoints::HitPoints(eufe::HitPoints hitPoints)
{
	armor = hitPoints.armor;
	hull = hitPoints.hull;
	shield = hitPoints.shield;
}

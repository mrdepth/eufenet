#include "stdafx.h"
#include "Resistances.h"

using namespace eufenet;

Resistances::Layer::Layer()
{
	em = explosive = kinetic = thermal = 0;
}

Resistances::Layer::Layer(const Resistances::Layer% other)
{
	em = other.em;
	explosive = other.explosive;
	kinetic = other.kinetic;
	thermal = other.thermal;
}

Resistances::Layer::Layer(const eufe::ResistancesLayer& layer)
{
	em = layer.em;
	explosive = layer.explosive;
	kinetic = layer.kinetic;
	thermal = layer.thermal;
}

Resistances::Layer% Resistances::Layer::operator = (const Resistances::Layer% other)
{
	em = other.em;
	explosive = other.explosive;
	kinetic = other.kinetic;
	thermal = other.thermal;
	return *this;
}

Resistances::Resistances(const Resistances% other)
{
	shield = other.shield;
	armor = other.armor;
	hull = other.hull;
}

Resistances::Resistances(const eufe::Resistances& resistances)
{
	shield = Layer(resistances.shield);
	armor = Layer(resistances.armor);
	hull = Layer(resistances.hull);
}

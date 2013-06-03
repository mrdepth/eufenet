#include "stdafx.h"
#include "Gang.h"

using namespace eufenet;

Gang::Gang(const Gang% other): Item(other)
{
}

Gang::Gang(eufe::Gang* gang): Item(gang)
{
}


array<Character^>^ Gang::getPilots()
{
	auto characters = dynamic_cast<eufe::Gang*>(item_)->getPilots();
	array<Character^>^ arr = gcnew array<Character^> (characters.size());

	int i = 0;
	for (auto character: characters)
		arr[i++] = gcnew Character(character);
	return arr;
}

Character^ Gang::addPilot()
{
	return gcnew Character(dynamic_cast<eufe::Gang*>(item_)->addPilot());
}

void Gang::removePilot(Character^ character)
{
	dynamic_cast<eufe::Gang*>(item_)->removePilot(dynamic_cast<eufe::Character*>(character->getItem()));
}

		
Character^ Gang::getFleetBooster()
{
	return gcnew Character(dynamic_cast<eufe::Gang*>(item_)->getFleetBooster());
}

Character^ Gang::getWingBooster()
{
	return gcnew Character(dynamic_cast<eufe::Gang*>(item_)->getWingBooster());
}

Character^ Gang::getSquadBooster()
{
	return gcnew Character(dynamic_cast<eufe::Gang*>(item_)->getSquadBooster());
}

void Gang::setFleetBooster(Character^ fleetBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setFleetBooster(dynamic_cast<eufe::Character*>(fleetBooster->getItem()));
}

void Gang::setWingBooster(Character^ wingBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setWingBooster(dynamic_cast<eufe::Character*>(wingBooster->getItem()));
}

void Gang::setSquadBooster(Character^ squadBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setSquadBooster(dynamic_cast<eufe::Character*>(squadBooster->getItem()));
}

void Gang::removeFleetBooster()
{
	return dynamic_cast<eufe::Gang*>(item_)->removeFleetBooster();
}

void Gang::removeWingBooster()
{
	return dynamic_cast<eufe::Gang*>(item_)->removeWingBooster();
}

void Gang::removeSquadBooster()
{
	return dynamic_cast<eufe::Gang*>(item_)->removeSquadBooster();
}

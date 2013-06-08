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
	eufe::CharactersList characters = dynamic_cast<eufe::Gang*>(item_)->getPilots();
	array<Character^>^ arr = gcnew array<Character^> (characters.size());

	int n = 0;

	eufe::CharactersList::const_iterator i, end = characters.end();
	for (i = characters.begin(); i != end; i++)
		arr[n++] = gcnew Character(*i);
	return arr;
}

Character^ Gang::addPilot()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->addPilot();
	return character ? gcnew Character(character) : nullptr;
}

void Gang::removePilot(Character^ character)
{
	dynamic_cast<eufe::Gang*>(item_)->removePilot(dynamic_cast<eufe::Character*>(character->getItem()));
}

		
Character^ Gang::getFleetBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getFleetBooster();
	return character ? gcnew Character(character) : nullptr;
}

Character^ Gang::getWingBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getWingBooster();
	return character ? gcnew Character(character) : nullptr;
}

Character^ Gang::getSquadBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getSquadBooster();
	return character ? gcnew Character(character) : nullptr;
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

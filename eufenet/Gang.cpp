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

	for (auto i: characters)
		arr[n++] = gcnew Character(i.get());
	return arr;
}

Character^ Gang::addPilot()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->addPilot().get();
	return character ? gcnew Character(character) : nullptr;
}

void Gang::removePilot(Character^ character)
{
	dynamic_cast<eufe::Gang*>(item_)->removePilot(dynamic_cast<eufe::Character*>(character->getItem())->shared_from_this());
}

		
Character^ Gang::getFleetBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getFleetBooster().get();
	return character ? gcnew Character(character) : nullptr;
}

Character^ Gang::getWingBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getWingBooster().get();
	return character ? gcnew Character(character) : nullptr;
}

Character^ Gang::getSquadBooster()
{
	eufe::Character* character = dynamic_cast<eufe::Gang*>(item_)->getSquadBooster().get();
	return character ? gcnew Character(character) : nullptr;
}

void Gang::setFleetBooster(Character^ fleetBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setFleetBooster(dynamic_cast<eufe::Character*>(fleetBooster->getItem())->shared_from_this());
}

void Gang::setWingBooster(Character^ wingBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setWingBooster(dynamic_cast<eufe::Character*>(wingBooster->getItem())->shared_from_this());
}

void Gang::setSquadBooster(Character^ squadBooster)
{
	dynamic_cast<eufe::Gang*>(item_)->setSquadBooster(dynamic_cast<eufe::Character*>(squadBooster->getItem())->shared_from_this());
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

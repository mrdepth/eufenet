#include "stdafx.h"
#include "Character.h"
#include <vcclr.h>
#include <cliext/adapter>

using namespace eufenet;

Character::Character(const Character% other): Item(other)
{
}

Character::Character(eufe::Character* character): Item(character)
{
}


Ship^ Character::getShip()
{
	auto ship = dynamic_cast<eufe::Character*>(item_)->getShip();
	return ship ? gcnew Ship(ship) : nullptr;
}

Ship^ Character::setShip(TypeID typeID)
{
	auto ship = dynamic_cast<eufe::Character*>(item_)->setShip(typeID);
	return ship ? gcnew Ship(ship) : nullptr;
}

Skill^ Character::getSkill(TypeID typeID)
{
	auto skill = dynamic_cast<eufe::Character*>(item_)->getSkill(typeID);
	return skill ? gcnew Skill(skill) : nullptr;
}
		
bool Character::emptyImplantSlot(int slot)
{
	return dynamic_cast<eufe::Character*>(item_)->emptyImplantSlot(slot);
}

bool Character::emptyBoosterSlot(int slot)
{
	return dynamic_cast<eufe::Character*>(item_)->emptyBoosterSlot(slot);
}

Implant^ Character::getImplant(int slot)
{
	auto implant = dynamic_cast<eufe::Character*>(item_)->getImplant(slot);
	return implant ? gcnew Implant(implant) : nullptr;
}

Booster^ Character::getBooster(int slot)
{
	auto booster = dynamic_cast<eufe::Character*>(item_)->getBooster(slot);
	return booster ? gcnew Booster(booster) : nullptr;
}

Implant^ Character::addImplant(eufe::TypeID typeID)
{
	auto implant = dynamic_cast<eufe::Character*>(item_)->addImplant(typeID);
	return implant ? gcnew Implant(implant) : nullptr;
}

Booster^ Character::addBooster(TypeID typeID)
{
	auto booster = dynamic_cast<eufe::Character*>(item_)->addBooster(typeID);
	return booster ? gcnew Booster(booster) : nullptr;
}

void Character::removeImplant(Implant^ implant)
{
	dynamic_cast<eufe::Character*>(item_)->removeImplant(dynamic_cast<eufe::Implant*>(implant->getItem()));
}

void Character::removeBooster(Booster^ booster)
{
	dynamic_cast<eufe::Character*>(item_)->removeBooster(dynamic_cast<eufe::Booster*>(booster->getItem()));
}

array<Implant^>^ Character::getImplants()
{
	auto implants = dynamic_cast<eufe::Character*>(item_)->getImplants();
	array<Implant^>^ arr = gcnew array<Implant^> (implants.size());

	int i = 0;
	for (auto implant: implants)
		arr[i++] = gcnew Implant(implant);
	return arr;
}

array<Booster^>^ Character::getBoosters()
{
	auto boosters = dynamic_cast<eufe::Character*>(item_)->getBoosters();
	array<Booster^>^ arr = gcnew array<Booster^> (boosters.size());

	int i = 0;
	for (auto booster: boosters)
		arr[i++] = gcnew Booster(booster);
	return arr;
}

void Character::setCharacterName(String^ characterName)
{
	pin_ptr<const wchar_t> wstr = PtrToStringChars(characterName);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((characterName->Length + 1) * 2);
	errno_t err = 0;
	char *str = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, str, sizeInBytes, wstr, sizeInBytes);
	if (err == 0)
		dynamic_cast<eufe::Character*>(item_)->setCharacterName(str);
	free(str);
}

String^ Character::getCharacterName()
{
	return gcnew String(dynamic_cast<eufe::Character*>(item_)->getCharacterName());
}

void Character::setSkillLevels(Dictionary<TypeID, int>^ levels)
{
	std::map<eufe::TypeID, int> levelsMap;
	cliext::collection_adapter<IDictionary<TypeID, int>> levelsAdapter(levels);
	for each (KeyValuePair<eufe::TypeID, int>^ pair in levelsAdapter)
		levelsMap[pair->Key] = pair->Value;

	dynamic_cast<eufe::Character*>(item_)->setSkillLevels(levelsMap);
}

void Character::setAllSkillsLevel(int level)
{
	dynamic_cast<eufe::Character*>(item_)->setAllSkillsLevel(level);
}

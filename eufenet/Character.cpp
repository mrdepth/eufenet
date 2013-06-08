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
	eufe::Ship* ship = dynamic_cast<eufe::Character*>(item_)->getShip();
	return ship ? gcnew Ship(ship) : nullptr;
}

Ship^ Character::setShip(TypeID typeID)
{
	eufe::Ship* ship = dynamic_cast<eufe::Character*>(item_)->setShip(typeID);
	return ship ? gcnew Ship(ship) : nullptr;
}

Skill^ Character::getSkill(TypeID typeID)
{
	eufe::Skill* skill = dynamic_cast<eufe::Character*>(item_)->getSkill(typeID);
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
	eufe::Implant* implant = dynamic_cast<eufe::Character*>(item_)->getImplant(slot);
	return implant ? gcnew Implant(implant) : nullptr;
}

Booster^ Character::getBooster(int slot)
{
	eufe::Booster* booster = dynamic_cast<eufe::Character*>(item_)->getBooster(slot);
	return booster ? gcnew Booster(booster) : nullptr;
}

Implant^ Character::addImplant(eufe::TypeID typeID)
{
	eufe::Implant* implant = dynamic_cast<eufe::Character*>(item_)->addImplant(typeID);
	return implant ? gcnew Implant(implant) : nullptr;
}

Booster^ Character::addBooster(TypeID typeID)
{
	eufe::Booster* booster = dynamic_cast<eufe::Character*>(item_)->addBooster(typeID);
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
	eufe::ImplantsList implants = dynamic_cast<eufe::Character*>(item_)->getImplants();
	array<Implant^>^ arr = gcnew array<Implant^> (implants.size());

	int n = 0;

	eufe::ImplantsList::const_iterator i, end = implants.end();
	for (i = implants.begin(); i != end; i++)
		arr[n++] = gcnew Implant(*i);
	return arr;
}

array<Booster^>^ Character::getBoosters()
{
	eufe::BoostersList boosters = dynamic_cast<eufe::Character*>(item_)->getBoosters();
	array<Booster^>^ arr = gcnew array<Booster^> (boosters.size());

	int n = 0;

	eufe::BoostersList::const_iterator i, end = boosters.end();
	for (i = boosters.begin(); i != end; i++)
		arr[n++] = gcnew Booster(*i);
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

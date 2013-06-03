#pragma once
#include "item.h"
#include "Ship.h"
#include "Skill.h"
#include "Implant.h"
#include "Booster.h"

using namespace System;
using namespace System::Collections::Generic;

namespace eufenet {

	public ref class Character: public Item
	{
	public:
		Character(const Character% other);
		Character(eufe::Character* character);

		Ship^ getShip();
		Ship^ setShip(TypeID typeID);

		Skill^ getSkill(TypeID typeID);
		
		bool emptyImplantSlot(int slot);
		bool emptyBoosterSlot(int slot);
		Implant^ getImplant(int slot);
		Booster^ getBooster(int slot);
		Implant^ addImplant(TypeID typeID);
		Booster^ addBooster(TypeID typeID);
		void removeImplant(Implant^ implant);
		void removeBooster(Booster^ booster);
		array<Implant^>^ getImplants();
		array<Booster^>^ getBoosters();
		
		void setCharacterName(String^ characterName);
		String^ getCharacterName();
		
		void setSkillLevels(Dictionary<TypeID, int>^ levels);
		void setAllSkillsLevel(int level);
	};

}
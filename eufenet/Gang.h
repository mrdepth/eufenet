#pragma once
#include "item.h"
#include "Character.h"

namespace eufenet {

	public ref class Gang: public Item
	{
	public:
		Gang(const Gang% other);
		Gang(eufe::Gang* gang);

		array<Character^>^ getPilots();
		Character addPilot();
		void removePilot(Character% character);
		
		Character getFleetBooster();
		Character getWingBooster();
		Character getSquadBooster();
		void setFleetBooster(Character% fleetBooster);
		void setWingBooster(Character% wingBooster);
		void setSquadBooster(Character% squadBooster);
		void removeFleetBooster();
		void removeWingBooster();
		void removeSquadBooster();
	};

}
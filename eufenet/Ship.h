#pragma once
#include "item.h"
#include "Module.h"
#include "Drone.h"
#include "DamagePattern.h"
#include "Resistances.h"
#include "Tank.h"
#include "HitPoints.h"

namespace eufenet {

	public ref class Ship: public Item
	{
	public:
		enum class ScanType
		{
			SCAN_TYPE_RADAR,
			SCAN_TYPE_LADAR,
			SCAN_TYPE_MAGNETOMETRIC,
			SCAN_TYPE_GRAVIMETRIC,
			SCAN_TYPE_MULTISPECTRAL
		};

		Ship(const Ship% other);
		Ship(eufe::Ship* ship);
		
		Module^ addModule(TypeID typeID);
		array<Module^>^ addModules(array<TypeID>^ typeIDs);
		Module^ replaceModule(Module^ oldModule, TypeID typeID);
		void removeModule(Module^ module);
		
		Drone^ addDrone(TypeID typeID);
		void removeDrone(Drone^ drone);
		
		array<Module^>^ getModules();
		array<Module^>^ getModules(Module::Slot slot);
		array<Drone^>^  getDrones();
		
		void setDamagePattern(DamagePattern^ damagePattern);
		
		//Calculations
		
		int getNumberOfSlots(Module::Slot slot);
		int getFreeSlots(Module::Slot slot);
		int getUsedSlots(Module::Slot slot);
		int getNumberOfHardpoints(Module::Hardpoint hardpoint);
		int getFreeHardpoints(Module::Hardpoint hardpoint);
		int getUsedHardpoints(Module::Hardpoint hardpoint);
		
		float getCalibrationUsed();
		float getTotalCalibration();
		float getPowerGridUsed();
		float getTotalPowerGrid();
		float getCpuUsed();
		float getTotalCpu();
		float getDroneBandwidthUsed();
		float getTotalDroneBandwidth();
		float getDroneBayUsed();
		float getTotalDroneBay();

		
		//Capacitor
		float getCapCapacity();
		bool isCapStable();
		float getCapLastsTime();
		float getCapStableLevel();
		float getCapUsed();
		float getCapRecharge();
		
		//Tank
		Resistances^ getResistances();
		Tank^ getTank();
		Tank^ getEffectiveTank();
		Tank^ getSustainableTank();
		Tank^ getEffectiveSustainableTank();
		
		HitPoints^ getHitPoints();
		HitPoints^ getEffectiveHitPoints();
		
		float getShieldRecharge();

		//DPS
		float getWeaponDps();
		float getWeaponVolley();
		float getDroneDps();
		float getDroneVolley();
		
		//Mobility
		float getAlignTime();
		float getWarpSpeed();
		float getMaxWarpDistance();
		float getVelocity();
		float getSignatureRadius();
		
		//Targeting
		int getMaxTargets();
		float getMaxTargetRange();
		float getScanStrength();
		ScanType getScanType();
		float getProbeSize();
		float getScanResolution();
		
		//Drones
		int getMaxActiveDrones();
		int getActiveDrones();
	};

};
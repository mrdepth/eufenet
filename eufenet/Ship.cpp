#include "stdafx.h"
#include "Ship.h"

using namespace eufenet;

Ship::Ship(const Ship% other): Item(other)
{
}

Ship::Ship(eufe::Ship* ship): Item(ship)
{
}


Module^ Ship::addModule(TypeID typeID)
{
	eufe::Module*  module = dynamic_cast<eufe::Ship*>(item_)->addModule(typeID).get();
	return module ? gcnew Module(module) : nullptr;
}

array<Module^>^ Ship::addModules(array<TypeID>^ typeIDs)
{
	std::list<TypeID> list;
	for each (TypeID typeID in typeIDs)
		list.push_back(typeID);

	eufe::ModulesList modules = dynamic_cast<eufe::Ship*>(item_)->addModules(list);
	array<Module^>^ arr = gcnew array<Module^> (modules.size());

	int n = 0;

	for (auto i: modules)
		arr[n++] = i ? gcnew Module(i.get()) : nullptr;
	return arr;
}

Module^ Ship::replaceModule(Module^ oldModule, TypeID typeID)
{
	eufe::Module* module = dynamic_cast<eufe::Ship*>(item_)->replaceModule(dynamic_cast<eufe::Module*>(oldModule->getItem())->shared_from_this(), typeID).get();
	return module ? gcnew Module(module) : nullptr;
}

void Ship::removeModule(Module^ module)
{
	dynamic_cast<eufe::Ship*>(item_)->removeModule(dynamic_cast<eufe::Module*>(module->getItem())->shared_from_this());
}

Drone^ Ship::addDrone(TypeID typeID)
{
	eufe::Drone* drone = dynamic_cast<eufe::Ship*>(item_)->addDrone(typeID).get();
	return drone ? gcnew Drone(drone) : nullptr;
}

void Ship::removeDrone(Drone^ drone)
{
	dynamic_cast<eufe::Ship*>(item_)->removeDrone(dynamic_cast<eufe::Drone*>(drone->getItem())->shared_from_this());
}

array<Module^>^ Ship::getModules()
{
	eufe::ModulesList modules = dynamic_cast<eufe::Ship*>(item_)->getModules();
	array<Module^>^ arr = gcnew array<Module^> (modules.size());

	int n = 0;

	for (auto i: modules)
		arr[n++] = i ? gcnew Module(i.get()) : nullptr;
	return arr;
}

array<Module^>^ Ship::getModules(Module::Slot slot)
{
	eufe::ModulesList modules;
	dynamic_cast<eufe::Ship*>(item_)->getModules(static_cast<eufe::Module::Slot>(slot), std::inserter(modules, modules.begin()));
	array<Module^>^ arr = gcnew array<Module^> (modules.size());

	int n = 0;

	for (auto i : modules)
		arr[n++] = i ? gcnew Module(i.get()) : nullptr;
	return arr;
}

array<Drone^>^  Ship::getDrones()
{
	eufe::DronesList drones = dynamic_cast<eufe::Ship*>(item_)->getDrones();
	array<Drone^>^ arr = gcnew array<Drone^> (drones.size());

	int n = 0;

	for (auto i : drones)
		arr[n++] = i ? gcnew Drone(i.get()) : nullptr;
	return arr;
}

		
void Ship::setDamagePattern(DamagePattern^ damagePattern)
{
	dynamic_cast<eufe::Ship*>(item_)->setDamagePattern(damagePattern->getDamagePattern());
}

		
//Calculations
		
int Ship::getNumberOfSlots(Module::Slot slot)
{
	return dynamic_cast<eufe::Ship*>(item_)->getNumberOfSlots(static_cast<eufe::Module::Slot>(slot));
}

int Ship::getFreeSlots(Module::Slot slot)
{
	return dynamic_cast<eufe::Ship*>(item_)->getFreeSlots(static_cast<eufe::Module::Slot>(slot));
}

int Ship::getUsedSlots(Module::Slot slot)
{
	return dynamic_cast<eufe::Ship*>(item_)->getUsedSlots(static_cast<eufe::Module::Slot>(slot));
}

int Ship::getNumberOfHardpoints(Module::Hardpoint hardpoint)
{
	return dynamic_cast<eufe::Ship*>(item_)->getNumberOfHardpoints(static_cast<eufe::Module::Hardpoint>(hardpoint));
}

int Ship::getFreeHardpoints(Module::Hardpoint hardpoint)
{
	return dynamic_cast<eufe::Ship*>(item_)->getFreeHardpoints(static_cast<eufe::Module::Hardpoint>(hardpoint));
}

int Ship::getUsedHardpoints(Module::Hardpoint hardpoint)
{
	return dynamic_cast<eufe::Ship*>(item_)->getUsedHardpoints(static_cast<eufe::Module::Hardpoint>(hardpoint));
}

		
float Ship::getCalibrationUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCalibrationUsed();
}

float Ship::getTotalCalibration()
{
	return dynamic_cast<eufe::Ship*>(item_)->getTotalCalibration();
}

float Ship::getPowerGridUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getPowerGridUsed();
}

float Ship::getTotalPowerGrid()
{
	return dynamic_cast<eufe::Ship*>(item_)->getTotalPowerGrid();
}

float Ship::getCpuUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCpuUsed();
}

float Ship::getTotalCpu()
{
	return dynamic_cast<eufe::Ship*>(item_)->getTotalCpu();
}

float Ship::getDroneBandwidthUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getDroneBandwidthUsed();
}

float Ship::getTotalDroneBandwidth()
{
	return dynamic_cast<eufe::Ship*>(item_)->getTotalDroneBandwidth();
}

float Ship::getDroneBayUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getDroneBayUsed();
}

float Ship::getTotalDroneBay()
{
	return dynamic_cast<eufe::Ship*>(item_)->getTotalDroneBay();
}


		
//Capacitor
float Ship::getCapCapacity()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCapCapacity();
}

bool Ship::isCapStable()
{
	return dynamic_cast<eufe::Ship*>(item_)->isCapStable();
}

float Ship::getCapLastsTime()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCapLastsTime();
}

float Ship::getCapStableLevel()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCapStableLevel();
}

float Ship::getCapUsed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCapUsed();
}

float Ship::getCapRecharge()
{
	return dynamic_cast<eufe::Ship*>(item_)->getCapRecharge();
}

		
//Tank
Resistances^ Ship::getResistances()
{
	return gcnew Resistances(dynamic_cast<eufe::Ship*>(item_)->getResistances());
}

Tank^ Ship::getTank()
{
	return gcnew Tank(dynamic_cast<eufe::Ship*>(item_)->getTank());
}

Tank^ Ship::getEffectiveTank()
{
	return gcnew Tank(dynamic_cast<eufe::Ship*>(item_)->getEffectiveTank());
}

Tank^ Ship::getSustainableTank()
{
	return gcnew Tank(dynamic_cast<eufe::Ship*>(item_)->getSustainableTank());
}

Tank^ Ship::getEffectiveSustainableTank()
{
	return gcnew Tank(dynamic_cast<eufe::Ship*>(item_)->getEffectiveSustainableTank());
}

		
HitPoints^ Ship::getHitPoints()
{
	return gcnew HitPoints(dynamic_cast<eufe::Ship*>(item_)->getHitPoints());
}

HitPoints^ Ship::getEffectiveHitPoints()
{
	return gcnew HitPoints(dynamic_cast<eufe::Ship*>(item_)->getEffectiveHitPoints());
}

		
float Ship::getShieldRecharge()
{
	return dynamic_cast<eufe::Ship*>(item_)->getShieldRecharge();
}


//DPS
float Ship::getWeaponDps()
{
	return dynamic_cast<eufe::Ship*>(item_)->getWeaponDps();
}

float Ship::getWeaponVolley()
{
	return dynamic_cast<eufe::Ship*>(item_)->getWeaponVolley();
}

float Ship::getDroneDps()
{
	return dynamic_cast<eufe::Ship*>(item_)->getDroneDps();
}

float Ship::getDroneVolley()
{
	return dynamic_cast<eufe::Ship*>(item_)->getDroneVolley();
}

		
//Mobility
float Ship::getAlignTime()
{
	return dynamic_cast<eufe::Ship*>(item_)->getAlignTime();
}

float Ship::getWarpSpeed()
{
	return dynamic_cast<eufe::Ship*>(item_)->getWarpSpeed();
}

float Ship::getMaxWarpDistance()
{
	return dynamic_cast<eufe::Ship*>(item_)->getMaxWarpDistance();
}

float Ship::getVelocity()
{
	return dynamic_cast<eufe::Ship*>(item_)->getVelocity();
}

float Ship::getSignatureRadius()
{
	return dynamic_cast<eufe::Ship*>(item_)->getSignatureRadius();
}

float Ship::getMass()
{
	return dynamic_cast<eufe::Ship*>(item_)->getMass();
}

float Ship::getVolume()
{
	return dynamic_cast<eufe::Ship*>(item_)->getVolume();
}

float Ship::getAgility()
{
	return dynamic_cast<eufe::Ship*>(item_)->getAgility();
}

float Ship::getMaxVelocityInOrbit(float r)
{
	return dynamic_cast<eufe::Ship*>(item_)->getMaxVelocityInOrbit(r);
}

float Ship::getOrbitRadiusWithTransverseVelocity(float v)
{
	return dynamic_cast<eufe::Ship*>(item_)->getOrbitRadiusWithTransverseVelocity(v);
}

float Ship::getOrbitRadiusWithAngularVelocity(float v)
{
	return dynamic_cast<eufe::Ship*>(item_)->getOrbitRadiusWithAngularVelocity(v);
}


//Targeting
int Ship::getMaxTargets()
{
	return dynamic_cast<eufe::Ship*>(item_)->getMaxTargets();
}

float Ship::getMaxTargetRange()
{
	return dynamic_cast<eufe::Ship*>(item_)->getMaxTargetRange();
}

float Ship::getScanStrength()
{
	return dynamic_cast<eufe::Ship*>(item_)->getScanStrength();
}

Ship::ScanType Ship::getScanType()
{
	return static_cast<Ship::ScanType>(dynamic_cast<eufe::Ship*>(item_)->getScanType());
}

float Ship::getProbeSize()
{
	return dynamic_cast<eufe::Ship*>(item_)->getProbeSize();
}

float Ship::getScanResolution()
{
	return dynamic_cast<eufe::Ship*>(item_)->getScanResolution();
}

		
//Drones
int Ship::getMaxActiveDrones()
{
	return dynamic_cast<eufe::Ship*>(item_)->getMaxActiveDrones();
}

int Ship::getActiveDrones()
{
	return dynamic_cast<eufe::Ship*>(item_)->getActiveDrones();
}

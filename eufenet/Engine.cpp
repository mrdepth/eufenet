#include "stdafx.h"
#include "Engine.h"

using namespace eufenet;

Engine::Engine(SqlConnector^ sqlConnector): sqlConnector_(sqlConnector)
{
	engine_ = new eufe::Engine(sqlConnector->getSqlConnector());
}


Engine::~Engine(void)
{
	delete engine_;
	delete sqlConnector_;
}

Area^ Engine::setArea(TypeID typeID)
{
	return gcnew Area(engine_->setArea(typeID));
}

ControlTower^ Engine::setControlTower(TypeID typeID)
{
	return gcnew ControlTower(engine_->setControlTower(typeID));
}

void Engine::clearArea()
{
	engine_->clearArea();
}

Gang^ Engine::getGang()
{
	return gcnew Gang(engine_->getGang());
}

Area^ Engine::getArea()
{
	return gcnew Area(engine_->getArea());
}

ControlTower^ Engine::getControlTower()
{
	return gcnew ControlTower(engine_->getControlTower());
}
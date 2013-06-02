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

Area Engine::setArea(TypeID typeID)
{
	return Area(engine_->setArea(typeID));
}

ControlTower Engine::setControlTower(TypeID typeID)
{
	return ControlTower(engine_->setControlTower(typeID));
}

void Engine::clearArea()
{
	engine_->clearArea();
}

Gang Engine::getGang()
{
	return Gang(engine_->getGang());
}

Area Engine::getArea()
{
	return Area(engine_->getArea());
}

ControlTower Engine::getControlTower()
{
	return ControlTower(engine_->getControlTower());
}
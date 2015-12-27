#include "stdafx.h"
#include "Engine.h"

using namespace eufenet;

Engine::Engine(SqlConnector^ sqlConnector)
{
	engine_ = new eufe::Engine(sqlConnector->getSqlConnector());
}


Engine::~Engine(void)
{
	delete engine_;
}

Area^ Engine::setArea(TypeID typeID)
{
	return gcnew Area(engine_->setArea(typeID).get());
}

ControlTower^ Engine::setControlTower(TypeID typeID)
{
	return gcnew ControlTower(engine_->setControlTower(typeID).get());
}

void Engine::clearArea()
{
	engine_->clearArea();
}

Gang^ Engine::getGang()
{
	return gcnew Gang(engine_->getGang().get());
}

Area^ Engine::getArea()
{
	return gcnew Area(engine_->getArea().get());
}

ControlTower^ Engine::getControlTower()
{
	return gcnew ControlTower(engine_->getControlTower().get());
}

void Engine::beginUpdates()
{
	engine_->beginUpdates();
}

void Engine::commitUpdates()
{
	engine_->commitUpdates();
}

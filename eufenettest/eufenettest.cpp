// eufenettest.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace eufenet;

int main(array<System::String ^> ^args)
{
	Engine^ engine = gcnew Engine(gcnew SqliteConnector("e:\\Programing\\dbinit\\eufe.sqlite "));
	Character character = engine->getGang().addPilot();
	Ship ship = character.setShip(645);

	Resistances res = ship.getResistances();
	Console::WriteLine(L"Hello World");
    return 0;
}

#pragma once
#include <eufe.h>
#include "SqlConnector.h"
#include "ControlTower.h"
#include "Area.h"
#include "Gang.h"

namespace eufenet {

	public ref class Engine
	{
	public:
		Engine(SqlConnector^ sqlConnector);
		virtual ~Engine(void);
		Area^ setArea(TypeID typeID);
		ControlTower^ setControlTower(TypeID typeID);
		void clearArea();
		Gang^ getGang();
		Area^ getArea();
		ControlTower^ getControlTower();

		void beginUpdates();
		void commitUpdates();

	private:
		eufe::Engine* engine_;
	};

}
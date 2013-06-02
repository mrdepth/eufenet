#pragma once
#include "SqlConnector.h"

namespace eufenet {
	public ref class SqliteConnector: public SqlConnector
	{
	public:
		SqliteConnector(System::String^ databasePath);
	};
}
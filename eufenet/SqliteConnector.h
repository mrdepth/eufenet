#pragma once
#include "SqlConnector.h"

namespace eufenet {
	public ref class SqliteConnector: public SqlConnector
	{
	public:
		SqliteConnector(System::String^ databasePath);
		virtual std::shared_ptr<eufe::SqlConnector> getSqlConnector() override;
	private:
		System::String^ databasePath_;
	};
}
#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class SqlConnector abstract
	{
	public:
		SqlConnector(void);
		virtual ~SqlConnector(void);
		virtual std::shared_ptr<eufe::SqlConnector> getSqlConnector() = 0;
	};

}
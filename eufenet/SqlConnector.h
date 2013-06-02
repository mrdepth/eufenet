#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class SqlConnector
	{
	public:
		SqlConnector(void);
		virtual ~SqlConnector(void);
		eufe::SqlConnector* getSqlConnector();
	protected:
		eufe::SqlConnector* sqlConnector_;
	};

}
#include "stdafx.h"
#include "SqlConnector.h"

using namespace eufenet;

SqlConnector::SqlConnector(void)
{
}


SqlConnector::~SqlConnector(void)
{
}

eufe::SqlConnector* SqlConnector::getSqlConnector()
{
	return sqlConnector_;
}
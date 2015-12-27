#include "stdafx.h"
#include "SqliteConnector.h"
#include <vcclr.h>

using namespace eufenet;

SqliteConnector::SqliteConnector(System::String^ databasePath) : databasePath_(databasePath)
{

}

std::shared_ptr<eufe::SqlConnector> eufenet::SqliteConnector::getSqlConnector()
{
	pin_ptr<const wchar_t> wstr = PtrToStringChars(databasePath_);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((databasePath_->Length + 1) * 2);
	errno_t err = 0;
	char *str = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, str, sizeInBytes, wstr, sizeInBytes);
	std::shared_ptr<eufe::SqlConnector> sqlConnector;
	if (err == 0)
		sqlConnector = std::make_shared<eufe::SqliteConnector>(str);
	free(str);
	return sqlConnector;
}


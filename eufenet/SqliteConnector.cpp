#include "stdafx.h"
#include "SqliteConnector.h"
#include <vcclr.h>

using namespace eufenet;

SqliteConnector::SqliteConnector(System::String^ databasePath)
{
	pin_ptr<const wchar_t> wstr = PtrToStringChars(databasePath);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((databasePath->Length + 1) * 2);
	errno_t err = 0;
	char *str = (char *)malloc(sizeInBytes);

	err = wcstombs_s(&convertedChars, str, sizeInBytes, wstr, sizeInBytes);
	if (err == 0)
		sqlConnector_ = new eufe::SqliteConnector(str);
	free(str);
}


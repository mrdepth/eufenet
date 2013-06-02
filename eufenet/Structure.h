#pragma once
#include "module.h"

namespace eufenet {

	public ref class Structure: public Module
	{
	public:
		Structure(const Structure% other);
		Structure(eufe::Structure* structure);
		virtual ~Structure(void);
	};

}
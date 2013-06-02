#pragma once
#include "item.h"

namespace eufenet {

	public ref class Area: public Item
	{
	public:
		Area(const Area% other);
		Area(eufe::Area* area);
		virtual ~Area(void);
	};

}

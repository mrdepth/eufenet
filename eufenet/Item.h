#pragma once
#include <eufe.h>
#include "types.h"
#include "ItemAttribute.h"

namespace eufenet {

	public ref class Item
	{
	public:
		Item(const Item% other);
		Item(eufe::Item* item);
		
		TypeID getTypeID();
		TypeID getGroupID();
		TypeID getCategoryID();
		ItemAttribute getAttribute(TypeID attributeID);
		eufe::Item* getItem();
	protected:
		eufe::Item* item_;
	};

}
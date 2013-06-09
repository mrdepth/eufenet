#pragma once
#include <eufe.h>
#include "types.h"
#include "ItemAttribute.h"

using namespace System;

namespace eufenet {

	public ref class Item
	{
	public:
		Item(const Item% other);
		Item(eufe::Item* item);
		
		TypeID getTypeID();
		TypeID getGroupID();
		TypeID getCategoryID();
		ItemAttribute^ getAttribute(TypeID attributeID);
		eufe::Item* getItem();
		String^ getTypeName();
		String^ getGroupName();
	protected:
		eufe::Item* item_;
	};

}
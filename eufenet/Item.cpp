#include "stdafx.h"
#include "Item.h"

using namespace eufenet;

Item::Item(const Item% other): item_(other.item_)
{
}

Item::Item(eufe::Item* item): item_(item)
{
}

TypeID Item::getTypeID()
{
	return item_->getTypeID();
}

TypeID Item::getGroupID()
{
	return item_->getGroupID();
}

TypeID Item::getCategoryID()
{
	return item_->getCategoryID();
}

ItemAttribute Item::getAttribute(TypeID attributeID)
{
	return ItemAttribute(item_->getAttribute(attributeID));
}

eufe::Item* Item::getItem()
{
	return item_;
}
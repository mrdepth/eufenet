#include "stdafx.h"
#include "ItemAttribute.h"

using namespace eufenet;

ItemAttribute::ItemAttribute(const ItemAttribute% other): attribute_(other.attribute_)
{
}

ItemAttribute::ItemAttribute(eufe::Attribute* attribute): attribute_(attribute)
{
}

float ItemAttribute::getValue()
{
	return attribute_->getValue();
}

bool ItemAttribute::isStackable()
{
	return attribute_->isStackable();
}

bool ItemAttribute::highIsGood()
{
	return attribute_->highIsGood();
}

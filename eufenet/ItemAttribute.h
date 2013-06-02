#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class ItemAttribute
	{
	public:
		ItemAttribute(const ItemAttribute% other);
		ItemAttribute(eufe::Attribute* attribute);

		float getValue();
		bool isStackable();
		bool highIsGood();
	private:
		eufe::Attribute* attribute_;
	};

}
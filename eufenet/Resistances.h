#pragma once
#include <eufe.h>

namespace eufenet {

	public ref class Resistances
	{
	public:
		ref class Layer {
		public:
			Layer();
			Layer(const Layer% other);
			Layer(const eufe::ResistancesLayer& layer);
			Layer% operator = (const Layer% other);
			float em;
			float explosive;
			float kinetic;
			float thermal;
		} armor, hull, shield;

		Resistances(const Resistances% other);
		Resistances(const eufe::Resistances& resistances);
	};

}

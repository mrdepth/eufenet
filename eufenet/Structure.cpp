#include "stdafx.h"
#include "Structure.h"

using namespace eufenet;

Structure::Structure(const Structure% other): Module(other)
{
}

Structure::Structure(eufe::Structure* structure): Module(structure)
{
}


Structure::~Structure(void)
{
}

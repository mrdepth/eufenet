#include "stdafx.h"
#include "Skill.h"

using namespace eufenet;

Skill::Skill(const Skill% other): Item(other)
{
}

Skill::Skill(eufe::Skill* skill): Item(skill)
{
}

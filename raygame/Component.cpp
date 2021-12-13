#include "Component.h"

void Component::AssignOwner(Actor* owner)
{
	if (getOwner())
		return;

	m_owner = owner;
}

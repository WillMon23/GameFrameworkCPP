#include "Enemy.h"

Enemy::Enemy(int x, int y, const char* name) : Actor::Actor(x, y, name)
{
	m_moveComp = new MoveComponent(this, 'E');
}

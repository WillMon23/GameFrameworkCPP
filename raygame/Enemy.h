#pragma once
#include "Actor.h"
#include "MoveComponent.h"
class Enemy : Actor
{
public:
	Enemy();
	~Enemy();
	Enemy(int x, int y, const char* name);

	void start() override;
	void update(float deltaTime) override;

private:
	MoveComponent* m_moveComp; 
};


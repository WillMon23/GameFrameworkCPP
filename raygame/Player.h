#pragma once
#include "Actor.h"
#include "InputComponent.h"

class Player : Actor
{
public:
	Player() {};
	Player(float x, float y, const char* name);
	~Player();

	void start() override;

private:
	InputComponent* m_inputComp;
};


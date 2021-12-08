#pragma once
#include "Transform2D.h"
#include "Component.h"
#include <iostream>

class MoveComponent : Component
{
public: 
	MoveComponent() :Component::Component() {};
	MoveComponent(Actor* owner, const char* name);
	~MoveComponent();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:
		MathLibrary::Vector2* m_volocity;
		MathLibrary::Vector2* m_position;
		const int* m_maxSpeed;


};


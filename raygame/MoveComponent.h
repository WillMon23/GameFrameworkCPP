#pragma once
#include "Transform2D.h"
#include "Component.h"
#include <iostream>


class MoveComponent : Component
{
public: 
	MoveComponent();
	MoveComponent(Actor* owner, const char* name);
	~MoveComponent();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	MathLibrary::Vector2 getVolocity() { return m_volocity; };

	

private:
	MathLibrary::Vector2 m_volocity;
	MathLibrary::Vector2 m_position;
	int m_maxSpeed;


};


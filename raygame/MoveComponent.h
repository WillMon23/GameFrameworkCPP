#pragma once
#include "Component.h"
#include <Vector2.h>



class MoveComponent : public Component
{
public: 
	MoveComponent(const char* name = "MoveComponenet") : Component::Component(name) {};
	~MoveComponent() {};
	//Inharets from component class 
	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	
	//Gets m
	MathLibrary::Vector2 getVolocity() { return m_velocity; };
	void setVolovity(MathLibrary::Vector2 velocity) { m_velocity = velocity; };

	float getMaxSpeed() { return m_maxSpeed; };
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }
private:
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_position;
	int m_maxSpeed;
};


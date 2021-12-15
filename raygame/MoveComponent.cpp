#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include <iostream>



void MoveComponent::start()
{
	//m_velocity = MathLibrary::Vector2(0, 1);
}

void MoveComponent::update(float deltaTime)
{
	m_position = getOwner()->getTransform()->getLocalPosition() + getVolocity() * deltaTime;

	if (m_velocity.getMagnitude() > m_maxSpeed)
		m_velocity = m_velocity.getNormalized() * m_maxSpeed * deltaTime;

	getOwner()->getTransform()->setLocalPosition(m_position);
}

void MoveComponent::draw()
{
	std::cout << "Name: " << getOwner()->getName() << " X - axis: " << m_position.x << " Y - axis: " << m_position.y << std::endl;
	
}

#include "MoveComponent.h"
#include <Vector2.h>
#include "Actor.h"

MoveComponent::MoveComponent(Actor* owner, const char* name) :Component::Component(owner, name)
{
	m_position = owner->getTransform()->getLocalPosition();
	m_maxSpeed = 0;
}

MoveComponent::~MoveComponent()
{
	delete &m_volocity;
	delete &m_maxSpeed;
	delete &m_position;
}

void MoveComponent::start()
{
	m_volocity = MathLibrary::Vector2(0, 1);
}

void MoveComponent::update(float deltaTime)
{
	if (m_volocity.getMagnitude() > m_maxSpeed)
		m_volocity = m_volocity.getNormalized() * m_maxSpeed * deltaTime;

	m_position = m_position + m_volocity;
	//m_position = m_position + (m_volocity * m_maxSpeed * deltaTime);
	
}

void MoveComponent::draw()
{
	std::cout << "Name: " << getOwener()->getName() << "Position X: " << m_position.x << "Position Y: " << m_position.y;
}

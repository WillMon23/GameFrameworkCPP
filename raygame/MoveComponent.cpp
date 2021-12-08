#include "MoveComponent.h"
#include <Vector2.h>
#include "Actor.h"

MoveComponent::MoveComponent(Actor* owner, const char* name) :Component::Component(owner, name)
{
	m_position = &owner->getTransform()->getLocalPosition();
}

MoveComponent::~MoveComponent()
{
	delete m_volocity;
	delete m_maxSpeed;
}

void MoveComponent::start()
{
	m_volocity = new MathLibrary::Vector2(0, 1);
}

void MoveComponent::update(float deltaTime)
{
	m_position = m_position + m_volocity;
	
}

void MoveComponent::draw()
{
	std::cout << "Name: " << getOwener()->getName() << "Position X : " << m_position.
}

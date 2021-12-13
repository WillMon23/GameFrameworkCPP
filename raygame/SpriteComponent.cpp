#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(char path[])
{
	m_texture = LoadTexture(path);

	m_owenrTransform = getOwner()->getTransform();

}


void SpriteComponent::draw()
{
	char component = 'M';

	m_owenrTransform = getOwner()->getTransform();

	float widthM00 = m_owenrTransform->getLocalMatrix()->m00;
	float widthM10 = m_owenrTransform->getLocalMatrix()->m10;

	MathLibrary::Vector2 width = MathLibrary::Vector2(widthM00, widthM10);
		
	float hightM01 = m_owenrTransform->getLocalMatrix()->m01;
	float hightM11 = m_owenrTransform->getLocalMatrix()->m11;

	MathLibrary::Vector2 hight = MathLibrary::Vector2(hightM01, hightM11);

	m_width = round((int)width.getMagnitude());
	m_hight = round((int)hight.getMagnitude());

	MathLibrary::Vector2* position;

	
	if (getOwner()->getComponent(&component) != nullptr)
		position = getOwner()->getComponent(&component)->getLocation();
	else
		position = new MathLibrary::Vector2(m_owenrTransform->getLocalMatrix->m02, m_owenrTransform->getLocalMatrix->m12);

	MathLibrary::Vector2* forward = new MathLibrary::Vector2(m_owenrTransform->getLocalMatrix->m00, m_owenrTransform->getLocalMatrix->m10);
	MathLibrary::Vector2* up = new MathLibrary::Vector2(m_owenrTransform->getLocalMatrix->m01, m_owenrTransform->getLocalMatrix->m11);

	position -= forward->normalize * m_width / 2;
	position -= up->normalize * m_hight / 2;

	float rotation = atan2f(m_owenrTransform->getLocalMatrix()->m10, m_owenrTransform->getLocalMatrix()->m00);

	Vector2* positionVec2 = new Vector2(position->x,position->y);
	
	DrawTextureEx(m_texture, (rotation * 180 / PI), 1, Color.WHITE);
}

void SpriteComponent::update(float deltaTime)
{
	m_texture.height = m_hight;
	m_texture.width = m_width;
}




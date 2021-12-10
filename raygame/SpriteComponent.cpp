#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(char path[])
{
	m_texture = LoadTexture(path);
}

void SpriteComponent::draw()
{
	setWidth(round(MathLibrary::Vector2(getOwener()-> )
}




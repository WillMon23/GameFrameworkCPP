#include "SpriteComponent.h"
#include <raylib.h>
#include <iostream>
#include <Vector2.h>
#include <cmath>

SpriteComponent::SpriteComponent(Texture2D* texture, const char* name) : Component::Component(name)
{
	m_texture = texture;
}

SpriteComponent::SpriteComponent(const char* path, const char* name) : Component::Component(name)
{
	m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
}

SpriteComponent::~SpriteComponent()
{
	RAYLIB_H::UnloadTexture(*m_texture);
	delete m_texture;
}

void SpriteComponent::draw()
{
	//SCALE
	//Gets the scale of the globle matrix
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	m_texture->width = m_width;
	m_texture->height = m_height;

	//POSITION
	//Gets the world position of rhe actor
	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01, getOwner()->getTransform()->getGlobalMatrix()->m11 };
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();

	//Change the position of the sprite to be in the center of the transfrom
	position = position - (forward * getWidth() / 2);
	position = position - (up.getNormalized() * getHeight() / 2);
	//Change the position of the sprite to be in the center of the transform 
	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	//ROTATION
	//Gets the value of the rotation in radians from the owners transfrom
	float rotation = atan2f(getOwner()->getTransform()->getGlobalMatrix()->m10, getOwner()->getTransform()->getGlobalMatrix()->m00);
	//Draws the sprite 
	RAYLIB_H::DrawTextureEx(*m_texture, rayPos, (float)(rotation * 180.0f / PI), 1, WHITE);
}


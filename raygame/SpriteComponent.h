#pragma once
#include "Component.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Matrix3.h>

class Texture2D;
class SpriteComponent : public Component
{
public :

	/// <param name="texture">sets the sprite image to be this</param>
	/// <param name="name">name for this componenet</param>
	SpriteComponent( Texture2D* texture, const char* name = "SpriteComponenet");

	/// <param name="path">path of the texture to load</param>
	/// <param name="name"></param>
	SpriteComponent(const char* path, const char* name = "SpriteComponenet");
	~SpriteComponent() override;

	int getWidth() { return m_width; };
	
	int getHeight() { return m_height; };

	void draw() override;

	void update(float deltaTime) override {};

private:
	int m_width;
	int m_height;

	Texture2D* m_texture;


};


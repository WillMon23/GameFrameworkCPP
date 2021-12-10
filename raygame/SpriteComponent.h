#pragma once
#include <Vector2.h>
#include "Component.h"
#include "raylib.h"
#include <cmath>

class SpriteComponent : Component
{
public :
	SpriteComponent();
	~SpriteComponent();
	SpriteComponent(char path[]);

	const int getWidth() { return m_texture.width; };
	void setWidth(const int width) { m_texture.width = width; };
	
	const int getHeight() { return m_texture.height; };
	void setHeight(const int height) { m_texture.height = height; };

	void draw() override;

private:
	Texture2D m_texture;
	Image m_image;


};


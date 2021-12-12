#pragma once
#include <Vector2.h>
#include "Component.h"
#include "raylib.h"
#include <cmath>
#include "Actor.h"
#include "Transform2D.h"

class SpriteComponent : Component
{
public :
	SpriteComponent();
	~SpriteComponent();
	SpriteComponent( char path[]);

	const int getWidth() { return m_texture.width; };
	
	const int getHeight() { return m_texture.height; };

	void draw() override;

	void update(float deltaTime) override;

private:
	int m_width;
	int m_hight;
	Texture2D m_texture;
	Transform2D* m_owenrTransform;


};


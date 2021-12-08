#pragma once
#include "Component.h"
class SpriteComponent : Component
{
public :
	SpriteComponent();
	~SpriteComponent();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void end();

private:

};


#pragma once
#include "Component.h"
#include <Vector2.h>

class Actor;

class InputComponent : Component
{
public:
	InputComponent();
	~InputComponent();
	InputComponent(Actor owner, const char* name);

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void end();



private:
};


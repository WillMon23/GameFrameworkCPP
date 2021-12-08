#pragma once
#include "Component.h"
class InputComponent : Component
{
public:
	InputComponent();
	~InputComponent();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void end();

private:
};


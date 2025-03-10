#pragma once
#include "Component.h"
#include "raylib.h"
#include <Vector2.h>

class InputComponent : public Component
{
public:
	~InputComponent() {};
	InputComponent(const char* name = "InputComponent") : Component::Component(name) {};

	MathLibrary::Vector2  getMoveAxis();

private:
	RAYLIB_H::KeyboardKey m_space_Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_P;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};


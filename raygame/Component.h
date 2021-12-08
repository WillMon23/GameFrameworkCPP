#pragma once
class Actor{};

class Component
{

public:
	/// <summary>
	/// Defult contructor 
	/// </summary>
	Component();
	/// <param name="actor">gets the actor associated with the this component</param>
	/// <param name="name"></param>
	Component(Actor* actor, const char* name) { m_owner = actor; m_name = name; };
	virtual~Component() { delete m_owner; delete m_name; };
	const char* getName();
	Actor* getOwener();
	
	virtual void start();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();

	virtual void onCollision(Actor* actor);

private:
	Actor* m_owner;
	const char* m_name;
};


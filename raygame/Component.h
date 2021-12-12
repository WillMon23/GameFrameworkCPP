#pragma once
class Actor;

class Component
{

public:
	/// <summary>
	/// Defult contructor 
	/// </summary>
	Component() { m_name = nullptr; m_owner = nullptr; };
	/// <param name="actor">gets the actor associated with the this component</param>
	/// <param name="name">this component names</param>
	Component(Actor* actor, const char* name) { m_owner = actor; m_name = name; };
	/// <summary>
	/// Desolves the constroctor in order to preserve memory 
	/// and prenvent memory leaks
	/// </summary>
	virtual~Component() { delete m_owner; delete m_name; };
	/// <summary>
	/// Gets the value of m_name 
	/// </summary>
	/// <returns>outputs the value of m_name</returns>
	const char* getName() { return m_name; };
	/// <summary>
	/// Gets the value of the owner associated with this component
	/// </summary>
	/// <returns>outputs the vlue of m_owner</returns>
	Actor* getOwner() { return m_owner; };
	
	virtual void start();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();

	virtual void onCollision(Actor* actor);

private:
	Actor* m_owner;
	const char* m_name;
};


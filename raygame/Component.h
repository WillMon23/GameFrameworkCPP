#pragma once
//forward decloration
class Actor;
#include "Transform2D.h"

class Component
{

public:
	/// <summary>
	/// Defult contructor 
	/// </summary>
	Component() { m_name = nullptr; m_started = false; };
	/// <param name="actor">gets the actor associated with the this component</param>
	/// <param name="name">this component names</param>
	Component(const char* name) { m_name = name; };
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
	/// <summary>
	/// Incase that the owner is set to be nullptr
	/// </summary>
	/// <param name="owner">sets a new owner</param>
	void AssignOwner(Actor* owner);
	/// <summary>
	/// Gets the new location associated with te owner 
	/// </summary>
	MathLibrary::Vector2 * getLocation() { return m_location; }
	/// <summary>
	/// Get whether th e instance of this component has been called
	/// </summary>
	/// <returns></returns>
	bool getStarted() { return m_started; }
	
	//Function called by actor class
	virtual void start() { m_started = true; };
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end();

	virtual void onCollision(Actor* actor);

	virtual void onDestroy();

private:
	Actor* m_owner;
	const char* m_name;
	bool m_started;

protected:
	MathLibrary::Vector2 * m_location;
};


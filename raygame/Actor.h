#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; };

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; };

    /// <summary>
    /// Sets the value of name to our private variable 
    /// m_name
    /// </summary>
    /// <param name="name"></param>
    void setName(const char* name) { m_name = name; };

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

    /// <summary>
    /// adds a component to the list of componets for the actor
    /// </summary>
    /// <param name="component">the component being added to the list of comonents</param>
    /// <returns>returns that component</returns>
    Component* addComponent(Component* component);

    /// <summary>
    /// Removes the component associated with with m_components  
    /// in the argument 
    /// </summary>
    /// <param name="component">component being removed from m_components</param>
    /// <returns>if removed it'll return true</returns>
    bool removeComponent(Component* component);

    /// <summary>
    /// Removes the component associated with it's m_name  
    /// in the argument 
    /// </summary>
    /// <param name="component">component being removed from m_components</param>
    /// <returns>if removed it'll return true</returns>
    bool removeComponent(const char* charactor);

    /// <summary>
    /// Gets the component based on the character associated with its
    /// name associated with it
    /// </summary>
    /// <param name="Name associated with the component"></param>
    /// <returns>returns that component in m_component</returns>
    Component* getComponent(const char* componentName);


protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    int m_componentCount;
};


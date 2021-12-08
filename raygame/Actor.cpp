 #include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->start();
}

void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{

    
    //Creats a temporary pointer that will temporary hold all the information
    //from from the m_component with a new added size of m_componentCount 
    Component** temPtrs = new Component * [m_componentCount + 1];
    //for the size of m_componentCount
    for (int i = 0; i < m_componentCount; i++)
    {
        //Checks to see if the componet exists within m_components 
        //If true. . . 
        if (m_components[i] == component)
        {
            //delets temPtrs
            delete[] temPtrs;
            //Jumps out of the fucntion
            return nullptr;
        }
        //... at the index of temPtrs  set that to be m_component at that same index 
        temPtrs[i] = m_components[i];
    }
    //set the new size of temPrts to be the component
    temPtrs[m_componentCount] = component;
    //exchange m_components to be temPtrs
    m_components = temPtrs;
   //once done we delete temPtrs 
    delete[] temPtrs;
    //Incraments components counter by 1
    m_componentCount++;
    //returns the component passed through;  
    return component;
}

bool Actor::removeComponent(Component* component)
{
    //checks if a component has been removed from m_components
    bool removed = false;
    //Creats a temporary pointer that will temporary hold all the information
    //from from the m_component with a new added size of m_componentCount 
    Component** temPtrs = new Component * [m_componentCount - 1];
    //Index of the temporary component
    int j = 0;
    //for the size of m_componentCount
    for (int i = 0; i < m_componentCount; i++)
    {
        //if j end up being greater then i . . .
        if (j > i)
            //Just skip and continue the loop from start
            continue;
        //if the component in the index of m_components does not match the the component . . .
        if (m_components[i] != component)
        {
            //... set that componet in the index of m_components to the index of temPrts
            temPtrs[j] = m_components[i];
            //... Incrament tempTrs index location
            j++;
        }
        //else. . .
        else
            //Set removed to be true
            removed = true;
    }
    // removed is true
    if (removed)
    {
        //set m_componeets to be temPtrs
        m_components = temPtrs;
        //decrament m_componentCOunter
        m_componentCount--;
    }
    //Delte temPtrs allocated memory
    delete temPtrs;
    //returns true if there has been a removed component
    return removed;
}

bool Actor::removeComponent(const char* charactor)
{
    //checks if a component has been removed from m_components
    bool removed = false;
    //Creats a temporary pointer that will temporary hold all the information
    //from from the m_component with a new added size of m_componentCount 
    Component** temPtrs = new Component * [m_componentCount - 1];
    //Index of the temporary component
    int j = 0;
    //for the size of m_componentCount
    for (int i = 0; i < m_componentCount; i++)
    {
        //if j end up being greater then i . . .
        if (j > i)
            //Just skip and continue the loop from start
            continue;
        //if the component in the index of m_name does not match the the character . . .
        if (m_components[i]->getName() != charactor)
        {
            //... set that componet in the index of m_components to the index of temPrts
            temPtrs[j] = m_components[i];
            //... Incrament tempTrs index location
            j++;
        }
        //else. . .
        else
            //Set removed to be true
            removed = true;
    }
    // removed is true
    if (removed)
    {
        //set m_componeets to be temPtrs
        m_components = temPtrs;
        //decrament m_componentCOunter
        m_componentCount--;
    }
    //Delte temPtrs allocated memory
    delete temPtrs;
    //returns true if there has been a removed component
    return removed;
}

Component* Actor::getComponent(const char* character)
{
    //for ever component in the current index of m_components...
    for (int i = 0; i < m_componentCount; i++)
        //if that component m_name in that index is the same as the character 
        if (m_components[i]->getName() == character)
            //return that component in that index
            return m_components[i];
    //Other then that return a null pointer
    return nullptr;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->update(deltaTime);
}

void Actor::draw()
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->draw();
}

void Actor::end()
{
    m_started = false;
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->end();
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}
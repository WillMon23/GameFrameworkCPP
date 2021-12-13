 #include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include <iostream>
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
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onCollision(other);
}

Component* Actor::addComponent(Component* component)
{
    //returs false if there is another implamatation of that component
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;
    component->AssignOwner(this);
    
    //Creats a temporary pointer that will temporary hold all the information
    //from from the m_component with a new added size of m_componentCount 
    Component** temPtrs = new Component * [m_componentCount + 1];
    //for the size of m_componentCount
    for (int i = 0; i < m_componentCount; i++)
        //... at the index of temPtrs  set that to be m_component at that same index 
        temPtrs[i] = m_components[i];


    temPtrs[m_componentCount] = component;
    if (m_componentCount > 1)
        delete[] m_components;
    else if (m_componentCount == 1)
        delete m_components;

    
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
    if (!component)
        return false;
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
        delete[] m_components;
        //set m_componeets to be temPtrs
        m_components = temPtrs;
        //decrament m_componentCOunter
        m_componentCount--;
        delete component;
    }
    else
    //Delte temPtrs allocated memory
    delete[] temPtrs;
    //returns true if there has been a removed component
    return removed;
}

bool Actor::removeComponent(const char* name)
{
    if (!name)
        return false;
    //checks if a component has been removed from m_components
    bool removed = false;
    //creats a new pointer for our possibly deleted component
    Component* componentDeleted = nullptr;
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
        if (strcmp(m_components[i]->getName(), name) == 0)
        {
            //... set that componet in the index of m_components to the index of temPrts
            temPtrs[j] = m_components[i];
            //... Incrament tempTrs index location
            j++;
        }
        //else. . .
        else
        {  //Set removed to be true
            removed = true;
            //... sets our deleted componenet to our deleted component 
            componentDeleted = m_components[i];
        }
    }
    // removed is true
    if (removed)
    {
        delete[] m_components;
        //set m_componeets to be temPtrs
        m_components = temPtrs;
        //decrament m_componentCOunter
        m_componentCount--;
        //Deletes that componenet
        delete componentDeleted;
    }
    else 
    //Delte temPtrs allocated memory
    delete[] temPtrs;
    //returns true if there has been a removed component
    return removed;
}

Component* Actor::getComponent(const char* componentName)
{
    //for ever component in the current index of m_components...
    for (int i = 0; i < m_componentCount; i++)
        //if that component m_name in that index is the same as the character 
        if (strcmp(m_components[i]->getName(), componentName) == 0)
            //return that component in that index
            return m_components[i];
    //Other then that return a null pointer
    return nullptr;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (!m_components[i]->getStarted())
            m_components[i]->start();

        m_components[i]->update(deltaTime);
    }
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
    for (int i = 0; i < m_componentCount; i++)
        m_components[i]->onDestroy();

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
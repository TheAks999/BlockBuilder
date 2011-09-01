#include "gocomponent.h"

/** @brief GOComponent
  * constructor
  */

GOComponent::GOComponent() : m_owner(0)
{
}

/** @brief GOComponent
  * constructor
  * @param owner the game object the component belongs to
  */

GOComponent::GOComponent( GameObject* owner ) : m_owner( owner )
{
}

/** @brief setOwner
  * set the owner of the component
  * @param owner the game object the component belongs to
  */

void GOComponent::setOwner( GameObject *owner )
{
  m_owner = owner;
}

/** @brief getOwner
  * accessor for owner
  * @return the owner of the object
  */

GameObject* GOComponent::getOwner()
{
  return m_owner;
}

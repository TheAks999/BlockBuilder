#include "gameobject.h"
#include <iostream>
using namespace std;

/** @brief id
  * The unique id of the object
  * @return the id of the object
  */

unsigned int GameObject::id()
{
  return m_id;
}


/** @brief id
  * mutator for the id of the object
  * @param ID the id the object will have
  */

void GameObject::id( const unsigned int& ID )
{
  m_id = ID;
}



/** @brief ~GameObject
  * Destructor
  */
 GameObject::~GameObject()
{
	ComponentTable_t::iterator it = m_components.begin();
	for (; it != m_components.end(); it++)
	{

		if (it->second)
		{
			delete it->second;
		}
	}
}

/** @brief clearGOCs
  * Clear all game object components from the object
  */
void GameObject::clearGOCs()
{
	ComponentTable_t::iterator it = m_components.begin();
	for (; it != m_components.end(); it++)
	{
		if (it->second)
		{
			delete it->second;
		}
	}
	m_components.clear();
}


/** @brief setGOC
  * Add in or replace a component in the game object. The old data if replacing will be cleaned up.
  * @param newComp A pointer to the new data to point at.
  */
void GameObject::setGOC(GOComponent * newComp)
{
	if (newComp)
	{
		ComponentTable_t::iterator it = m_components.find(newComp->familyID());
		if( it != m_components.end())
		{
			delete it->second;
		}
		m_components[newComp->familyID()] = newComp;
	}
}

/** @brief getGOC
  * Get a reference to a game object component
  * @param familyID the family id that the component its refered to as
  * @return a reference to the game object component
  */
GOComponent* GameObject::getGOC(const GOC_IDType & familyID)
{

  ComponentTable_t::iterator it = m_components.find( familyID );
  if( it != m_components.end() )
  {
    // This is returning junk for some reason.
    return it->second;
  }
	return NULL;
}

/** @brief GameObject
  * constructor
  * @param id the id of the object
  */
 GameObject::GameObject(const unsigned int & id):m_id(id)
{

}

/** @brief listComponentFamilies
  * List the component families that are contained in the object in a vector.
  * @return a vector of ids
  */
std::vector<GOC_IDType> GameObject::listComponentFamilies()
{
	ComponentTable_t::iterator it = m_components.begin();
	std::vector<GOC_IDType> vect;
	for (; it != m_components.end(); it++)
	{
		vect.push_back(it->first);
	}
	return vect;
}

/** @brief listComponents
  * List the component names that are contained in the object in a vector.
  * @return a vector of ids
  */
std::vector<GOC_IDType> GameObject::listComponents()
{
	ComponentTable_t::iterator it = m_components.begin();
	std::vector<GOC_IDType> vect;
	for (; it != m_components.end(); it++)
	{
		vect.push_back(it->second->componentID());
	}
	return vect;
}

/** @brief hasComponentFam
  * checks to see if a component family exists
  * @param familyID
  * @return true if the family exists in the object
  */
bool GameObject::hasComponentFam(const GOC_IDType & familyID)
{
	if (m_components.find(familyID) != m_components.end())
	{
		return true;
	}
	return false;
}

/** @brief constructHash
  * construct a unique hash specifically for the object
  * @return a hash that is nearly unique for the object
  */
GO_IDType GameObject::constructHash()
{
	return m_id;
}

/** @brief requirementsMet
  * find out if the object is really ready to be used
  * @return true if all requirements are met
  */

bool GameObject::requirementsMet()
{
	for (ComponentTable_t::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		if ( !(it->second->requirementsMet()) )
		{
			return false;
		}
	}
	return true;
}

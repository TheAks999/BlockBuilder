#include "gotemplate.h"

/** @brief ~GOTemplate
  * destructor
  */

GOTemplate :: ~GOTemplate()
{
	clearGOCTs();
}

/** @brief makeObject
  * make an object out of this template
  * @param id the id to assign the object
  * @return a pointer to the new data
  */

GameObject * GOTemplate :: makeObject(const GO_IDType & id)
{
	GameObject * GO = new GameObject(id);
	TemplateTable::iterator it = m_templates.begin();
	for (; it != m_templates.end(); it++)
	{
		GO->setGOC(it->second->makeComponent());
	}

	return GO;
}


/** @brief hasComponentFam
  * check to see if a family has been assigned to the template
  * @param familyID the family to be checking for
  * @return true if the family exits
  */

bool GOTemplate :: hasComponentFam(const GOC_IDType & familyID)
{
	if (m_templates.end() != m_templates.find(familyID))
	{
		return true;
	}

	return false;
}

/** @brief getGOCT
  * get a pointer to a component template
  * @param familyID the family to get from the object template
  * @return a pointer to the component template or NULL if the template doesn't exist
  */

GOCTemplate * GOTemplate :: getGOCT(const GOC_IDType & familyID)
{
	TemplateTable::iterator it = m_templates.find(familyID);
	if (it != m_templates.end())
	{
		return it->second;
	}
	return NULL;
}

/** @brief setGOCT
  * assign a component template to the object template
  * @param newComp a pointer to the component template to be assigned to the object template
  */

void GOTemplate :: setGOCT(GOCTemplate * newComp)
{
	if (newComp)
	{
		TemplateTable::iterator it = m_templates.find(newComp->familyID());
		if (it != m_templates.end())
		{
			delete it->second;
		}

		m_templates[newComp->familyID()] = newComp;
	}
}

/** @brief clearGOCTs
  * clean out all of the component templates from the object template
  */

void GOTemplate :: clearGOCTs()
{
	TemplateTable::iterator it = m_templates.begin();
	for (; it != m_templates.end(); it++)
	{
		delete it->second;
	}
	m_templates.clear();
}

/** @brief listCompTemplates
  * list all of the names of component templates in the object template
  * @return a vector of ids
  * @todo fill out this equation
  */

std::vector<GOC_IDType> GOTemplate :: listCompTemplates()
{

}

/** @brief listCompTemplates
  * list all of the names of component template families in the object template
  * @return a vector of ids
  * @todo fill out this equation
  */

std::vector<GOC_IDType> GOTemplate :: listCompTemplateFamilies()
{

}


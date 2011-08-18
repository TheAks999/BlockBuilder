#include "gotemplate.h"

GOTemplate :: ~GOTemplate()
{
	clearGOCTs();
}

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

bool GOTemplate :: hasComponentFam(const GOC_IDType & familyID)
{
	if (m_templates.end() != m_templates.find(familyID))
	{
		return true;
	}

	return false;
}

GOCTemplate * GOTemplate :: getGOCT(const GOC_IDType & familyID)
{
	TemplateTable::iterator it = m_templates.find(familyID);
	if (it != m_templates.end())
	{
		return it->second;
	}
	return NULL;
}

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

void GOTemplate :: clearGOCTs()
{
	TemplateTable::iterator it = m_templates.begin();
	for (; it != m_templates.end(); it++)
	{
		delete it->second;
	}
	m_templates.clear();
}


std::vector<GOC_IDType> GOTemplate :: listCompTemplates()
{

}

std::vector<GOC_IDType> GOTemplate :: listCompTemplateFamilies()
{

}


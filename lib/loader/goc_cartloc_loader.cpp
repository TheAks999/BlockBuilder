#include "goc_cartloc_loader.h"

bool GOC_CartLoc_Loader::load(TiXmlElement * elem, Loadable * loadable)
{
	//Sanity check
	if (!elem)
	{
		Errorer::PushError("GOC_CartLoc_Loader",LB_ERRORSTR_BADELEM,LB_ERRORCDE_BADELEM,ERR_MINOR);
		return false;
	}

	if (elem->Value() != "Component")
	{
		Errorer::PushError("GOC_CartLoc_Loader",std::string("Parsing Wrong Element Type. Looing for \"Component\" instead ")+elem->Value(),2,ERR_MAJOR);
		return false;
	}

	//! @todo load the component here
}

bool GOC_CartLoc_Template_Loader::load(TiXmlElement * elem, Loadable * loadable)
{
	if (!elem)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader",LB_ERRORSTR_BADELEM,LB_ERRORCDE_BADELEM,ERR_MINOR);

		return false;
	}

	if (elem->Value() != "ComponentTemplate")
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader",std::string("Parsing Wrong Element Type. Looing for \"Component\" instead ")+elem->Value(),2,ERR_MAJOR);
		return false;
	}

	if (elem->Attribute("family") != "Location")
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader",std::string("Attribute Error. Want family->Location instead ")+elem->Attribute("family"),3,ERR_MAJOR);
		return false;
	}

	if (elem->Attribute("component") != "Cartesian_Location")
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader",std::string("Attribute Error. Want component->Cartesian_Location instead ")+elem->Attribute("family"),3,ERR_MAJOR);
		return false;
	}

	if (elem->Attribute("name") == NULL)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader",std::string("Attribute Error. Missing name attribute"),3,ERR_MAJOR);
		return false;
	}

	std::string name = elem->Attribute("name");

	double x;
	double y;
	double z;

	TiXmlNode * node = elem->FirstChild();
	TiXmlElement * child;


	//Child one!!

	if (!node)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template too few children",4,ERR_MAJOR);
		return false;
	}

	if (node->Type() != 1)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child of wrong type",4,ERR_MAJOR);
		return false;
	}

	child = node->ToElement();

	if (child->Value() != "x")
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child not x",4,ERR_MAJOR);
		return false;
	}

	if (child->Attribute("value") == NULL)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child has no attribute \"value\"",4,ERR_MAJOR);
		return false;
	}

	child->Attribute("value",&x);
	//Second Child

	node = elem->IterateChildren(node);

	if (!node)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template too few children",4,ERR_MAJOR);
		return false;
	}

	if (node->Type() != 1)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child of wrong type",4,ERR_MAJOR);
		return false;
	}

	child = node->ToElement();

	if (child->Value() != "x")
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child not x",4,ERR_MAJOR);
		return false;
	}

	if (child->Attribute("value") == NULL)
	{
		Errorer::PushError("GOC_CartLoc_Template_Loader","Cartesian Location Template first child has no attribute \"value\"",4,ERR_MAJOR);
		return false;
	}

	child->Attribute("value",&x);

	GOC_CartLocTemplate * temp = new GOC_CartLocTemplate(elem->Attribute("name"));



	return true;
}


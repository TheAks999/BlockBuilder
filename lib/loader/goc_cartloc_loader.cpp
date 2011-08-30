#include "goc_cartloc_loader.h"

bool GOC_CartLoc_Loader::load(TiXmlElement * elem, Loadable * loadable)
{
	//Sanity check
	if (!elem)
	{
		pushError(LB_ERRORCDE_BADELEM,LB_ERRORSTR_BADELEM);
		return false;
	}

	if (elem->Value() != "Component")
	{
		pushError(2,std::string("Parsing Wrong Element Type. Looing for \"Component\" instead ")+elem->Value());
		return false;
	}


}

bool GOC_CartLoc_Template_Loader::load(TiXmlElement * elem, Loadable * loadable)
{
	if (!elem)
	{
		pushError(LB_ERRORCDE_BADELEM,LB_ERRORSTR_BADELEM);
		return false;
	}

	if (elem->Value() != "ComponentTemplate")
	{
		pushError(2,std::string("Parsing Wrong Element Type. Looing for \"ComponentTemplate\" instead ")+elem->Value());
		return false;
	}

	if (elem->Attribute("family") != "Location")
	{
		pushError(3,std::string("Attribute Error. Want family->Location instead ")+elem->Attribute("family"));
		return false;
	}

	if (elem->Attribute("component") != "Cartesian_Location")
	{
		pushError(3,std::string("Attribute Error. Want component->Cartesian_Location instead ")+elem->Attribute("component"));
		return false;
	}

	if (elem->Attribute("name") == NULL)
	{
		pushError(3,std::string("Attribute Error. Missing name attribute"));
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
		pushError(4,std::string("Cartesian Location Template too few children"));
		return false;
	}

	if (node->Type() != 1)
	{
		pushError(4,std::string("Cartesian Location Template first child of wrong type"));
		return false;
	}

	child = node->ToElement();

	if (child->Value() != "x")
	{
		pushError(4,std::string("Cartesian Location Template first child not x"));
		return false;
	}

	if (child->Attribute("value") == NULL)
	{
		pushError(4,std::string("Cartesian Location Template first child has no attribute \"value\""));
		return false;
	}

	child->Attribute("value",&x);
	//Second Child

	node = elem->IterateChildren(node);

	if (!node)
	{
		pushError(4,std::string("Cartesian Location Template too few children"));
		return false;
	}

	if (node->Type() != 1)
	{
		pushError(4,std::string("Cartesian Location Template first child of wrong type"));
		return false;
	}

	child = node->ToElement();

	if (child->Value() != "x")
	{
		pushError(4,std::string("Cartesian Location Template first child not x"));
		return false;
	}

	if (child->Attribute("value") == NULL)
	{
		pushError(4,std::string("Cartesian Location Template first child has no attribute \"value\""));
		return false;
	}

	child->Attribute("value",&x);

	GOC_CartLocTemplate * temp = new GOC_CartLocTemplate(elem->Attribute("name"));



	return true;
}


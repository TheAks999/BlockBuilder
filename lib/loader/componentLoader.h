#ifndef COMPONENTLOADER_H
#define COMPONENTLOADER_H
#include "loaderbase.h"
#include "../gameobject/goctemplate.h"

class GOCTemplateLoader : public LoaderBase
{
	public:
		virtual const Loader_IDType familyID(){ return "ComponentTemplate"; }
	protected:


};

class GOCLoader : public LoaderBase
{
	public:
		virtual const Loader_IDType familyID(){ return "Component"; }
	protected:
};

#endif

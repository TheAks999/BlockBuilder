#ifndef GOC_CARTLOC_LOADER_H
#define GOC_CARTLOC_LOADER_H
#include "componentLoader.h"

class GOC_CartLoc_Loader : public GOCLoader
{
	public:
	const Loader_IDType typeID() { return "Cartesian_Location";}
	bool load(TiXmlElement *, Loadable *);

	protected:
	private:

};

class GOC_CartLoc_Template_Loader : public GOCTemplateLoader
{
	public:
	const Loader_IDType typeID() { return "Cartesian_Location_Template";}
	bool load(TiXmlElement *, Loadable *);

	protected:
		bool parseChild(TiXmlNode * , std::string, int & );
	private:

};

#endif //GOC_CARTLOC_LOADER_H

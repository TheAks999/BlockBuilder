#ifndef LOADERBASE_H
#define LOADERBASE_H
#include <string>
#include "../TinyXml/tinyxml.h"
#include "../manager/manager.h"
#include "../gameobject/loadable.h"
#include "../Errorer/errorer.h"
#include <vector>


typedef std::string Loader_IDType;


#define LB_ERRORSTR_NOERR "No Error"
#define LB_ERRORCDE_NOERR 0

#define LB_ERRORSTR_BADELEM "Null element Reference"
#define LB_ERRORCDE_BADELEM 1



class LoaderBase
{
	public:
		LoaderBase(){}

		virtual const Loader_IDType typeID() = 0;
		virtual const Loader_IDType familyID() = 0;
		virtual bool load(TiXmlNode *, Loadable *) = 0;
};

class LoaderManager : public Manager< Loader_IDType, LoaderBase*>
{
	public:
		virtual bool loadFromFile(const std::string &) = 0;
		virtual bool saveToFile(const std::string &);
		std::vector<std::string> setNames();
	protected:
	private:
};

#endif

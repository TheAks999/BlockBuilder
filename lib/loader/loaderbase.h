#ifndef LOADERBASE_H
#define LOADERBASE_H
#include <string>
#include "../TinyXml/tinyxml.h"
#include "../manager/manager.h"
#include "../gameobject/loadable.h"
#include "../Errorer/errorer.h"
#include <vector>


typedef std::string Loader_IDType;



#define LB_ERRORSTR_BADELEM "Null element Reference"
#define LB_ERRORCDE_BADELEM 1



class LoaderBase
{
	public:

		/** @brief LoaderBase
		  * basic Constructor
		  */
		LoaderBase(){}


		/** @brief typeID
		  * the id of the actual loader, should be unique for the family. Pure Virtual.
		  * @return the id
		  */
		virtual const Loader_IDType typeID() = 0;

		/** @brief familyID
		  * the family id the loader belongs to, this is the . Pure Virtual.
		  * @return the id
		  */
		virtual const Loader_IDType familyID() = 0;

		virtual const Loader_IDType constructHash(){return familyID()+typeID();}

		/** @brief load
		  * loads the specific form of data that the loader is designed for
		  * @param node the node that the last loader left at
		  * @return true if nothing went wrong
		  */
		virtual bool load(TiXmlNode * node) = 0;
};

class LoaderManager : public Manager< Loader_IDType, LoaderBase*>
{
	public:
		/** @brief loadFromFile
		  * loads a file into memory
		  * @param filename the name of the file to load
		  * @return true if all went well
		  */

		bool loadFromFile(const std::string & filename);

		//virtual bool saveToFile(const std::string & filename;

		/** @brief setNames
		  * the set of names
		  */
		std::vector<std::string> setNames();

	protected:
	private:
};

#endif

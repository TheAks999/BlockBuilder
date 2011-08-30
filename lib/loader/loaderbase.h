#ifndef LOADERBASE_H
#define LOADERBASE_H
#include <string>
#include "../TinyXml/tinyxml.h"
#include "../manager/manager.h"
#include "../gameobject/loadable.h"
#include <vector>


typedef std::string Loader_IDType;


#define LB_ERRORSTR_NOERR "No Error"
#define LB_ERRORCDE_NOERR 0

#define LB_ERRORSTR_BADELEM "Null element Reference"
#define LB_ERRORCDE_BADELEM 1



class LoaderBase
{
	public:
		LoaderBase(){m_errorStrings.push_back(LB_ERRORSTR_NOERR); m_errorCodes.push_back(LB_ERRORCDE_NOERR);}

		virtual const Loader_IDType typeID() = 0;
		virtual const Loader_IDType familyID() = 0;
		virtual bool load(TiXmlNode *, Loadable *) = 0;

		std::string ErrorDesc();
		unsigned int ErrorCode();
		void nextError();
		void clearErrors();
		void flushErrorsTo(std::iostream *);

	protected:
		void pushError(const unsigned int & errCode, const std::string & errString);

	private:

		std::vector<std::string> m_errorStrings;
		std::vector<unsigned int> m_errorCodes;

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

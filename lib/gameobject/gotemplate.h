#ifndef GOTEMPLATE_H
#define GOTEMPLATE_H
#include "gameobject.h"
#include "goctemplate.h"

typedef std::string GOT_IDType;

class GOTemplate : Loadable
{
	public:
		GOTemplate(const GOT_IDType & id):m_TID(id){}
		/** Default destructor */
		virtual ~GOTemplate();

		virtual GameObject * makeObject(const GO_IDType & id);

		bool hasComponentFam(const GOC_IDType & familyID);

		GOCTemplate * getGOCT(const GOC_IDType & familyID);
		void setGOCT(GOCTemplate * newComp);
		void clearGOCTs();

		std::vector<GOC_IDType> listCompTemplates();
		std::vector<GOC_IDType> listCompTemplateFamilies();

		GOT_IDType templateID() { return m_TID;}
		void templateID(const GOT_IDType & id) { m_TID = id; }

		virtual GOT_IDType constructHash() = 0;

	protected:
		typedef std::map<GOC_IDType,GOCTemplate*> TemplateTable;
		TemplateTable m_templates;
		GOT_IDType m_TID;

	private:

};


#endif


#ifndef GOCTEMPLATE_H
#define GOCTEMPLATE_H
#include "gocomponent.h"



class GOCTemplate : Loadable
{
	public:
		/** Default constructor */
		GOCTemplate(const GOC_IDType & id):m_templateID(id){}
		/** Default destructor */
		virtual ~GOCTemplate(){}

		GOC_IDType templateID() { return m_templateID; }
		virtual const GOC_IDType & componentID() const = 0;
		virtual const GOC_IDType & familyID() const = 0;

		virtual GOComponent * makeComponent() = 0;

		void templateID(const GOC_IDType & id){m_templateID = id;}

		virtual GOC_IDType constructHash() = 0;

	protected:
	private:
		GOC_IDType m_templateID;
};

#endif // GOCTEMPLATE_H

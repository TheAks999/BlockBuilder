#ifndef GOCOMPONENT_H
#define GOCOMPONENT_H

#include <string>
#include "gameobject.h"
#include "loadable.h"
//to make changing the id type easy

class GameObject;
typedef std::string GOC_IDType;

class GOComponent : public Loadable
{
	public:
		/** Default constructor */
		GOComponent();
		GOComponent( GameObject* owner );


		virtual const GOC_IDType componentID() const = 0;
		virtual const GOC_IDType familyID() const = 0;

		virtual void update() = 0;

		void setOwner( GameObject * owner);
		GameObject * getOwner();

		virtual GOC_IDType constructHash() = 0;

		virtual bool requirementsMet(){ return true; }

	protected:
	private:
		GameObject * m_owner;
};

#endif // GOCOMPONENT_H

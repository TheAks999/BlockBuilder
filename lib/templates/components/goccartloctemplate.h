#ifndef GOCCARTLOCTEMPLATE_H
#define GOCCARTLOCTEMPLATE_H
#include "../../gameobject/goctemplate.h"
#include "../../components/goc_cartloc.h"

class GOC_CartLocTemplate : public GOCTemplate
{
	public:
		GOC_CartLocTemplate(GOC_IDType id):GOCTemplate(id),m_x(0),m_y(0),m_z(0){}

		float x(){ return m_x; }
		float y(){ return m_y; }
		float z(){ return m_z; }
		void x(const float & X){ m_x = X; }
		void y(const float & Y){ m_y = Y; }
		void z(const float & Z){ m_z = Z; }

		const GOC_IDType & componentID() const { return GOC_IDType("Cartesian_Location"); }
		const GOC_IDType & familyID() const { return GOC_IDType("Location"); }

		GOComponent * makeComponent()
		{
			/*GOC_CartLoc * temp = new GOC_CartLoc;
			temp->x(x());
			temp->y(y());
			temp->z(z());
			return dynamic_cast<GOComponent*>(temp);*/ return NULL;
		}

		GOC_IDType constructHash(){ return std::string("Location Cartesian_Location ") + templateID(); }

		~GOC_CartLocTemplate(){}
	private:
		float m_x, m_y, m_z;
};


#endif //GOCCARTLOCTEMPLATE_H

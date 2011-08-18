#ifndef	GOC_CARTLOC_H
#define GOC_CARTLOC_H
#include "goc_location.h"

/********************
Cartesian Coordinates
********************/

class GOC_CartLoc : public GOC_Location
{
	public:
		float x();
		float y();
		float z();
		void x(const float & X);
		void y(const float & Y);
		void z(const float & Z);

		const GOC_IDType componentID() const{ return "Cartesian_Location"; }
		GOC_IDType constructHash(){return familyID(); }

	private:
		float m_x, m_y, m_z;
};

#endif

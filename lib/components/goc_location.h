#ifndef GOC_LOCTATION_H
#define GOC_LOCATION_H
#include "../gameobject/gocomponent.h"


class GOC_Location : public GOComponent
{
	public:
		virtual float x() = 0;
		virtual float y() = 0;
		virtual float z() = 0;
		virtual void x(const float & X) = 0;
		virtual void y(const float & Y) = 0;
		virtual void z(const float & Z) = 0;
		virtual void update(){};

		const GOC_IDType familyID() const{ return "Location"; }
};

#endif


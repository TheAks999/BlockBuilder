#ifndef GOCREQUIREMENTS_H
#define GOCREQUIREMENTS_H

#include "gocomponent.h"

enum GOReqType
{
	GOR_Family, // require a specific family ID
	GOR_ID // require a specific ID
};

class GO_Requirement
{
	public:
	GOC_IDType & instigatorID() const;
	void instigatorID(const GOC_IDType & id);

	GOComponent * instigator();
	void instigator(GOComponent * goc);

	GOC_IDType & requiredID() const;
	void requiredID(const GOC_IDType & id);

	bool isSet();

	GOReqType & requirementType() const;
	void requirementType(const GOReqType & type);

	friend ostream & operator<<(ostream & o, const GO_Requirement & gor);

};




#endif

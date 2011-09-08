#ifndef GOCREQUIREMENTS_H
#define GOCREQUIREMENTS_H

#include <string>
#include <iostream>
#include "gocomponent.h"


enum GOReqType
{
	GOR_Family, // require a specific family ID
	GOR_ID // require a specific ID
};

class GOComponent;
typedef std::string GOC_IDType;

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

	friend std::ostream & operator<<(std::ostream & o, const GO_Requirement & gor);

};




#endif

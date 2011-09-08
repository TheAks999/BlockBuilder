#ifndef GAMEOBJECTTEST_H
#define GAMEOBJECTTEST_H
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../lib/gameobject/gameobject.h"


class GameObjectTest : public  CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( GameObjectTest );
	CPPUNIT_TEST( DoBasicSetup );
	CPPUNIT_TEST( DoBasicCleanup );

	CPPUNIT_TEST( AddComponent );
	CPPUNIT_TEST( DoComponentCleanup );
	CPPUNIT_TEST( RemoveComponent );

	CPPUNIT_TEST( AddRequirement );
	CPPUNIT_TEST( DoRequirementCleanup );
	CPPUNIT_TEST( RemoveRequirement );

	CPPUNIT_TEST( ListComponents );
	CPPUNIT_TEST( ListComponentFamilies );

	CPPUNIT_TEST( HasComponentFamily );

	CPPUNIT_TEST_SUITE_END();


	public:
	void DoBasicSetup();
	void DoBasicCleanup();

	void AddComponent();


};


#endif

#ifndef GAMEOBJECTTEST_H
#define GAMEOBJECTTEST_H
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../lib/gameobject/gameobject.h"


class GameObjectTest : public  CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( GameObjectTest );
	CPPUNIT_TEST( DoBasicSetup );

	CPPUNIT_TEST( AddComponent );
	CPPUNIT_TEST( AddComponentOfDiffFam );
	CPPUNIT_TEST( AddComponentOfSameFam );

	/*
	CPPUNIT_TEST( RemoveComponent );

	CPPUNIT_TEST( HasComponentFamily );

	CPPUNIT_TEST( AddRequirementComponent );
	CPPUNIT_TEST( DoRequirementComponentCleanup );
	CPPUNIT_TEST( RemoveRequirementComponent );

	CPPUNIT_TEST( ListComponents );
	CPPUNIT_TEST( ListComponentFamilies );
	*/

	CPPUNIT_TEST_SUITE_END();


	public:
	void DoBasicSetup();

	void AddComponent();
	void AddComponentOfDiffFam();
	void AddComponentOfSameFam();
	void DoComponentCleanup();
	void RemoveComponent();

	void HasComponentFamily ();

	void AddRequirementComponent();
	void DoRequirementComponentCleanup();
	void RemoveRequirementComponent();

	void ListComponents();
	void ListComponentFamilies();

};


#endif

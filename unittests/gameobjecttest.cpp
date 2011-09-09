
#include "gameobjecttest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( GameObjectTest );

void GameObjectTest::DoBasicSetup()
{
	GameObject GO(5);

	CPPUNIT_ASSERT( (GO.id() == 5) && "Check if the id is what it should be." );
	GO.id(7);
	CPPUNIT_ASSERT( (GO.id() != 5 ) && "Make Sure the id isn't what it was after change." );
	CPPUNIT_ASSERT( (GO.id() == 7) && "Check if the id is what it should be." );
}

/** two components with same families **/
class foh_GOComponentA : public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentA"; }
		const GOC_IDType familyID() const { return "family1"; }

		void update() {}

		const GOC_IDType constructHash() const { return familyID(); }
};

class foh_GOComponentB: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentB"; }
		const GOC_IDType familyID() const { return "family1"; }

		void update() {}

		const GOC_IDType constructHash() const { return familyID(); }
};


/** components with different families **/
class foh_GOComponentC: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentC"; }
		const GOC_IDType familyID() const { return "family2"; }

		void update() {}

		const GOC_IDType constructHash() const { return familyID(); }
};

/** components with different families **/
class foh_GOComponentD: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentD"; }
		const GOC_IDType familyID() const { return "family3"; }

		void update() {}

		const GOC_IDType constructHash() const { return familyID(); }
};

/** components with different families **/
class foh_GOComponentE: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentE"; }
		const GOC_IDType familyID() const { return "family4"; }

		void update() {}

		const GOC_IDType constructHash() const { return familyID(); }
};


void GameObjectTest::AddComponent()
{
	GameObject GO(0);
	CPPUNIT_ASSERT( !GO.hasComponentFam("") ); // empty family check
	CPPUNIT_ASSERT( !GO.hasComponentFam("family1") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family2") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family3") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family4") );

	//insert the first component
	foh_GOComponentA comp1;
	GO.setGOC( &comp1 );

	CPPUNIT_ASSERT( !GO.hasComponentFam("") ); // empty family check
	CPPUNIT_ASSERT( GO.hasComponentFam("family1") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family2") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family3") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family4") );

	CPPUNIT_ASSERT( GO.getGOC("family1") == comp1 );


	//insert a second component

}

void RemoveComponent();

void HasComponentFamily ();

void AddRequirementComponent();
void DoRequirementComponentCleanup();
void RemoveRequirementComponent();

void ListComponents();
void ListComponentFamilies();

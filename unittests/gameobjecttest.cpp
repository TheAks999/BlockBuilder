
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

		GOC_IDType constructHash() { return familyID(); }
};

class foh_GOComponentB: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentB"; }
		const GOC_IDType familyID() const { return "family1"; }

		void update() {}

		GOC_IDType constructHash(){ return familyID(); }
};


/** components with different families **/
class foh_GOComponentC: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentC"; }
		const GOC_IDType familyID() const { return "family2"; }

		void update() {}

		 GOC_IDType constructHash() const { return familyID(); }
};

/** components with different families **/
class foh_GOComponentD: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentD"; }
		const GOC_IDType familyID() const { return "family3"; }

		void update() {}

		GOC_IDType constructHash() const { return familyID(); }
};

/** components with different families **/
class foh_GOComponentE: public GOComponent
{
	public:

		const GOC_IDType componentID() const { return "componentE"; }
		const GOC_IDType familyID() const { return "family4"; }

		void update() {}

		GOC_IDType constructHash() const { return familyID(); }
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
	foh_GOComponentA * comp1 = new foh_GOComponentA;
	GO.setGOC( comp1 );

	CPPUNIT_ASSERT( !GO.hasComponentFam("") ); // empty family check
	CPPUNIT_ASSERT( GO.hasComponentFam("family1") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family2") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family3") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family4") );
	CPPUNIT_ASSERT( GO.getGOC("family1") == comp1 );

}

void AddComponentOfDiffFam()
{
	//insert a second component of the same family
	foh_GOComponentA * comp1 = new foh_GOComponentA;
	GO.setGOC( comp1 );
	foh_GOComponentC * comp2 = new foh_GOComponentC;
	GO.setGOC( comp2 );
	CPPUNIT_ASSERT( !GO.hasComponentFam("") ); // empty family check
	CPPUNIT_ASSERT( GO.hasComponentFam("family1") );
	CPPUNIT_ASSERT( GO.hasComponentFam("family2") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family3") );
	CPPUNIT_ASSERT( !GO.hasComponentFam("family4") );
	CPPUNIT_ASSERT( GO.getGOC("family1") == comp1 );
	CPPUNIT_ASSERT( GO.getGOC("family2") == comp2 );

	foh_GOComponentD * comp3 = new foh_GOComponentD;
	foh_GOComponentE * comp4 = new foh_GOComponentE;
	GO.setGOC( comp3 );
	GO.setGOC( comp4 );


	CPPUNIT_ASSERT( !GO.hasComponentFam("") ); // empty family check
	CPPUNIT_ASSERT( GO.hasComponentFam("family1") );
	CPPUNIT_ASSERT( GO.hasComponentFam("family2") );
	CPPUNIT_ASSERT( GO.hasComponentFam("family3") );
	CPPUNIT_ASSERT( GO.hasComponentFam("family4") );
	CPPUNIT_ASSERT( GO.getGOC("family1") == comp1 );
	CPPUNIT_ASSERT( GO.getGOC("family2") == comp2 );
	CPPUNIT_ASSERT( GO.getGOC("family3") == comp3 );
	CPPUNIT_ASSERT( GO.getGOC("family4") == comp4 );

}

void AddComponentOfSameFam()
{
}

void RemoveComponent();

void HasComponentFamily ();

void AddRequirementComponent();
void DoRequirementComponentCleanup();
void RemoveRequirementComponent();

void ListComponents();
void ListComponentFamilies();

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <map>
#include <vector>

#include "gocomponent.h"
#include "loadable.h"
#include "gocrequirements.h"

class GOComponent;
typedef std::string GOC_IDType;
typedef unsigned int GO_IDType;


class GameObject : public Loadable
{
	public:
		/** Default constructor */
		GameObject(const GO_IDType & id);

		GO_IDType id();
		void id(const GO_IDType & ID);

		bool hasComponentFam(const GOC_IDType & familyID);

		GOComponent * getGOC(const GOC_IDType & familyID);
		void setGOC(GOComponent * newComp);
		bool removeGOC(const GOC_IDType & familyID);
		void clearGOCs();

		std::vector<GOC_IDType> listComponents();
		std::vector<GOC_IDType> listComponentFamilies();
		std::vector<GO_Requirement> listRequirements();

		bool requirementsMet();


		virtual GO_IDType constructHash();

		/** Default destructor */
		virtual ~GameObject();
	protected:


		//for easy access
		typedef std::map < GOC_IDType /*id*/,GOComponent* /*value*/>
				ComponentTable_t;

		typedef std::vector<GO_Requirement*> RequirementTable;

		GO_IDType m_id;
		ComponentTable_t m_components;
		RequirementTable m_requirements;
	private:
};

#endif // GAMEOBJECT_H

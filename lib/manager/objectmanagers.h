#ifndef OBJECTMANAGERS_H
#define OBJECTMANAGERS_H
#include "manager.h"
#include "../gameobject/gotemplate.h"

typedef Manager<GO_IDType,GameObject*> 		GameObjectManager;
typedef Manager<GOC_IDType,GOComponent*> 	ComponentManager;
typedef Manager<GOT_IDType,GOTemplate*>		GOTemplateManager;
typedef Manager<GOC_IDType,GOCTemplate*>	GOCTemplateManager;

#endif

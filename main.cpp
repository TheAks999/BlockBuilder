#include "lib/components/goc_cartloc.h"
#include "lib/manager/objectmanagers.h"
#include "lib/gameobject/gotemplate.h"
#include "lib/TinyXml/tinyxml.h"
#include "lib/templates/components/goccartloctemplate.h"



int main (int argc, char ** argv)
{
	GOCTemplate * temp = new GOC_CartLocTemplate("something");
	std::cout << temp->constructHash() << '\n';


	TiXmlDocument doc("test.xml");
	if (doc.LoadFile())



	return 0;
}



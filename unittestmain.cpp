
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/XmlOutputter.h>




#include <fstream>

using namespace std;
using namespace CppUnit;

int main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  Test *suite = TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  TextTestRunner runner;
  runner.addTest( suite );

  ofstream output("cppunitoutput.xml");

  // Run the tests.
  bool wasSucessful = runner.run();

  // Change the default outputter to a compiler error format outputter
  XmlOutputter Xml(&runner.result(),output);
  Xml.write();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}

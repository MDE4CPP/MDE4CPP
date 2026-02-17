
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecoreAnnotationsExample/ecoreAnnotationsExampleFactory.hpp"
#include "ecoreAnnotationsExample/ecoreAnnotationsExamplePackage.hpp"

#include "ecoreAnnotationsExample/Library.hpp"
#include "ecoreAnnotationsExample/NamedElement.hpp"
#include "ecoreAnnotationsExample/Book.hpp"
#include "ecoreAnnotationsExample/Author.hpp"
#include "ecoreAnnotationsExample/Picture.hpp"

/*This DetailsEntry can be used to define additional include statements for labraries 
to be included in the main application.

NOTE: The include statements should be listed, a new line
for each statement (as the value of this DetailsEntry will be generated into the final code
as is).

Example:

#include <cmath>
#include <string>
*/

// Start of user code includes 
// You may manually edit additional includes, won't be overwritten upon generation.

// End of user code

using namespace ecoreAnnotationsExample;

// Start of user code functions 
// You may manually edit additional functions, won't be overwritten upon generation.

// End of user code

int main ()
{
	//Create Model Factory
	std::shared_ptr<ecoreAnnotationsExampleFactory> factory = ecoreAnnotationsExampleFactory::eInstance();

/*This DetailsEntry can be used to define the body of the applications main function.

Example:
*/
std::string hw = "Hello World";
std::cout<<hw<<std::endl;

// Start of user code main
// You may manually edit the following lines, won't be overwritten upon generation.

// End of user code

    return 0;

}

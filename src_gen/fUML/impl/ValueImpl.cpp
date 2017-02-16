#include "ValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <Classifier.hpp>

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ValueImpl::ValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

ValueImpl::~ValueImpl()
{
	
}

ValueImpl::ValueImpl(const ValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
}

ecore::EObject *  ValueImpl::copy() const
{
	return new ValueImpl(*this);
}

ecore::EClass* ValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    std::vector<uml::Classifier*>  * myTypes = this->getTypes();
    std::vector<uml::Classifier*>  * otherTypes = otherValue->getTypes();

    DEBUG_MESSAGE(std::cout<<"in Value"<<std::endl;)
    bool isEqual = true;

    if(myTypes->size() != otherTypes->size())
    {
        isEqual = false;

    }
    else
    {
        int i = 1;
        while(isEqual && i <= myTypes->size())
        {
            bool matched = false;
            unsigned int j = 1;
            while(!matched && j <= otherTypes->size())
            {
                matched = (otherTypes->at(j - 1) == myTypes->at(i - 1));
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
}

std::vector<uml::Classifier * > *  ValueImpl::getTypes()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::hasTypes(uml::Classifier *  type) 
{
	//generated from body annotation
	    std::vector<uml::Classifier*>  * types = this->getTypes();

    bool found = false;
    int i = 1;
    while(!found && i <= types->size())
    {
        found = (types->at(i - 1) == type);
        i = i + 1;
    }

    return found;
}

std::string ValueImpl::objectId() 
{
	//generated from body annotation
	return "SemanticVisitor";//typename(SemanticVisitor); //return super.toString();

}

uml::ValueSpecification *  ValueImpl::specify() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ValueImpl::toString() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return boost::any();
}

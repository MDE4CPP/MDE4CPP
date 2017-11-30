#include "ValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include <Classifier.hpp>

//Forward declaration includes
#include "Classifier.hpp"

#include "SemanticVisitor.hpp"

#include "Value.hpp"

#include "ValueSpecification.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ValueImpl::ValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ValueImpl::~ValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Value "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




ValueImpl::ValueImpl(const ValueImpl & obj):ValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Value "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getValue();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Classifier> > myTypes = this->getTypes();
	std::shared_ptr<Bag<uml::Classifier> > otherTypes = otherValue->getTypes();

    DEBUG_MESSAGE(std::cout<<"in Value"<<std::endl;)
    bool isEqual = true;

    if(myTypes->size() != otherTypes->size())
    {
        isEqual = false;
    }
    else
    {
        unsigned int i = 0;
        while(isEqual && i < myTypes->size())
        {
            bool matched = false;
            unsigned int j = 0;
            while(!matched && j < otherTypes->size())
            {
                matched = (otherTypes->at(j) == myTypes->at(i));
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ValueImpl::getTypes()  const 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::hasTypes(std::shared_ptr<uml::Classifier>  type) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Classifier> > types = this->getTypes();

    bool found = false;
    unsigned int i = 0;
    while(!found && i < types->size())
    {
        found = (types->at(i) == type);
        i = i + 1;
    }

    return found;
	//end of body
}

std::string ValueImpl::objectId() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "SemanticVisitor";//typename(SemanticVisitor); //return super.toString();

	//end of body
}

std::shared_ptr<uml::ValueSpecification> ValueImpl::specify() 
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

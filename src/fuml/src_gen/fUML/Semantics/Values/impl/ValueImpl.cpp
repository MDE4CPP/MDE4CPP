#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "abstractDataTypes/Subset.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Values;

//*********************************
// Constructor / Destructor
//*********************************
ValueImpl::ValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ValueImpl::~ValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Value "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ValueImpl::ValueImpl(const ValueImpl & obj): ValueImpl()
{
	*this = obj;
}

ValueImpl& ValueImpl::operator=(const ValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticVisitorImpl::operator=(obj);
	Value::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Value "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ValueImpl::copy() const
{
	std::shared_ptr<ValueImpl> element(new ValueImpl());
	*element =(*this);
	element->setThisValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ValueImpl::eStaticClass() const
{
	return fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new value that is equal to this value.
// By default, this operation simply creates a new value with empty properties.
// It must be overridden in each Value subclass to do the superclass copy and then appropriately set properties defined in the subclass.

std::shared_ptr<fUML::Semantics::Values::Value> newValue(new fUML::Semantics::Values::ValueImpl());
return newValue;
	//end of body
}

bool ValueImpl::checkAllParents(std::shared_ptr<uml::Classifier> type,std::shared_ptr<uml::Classifier> classifier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
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

std::shared_ptr<Bag<uml::Classifier> > ValueImpl::getTypes() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ValueImpl::hasTypes(std::shared_ptr<uml::Classifier> type)
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



std::shared_ptr<Value> ValueImpl::getThisValuePtr() const
{
	return m_thisValuePtr.lock();
}
void ValueImpl::setThisValuePtr(std::weak_ptr<Value> thisValuePtr)
{
	m_thisValuePtr = thisValuePtr;
	setThisSemanticVisitorPtr(thisValuePtr);
}
std::shared_ptr<ecore::EObject> ValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::eGet(featureID, resolve, coreType);
}
bool ValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticVisitorImpl::internalEIsSet(featureID);
}
bool ValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticVisitorImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 11809
		case ValuesPackage::VALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 11808
		case ValuesPackage::VALUE_OPERATION_CHECKALLPARENTS_CLASSIFIER_CLASSIFIER:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			//Retrieve input parameter 'classifier'
			//parameter 1
			std::shared_ptr<uml::Classifier> incoming_param_classifier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->checkAllParents(incoming_param_type,incoming_param_classifier));
			break;
		}
		
		// 11803
		case ValuesPackage::VALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue));
			break;
		}
		
		// 11804
		case ValuesPackage::VALUE_OPERATION_GETTYPES:
		{
			result = eAny(this->getTypes());
			break;
		}
		
		// 11805
		case ValuesPackage::VALUE_OPERATION_HASTYPES_CLASSIFIER:
		{
			//Retrieve input parameter 'type'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_type_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_type = (*incoming_param_type_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->hasTypes(incoming_param_type));
			break;
		}
		
		// 11807
		case ValuesPackage::VALUE_OPERATION_OBJECTID:
		{
			result = eAny(this->objectId());
			break;
		}
		
		// 11802
		case ValuesPackage::VALUE_OPERATION_SPECIFY:
		{
			result = eAny(this->specify());
			break;
		}
		
		// 11806
		case ValuesPackage::VALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticVisitorImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticVisitorImpl::loadAttributes(loadHandler, attr_list);
}

void ValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticVisitorImpl::loadNode(nodeName, loadHandler);
}

void ValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticVisitorImpl::resolveReferences(featureID, references);
}

void ValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Values::ValuesPackage> package = fUML::Semantics::Values::ValuesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "fUML/Semantics/Loci/impl/FirstChoiceStrategyImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Loci;

//*********************************
// Constructor / Destructor
//*********************************
FirstChoiceStrategyImpl::FirstChoiceStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FirstChoiceStrategyImpl::~FirstChoiceStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FirstChoiceStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


FirstChoiceStrategyImpl::FirstChoiceStrategyImpl(const FirstChoiceStrategyImpl & obj): FirstChoiceStrategyImpl()
{
	*this = obj;
}

FirstChoiceStrategyImpl& FirstChoiceStrategyImpl::operator=(const FirstChoiceStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	ChoiceStrategyImpl::operator=(obj);
	FirstChoiceStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FirstChoiceStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FirstChoiceStrategyImpl::copy() const
{
	std::shared_ptr<FirstChoiceStrategyImpl> element(new FirstChoiceStrategyImpl());
	*element =(*this);
	element->setThisFirstChoiceStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FirstChoiceStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::Loci::LociPackage::eInstance()->getFirstChoiceStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int FirstChoiceStrategyImpl::choose(int size)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return 1;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<FirstChoiceStrategy> FirstChoiceStrategyImpl::getThisFirstChoiceStrategyPtr() const
{
	return m_thisFirstChoiceStrategyPtr.lock();
}
void FirstChoiceStrategyImpl::setThisFirstChoiceStrategyPtr(std::weak_ptr<FirstChoiceStrategy> thisFirstChoiceStrategyPtr)
{
	m_thisFirstChoiceStrategyPtr = thisFirstChoiceStrategyPtr;
	setThisChoiceStrategyPtr(thisFirstChoiceStrategyPtr);
}
std::shared_ptr<ecore::EObject> FirstChoiceStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FirstChoiceStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ChoiceStrategyImpl::eGet(featureID, resolve, coreType);
}
bool FirstChoiceStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ChoiceStrategyImpl::internalEIsSet(featureID);
}
bool FirstChoiceStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ChoiceStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any FirstChoiceStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5603
		case LociPackage::FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT:
		{
			//Retrieve input parameter 'size'
			//parameter 0
			int incoming_param_size;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_size_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_size = (*incoming_param_size_arguments_citer)->get()->get<int >();
			result = eAny(this->choose(incoming_param_size));
			break;
		}

		default:
		{
			// call superTypes
			result = ChoiceStrategyImpl::eInvoke(operationID, arguments);
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
void FirstChoiceStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FirstChoiceStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ChoiceStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void FirstChoiceStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ChoiceStrategyImpl::loadNode(nodeName, loadHandler);
}

void FirstChoiceStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ChoiceStrategyImpl::resolveReferences(featureID, references);
}

void FirstChoiceStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ChoiceStrategyImpl::saveContent(saveHandler);
	
	SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void FirstChoiceStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Loci::LociPackage> package = fUML::Semantics::Loci::LociPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


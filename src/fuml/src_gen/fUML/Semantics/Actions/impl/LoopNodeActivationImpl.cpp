#include "fUML/Semantics/Actions/impl/LoopNodeActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/UmlFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/Values.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeActivationImpl::LoopNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LoopNodeActivationImpl::LoopNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:LoopNodeActivationImpl()
{
	m_group = par_group;
}

LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj): LoopNodeActivationImpl()
{
	*this = obj;
}

LoopNodeActivationImpl& LoopNodeActivationImpl::operator=(const LoopNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeActivationImpl::operator=(obj);
	LoopNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> bodyOutputListsContainer = getBodyOutputLists();
	if(nullptr != bodyOutputListsContainer )
	{
		int size = bodyOutputListsContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _bodyOutputLists=(*bodyOutputListsContainer)[i];
			if(nullptr != _bodyOutputLists)
			{
				bodyOutputListsContainer->push_back(std::dynamic_pointer_cast<fUML::Semantics::Actions::Values>(_bodyOutputLists->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container bodyOutputLists."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr bodyOutputLists."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> LoopNodeActivationImpl::copy() const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl());
	*element =(*this);
	element->setThisLoopNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LoopNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getLoopNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::ActivityNode> LoopNodeActivationImpl::makeLoopVariableList()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void LoopNodeActivationImpl::runBody()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void LoopNodeActivationImpl::runLoopVariables()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LoopNodeActivationImpl::runTest()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference bodyOutputLists
*/
std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> LoopNodeActivationImpl::getBodyOutputLists() const
{
	if(m_bodyOutputLists == nullptr)
	{
		m_bodyOutputLists.reset(new Bag<fUML::Semantics::Actions::Values>());
		
		
	}

    return m_bodyOutputLists;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> LoopNodeActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}




std::shared_ptr<LoopNodeActivation> LoopNodeActivationImpl::getThisLoopNodeActivationPtr() const
{
	return m_thisLoopNodeActivationPtr.lock();
}
void LoopNodeActivationImpl::setThisLoopNodeActivationPtr(std::weak_ptr<LoopNodeActivation> thisLoopNodeActivationPtr)
{
	m_thisLoopNodeActivationPtr = thisLoopNodeActivationPtr;
	setThisStructuredActivityNodeActivationPtr(thisLoopNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> LoopNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LoopNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			return eAny(getBodyOutputLists()); //7812			
		}
	}
	return StructuredActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool LoopNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
			return getBodyOutputLists() != nullptr; //7812
	}
	return StructuredActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool LoopNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> bodyOutputListsList(new Bag<fUML::Semantics::Actions::Values>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyOutputListsList->add(std::dynamic_pointer_cast<fUML::Semantics::Actions::Values>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Actions::Values>::iterator iterBodyOutputLists = m_bodyOutputLists->begin();
			Bag<fUML::Semantics::Actions::Values>::iterator endBodyOutputLists = m_bodyOutputLists->end();
			while (iterBodyOutputLists != endBodyOutputLists)
			{
				if (bodyOutputListsList->find(*iterBodyOutputLists) == -1)
				{
					m_bodyOutputLists->erase(*iterBodyOutputLists);
				}
				iterBodyOutputLists++;
			}
 
			iterBodyOutputLists = bodyOutputListsList->begin();
			endBodyOutputLists = bodyOutputListsList->end();
			while (iterBodyOutputLists != endBodyOutputLists)
			{
				if (m_bodyOutputLists->find(*iterBodyOutputLists) == -1)
				{
					m_bodyOutputLists->add(*iterBodyOutputLists);
				}
				iterBodyOutputLists++;			
			}
			return true;
		}
	}

	return StructuredActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LoopNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 7877
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_MAKELOOPVARIABLELIST:
		{
			result = eAny(this->makeLoopVariableList());
			break;
		}
		
		// 7875
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNBODY:
		{
			this->runBody();
			break;
		}
		
		// 7876
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNLOOPVARIABLES:
		{
			this->runLoopVariables();
			break;
		}
		
		// 7874
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNTEST:
		{
			result = eAny(this->runTest());
			break;
		}

		default:
		{
			// call superTypes
			result = StructuredActivityNodeActivationImpl::eInvoke(operationID, arguments);
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
void LoopNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LoopNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void LoopNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("bodyOutputLists") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Values";
			}
			loadHandler->handleChildContainer<fUML::Semantics::Actions::Values>(this->getBodyOutputLists());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	StructuredActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void LoopNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void LoopNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void LoopNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'bodyOutputLists'

		saveHandler->addReferences<fUML::Semantics::Actions::Values>("bodyOutputLists", this->getBodyOutputLists());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


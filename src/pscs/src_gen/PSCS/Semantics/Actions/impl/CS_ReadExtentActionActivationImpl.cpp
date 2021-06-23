#include "PSCS/Semantics/Actions/impl/CS_ReadExtentActionActivationImpl.hpp"

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
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/ReadExtentAction.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"


#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/ReadExtentActionActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_ReadExtentActionActivationImpl::CS_ReadExtentActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_ReadExtentActionActivationImpl::~CS_ReadExtentActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ReadExtentActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_ReadExtentActionActivationImpl::CS_ReadExtentActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_ReadExtentActionActivationImpl()
{
	m_group = par_group;
}

CS_ReadExtentActionActivationImpl::CS_ReadExtentActionActivationImpl(const CS_ReadExtentActionActivationImpl & obj): CS_ReadExtentActionActivationImpl()
{
	*this = obj;
}

CS_ReadExtentActionActivationImpl& CS_ReadExtentActionActivationImpl::operator=(const CS_ReadExtentActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::ReadExtentActionActivationImpl::operator=(obj);
	CS_ReadExtentActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ReadExtentActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ReadExtentActionActivationImpl::copy() const
{
	std::shared_ptr<CS_ReadExtentActionActivationImpl> element(new CS_ReadExtentActionActivationImpl());
	*element =(*this);
	element->setThisCS_ReadExtentActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_ReadExtentActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ReadExtentActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_ReadExtentActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the extent, at the current execution locus, of the classifier
	// (which must be a class) identified in the action.
	// Place references to the resulting set of objects on the result pin.
	// Extends default fUML semantics in the sense that produced tokens contain
	// CS_References instead of References, in the case where the object is a
	// CS_Object

	std::shared_ptr<uml::ReadExtentAction> action = std::dynamic_pointer_cast<uml::ReadExtentAction>(this->getNode());
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> objects = this->getExecutionLocus()->retrieveExtent(action->getClassifier());
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> references(new Bag<fUML::Semantics::Values::Value>());
	
	for(unsigned int i = 0; i < objects->size(); i++) {
		std::shared_ptr<fUML::Semantics::Values::Value> object = objects->at(i);
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = nullptr;
		if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object) != nullptr) {
			reference = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
			(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Reference>(reference))->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(object));
		}
		else {
			reference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
		}
		reference->setReferent(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(object));
		references->add(reference);
	}	
	this->putTokens(action->getResult(), references);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_ReadExtentActionActivationImpl::getPinActivation() const
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




std::shared_ptr<CS_ReadExtentActionActivation> CS_ReadExtentActionActivationImpl::getThisCS_ReadExtentActionActivationPtr() const
{
	return m_thisCS_ReadExtentActionActivationPtr.lock();
}
void CS_ReadExtentActionActivationImpl::setThisCS_ReadExtentActionActivationPtr(std::weak_ptr<CS_ReadExtentActionActivation> thisCS_ReadExtentActionActivationPtr)
{
	m_thisCS_ReadExtentActionActivationPtr = thisCS_ReadExtentActionActivationPtr;
	setThisReadExtentActionActivationPtr(thisCS_ReadExtentActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_ReadExtentActionActivationImpl::eContainer() const
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
Any CS_ReadExtentActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ReadExtentActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool CS_ReadExtentActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ReadExtentActionActivationImpl::internalEIsSet(featureID);
}
bool CS_ReadExtentActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::ReadExtentActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_ReadExtentActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2458
		case ActionsPackage::CS_READEXTENTACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::ReadExtentActionActivationImpl::eInvoke(operationID, arguments);
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
void CS_ReadExtentActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_ReadExtentActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::ReadExtentActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ReadExtentActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::ReadExtentActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_ReadExtentActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::ReadExtentActionActivationImpl::resolveReferences(featureID, references);
}

void CS_ReadExtentActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::ReadExtentActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CS_ReadExtentActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


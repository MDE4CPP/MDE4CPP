
#include "PSCS/Semantics/Actions/impl/CS_AddStructuralFeatureValueActionActivationImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Includes from codegen annotation
/*
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"

#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Port.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Association.hpp"
#include "uml/umlPackage.hpp"
#include "uml/InputPin.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
*/
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "fUML/Semantics/Actions/AddStructuralFeatureValueActionActivation.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_AddStructuralFeatureValueActionActivationImpl::~CS_AddStructuralFeatureValueActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_AddStructuralFeatureValueActionActivationImpl()
{
	m_group = par_group;
}

CS_AddStructuralFeatureValueActionActivationImpl::CS_AddStructuralFeatureValueActionActivationImpl(const CS_AddStructuralFeatureValueActionActivationImpl & obj): CS_AddStructuralFeatureValueActionActivationImpl()
{
	*this = obj;
}

CS_AddStructuralFeatureValueActionActivationImpl& CS_AddStructuralFeatureValueActionActivationImpl::operator=(const CS_AddStructuralFeatureValueActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_AddStructuralFeatureValueActionActivation 
	 * which is generated by the compiler (as CS_AddStructuralFeatureValueActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_AddStructuralFeatureValueActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AddStructuralFeatureValueActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AddStructuralFeatureValueActionActivationImpl> element(new CS_AddStructuralFeatureValueActionActivationImpl());
	*element =(*this);
	element->setThisCS_AddStructuralFeatureValueActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************




//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_AddStructuralFeatureValueActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_AddStructuralFeatureValueActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_AddStructuralFeatureValueActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AddStructuralFeatureValueActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_AddStructuralFeatureValueActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::resolveReferences(featureID, references);
}

void CS_AddStructuralFeatureValueActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::WriteStructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_AddStructuralFeatureValueActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

const std::shared_ptr<ecore::EClass>& CS_AddStructuralFeatureValueActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_AddStructuralFeatureValueActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CS_AddStructuralFeatureValueActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CS_AddStructuralFeatureValueActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::internalEIsSet(featureID);
}

bool CS_AddStructuralFeatureValueActionActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CS_AddStructuralFeatureValueActionActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> CS_AddStructuralFeatureValueActionActivationImpl::getThisCS_AddStructuralFeatureValueActionActivationPtr() const
{
	return m_thisCS_AddStructuralFeatureValueActionActivationPtr.lock();
}
void CS_AddStructuralFeatureValueActionActivationImpl::setThisCS_AddStructuralFeatureValueActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> thisCS_AddStructuralFeatureValueActionActivationPtr)
{
	m_thisCS_AddStructuralFeatureValueActionActivationPtr = thisCS_AddStructuralFeatureValueActionActivationPtr;
	setThisAddStructuralFeatureValueActionActivationPtr(thisCS_AddStructuralFeatureValueActionActivationPtr);
}



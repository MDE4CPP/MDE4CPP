
#include "PSCS/Semantics/Actions/impl/CS_CreateLinkActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/CreateLinkAction.hpp"
#include "uml/LinkEndCreationData.hpp"
#include "uml/Association.hpp"
#include "uml/Property.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
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
#include "fUML/Semantics/Actions/CreateLinkActionActivation.hpp"
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
CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_CreateLinkActionActivationImpl::~CS_CreateLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_CreateLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_CreateLinkActionActivationImpl()
{
	m_group = par_group;
}

CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl(const CS_CreateLinkActionActivationImpl & obj): CS_CreateLinkActionActivationImpl()
{
	*this = obj;
}

CS_CreateLinkActionActivationImpl& CS_CreateLinkActionActivationImpl::operator=(const CS_CreateLinkActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::CreateLinkActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_CreateLinkActionActivation 
	 * which is generated by the compiler (as CS_CreateLinkActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_CreateLinkActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_CreateLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_CreateLinkActionActivationImpl::copy() const
{
	std::shared_ptr<CS_CreateLinkActionActivationImpl> element(new CS_CreateLinkActionActivationImpl());
	*element =(*this);
	element->setThisCS_CreateLinkActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CS_CreateLinkActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Get the extent at the current execution locus of the association for
	// which a link is being created.
	// Destroy all links that have a value for any end for which
	// isReplaceAll is true.
	// Create a new link for the association, at the current locus, with the
	// given end data values,
	// inserted at the given insertAt position (for ordered ends).
	// fUML semantics is extended in the sense that a CS_Link is created instead of
	// a Link

	std::shared_ptr<uml::CreateLinkAction> action = std::dynamic_pointer_cast<uml::CreateLinkAction>(this->getNode());
	std::shared_ptr<Bag<uml::LinkEndCreationData>> endDataList = std::dynamic_pointer_cast<Bag<uml::LinkEndCreationData>>(action->getEndData());
	
	std::shared_ptr<uml::Association> linkAssociation = this->getAssociation();
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = this->getExecutionLocus()->retrieveExtent(linkAssociation);
	
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> oldLink = nullptr;
	for(unsigned int i = 0; i < extent->size(); i++) {
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value = extent->at(i);
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(value);
		
		bool noMatch = true;
		unsigned int j = 1;
		while ((noMatch) && (j <= endDataList->size())) {
			std::shared_ptr<uml::LinkEndCreationData> endData = endDataList->at(j-1);
			if((endData->getIsReplaceAll()) && (this->endMatchesEndData(link, endData))) {
				oldLink = link;
				link->destroy();
				noMatch = false;
			}
			j += 1;
		}
	}
	
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> newLink = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Link();
	newLink->setType(linkAssociation);
	// This is necessary when setting a feature value with an insertAt position
	newLink->setLocus(this->getExecutionLocus());
	
	for(unsigned int i = 0; i < endDataList->size(); i++) {
		std::shared_ptr<uml::LinkEndCreationData> endData = endDataList->at(i);
		
		int insertAt;
		if (endData->getInsertAt() == nullptr) {
			insertAt = 0;
		}
		else {
			insertAt = (std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue>(this->takeTokens(endData->getInsertAt())->at(0)))->getValue();
			if(oldLink != nullptr) {
				if(oldLink->retrieveFeatureValue(endData->getEnd())->getPosition() < insertAt) {
					insertAt = insertAt - 1;
				}
			}
		}
		newLink->assignFeatureValue(endData->getEnd(), this->takeTokens(endData->getValue()), insertAt);
	}
	
	this->getExecutionLocus()->add(newLink);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_CreateLinkActionActivationImpl::getPinActivation() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_CreateLinkActionActivationImpl::eContainer() const
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
void CS_CreateLinkActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_CreateLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::CreateLinkActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_CreateLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::CreateLinkActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_CreateLinkActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::CreateLinkActionActivationImpl::resolveReferences(featureID, references);
}

void CS_CreateLinkActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::CreateLinkActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::WriteLinkActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::LinkActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_CreateLinkActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> CS_CreateLinkActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_CreateLinkActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_CreateLinkActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::CreateLinkActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CS_CreateLinkActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::CreateLinkActionActivationImpl::internalEIsSet(featureID);
}

bool CS_CreateLinkActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::CreateLinkActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_CreateLinkActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Actions::CS_CreateLinkActionActivation::doAction(): 3584940798
		case ActionsPackage::CS_CREATELINKACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::CreateLinkActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> CS_CreateLinkActionActivationImpl::getThisCS_CreateLinkActionActivationPtr() const
{
	return m_thisCS_CreateLinkActionActivationPtr.lock();
}
void CS_CreateLinkActionActivationImpl::setThisCS_CreateLinkActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> thisCS_CreateLinkActionActivationPtr)
{
	m_thisCS_CreateLinkActionActivationPtr = thisCS_CreateLinkActionActivationPtr;
	setThisCreateLinkActionActivationPtr(thisCS_CreateLinkActionActivationPtr);
}



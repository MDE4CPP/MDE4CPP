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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "fUML/Semantics/Actions/CreateLinkActionActivation.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl()
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

CS_CreateLinkActionActivationImpl::~CS_CreateLinkActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_CreateLinkActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
			:CS_CreateLinkActionActivationImpl()
			{
			    m_group = par_group;
			}






CS_CreateLinkActionActivationImpl::CS_CreateLinkActionActivationImpl(const CS_CreateLinkActionActivationImpl & obj):CS_CreateLinkActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_CreateLinkActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::Semantics::Activities::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Semantics::Activities::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Semantics::Activities::Token>(std::dynamic_pointer_cast<fUML::Semantics::Activities::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::InputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation>(std::dynamic_pointer_cast<fUML::Semantics::Actions::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CS_CreateLinkActionActivationImpl::copy() const
{
	std::shared_ptr<CS_CreateLinkActionActivationImpl> element(new CS_CreateLinkActionActivationImpl(*this));
	element->setThisCS_CreateLinkActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_CreateLinkActionActivationImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_CreateLinkActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

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
	
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> newLink = PSCS::PSCSFactory::eInstance()->createCS_Link();
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
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_CreateLinkActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<CS_CreateLinkActionActivation> CS_CreateLinkActionActivationImpl::getThisCS_CreateLinkActionActivationPtr() const
{
	return m_thisCS_CreateLinkActionActivationPtr.lock();
}
void CS_CreateLinkActionActivationImpl::setThisCS_CreateLinkActionActivationPtr(std::weak_ptr<CS_CreateLinkActionActivation> thisCS_CreateLinkActionActivationPtr)
{
	m_thisCS_CreateLinkActionActivationPtr = thisCS_CreateLinkActionActivationPtr;
	setThisCreateLinkActionActivationPtr(thisCS_CreateLinkActionActivationPtr);
}
std::shared_ptr<ecore::EObject> CS_CreateLinkActionActivationImpl::eContainer() const
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
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CS_CreateLinkActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::CreateLinkActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_CreateLinkActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{


	fUML::Semantics::Actions::CreateLinkActionActivationImpl::loadNode(nodeName, loadHandler, fUML::FUMLFactory::eInstance());
}

void CS_CreateLinkActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
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
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


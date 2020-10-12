#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"

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
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"

#include "fUML/Semantics/Actions/ActionActivation.hpp"

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/Association.hpp"

#include "fUML/Semantics/Actions/InputPinActivation.hpp"

#include "fUML/Semantics/StructuredClassifiers/Link.hpp"

#include "fUML/Semantics/Actions/OutputPinActivation.hpp"

#include "fUML/Semantics/Actions/PinActivation.hpp"

#include "uml/Property.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/Activities/Token.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl()
{	
}

StructuralFeatureActionActivationImpl::~StructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
:StructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}


StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(const StructuralFeatureActionActivationImpl & obj):StructuralFeatureActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_action  = obj.getAction();

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

std::shared_ptr<ecore::EObject>  StructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<StructuralFeatureActionActivationImpl> element(new StructuralFeatureActionActivationImpl(*this));
	element->setThisStructuralFeatureActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuralFeatureActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Association> StructuralFeatureActionActivationImpl::getAssociation(std::shared_ptr<uml::StructuralFeature>  feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If the structural feature for the action of this activation is an association end,
// then get the associated association.

std::shared_ptr<uml::Association> association = nullptr;
std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

if(property != nullptr)
{
	association = property->getAssociation();
}

return association;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > StructuralFeatureActionActivationImpl::getMatchingLinks(std::shared_ptr<uml::Association>  association,std::shared_ptr<uml::StructuralFeature>  end,std::shared_ptr<fUML::Semantics::Values::Value>  oppositeValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given value

return getMatchingLinksForEndValue(association, end, oppositeValue, nullptr);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > StructuralFeatureActionActivationImpl::getMatchingLinksForEndValue(std::shared_ptr<uml::Association>  association,std::shared_ptr<uml::StructuralFeature>  end,std::shared_ptr<fUML::Semantics::Values::Value>  oppositeValue,std::shared_ptr<fUML::Semantics::Values::Value>  endValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given opposite value and, optionally, that
// has a given end value for the given end.

std::shared_ptr<uml::Property> oppositeEnd = getOppositeEnd(association, end);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = this->getExecutionLocus()->retrieveExtent(association);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links(new Bag<fUML::Semantics::StructuredClassifiers::Link>);
for(unsigned int i = 0; i < extent->size(); i++){
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link = extent->at(i);
	if(link->retrieveFeatureValue(oppositeEnd)->getValues()->at(0) == oppositeValue) {
		bool matches = true;
		if(endValue != nullptr) {
			matches = (link->retrieveFeatureValue(end)->getValues()->at(0) == endValue);
		}
		
		if(matches){
			if(!(std::dynamic_pointer_cast<uml::MultiplicityElement>(end)->getIsOrdered()) || (links->size() == 0)){
				links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
			}
			else {
				unsigned int n = link->retrieveFeatureValue(end)->getPosition();
				bool continueSearching = true;
				unsigned int j = 0;
				while(continueSearching && (j < links->size())){
					j += 1;
					continueSearching = (unsigned int)(links->at(j-1)->retrieveFeatureValue(end)->getPosition()) < n;
				}
				if(continueSearching){
					links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
				else {
					links->insert((links->begin() + (j-1)), std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
			}
		}
	}
}

return links;
	//end of body
}

std::shared_ptr<uml::Property> StructuralFeatureActionActivationImpl::getOppositeEnd(std::shared_ptr<uml::Association>  association,std::shared_ptr<uml::StructuralFeature>  end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the end of a binary association opposite to the given end.

std::shared_ptr<uml::Property> oppositeEnd = association->getMemberEnd()->at(0);
if(oppositeEnd == end)
{
		oppositeEnd = association->getMemberEnd()->at(1);
}

return oppositeEnd;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> StructuralFeatureActionActivationImpl::getPinActivation() const
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




std::shared_ptr<StructuralFeatureActionActivation> StructuralFeatureActionActivationImpl::getThisStructuralFeatureActionActivationPtr() const
{
	return m_thisStructuralFeatureActionActivationPtr.lock();
}
void StructuralFeatureActionActivationImpl::setThisStructuralFeatureActionActivationPtr(std::weak_ptr<StructuralFeatureActionActivation> thisStructuralFeatureActionActivationPtr)
{
	m_thisStructuralFeatureActionActivationPtr = thisStructuralFeatureActionActivationPtr;
	setThisActionActivationPtr(thisStructuralFeatureActionActivationPtr);
}
std::shared_ptr<ecore::EObject> StructuralFeatureActionActivationImpl::eContainer() const
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
Any StructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool StructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}
bool StructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void StructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void StructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void StructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ActionActivationImpl::resolveReferences(featureID, references);
}

void StructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void StructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


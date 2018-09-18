#include "fUML/impl/ReadStructuralFeatureActionActivationImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "fUML/impl/FUMLPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/InputPinActivation.hpp"

#include "fUML/OutputPinActivation.hpp"

#include "fUML/PinActivation.hpp"

#include "fUML/StructuralFeatureActionActivation.hpp"

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl()
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

ReadStructuralFeatureActionActivationImpl::~ReadStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ReadStructuralFeatureActionActivationImpl()
			{
			    m_group = par_group;
			}






ReadStructuralFeatureActionActivationImpl::ReadStructuralFeatureActionActivationImpl(const ReadStructuralFeatureActionActivationImpl & obj):ReadStructuralFeatureActionActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firing = obj.isFiring();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));

	std::shared_ptr<Union<fUML::PinActivation>> _pinActivation = obj.getPinActivation();
	m_pinActivation.reset(new Union<fUML::PinActivation>(*(obj.getPinActivation().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::InputPinActivation>> _inputPinActivationList = obj.getInputPinActivation();
	for(std::shared_ptr<fUML::InputPinActivation> _inputPinActivation : *_inputPinActivationList)
	{
		this->getInputPinActivation()->add(std::shared_ptr<fUML::InputPinActivation>(std::dynamic_pointer_cast<fUML::InputPinActivation>(_inputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inputPinActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::OutputPinActivation>> _outputPinActivationList = obj.getOutputPinActivation();
	for(std::shared_ptr<fUML::OutputPinActivation> _outputPinActivation : *_outputPinActivationList)
	{
		this->getOutputPinActivation()->add(std::shared_ptr<fUML::OutputPinActivation>(std::dynamic_pointer_cast<fUML::OutputPinActivation>(_outputPinActivation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outputPinActivation" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ReadStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<ReadStructuralFeatureActionActivationImpl> element(new ReadStructuralFeatureActionActivationImpl(*this));
	element->setThisReadStructuralFeatureActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReadStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReadStructuralFeatureActionActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> ReadStructuralFeatureActionActivationImpl::getPinActivation() const
{
	return m_pinActivation;
}


std::shared_ptr<ReadStructuralFeatureActionActivation> ReadStructuralFeatureActionActivationImpl::getThisReadStructuralFeatureActionActivationPtr() const
{
	return m_thisReadStructuralFeatureActionActivationPtr.lock();
}
void ReadStructuralFeatureActionActivationImpl::setThisReadStructuralFeatureActionActivationPtr(std::weak_ptr<ReadStructuralFeatureActionActivation> thisReadStructuralFeatureActionActivationPtr)
{
	m_thisReadStructuralFeatureActionActivationPtr = thisReadStructuralFeatureActionActivationPtr;
	setThisStructuralFeatureActionActivationPtr(thisReadStructuralFeatureActionActivationPtr);
}
std::shared_ptr<ecore::EObject> ReadStructuralFeatureActionActivationImpl::eContainer() const
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
Any ReadStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return StructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool ReadStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return StructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool ReadStructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return StructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ReadStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ReadStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ReadStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	StructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ReadStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	StructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void ReadStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ReadStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


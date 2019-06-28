#include "fUML/impl/LoopNodeActivationImpl.hpp"

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

#include "fUML/StructuredActivityNodeActivation.hpp"

#include "fUML/Token.hpp"

#include "fUML/Values.hpp"

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
LoopNodeActivationImpl::LoopNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_bodyOutputLists.reset(new Bag<fUML::Values>());
	
	

	//Init references
	
	
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LoopNodeActivationImpl::LoopNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:LoopNodeActivationImpl()
			{
			    m_group = par_group;
			}






LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj):LoopNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Values>> _bodyOutputListsList = obj.getBodyOutputLists();
	for(std::shared_ptr<fUML::Values> _bodyOutputLists : *_bodyOutputListsList)
	{
		this->getBodyOutputLists()->add(std::shared_ptr<fUML::Values>(std::dynamic_pointer_cast<fUML::Values>(_bodyOutputLists->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_bodyOutputLists" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  LoopNodeActivationImpl::copy() const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl(*this));
	element->setThisLoopNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LoopNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLoopNodeActivation_Class();
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
std::shared_ptr<Bag<fUML::Values>> LoopNodeActivationImpl::getBodyOutputLists() const
{

    return m_bodyOutputLists;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::PinActivation>> LoopNodeActivationImpl::getPinActivation() const
{
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
		case FUMLPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Values>::iterator iter = m_bodyOutputLists->begin();
			Bag<fUML::Values>::iterator end = m_bodyOutputLists->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7411
		}
	}
	return StructuredActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool LoopNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
			return getBodyOutputLists() != nullptr; //7411
	}
	return StructuredActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool LoopNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Values>> bodyOutputListsList(new Bag<fUML::Values>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bodyOutputListsList->add(std::dynamic_pointer_cast<fUML::Values>(*iter));
				iter++;
			}
			
			Bag<fUML::Values>::iterator iterBodyOutputLists = m_bodyOutputLists->begin();
			Bag<fUML::Values>::iterator endBodyOutputLists = m_bodyOutputLists->end();
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
// Persistence Functions
//*********************************
void LoopNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LoopNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void LoopNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
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
			std::shared_ptr<fUML::Values> bodyOutputLists = std::dynamic_pointer_cast<fUML::Values>(modelFactory->create(typeName));
			if (bodyOutputLists != nullptr)
			{
				std::shared_ptr<Bag<fUML::Values>> list_bodyOutputLists = this->getBodyOutputLists();
				list_bodyOutputLists->push_back(bodyOutputLists);
				loadHandler->handleChild(bodyOutputLists);
			}
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

	StructuredActivityNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LoopNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	StructuredActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void LoopNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void LoopNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'bodyOutputLists'
		std::shared_ptr<Bag<fUML::Values>> list_bodyOutputLists = this->getBodyOutputLists();
		for (std::shared_ptr<fUML::Values> bodyOutputLists : *list_bodyOutputLists) 
		{
			saveHandler->addReference(bodyOutputLists, "bodyOutputLists", bodyOutputLists->eClass() != package->getValues_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


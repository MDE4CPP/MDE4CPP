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
#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionsPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeActivationImpl::LoopNodeActivationImpl()
{	
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LoopNodeActivationImpl::LoopNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group)
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

	if(obj.getActivationGroup()!=nullptr)
	{
		m_activationGroup = std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityNodeActivationGroup>(obj.getActivationGroup()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_activationGroup" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> _bodyOutputListsList = obj.getBodyOutputLists();
	for(std::shared_ptr<fUML::Semantics::Actions::Values> _bodyOutputLists : *_bodyOutputListsList)
	{
		this->getBodyOutputLists()->add(std::shared_ptr<fUML::Semantics::Actions::Values>(std::dynamic_pointer_cast<fUML::Semantics::Actions::Values>(_bodyOutputLists->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_bodyOutputLists" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  LoopNodeActivationImpl::copy() const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl(*this));
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
std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> LoopNodeActivationImpl::makeLoopVariableList()
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
			/*
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Actions::Values>::iterator iter = m_bodyOutputLists->begin();
			Bag<fUML::Semantics::Actions::Values>::iterator end = m_bodyOutputLists->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //7812
			*/
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
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	try
	{
		if ( nodeName.compare("bodyOutputLists") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Values";
			}
			std::shared_ptr<fUML::Semantics::Actions::Values> bodyOutputLists = std::dynamic_pointer_cast<fUML::Semantics::Actions::Values>(modelFactory->create(typeName));
			if (bodyOutputLists != nullptr)
			{
				std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> list_bodyOutputLists = this->getBodyOutputLists();
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
	//load BasePackage Nodes
	StructuredActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
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
		std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> list_bodyOutputLists = this->getBodyOutputLists();
		for (std::shared_ptr<fUML::Semantics::Actions::Values> bodyOutputLists : *list_bodyOutputLists) 
		{
			saveHandler->addReference(bodyOutputLists, "bodyOutputLists", bodyOutputLists->eClass() !=fUML::Semantics::Actions::ActionsPackage::eInstance()->getValues_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


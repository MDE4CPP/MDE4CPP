
#include "uml/impl/LoopNodeImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeImpl::LoopNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopNodeImpl::~LoopNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:LoopNodeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:LoopNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LoopNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::Element> par_owner)
:LoopNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
LoopNodeImpl::LoopNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:LoopNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

LoopNodeImpl::LoopNodeImpl(const LoopNodeImpl & obj): LoopNodeImpl()
{
	*this = obj;
}

LoopNodeImpl& LoopNodeImpl::operator=(const LoopNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LoopNode 
	 * which is generated by the compiler (as LoopNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LoopNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isTestedFirst = obj.getIsTestedFirst();

	//copy references with no containment (soft copy)
	m_bodyOutput  = obj.getBodyOutput();
	m_bodyPart  = obj.getBodyPart();
	m_decider  = obj.getDecider();
	m_setupPart  = obj.getSetupPart();
	m_test  = obj.getTest();
	//Clone references with containment (deep copy)
	//clone reference 'loopVariable'
	std::shared_ptr<Subset<uml::OutputPin, uml::Element>> loopVariableList = obj.getLoopVariable();
	if(loopVariableList)
	{
		/*Subset*/
		m_loopVariable.reset(new Subset<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLoopVariable()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::OutputPin>& loopVariableindexElem: *loopVariableList) 
		{
			std::shared_ptr<uml::OutputPin> temp = std::dynamic_pointer_cast<uml::OutputPin>((loopVariableindexElem)->copy());
			m_loopVariable->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for loopVariable.")
	}
	/*Subset*/
	getLoopVariable()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> LoopNodeImpl::copy() const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl());
	*element =(*this);
	element->setThisLoopNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isTestedFirst */
bool LoopNodeImpl::getIsTestedFirst() const 
{
	return m_isTestedFirst;
}
void LoopNodeImpl::setIsTestedFirst(bool _isTestedFirst)
{
	m_isTestedFirst = _isTestedFirst;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bodyOutput */
const std::shared_ptr<Bag<uml::OutputPin>>& LoopNodeImpl::getBodyOutput() const
{
	if(m_bodyOutput == nullptr)
	{
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
		
		
	}
    return m_bodyOutput;
}

/* Getter & Setter for reference bodyPart */
const std::shared_ptr<Bag<uml::ExecutableNode>>& LoopNodeImpl::getBodyPart() const
{
	if(m_bodyPart == nullptr)
	{
		m_bodyPart.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_bodyPart;
}

/* Getter & Setter for reference decider */
const std::shared_ptr<uml::OutputPin>& LoopNodeImpl::getDecider() const
{
    return m_decider;
}
void LoopNodeImpl::setDecider(const std::shared_ptr<uml::OutputPin>& _decider)
{
    m_decider = _decider;
	
}

/* Getter & Setter for reference loopVariable */
const std::shared_ptr<Subset<uml::OutputPin, uml::Element>>& LoopNodeImpl::getLoopVariable() const
{
	if(m_loopVariable == nullptr)
	{
		/*Subset*/
		m_loopVariable.reset(new Subset<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getLoopVariable()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_loopVariable - Subset<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_loopVariable;
}

/* Getter & Setter for reference loopVariableInput */
std::shared_ptr<Bag<uml::InputPin>> LoopNodeImpl::getLoopVariableInput() const
{
	//Getter call of redefined container reference StructuredActivityNode::structuredNodeInput 
	return uml::StructuredActivityNodeImpl::getStructuredNodeInput();
}

/* Getter & Setter for reference result */
std::shared_ptr<Bag<uml::OutputPin>> LoopNodeImpl::getResult() const
{
	//Getter call of redefined container reference StructuredActivityNode::structuredNodeOutput 
	return uml::StructuredActivityNodeImpl::getStructuredNodeOutput();
}

/* Getter & Setter for reference setupPart */
const std::shared_ptr<Bag<uml::ExecutableNode>>& LoopNodeImpl::getSetupPart() const
{
	if(m_setupPart == nullptr)
	{
		m_setupPart.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_setupPart;
}

/* Getter & Setter for reference test */
const std::shared_ptr<Bag<uml::ExecutableNode>>& LoopNodeImpl::getTest() const
{
	if(m_test == nullptr)
	{
		m_test.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_test;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LoopNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}


	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LoopNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void LoopNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isTestedFirst");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsTestedFirst(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("bodyPart");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyPart")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decider");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decider")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("setupPart");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("setupPart")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("test");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("test")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuredActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void LoopNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("loopVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getLoopVariable());  

			return; 
		}

		if ( nodeName.compare("loopVariableInput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getLoopVariableInput());  

			return; 
		}

		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getResult());  

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
	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void LoopNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
		{
			const std::shared_ptr<Bag<uml::OutputPin>>& _bodyOutput = getBodyOutput();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::OutputPin>  _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
		{
			const std::shared_ptr<Bag<uml::ExecutableNode>>& _bodyPart = getBodyPart();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_bodyPart->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
		{
			const std::shared_ptr<Bag<uml::ExecutableNode>>& _setupPart = getSetupPart();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_setupPart->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
		{
			const std::shared_ptr<Bag<uml::ExecutableNode>>& _test = getTest();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_test->push_back(_r);
				}
			}
			return;
		}
	}
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void LoopNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	ActivityGroupImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LoopNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'loopVariable'
		for (const std::shared_ptr<uml::OutputPin>& loopVariable : *this->getLoopVariable()) 
		{
			saveHandler->addReference(loopVariable, "loopVariable", loopVariable->eClass() != package->getOutputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getLoopNode_Attribute_isTestedFirst()) )
		{
			saveHandler->addAttribute("isTestedFirst", this->getIsTestedFirst());
		}
	// Add references
		saveHandler->addReferences<uml::OutputPin>("bodyOutput", this->getBodyOutput());
		saveHandler->addReferences<uml::ExecutableNode>("bodyPart", this->getBodyPart());
		saveHandler->addReference(this->getDecider(), "decider", getDecider()->eClass() != uml::umlPackage::eInstance()->getOutputPin_Class()); 
		saveHandler->addReferences<uml::ExecutableNode>("setupPart", this->getSetupPart());
		saveHandler->addReferences<uml::ExecutableNode>("test", this->getTest());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'loopVariableInput'

		saveHandler->addReferences<uml::InputPin>("loopVariableInput", this->getLoopVariableInput());

		// Save 'result'

		saveHandler->addReferences<uml::OutputPin>("result", this->getResult());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& LoopNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLoopNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LoopNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
			return eEcoreContainerAny(getBodyOutput(),uml::umlPackage::OUTPUTPIN_CLASS); //14444
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
			return eEcoreContainerAny(getBodyPart(),uml::umlPackage::EXECUTABLENODE_CLASS); //14445
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
			return eAny(getDecider(),uml::umlPackage::OUTPUTPIN_CLASS,false); //14446
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
			return eAny(getIsTestedFirst(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //14447
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
			return eEcoreContainerAny(getLoopVariable(),uml::umlPackage::OUTPUTPIN_CLASS); //14448
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
			return eEcoreContainerAny(getLoopVariableInput(),uml::umlPackage::INPUTPIN_CLASS); //14449
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
			return eEcoreContainerAny(getResult(),uml::umlPackage::OUTPUTPIN_CLASS); //14450
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
			return eEcoreContainerAny(getSetupPart(),uml::umlPackage::EXECUTABLENODE_CLASS); //14451
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
			return eEcoreContainerAny(getTest(),uml::umlPackage::EXECUTABLENODE_CLASS); //14452
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool LoopNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //14444
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
			return getBodyPart() != nullptr; //14445
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
			return getDecider() != nullptr; //14446
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
			return getIsTestedFirst() != false; //14447
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
			return getLoopVariable() != nullptr; //14448
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
			return getLoopVariableInput() != nullptr; //14449
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //14450
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
			return getSetupPart() != nullptr; //14451
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
			return getTest() != nullptr; //14452
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}

bool LoopNodeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::OutputPin>>& _bodyOutput = getBodyOutput();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_bodyOutput->includes(valueToAdd)))
								{
									_bodyOutput->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'bodyOutput'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'bodyOutput'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_BODYPART:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExecutableNode>>& _bodyPart = getBodyPart();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExecutableNode> valueToAdd = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_bodyPart->includes(valueToAdd)))
								{
									_bodyPart->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'bodyPart'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'bodyPart'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_DECIDER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>(eObject);
					if(_decider)
					{
						setDecider(_decider); //14446
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'decider'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'decider'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_ISTESTEDFIRST:
		{
			try
			{
				bool _isTestedFirst = newValue->get<bool>();
				setIsTestedFirst(_isTestedFirst); //14447
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isTestedFirst'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::OutputPin>>& _loopVariable = getLoopVariable();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_loopVariable->includes(valueToAdd)))
								{
									_loopVariable->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'loopVariable'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'loopVariable'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::InputPin>>& _loopVariableInput = getLoopVariableInput();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InputPin> valueToAdd = std::dynamic_pointer_cast<uml::InputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_loopVariableInput->includes(valueToAdd)))
								{
									_loopVariableInput->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'loopVariableInput'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'loopVariableInput'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::OutputPin>>& _result = getResult();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_result->includes(valueToAdd)))
								{
									_result->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_SETUPPART:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExecutableNode>>& _setupPart = getSetupPart();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExecutableNode> valueToAdd = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_setupPart->includes(valueToAdd)))
								{
									_setupPart->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'setupPart'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'setupPart'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LOOPNODE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExecutableNode>>& _test = getTest();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExecutableNode> valueToAdd = std::dynamic_pointer_cast<uml::ExecutableNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_test->includes(valueToAdd)))
								{
									_test->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'test'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'test'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LoopNodeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = StructuredActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::LoopNode> LoopNodeImpl::getThisLoopNodePtr() const
{
	return m_thisLoopNodePtr.lock();
}
void LoopNodeImpl::setThisLoopNodePtr(std::weak_ptr<uml::LoopNode> thisLoopNodePtr)
{
	m_thisLoopNodePtr = thisLoopNodePtr;
	setThisStructuredActivityNodePtr(thisLoopNodePtr);
}



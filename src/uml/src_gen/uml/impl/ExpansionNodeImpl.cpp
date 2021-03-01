#include "uml/impl/ExpansionNodeImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExpansionRegion.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/ObjectNode.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionNodeImpl::ExpansionNodeImpl()
{	
}

ExpansionNodeImpl::~ExpansionNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ExpansionNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ExpansionNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExpansionNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExpansionNodeImpl::ExpansionNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ExpansionNodeImpl()
{
	m_owner = par_owner;
}

ExpansionNodeImpl::ExpansionNodeImpl(const ExpansionNodeImpl & obj): ExpansionNodeImpl()
{
	*this = obj;
}

ExpansionNodeImpl& ExpansionNodeImpl::operator=(const ExpansionNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectNodeImpl::operator=(obj);
	ExpansionNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_regionAsInput  = obj.getRegionAsInput();
	m_regionAsOutput  = obj.getRegionAsOutput();

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionNodeImpl::copy() const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl());
	*element =(*this);
	element->setThisExpansionNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExpansionNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExpansionNodeImpl::region_as_input_or_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference regionAsInput
*/
std::shared_ptr<uml::ExpansionRegion> ExpansionNodeImpl::getRegionAsInput() const
{

    return m_regionAsInput;
}
void ExpansionNodeImpl::setRegionAsInput(std::shared_ptr<uml::ExpansionRegion> _regionAsInput)
{
    m_regionAsInput = _regionAsInput;
}


/*
Getter & Setter for reference regionAsOutput
*/
std::shared_ptr<uml::ExpansionRegion> ExpansionNodeImpl::getRegionAsOutput() const
{

    return m_regionAsOutput;
}
void ExpansionNodeImpl::setRegionAsOutput(std::shared_ptr<uml::ExpansionRegion> _regionAsOutput)
{
    m_regionAsOutput = _regionAsOutput;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ExpansionNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> ExpansionNodeImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ExpansionNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ExpansionNodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<ExpansionNode> ExpansionNodeImpl::getThisExpansionNodePtr() const
{
	return m_thisExpansionNodePtr.lock();
}
void ExpansionNodeImpl::setThisExpansionNodePtr(std::weak_ptr<ExpansionNode> thisExpansionNodePtr)
{
	m_thisExpansionNodePtr = thisExpansionNodePtr;
	setThisObjectNodePtr(thisExpansionNodePtr);
}
std::shared_ptr<ecore::EObject> ExpansionNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExpansionNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT:
			return eAny(getRegionAsInput()); //9326
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT:
			return eAny(getRegionAsOutput()); //9327
	}
	return ObjectNodeImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT:
			return getRegionAsInput() != nullptr; //9326
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT:
			return getRegionAsOutput() != nullptr; //9327
	}
	return ObjectNodeImpl::internalEIsSet(featureID);
}
bool ExpansionNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ExpansionRegion> _regionAsInput = std::dynamic_pointer_cast<uml::ExpansionRegion>(_temp);
			setRegionAsInput(_regionAsInput); //9326
			return true;
		}
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ExpansionRegion> _regionAsOutput = std::dynamic_pointer_cast<uml::ExpansionRegion>(_temp);
			setRegionAsOutput(_regionAsOutput); //9327
			return true;
		}
	}

	return ObjectNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExpansionNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpansionNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("regionAsInput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("regionAsInput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("regionAsOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("regionAsOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ObjectNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ObjectNodeImpl::loadNode(nodeName, loadHandler);
}

void ExpansionNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExpansionRegion> _regionAsInput = std::dynamic_pointer_cast<uml::ExpansionRegion>( references.front() );
				setRegionAsInput(_regionAsInput);
			}
			
			return;
		}

		case uml::umlPackage::EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExpansionRegion> _regionAsOutput = std::dynamic_pointer_cast<uml::ExpansionRegion>( references.front() );
				setRegionAsOutput(_regionAsOutput);
			}
			
			return;
		}
	}
	ObjectNodeImpl::resolveReferences(featureID, references);
}

void ExpansionNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void ExpansionNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getRegionAsInput(), "regionAsInput", getRegionAsInput()->eClass() != uml::umlPackage::eInstance()->getExpansionRegion_Class()); 
		saveHandler->addReference(this->getRegionAsOutput(), "regionAsOutput", getRegionAsOutput()->eClass() != uml::umlPackage::eInstance()->getExpansionRegion_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


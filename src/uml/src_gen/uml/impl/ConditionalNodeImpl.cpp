#include "uml/impl/ConditionalNodeImpl.hpp"

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
#include "uml/Classifier.hpp"
#include "uml/Clause.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeImpl::ConditionalNodeImpl()
{	
}

ConditionalNodeImpl::~ConditionalNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:ConditionalNodeImpl()
{
	switch(reference_id)
	{	
	case umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ConditionalNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConditionalNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ConditionalNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ConditionalNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

ConditionalNodeImpl::ConditionalNodeImpl(const ConditionalNodeImpl & obj): StructuredActivityNodeImpl(obj), ConditionalNode(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConditionalNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isAssured = obj.getIsAssured();
	m_isDeterminate = obj.getIsDeterminate();

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Clause, uml::Element>> clauseContainer = getClause();
	for(auto _clause : *obj.getClause()) 
	{
		clauseContainer->push_back(std::dynamic_pointer_cast<uml::Clause>(_clause->copy()));
	}
	std::shared_ptr<Bag<uml::OutputPin>> resultContainer = getResult();
	for(auto _result : *obj.getResult()) 
	{
		resultContainer->push_back(std::dynamic_pointer_cast<uml::OutputPin>(_result->copy()));
	}
	/*Subset*/
	m_clause->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_clause - Subset<uml::Clause, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
}

std::shared_ptr<ecore::EObject>  ConditionalNodeImpl::copy() const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(*this));
	element->setThisConditionalNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConditionalNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConditionalNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isAssured
*/
bool ConditionalNodeImpl::getIsAssured() const 
{
	return m_isAssured;
}
void ConditionalNodeImpl::setIsAssured(bool _isAssured)
{
	m_isAssured = _isAssured;
} 


/*
Getter & Setter for attribute isDeterminate
*/
bool ConditionalNodeImpl::getIsDeterminate() const 
{
	return m_isDeterminate;
}
void ConditionalNodeImpl::setIsDeterminate(bool _isDeterminate)
{
	m_isDeterminate = _isDeterminate;
} 


//*********************************
// Operations
//*********************************
bool ConditionalNodeImpl::clause_no_predecessor(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::executable_nodes(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::matching_output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::no_input_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::one_clause_with_executable_node(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConditionalNodeImpl::result_no_incoming(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference clause
*/
std::shared_ptr<Subset<uml::Clause, uml::Element>> ConditionalNodeImpl::getClause() const
{
	if(m_clause == nullptr)
	{
		/*Subset*/
		m_clause.reset(new Subset<uml::Clause, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_clause - Subset<uml::Clause, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_clause->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_clause - Subset<uml::Clause, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
//assert(m_clause);
    return m_clause;
}



/*
Getter & Setter for reference result
*/
std::shared_ptr<Bag<uml::OutputPin>> ConditionalNodeImpl::getResult() const
{
	if(m_result == nullptr)
	{
		m_result.reset(new Bag<uml::OutputPin>());
		
		
	}

    return m_result;
}

/*Additional Setter for redefined reference 'StructuredActivityNode::structuredNodeOutput'*/



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ConditionalNodeImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> ConditionalNodeImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::ActivityGroup>> ConditionalNodeImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ConditionalNodeImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::NamedElement>> ConditionalNodeImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ConditionalNodeImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> ConditionalNodeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ConditionalNodeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ConditionalNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ConditionalNodeImpl::getRedefinedElement() const
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




std::shared_ptr<ConditionalNode> ConditionalNodeImpl::getThisConditionalNodePtr() const
{
	return m_thisConditionalNodePtr.lock();
}
void ConditionalNodeImpl::setThisConditionalNodePtr(std::weak_ptr<ConditionalNode> thisConditionalNodePtr)
{
	m_thisConditionalNodePtr = thisConditionalNodePtr;
	setThisStructuredActivityNodePtr(thisConditionalNodePtr);
}
std::shared_ptr<ecore::EObject> ConditionalNodeImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any ConditionalNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
		{
			return eAny(getClause()); //4944			
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
			return eAny(getIsAssured()); //4945
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
			return eAny(getIsDeterminate()); //4946
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
		{
			return eAny(getResult()); //4947			
		}
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}
bool ConditionalNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
			return getClause() != nullptr; //4944
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
			return getIsAssured() != false; //4945
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
			return getIsDeterminate() != false; //4946
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //4947
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}
bool ConditionalNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Clause>> clauseList(new Bag<uml::Clause>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				clauseList->add(std::dynamic_pointer_cast<uml::Clause>(*iter));
				iter++;
			}
			
			Bag<uml::Clause>::iterator iterClause = m_clause->begin();
			Bag<uml::Clause>::iterator endClause = m_clause->end();
			while (iterClause != endClause)
			{
				if (clauseList->find(*iterClause) == -1)
				{
					m_clause->erase(*iterClause);
				}
				iterClause++;
			}
 
			iterClause = clauseList->begin();
			endClause = clauseList->end();
			while (iterClause != endClause)
			{
				if (m_clause->find(*iterClause) == -1)
				{
					m_clause->add(*iterClause);
				}
				iterClause++;			
			}
			return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
		{
			// BOOST CAST
			bool _isAssured = newValue->get<bool>();
			setIsAssured(_isAssured); //4945
			return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
		{
			// BOOST CAST
			bool _isDeterminate = newValue->get<bool>();
			setIsDeterminate(_isDeterminate); //4946
			return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> resultList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				resultList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterResult = m_result->begin();
			Bag<uml::OutputPin>::iterator endResult = m_result->end();
			while (iterResult != endResult)
			{
				if (resultList->find(*iterResult) == -1)
				{
					m_result->erase(*iterResult);
				}
				iterResult++;
			}
 
			iterResult = resultList->begin();
			endResult = resultList->end();
			while (iterResult != endResult)
			{
				if (m_result->find(*iterResult) == -1)
				{
					m_result->add(*iterResult);
				}
				iterResult++;			
			}
			return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ConditionalNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConditionalNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isAssured");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAssured(value);
		}

		iter = attr_list.find("isDeterminate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDeterminate(value);
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

void ConditionalNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("clause") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Clause";
			}
			loadHandler->handleChildContainer<uml::Clause>(this->getClause());  

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

void ConditionalNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void ConditionalNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ConditionalNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'clause'
		for (std::shared_ptr<uml::Clause> clause : *this->getClause()) 
		{
			saveHandler->addReference(clause, "clause", clause->eClass() != package->getClause_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getConditionalNode_Attribute_isAssured()) )
		{
			saveHandler->addAttribute("isAssured", this->getIsAssured());
		}

		if ( this->eIsSet(package->getConditionalNode_Attribute_isDeterminate()) )
		{
			saveHandler->addAttribute("isDeterminate", this->getIsDeterminate());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'result'

		saveHandler->addReferences<uml::OutputPin>("result", this->getResult());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


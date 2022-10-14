
#include "uml/impl/StructuredActivityNodeImpl.hpp"
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
#include <stdexcept>
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
#include "uml/Action.hpp"
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
StructuredActivityNodeImpl::StructuredActivityNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredActivityNodeImpl::~StructuredActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:StructuredActivityNodeImpl()
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
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:StructuredActivityNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StructuredActivityNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Element> par_owner)
:StructuredActivityNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:StructuredActivityNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

StructuredActivityNodeImpl::StructuredActivityNodeImpl(const StructuredActivityNodeImpl & obj): StructuredActivityNodeImpl()
{
	*this = obj;
}

StructuredActivityNodeImpl& StructuredActivityNodeImpl::operator=(const StructuredActivityNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	NamespaceImpl::operator=(obj);
	ActivityGroupImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuredActivityNode 
	 * which is generated by the compiler (as StructuredActivityNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuredActivityNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_mustIsolate = obj.getMustIsolate();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'edge'
	std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element>> edgeList = obj.getEdge();
	if(edgeList)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getContainedEdge(), getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >(getContainedEdge(), getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityEdge> edgeindexElem: *edgeList) 
		{
			std::shared_ptr<uml::ActivityEdge> temp = std::dynamic_pointer_cast<uml::ActivityEdge>((edgeindexElem)->copy());
			m_edge->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for edge.")
	}

	//clone reference 'node'
	std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode, uml::Element>> nodeList = obj.getNode();
	if(nodeList)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode(), getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >(getContainedNode(), getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode> nodeindexElem: *nodeList) 
		{
			std::shared_ptr<uml::ActivityNode> temp = std::dynamic_pointer_cast<uml::ActivityNode>((nodeindexElem)->copy());
			m_node->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for node.")
	}

	//clone reference 'structuredNodeInput'
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> structuredNodeInputList = obj.getStructuredNodeInput();
	if(structuredNodeInputList)
	{
		/*Subset*/
		m_structuredNodeInput.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNodeInput()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InputPin> structuredNodeInputindexElem: *structuredNodeInputList) 
		{
			std::shared_ptr<uml::InputPin> temp = std::dynamic_pointer_cast<uml::InputPin>((structuredNodeInputindexElem)->copy());
			m_structuredNodeInput->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for structuredNodeInput.")
	}

	//clone reference 'structuredNodeOutput'
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> structuredNodeOutputList = obj.getStructuredNodeOutput();
	if(structuredNodeOutputList)
	{
		/*Subset*/
		m_structuredNodeOutput.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNodeOutput()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::OutputPin> structuredNodeOutputindexElem: *structuredNodeOutputList) 
		{
			std::shared_ptr<uml::OutputPin> temp = std::dynamic_pointer_cast<uml::OutputPin>((structuredNodeOutputindexElem)->copy());
			m_structuredNodeOutput->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for structuredNodeOutput.")
	}

	//clone reference 'variable'
	std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> variableList = obj.getVariable();
	if(variableList)
	{
		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getVariable()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Variable> variableindexElem: *variableList) 
		{
			std::shared_ptr<uml::Variable> temp = std::dynamic_pointer_cast<uml::Variable>((variableindexElem)->copy());
			m_variable->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for variable.")
	}
	/*Subset*/
	getEdge()->initSubset(getContainedEdge(), getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >(getContainedEdge(), getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getNode()->initSubset(getContainedNode(), getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >(getContainedNode(), getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getStructuredNodeInput()->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	/*Subset*/
	getStructuredNodeOutput()->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	/*Subset*/
	getVariable()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StructuredActivityNodeImpl::copy() const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl());
	*element =(*this);
	element->setThisStructuredActivityNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool StructuredActivityNodeImpl::edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StructuredActivityNodeImpl::input_pin_edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool StructuredActivityNodeImpl::output_pin_edges(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::ActivityNode>> StructuredActivityNodeImpl::sourceNodes()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::ActivityNode>> StructuredActivityNodeImpl::targetNodes()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute mustIsolate */
bool StructuredActivityNodeImpl::getMustIsolate() const 
{
	return m_mustIsolate;
}
void StructuredActivityNodeImpl::setMustIsolate(bool _mustIsolate)
{
	m_mustIsolate = _mustIsolate;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference edge */
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element>> StructuredActivityNodeImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getContainedEdge(), getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element >(getContainedEdge(), getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_edge;
}

/* Getter & Setter for reference node */
std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode, uml::Element>> StructuredActivityNodeImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode(), getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode, uml::Element >(getContainedNode(), getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_node;
}

/* Getter & Setter for reference structuredNodeInput */
std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> StructuredActivityNodeImpl::getStructuredNodeInput() const
{
	if(m_structuredNodeInput == nullptr)
	{
		/*Subset*/
		m_structuredNodeInput.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNodeInput()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}
    return m_structuredNodeInput;
}

/* Getter & Setter for reference structuredNodeOutput */
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> StructuredActivityNodeImpl::getStructuredNodeOutput() const
{
	if(m_structuredNodeOutput == nullptr)
	{
		/*Subset*/
		m_structuredNodeOutput.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNodeOutput()->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}
    return m_structuredNodeOutput;
}

/* Getter & Setter for reference variable */
std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> StructuredActivityNodeImpl::getVariable() const
{
	if(m_variable == nullptr)
	{
		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getVariable()->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_variable;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuredActivityNodeImpl::eContainer() const
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
void StructuredActivityNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredActivityNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("mustIsolate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setMustIsolate(value);
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredActivityNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("edge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityEdge>(this->getEdge());  

			return; 
		}

		if ( nodeName.compare("node") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityNode>(this->getNode());  

			return; 
		}

		if ( nodeName.compare("structuredNodeInput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getStructuredNodeInput());  

			return; 
		}

		if ( nodeName.compare("structuredNodeOutput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getStructuredNodeOutput());  

			return; 
		}

		if ( nodeName.compare("variable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			loadHandler->handleChildContainer<uml::Variable>(this->getVariable());  

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
	ActionImpl::loadNode(nodeName, loadHandler);
	ActivityGroupImpl::loadNode(nodeName, loadHandler);
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void StructuredActivityNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
	ActivityGroupImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void StructuredActivityNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void StructuredActivityNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'edge'
		for (std::shared_ptr<uml::ActivityEdge> edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'node'
		for (std::shared_ptr<uml::ActivityNode> node : *this->getNode()) 
		{
			saveHandler->addReference(node, "node", node->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNodeInput'
		for (std::shared_ptr<uml::InputPin> structuredNodeInput : *this->getStructuredNodeInput()) 
		{
			saveHandler->addReference(structuredNodeInput, "structuredNodeInput", structuredNodeInput->eClass() != package->getInputPin_Class());
		}

		// Save 'structuredNodeOutput'
		for (std::shared_ptr<uml::OutputPin> structuredNodeOutput : *this->getStructuredNodeOutput()) 
		{
			saveHandler->addReference(structuredNodeOutput, "structuredNodeOutput", structuredNodeOutput->eClass() != package->getOutputPin_Class());
		}

		// Save 'variable'
		for (std::shared_ptr<uml::Variable> variable : *this->getVariable()) 
		{
			saveHandler->addReference(variable, "variable", variable->eClass() != package->getVariable_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getStructuredActivityNode_Attribute_mustIsolate()) )
		{
			saveHandler->addAttribute("mustIsolate", this->getMustIsolate());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStructuredActivityNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> StructuredActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
			return eEcoreContainerAny(getEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //22738
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return eAny(getMustIsolate(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //22739
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
			return eEcoreContainerAny(getNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //22743
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
			return eEcoreContainerAny(getStructuredNodeInput(),uml::umlPackage::INPUTPIN_CLASS); //22740
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
			return eEcoreContainerAny(getStructuredNodeOutput(),uml::umlPackage::OUTPUTPIN_CLASS); //22741
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
			return eEcoreContainerAny(getVariable(),uml::umlPackage::VARIABLE_CLASS); //22742
	}
	std::shared_ptr<Any> result;
	result = ActionImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = ActivityGroupImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool StructuredActivityNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //22738
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return getMustIsolate() != false; //22739
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
			return getNode() != nullptr; //22743
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput() != nullptr; //22740
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput() != nullptr; //22741
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //22742
	}
	bool result = false;
	result = ActionImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}

bool StructuredActivityNodeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityEdge>> _edge = getEdge();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityEdge> valueToAdd = std::dynamic_pointer_cast<uml::ActivityEdge>(anEObject);
	
							if (valueToAdd)
							{
								if(_edge->find(valueToAdd) == -1)
								{
									_edge->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'edge'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'edge'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
		{
			try
			{
				bool _mustIsolate = newValue->get<bool>();
				setMustIsolate(_mustIsolate); //22739
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'mustIsolate'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ActivityNode>> _node = getNode();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityNode> valueToAdd = std::dynamic_pointer_cast<uml::ActivityNode>(anEObject);
	
							if (valueToAdd)
							{
								if(_node->find(valueToAdd) == -1)
								{
									_node->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'node'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'node'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::InputPin>> _structuredNodeInput = getStructuredNodeInput();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InputPin> valueToAdd = std::dynamic_pointer_cast<uml::InputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_structuredNodeInput->find(valueToAdd) == -1)
								{
									_structuredNodeInput->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'structuredNodeInput'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'structuredNodeInput'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::OutputPin>> _structuredNodeOutput = getStructuredNodeOutput();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_structuredNodeOutput->find(valueToAdd) == -1)
								{
									_structuredNodeOutput->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'structuredNodeOutput'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'structuredNodeOutput'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Variable>> _variable = getVariable();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Variable> valueToAdd = std::dynamic_pointer_cast<uml::Variable>(anEObject);
	
							if (valueToAdd)
							{
								if(_variable->find(valueToAdd) == -1)
								{
									_variable->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'variable'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'variable'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	bool result = false;
	result = ActionImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> StructuredActivityNodeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::StructuredActivityNode::edges(Any, std::map) : bool: 2175188978
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'edges'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'edges'!")
				return nullptr;
			}
		
			result = eAny(this->edges(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::StructuredActivityNode::input_pin_edges(Any, std::map) : bool: 1705277235
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_INPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'input_pin_edges'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'input_pin_edges'!")
				return nullptr;
			}
		
			result = eAny(this->input_pin_edges(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::StructuredActivityNode::output_pin_edges(Any, std::map) : bool: 3435203420
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_OUTPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'output_pin_edges'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'output_pin_edges'!")
				return nullptr;
			}
		
			result = eAny(this->output_pin_edges(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::StructuredActivityNode::sourceNodes() : uml::ActivityNode[*]: 3462902530
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_SOURCENODES:
		{
			std::shared_ptr<Bag<uml::ActivityNode>> resultList = this->sourceNodes();
			return eEcoreContainerAny(resultList,uml::umlPackage::ACTIVITYNODE_CLASS);
			break;
		}
		// uml::StructuredActivityNode::targetNodes() : uml::ActivityNode[*]: 2207842792
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_TARGETNODES:
		{
			std::shared_ptr<Bag<uml::ActivityNode>> resultList = this->targetNodes();
			return eEcoreContainerAny(resultList,uml::umlPackage::ACTIVITYNODE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityGroupImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = ActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::StructuredActivityNode> StructuredActivityNodeImpl::getThisStructuredActivityNodePtr() const
{
	return m_thisStructuredActivityNodePtr.lock();
}
void StructuredActivityNodeImpl::setThisStructuredActivityNodePtr(std::weak_ptr<uml::StructuredActivityNode> thisStructuredActivityNodePtr)
{
	m_thisStructuredActivityNodePtr = thisStructuredActivityNodePtr;
	setThisActionPtr(thisStructuredActivityNodePtr);
	setThisActivityGroupPtr(thisStructuredActivityNodePtr);
	setThisNamespacePtr(thisStructuredActivityNodePtr);
}



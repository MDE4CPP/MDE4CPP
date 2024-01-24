
#include "uml/impl/ActivityImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Extension.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/Port.hpp"
#include "uml/Property.hpp"
#include "uml/Reception.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/UseCase.hpp"
#include "uml/Variable.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityImpl::ActivityImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityImpl::~ActivityImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Activity "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier)
:ActivityImpl()
{
	m_behavioredClassifier = par_behavioredClassifier;
	m_namespace = par_behavioredClassifier;
}

//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ActivityImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ActivityImpl::ActivityImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ActivityImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ActivityImpl::ActivityImpl(const ActivityImpl & obj): ActivityImpl()
{
	*this = obj;
}

ActivityImpl& ActivityImpl::operator=(const ActivityImpl & obj)
{
	//call overloaded =Operator for each base class
	BehaviorImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Activity 
	 * which is generated by the compiler (as Activity is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Activity::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Activity "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReadOnly = obj.getIsReadOnly();
	m_isSingleExecution = obj.getIsSingleExecution();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'edge'
	const std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>>& edgeList = obj.getEdge();
	if(edgeList)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityEdge>& edgeindexElem: *edgeList) 
		{
			const std::shared_ptr<uml::ActivityEdge>& temp = std::dynamic_pointer_cast<uml::ActivityEdge>((edgeindexElem)->copy());
			m_edge->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for edge.")
	}

	//clone reference 'node'
	const std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>>& nodeList = obj.getNode();
	if(nodeList)
	{
		/*SubsetUnion*/
		m_node.reset(new SubsetUnion<uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getNode()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode>& nodeindexElem: *nodeList) 
		{
			const std::shared_ptr<uml::ActivityNode>& temp = std::dynamic_pointer_cast<uml::ActivityNode>((nodeindexElem)->copy());
			m_node->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for node.")
	}

	//clone reference 'ownedGroup'
	const std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>>& ownedGroupList = obj.getOwnedGroup();
	if(ownedGroupList)
	{
		/*SubsetUnion*/
		m_ownedGroup.reset(new SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedGroup()->initSubsetUnion(getGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(getGroup())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityGroup>& ownedGroupindexElem: *ownedGroupList) 
		{
			const std::shared_ptr<uml::ActivityGroup>& temp = std::dynamic_pointer_cast<uml::ActivityGroup>((ownedGroupindexElem)->copy());
			m_ownedGroup->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedGroup.")
	}

	//clone reference 'ownedNode'
	const std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>>& ownedNodeList = obj.getOwnedNode();
	if(ownedNodeList)
	{
		/*Subset*/
		m_ownedNode.reset(new Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedNode()->initSubset(getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(getNode())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode>& ownedNodeindexElem: *ownedNodeList) 
		{
			const std::shared_ptr<uml::ActivityNode>& temp = std::dynamic_pointer_cast<uml::ActivityNode>((ownedNodeindexElem)->copy());
			m_ownedNode->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedNode.")
	}

	//clone reference 'partition'
	const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/>>& partitionList = obj.getPartition();
	if(partitionList)
	{
		/*Subset*/
		m_partition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPartition()->initSubset(getGroup(), getOwnedGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >(getGroup(), getOwnedGroup())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityPartition>& partitionindexElem: *partitionList) 
		{
			const std::shared_ptr<uml::ActivityPartition>& temp = std::dynamic_pointer_cast<uml::ActivityPartition>((partitionindexElem)->copy());
			m_partition->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for partition.")
	}

	//clone reference 'structuredNode'
	const std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/>>& structuredNodeList = obj.getStructuredNode();
	if(structuredNodeList)
	{
		/*Subset*/
		m_structuredNode.reset(new Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNode()->initSubset(getGroup(), getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >(getGroup(), getNode())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::StructuredActivityNode>& structuredNodeindexElem: *structuredNodeList) 
		{
			const std::shared_ptr<uml::StructuredActivityNode>& temp = std::dynamic_pointer_cast<uml::StructuredActivityNode>((structuredNodeindexElem)->copy());
			m_structuredNode->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for structuredNode.")
	}

	//clone reference 'variable'
	const std::shared_ptr<Subset<uml::Variable, uml::NamedElement>>& variableList = obj.getVariable();
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
		
		for(const std::shared_ptr<uml::Variable>& variableindexElem: *variableList) 
		{
			const std::shared_ptr<uml::Variable>& temp = std::dynamic_pointer_cast<uml::Variable>((variableindexElem)->copy());
			m_variable->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for variable.")
	}
	/*Subset*/
	getEdge()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getNode()->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getOwnedGroup()->initSubsetUnion(getGroup());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(getGroup())" << std::endl;
	#endif
	
	/*Subset*/
	getOwnedNode()->initSubset(getNode());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(getNode())" << std::endl;
	#endif
	
	/*Subset*/
	getStructuredNode()->initSubset(getGroup(), getNode());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >(getGroup(), getNode())" << std::endl;
	#endif
	
	/*Subset*/
	getVariable()->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityImpl::copy() const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl());
	*element =(*this);
	element->setThisActivityPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReadOnly */
bool ActivityImpl::getIsReadOnly() const 
{
	return m_isReadOnly;
}
void ActivityImpl::setIsReadOnly(bool _isReadOnly)
{
	m_isReadOnly = _isReadOnly;
	
}

/* Getter & Setter for attribute isSingleExecution */
bool ActivityImpl::getIsSingleExecution() const 
{
	return m_isSingleExecution;
}
void ActivityImpl::setIsSingleExecution(bool _isSingleExecution)
{
	m_isSingleExecution = _isSingleExecution;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference edge */
const std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>>& ActivityImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_edge;
}

/* Getter & Setter for reference group */

/* Getter & Setter for reference node */
const std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>>& ActivityImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*SubsetUnion*/
		m_node.reset(new SubsetUnion<uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getNode()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_node;
}

/* Getter & Setter for reference ownedGroup */
const std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>>& ActivityImpl::getOwnedGroup() const
{
	if(m_ownedGroup == nullptr)
	{
		/*SubsetUnion*/
		m_ownedGroup.reset(new SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedGroup()->initSubsetUnion(getGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(getGroup())" << std::endl;
		#endif
		
	}
    return m_ownedGroup;
}

/* Getter & Setter for reference ownedNode */
const std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>>& ActivityImpl::getOwnedNode() const
{
	if(m_ownedNode == nullptr)
	{
		/*Subset*/
		m_ownedNode.reset(new Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedNode()->initSubset(getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(getNode())" << std::endl;
		#endif
		
	}
    return m_ownedNode;
}

/* Getter & Setter for reference partition */
const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/>>& ActivityImpl::getPartition() const
{
	if(m_partition == nullptr)
	{
		/*Subset*/
		m_partition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPartition()->initSubset(getGroup(), getOwnedGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/ >(getGroup(), getOwnedGroup())" << std::endl;
		#endif
		
	}
    return m_partition;
}

/* Getter & Setter for reference structuredNode */
const std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/>>& ActivityImpl::getStructuredNode() const
{
	if(m_structuredNode == nullptr)
	{
		/*Subset*/
		m_structuredNode.reset(new Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getStructuredNode()->initSubset(getGroup(), getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/ >(getGroup(), getNode())" << std::endl;
		#endif
		
	}
    return m_structuredNode;
}

/* Getter & Setter for reference variable */
const std::shared_ptr<Subset<uml::Variable, uml::NamedElement>>& ActivityImpl::getVariable() const
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
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityImpl::getGroup() const
{
	if(m_group == nullptr)
	{
		/*SubsetUnion*/
		m_group.reset(new SubsetUnion<uml::ActivityGroup, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_group - SubsetUnion<uml::ActivityGroup, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getGroup()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_group - SubsetUnion<uml::ActivityGroup, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_group;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityImpl::eContainer() const
{
	if(auto wp = m_behavioredClassifier.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_package.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ActivityImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ActivityImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReadOnly");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReadOnly(value);
		}

		iter = attr_list.find("isSingleExecution");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSingleExecution(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("partition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("partition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehaviorImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("edge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ActivityEdge> new_edge = std::dynamic_pointer_cast<uml::ActivityEdge>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE));
			if(new_edge)
			{
				loadHandler->handleChild(new_edge);
				getEdge()->push_back(new_edge);
			} 

			return; 
		}

		if ( nodeName.compare("group") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ActivityGroup> new_group = std::dynamic_pointer_cast<uml::ActivityGroup>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP));
			if(new_group)
			{
				loadHandler->handleChild(new_group);
				getGroup()->push_back(new_group);
			} 

			return; 
		}

		if ( nodeName.compare("node") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ActivityNode> new_node = std::dynamic_pointer_cast<uml::ActivityNode>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE));
			if(new_node)
			{
				loadHandler->handleChild(new_node);
				getNode()->push_back(new_node);
			} 

			return; 
		}

		if ( nodeName.compare("ownedGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ActivityGroup> new_ownedGroup = std::dynamic_pointer_cast<uml::ActivityGroup>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP));
			if(new_ownedGroup)
			{
				loadHandler->handleChild(new_ownedGroup);
				getOwnedGroup()->push_back(new_ownedGroup);
			} 

			return; 
		}

		if ( nodeName.compare("ownedNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ActivityNode> new_ownedNode = std::dynamic_pointer_cast<uml::ActivityNode>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE));
			if(new_ownedNode)
			{
				loadHandler->handleChild(new_ownedNode);
				getOwnedNode()->push_back(new_ownedNode);
			} 

			return; 
		}

		if ( nodeName.compare("structuredNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::StructuredActivityNode";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::StructuredActivityNode> new_structuredNode = std::dynamic_pointer_cast<uml::StructuredActivityNode>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE));
			if(new_structuredNode)
			{
				loadHandler->handleChild(new_structuredNode);
				getStructuredNode()->push_back(new_structuredNode);
			} 

			return; 
		}

		if ( nodeName.compare("variable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::Variable";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::Variable> new_variable = std::dynamic_pointer_cast<uml::Variable>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE));
			if(new_variable)
			{
				loadHandler->handleChild(new_variable);
				getVariable()->push_back(new_variable);
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
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void ActivityImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			const std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup, uml::ActivityGroup /*Subset does not reference a union*/>>& _partition = getPartition();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<uml::ActivityPartition>  _r = std::dynamic_pointer_cast<uml::ActivityPartition>(ref);
				if (_r != nullptr)
				{
					_partition->push_back(_r);
				}
			}
			return;
		}
	}
	BehaviorImpl::resolveReferences(featureID, references);
}

void ActivityImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehaviorImpl::saveContent(saveHandler);
	
	ClassImpl::saveContent(saveHandler);
	
	BehavioredClassifierImpl::saveContent(saveHandler);
	EncapsulatedClassifierImpl::saveContent(saveHandler);
	
	StructuredClassifierImpl::saveContent(saveHandler);
	
	ClassifierImpl::saveContent(saveHandler);
	
	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'edge'
		for (const std::shared_ptr<uml::ActivityEdge>& edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'ownedNode'
		for (const std::shared_ptr<uml::ActivityNode>& ownedNode : *this->getOwnedNode()) 
		{
			saveHandler->addReference(ownedNode, "ownedNode", ownedNode->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNode'
		for (const std::shared_ptr<uml::StructuredActivityNode>& structuredNode : *this->getStructuredNode()) 
		{
			saveHandler->addReference(structuredNode, "structuredNode", structuredNode->eClass() != package->getStructuredActivityNode_Class());
		}

		// Save 'variable'
		for (const std::shared_ptr<uml::Variable>& variable : *this->getVariable()) 
		{
			saveHandler->addReference(variable, "variable", variable->eClass() != package->getVariable_Class());
		}
		// Add attributes
          if ( this->eIsSet(package->getActivity_Attribute_isReadOnly()) )
          {
			saveHandler->addAttribute("isReadOnly", this->getIsReadOnly());
          }

          if ( this->eIsSet(package->getActivity_Attribute_isSingleExecution()) )
          {
			saveHandler->addAttribute("isSingleExecution", this->getIsSingleExecution());
          }
	// Add references
	if ( this->eIsSet(package->getActivity_Attribute_group()) )
	{
		saveHandler->addReferences<uml::ActivityGroup>("group", this->getGroup());
	}
	if ( this->eIsSet(package->getActivity_Attribute_node()) )
	{
		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());
	}
	if ( this->eIsSet(package->getActivity_Attribute_partition()) )
	{
		saveHandler->addReferences<uml::ActivityPartition>("partition", this->getPartition());
	}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'group'
	    if ( this->eIsSet(package->getActivity_Attribute_group()) )
	    {
		saveHandler->addReferences<uml::ActivityGroup>("group", this->getGroup());
	    }

		// Save 'node'
	    if ( this->eIsSet(package->getActivity_Attribute_node()) )
	    {
		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());
	    }

		// Save 'ownedGroup'
	    if ( this->eIsSet(package->getActivity_Attribute_ownedGroup()) )
	    {
		saveHandler->addReferences<uml::ActivityGroup>("ownedGroup", this->getOwnedGroup());
	    }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ActivityImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivity_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
			return eEcoreContainerAny(getEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //763
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
			return eEcoreContainerAny(getGroup(),uml::umlPackage::ACTIVITYGROUP_CLASS); //766
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return eAny(getIsReadOnly(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //768
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return eAny(getIsSingleExecution(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //769
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
			return eEcoreContainerAny(getNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //764
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
			return eEcoreContainerAny(getOwnedGroup(),uml::umlPackage::ACTIVITYGROUP_CLASS); //762
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
			return eEcoreContainerAny(getOwnedNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //767
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
			return eEcoreContainerAny(getPartition(),uml::umlPackage::ACTIVITYPARTITION_CLASS); //770
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
			return eEcoreContainerAny(getStructuredNode(),uml::umlPackage::STRUCTUREDACTIVITYNODE_CLASS); //771
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
			return eEcoreContainerAny(getVariable(),uml::umlPackage::VARIABLE_CLASS); //765
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}

bool ActivityImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //763
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
			return getGroup() != nullptr; //766
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return getIsReadOnly() != false; //768
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return getIsSingleExecution() != false; //769
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
			return getNode() != nullptr; //764
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
			return getOwnedGroup() != nullptr; //762
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
			return getOwnedNode() != nullptr; //767
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
			return getPartition() != nullptr; //770
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
			return getStructuredNode() != nullptr; //771
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //765
	}
	return BehaviorImpl::internalEIsSet(featureID);
}

bool ActivityImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityEdge>>& _edge = getEdge();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityEdge> valueToAdd = std::dynamic_pointer_cast<uml::ActivityEdge>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_edge->includes(valueToAdd)))
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
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityGroup>>& _group = getGroup();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityGroup> valueToAdd = std::dynamic_pointer_cast<uml::ActivityGroup>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_group->includes(valueToAdd)))
								{
									_group->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'group'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'group'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
		{
			try
			{
				bool _isReadOnly = newValue->get<bool>();
				setIsReadOnly(_isReadOnly); //768
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReadOnly'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
		{
			try
			{
				bool _isSingleExecution = newValue->get<bool>();
				setIsSingleExecution(_isSingleExecution); //769
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isSingleExecution'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityNode>>& _node = getNode();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityNode> valueToAdd = std::dynamic_pointer_cast<uml::ActivityNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_node->includes(valueToAdd)))
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
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityGroup>>& _ownedGroup = getOwnedGroup();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityGroup> valueToAdd = std::dynamic_pointer_cast<uml::ActivityGroup>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedGroup->includes(valueToAdd)))
								{
									_ownedGroup->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedGroup'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedGroup'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityNode>>& _ownedNode = getOwnedNode();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityNode> valueToAdd = std::dynamic_pointer_cast<uml::ActivityNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_ownedNode->includes(valueToAdd)))
								{
									_ownedNode->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ActivityPartition>>& _partition = getPartition();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ActivityPartition> valueToAdd = std::dynamic_pointer_cast<uml::ActivityPartition>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_partition->includes(valueToAdd)))
								{
									_partition->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'partition'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'partition'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::StructuredActivityNode>>& _structuredNode = getStructuredNode();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::StructuredActivityNode> valueToAdd = std::dynamic_pointer_cast<uml::StructuredActivityNode>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_structuredNode->includes(valueToAdd)))
								{
									_structuredNode->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'structuredNode'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'structuredNode'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::Variable>>& _variable = getVariable();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Variable> valueToAdd = std::dynamic_pointer_cast<uml::Variable>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_variable->includes(valueToAdd)))
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

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Activity> ActivityImpl::getThisActivityPtr() const
{
	return m_thisActivityPtr.lock();
}
void ActivityImpl::setThisActivityPtr(std::weak_ptr<uml::Activity> thisActivityPtr)
{
	m_thisActivityPtr = thisActivityPtr;
	setThisBehaviorPtr(thisActivityPtr);
}



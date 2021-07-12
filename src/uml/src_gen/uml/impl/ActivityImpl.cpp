#include "uml/impl/ActivityImpl.hpp"

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Activity::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Activity "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReadOnly = obj.getIsReadOnly();
	m_isSingleExecution = obj.getIsSingleExecution();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> edgeContainer = getEdge();
	if(nullptr != edgeContainer )
	{
		int size = edgeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _edge=(*edgeContainer)[i];
			if(nullptr != _edge)
			{
				edgeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityEdge>(_edge->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container edge."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr edge."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> nodeContainer = getNode();
	if(nullptr != nodeContainer )
	{
		int size = nodeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _node=(*nodeContainer)[i];
			if(nullptr != _node)
			{
				nodeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container node."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr node."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> ownedGroupContainer = getOwnedGroup();
	if(nullptr != ownedGroupContainer )
	{
		int size = ownedGroupContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedGroup=(*ownedGroupContainer)[i];
			if(nullptr != _ownedGroup)
			{
				ownedGroupContainer->push_back(std::dynamic_pointer_cast<uml::ActivityGroup>(_ownedGroup->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedGroup."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedGroup."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> ownedNodeContainer = getOwnedNode();
	if(nullptr != ownedNodeContainer )
	{
		int size = ownedNodeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedNode=(*ownedNodeContainer)[i];
			if(nullptr != _ownedNode)
			{
				ownedNodeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(_ownedNode->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedNode."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedNode."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/>> partitionContainer = getPartition();
	if(nullptr != partitionContainer )
	{
		int size = partitionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _partition=(*partitionContainer)[i];
			if(nullptr != _partition)
			{
				partitionContainer->push_back(std::dynamic_pointer_cast<uml::ActivityPartition>(_partition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container partition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr partition."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/>> structuredNodeContainer = getStructuredNode();
	if(nullptr != structuredNodeContainer )
	{
		int size = structuredNodeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _structuredNode=(*structuredNodeContainer)[i];
			if(nullptr != _structuredNode)
			{
				structuredNodeContainer->push_back(std::dynamic_pointer_cast<uml::StructuredActivityNode>(_structuredNode->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container structuredNode."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr structuredNode."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> variableContainer = getVariable();
	if(nullptr != variableContainer )
	{
		int size = variableContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _variable=(*variableContainer)[i];
			if(nullptr != _variable)
			{
				variableContainer->push_back(std::dynamic_pointer_cast<uml::Variable>(_variable->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container variable."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr variable."<< std::endl;)
	}
	/*Subset*/
	m_edge->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_node->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_ownedGroup->initSubsetUnion(getGroup());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(getGroup())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedNode->initSubset(getNode());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(getNode())" << std::endl;
	#endif
	
	/*Subset*/
	m_structuredNode->initSubset(getGroup(),getNode());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >(getGroup(),getNode())" << std::endl;
	#endif
	
	/*Subset*/
	m_variable->initSubset(getOwnedMember());
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

std::shared_ptr<ecore::EClass> ActivityImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivity_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isReadOnly
*/
bool ActivityImpl::getIsReadOnly() const 
{
	return m_isReadOnly;
}
void ActivityImpl::setIsReadOnly(bool _isReadOnly)
{
	m_isReadOnly = _isReadOnly;
} 


/*
Getter & Setter for attribute isSingleExecution
*/
bool ActivityImpl::getIsSingleExecution() const 
{
	return m_isSingleExecution;
}
void ActivityImpl::setIsSingleExecution(bool _isSingleExecution)
{
	m_isSingleExecution = _isSingleExecution;
} 


//*********************************
// Operations
//*********************************
bool ActivityImpl::maximum_one_parameter_node(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ActivityImpl::maximum_two_parameter_nodes(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference edge
*/
std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> ActivityImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_edge->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_edge;
}



/*
Getter & Setter for reference group
*/




/*
Getter & Setter for reference node
*/
std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> ActivityImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*SubsetUnion*/
		m_node.reset(new SubsetUnion<uml::ActivityNode, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_node->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_node - SubsetUnion<uml::ActivityNode, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_node;
}



/*
Getter & Setter for reference ownedGroup
*/
std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> ActivityImpl::getOwnedGroup() const
{
	if(m_ownedGroup == nullptr)
	{
		/*SubsetUnion*/
		m_ownedGroup.reset(new SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedGroup->initSubsetUnion(getGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedGroup - SubsetUnion<uml::ActivityGroup, uml::ActivityGroup >(getGroup())" << std::endl;
		#endif
		
	}

    return m_ownedGroup;
}



/*
Getter & Setter for reference ownedNode
*/
std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> ActivityImpl::getOwnedNode() const
{
	if(m_ownedNode == nullptr)
	{
		/*Subset*/
		m_ownedNode.reset(new Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedNode->initSubset(getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedNode - Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/ >(getNode())" << std::endl;
		#endif
		
	}

    return m_ownedNode;
}



/*
Getter & Setter for reference partition
*/
std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/>> ActivityImpl::getPartition() const
{
	if(m_partition == nullptr)
	{
		/*Subset*/
		m_partition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_partition->initSubset(getGroup(),getOwnedGroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_partition - Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/ >(getGroup(),getOwnedGroup())" << std::endl;
		#endif
		
	}

    return m_partition;
}



/*
Getter & Setter for reference structuredNode
*/
std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/>> ActivityImpl::getStructuredNode() const
{
	if(m_structuredNode == nullptr)
	{
		/*Subset*/
		m_structuredNode.reset(new Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_structuredNode->initSubset(getGroup(),getNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNode - Subset<uml::StructuredActivityNode, uml::ActivityGroup,uml::ActivityNode /*Subset does not reference a union*/ >(getGroup(),getNode())" << std::endl;
		#endif
		
	}

    return m_structuredNode;
}



/*
Getter & Setter for reference variable
*/
std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> ActivityImpl::getVariable() const
{
	if(m_variable == nullptr)
	{
		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_variable->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_variable;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ActivityImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ActivityImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

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
		m_group->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_group - SubsetUnion<uml::ActivityGroup, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_group;
}

std::shared_ptr<Union<uml::NamedElement>> ActivityImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ActivityImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ActivityImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ActivityImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> ActivityImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ActivityImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> ActivityImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}

std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> ActivityImpl::getRole() const
{
	if(m_role == nullptr)
	{
		/*SubsetUnion*/
		m_role.reset(new SubsetUnion<uml::ConnectableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_role->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_role - SubsetUnion<uml::ConnectableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_role;
}




std::shared_ptr<Activity> ActivityImpl::getThisActivityPtr() const
{
	return m_thisActivityPtr.lock();
}
void ActivityImpl::setThisActivityPtr(std::weak_ptr<Activity> thisActivityPtr)
{
	m_thisActivityPtr = thisActivityPtr;
	setThisBehaviorPtr(thisActivityPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ActivityImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = getEdge()->begin();
			Bag<uml::ActivityEdge>::iterator end = getEdge()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //762			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = getGroup()->begin();
			Bag<uml::ActivityGroup>::iterator end = getGroup()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //765			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return eAny(getIsReadOnly()); //767
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return eAny(getIsSingleExecution()); //768
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = getNode()->begin();
			Bag<uml::ActivityNode>::iterator end = getNode()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //763			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityGroup>::iterator iter = getOwnedGroup()->begin();
			Bag<uml::ActivityGroup>::iterator end = getOwnedGroup()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //761			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = getOwnedNode()->begin();
			Bag<uml::ActivityNode>::iterator end = getOwnedNode()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //766			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityPartition>::iterator iter = getPartition()->begin();
			Bag<uml::ActivityPartition>::iterator end = getPartition()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //769			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StructuredActivityNode>::iterator iter = getStructuredNode()->begin();
			Bag<uml::StructuredActivityNode>::iterator end = getStructuredNode()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //770			
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Variable>::iterator iter = getVariable()->begin();
			Bag<uml::Variable>::iterator end = getVariable()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //764			
		}
	}
	return BehaviorImpl::eGet(featureID, resolve, coreType);
}
bool ActivityImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //762
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
			return getGroup() != nullptr; //765
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
			return getIsReadOnly() != false; //767
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
			return getIsSingleExecution() != false; //768
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
			return getNode() != nullptr; //763
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
			return getOwnedGroup() != nullptr; //761
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
			return getOwnedNode() != nullptr; //766
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
			return getPartition() != nullptr; //769
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
			return getStructuredNode() != nullptr; //770
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //764
	}
	return BehaviorImpl::internalEIsSet(featureID);
}
bool ActivityImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> edgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterEdge = getEdge()->begin();
			Bag<uml::ActivityEdge>::iterator endEdge = getEdge()->end();
			while (iterEdge != endEdge)
			{
				if (edgeList->find(*iterEdge) == -1)
				{
					getEdge()->erase(*iterEdge);
				}
				iterEdge++;
			}
 
			iterEdge = edgeList->begin();
			endEdge = edgeList->end();
			while (iterEdge != endEdge)
			{
				if (getEdge()->find(*iterEdge) == -1)
				{
					getEdge()->add(*iterEdge);
				}
				iterEdge++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityGroup>> groupList(new Bag<uml::ActivityGroup>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				groupList->add(std::dynamic_pointer_cast<uml::ActivityGroup>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityGroup>::iterator iterGroup = getGroup()->begin();
			Bag<uml::ActivityGroup>::iterator endGroup = getGroup()->end();
			while (iterGroup != endGroup)
			{
				if (groupList->find(*iterGroup) == -1)
				{
					getGroup()->erase(*iterGroup);
				}
				iterGroup++;
			}
 
			iterGroup = groupList->begin();
			endGroup = groupList->end();
			while (iterGroup != endGroup)
			{
				if (getGroup()->find(*iterGroup) == -1)
				{
					getGroup()->add(*iterGroup);
				}
				iterGroup++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = newValue->get<bool>();
			setIsReadOnly(_isReadOnly); //767
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION:
		{
			// BOOST CAST
			bool _isSingleExecution = newValue->get<bool>();
			setIsSingleExecution(_isSingleExecution); //768
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> nodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterNode = getNode()->begin();
			Bag<uml::ActivityNode>::iterator endNode = getNode()->end();
			while (iterNode != endNode)
			{
				if (nodeList->find(*iterNode) == -1)
				{
					getNode()->erase(*iterNode);
				}
				iterNode++;
			}
 
			iterNode = nodeList->begin();
			endNode = nodeList->end();
			while (iterNode != endNode)
			{
				if (getNode()->find(*iterNode) == -1)
				{
					getNode()->add(*iterNode);
				}
				iterNode++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDGROUP:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityGroup>> ownedGroupList(new Bag<uml::ActivityGroup>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedGroupList->add(std::dynamic_pointer_cast<uml::ActivityGroup>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityGroup>::iterator iterOwnedGroup = getOwnedGroup()->begin();
			Bag<uml::ActivityGroup>::iterator endOwnedGroup = getOwnedGroup()->end();
			while (iterOwnedGroup != endOwnedGroup)
			{
				if (ownedGroupList->find(*iterOwnedGroup) == -1)
				{
					getOwnedGroup()->erase(*iterOwnedGroup);
				}
				iterOwnedGroup++;
			}
 
			iterOwnedGroup = ownedGroupList->begin();
			endOwnedGroup = ownedGroupList->end();
			while (iterOwnedGroup != endOwnedGroup)
			{
				if (getOwnedGroup()->find(*iterOwnedGroup) == -1)
				{
					getOwnedGroup()->add(*iterOwnedGroup);
				}
				iterOwnedGroup++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_OWNEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> ownedNodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedNodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterOwnedNode = getOwnedNode()->begin();
			Bag<uml::ActivityNode>::iterator endOwnedNode = getOwnedNode()->end();
			while (iterOwnedNode != endOwnedNode)
			{
				if (ownedNodeList->find(*iterOwnedNode) == -1)
				{
					getOwnedNode()->erase(*iterOwnedNode);
				}
				iterOwnedNode++;
			}
 
			iterOwnedNode = ownedNodeList->begin();
			endOwnedNode = ownedNodeList->end();
			while (iterOwnedNode != endOwnedNode)
			{
				if (getOwnedNode()->find(*iterOwnedNode) == -1)
				{
					getOwnedNode()->add(*iterOwnedNode);
				}
				iterOwnedNode++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityPartition>> partitionList(new Bag<uml::ActivityPartition>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				partitionList->add(std::dynamic_pointer_cast<uml::ActivityPartition>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityPartition>::iterator iterPartition = getPartition()->begin();
			Bag<uml::ActivityPartition>::iterator endPartition = getPartition()->end();
			while (iterPartition != endPartition)
			{
				if (partitionList->find(*iterPartition) == -1)
				{
					getPartition()->erase(*iterPartition);
				}
				iterPartition++;
			}
 
			iterPartition = partitionList->begin();
			endPartition = partitionList->end();
			while (iterPartition != endPartition)
			{
				if (getPartition()->find(*iterPartition) == -1)
				{
					getPartition()->add(*iterPartition);
				}
				iterPartition++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_STRUCTUREDNODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::StructuredActivityNode>> structuredNodeList(new Bag<uml::StructuredActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeList->add(std::dynamic_pointer_cast<uml::StructuredActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::StructuredActivityNode>::iterator iterStructuredNode = getStructuredNode()->begin();
			Bag<uml::StructuredActivityNode>::iterator endStructuredNode = getStructuredNode()->end();
			while (iterStructuredNode != endStructuredNode)
			{
				if (structuredNodeList->find(*iterStructuredNode) == -1)
				{
					getStructuredNode()->erase(*iterStructuredNode);
				}
				iterStructuredNode++;
			}
 
			iterStructuredNode = structuredNodeList->begin();
			endStructuredNode = structuredNodeList->end();
			while (iterStructuredNode != endStructuredNode)
			{
				if (getStructuredNode()->find(*iterStructuredNode) == -1)
				{
					getStructuredNode()->add(*iterStructuredNode);
				}
				iterStructuredNode++;			
			}
			return true;
		}
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_VARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Variable>> variableList(new Bag<uml::Variable>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				variableList->add(std::dynamic_pointer_cast<uml::Variable>(*iter));
				iter++;
			}
			
			Bag<uml::Variable>::iterator iterVariable = getVariable()->begin();
			Bag<uml::Variable>::iterator endVariable = getVariable()->end();
			while (iterVariable != endVariable)
			{
				if (variableList->find(*iterVariable) == -1)
				{
					getVariable()->erase(*iterVariable);
				}
				iterVariable++;
			}
 
			iterVariable = variableList->begin();
			endVariable = variableList->end();
			while (iterVariable != endVariable)
			{
				if (getVariable()->find(*iterVariable) == -1)
				{
					getVariable()->add(*iterVariable);
				}
				iterVariable++;			
			}
			return true;
		}
	}

	return BehaviorImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ActivityImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 901
		case umlPackage::ACTIVITY_OPERATION_MAXIMUM_ONE_PARAMETER_NODE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->maximum_one_parameter_node(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 902
		case umlPackage::ACTIVITY_OPERATION_MAXIMUM_TWO_PARAMETER_NODES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->maximum_two_parameter_nodes(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = BehaviorImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
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
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityEdge>(this->getEdge());  

			return; 
		}

		if ( nodeName.compare("group") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityGroup>(this->getGroup());  

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

		if ( nodeName.compare("ownedGroup") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityGroup>(this->getOwnedGroup());  

			return; 
		}

		if ( nodeName.compare("ownedNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityNode>(this->getOwnedNode());  

			return; 
		}

		if ( nodeName.compare("structuredNode") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StructuredActivityNode";
			}
			loadHandler->handleChildContainer<uml::StructuredActivityNode>(this->getStructuredNode());  

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
	BehaviorImpl::loadNode(nodeName, loadHandler);
}

void ActivityImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITY_ATTRIBUTE_PARTITION:
		{
			std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup,uml::ActivityGroup /*Subset does not reference a union*/>> _partition = getPartition();
			for(std::shared_ptr<ecore::EObject> ref : references)
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
		for (std::shared_ptr<uml::ActivityEdge> edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'ownedNode'
		for (std::shared_ptr<uml::ActivityNode> ownedNode : *this->getOwnedNode()) 
		{
			saveHandler->addReference(ownedNode, "ownedNode", ownedNode->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNode'
		for (std::shared_ptr<uml::StructuredActivityNode> structuredNode : *this->getStructuredNode()) 
		{
			saveHandler->addReference(structuredNode, "structuredNode", structuredNode->eClass() != package->getStructuredActivityNode_Class());
		}

		// Save 'variable'
		for (std::shared_ptr<uml::Variable> variable : *this->getVariable()) 
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
		saveHandler->addReferences<uml::ActivityGroup>("group", this->getGroup());
		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());
		saveHandler->addReferences<uml::ActivityPartition>("partition", this->getPartition());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'group'

		saveHandler->addReferences<uml::ActivityGroup>("group", this->getGroup());

		// Save 'node'

		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());

		// Save 'ownedGroup'

		saveHandler->addReferences<uml::ActivityGroup>("ownedGroup", this->getOwnedGroup());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


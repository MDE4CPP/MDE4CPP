#include "InformationFlowImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "ActivityEdge.hpp";

#include "Classifier.hpp";

#include "Comment.hpp";

#include "Connector.hpp";

#include "Dependency.hpp";

#include "DirectedRelationship.hpp";

#include "EAnnotation.hpp";

#include "Element.hpp";

#include "Message.hpp";

#include "NamedElement.hpp";

#include "Namespace.hpp";

#include "PackageableElement.hpp";

#include "Relationship.hpp";

#include "StringExpression.hpp";

#include "TemplateParameter.hpp";


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InformationFlowImpl::InformationFlowImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_conveyed.reset(new Bag<uml::Classifier>());
	
	

		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
	
	

		m_realization.reset(new Bag<uml::Relationship>());
	
	

		m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>());
	
	

		m_realizingConnector.reset(new Bag<uml::Connector>());
	
	

		m_realizingMessage.reset(new Bag<uml::Message>());
	
	

	//Init references
	
	

		/*Subset*/
		m_informationSource->initSubset(m_source);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(m_source)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_informationTarget->initSubset(m_target);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(m_target)" << std::endl;
		#endif
	
	

	
	

	
	

	
	

	
	
}

InformationFlowImpl::~InformationFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj):InformationFlowImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InformationFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

		std::shared_ptr< Bag<uml::Classifier> >
	 _conveyed = obj.getConveyed();
	m_conveyed.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getConveyed().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

		std::shared_ptr< Bag<uml::Relationship> >
	 _realization = obj.getRealization();
	m_realization.reset(new 	 Bag<uml::Relationship> 
	(*(obj.getRealization().get())));

		std::shared_ptr< Bag<uml::ActivityEdge> >
	 _realizingActivityEdge = obj.getRealizingActivityEdge();
	m_realizingActivityEdge.reset(new 	 Bag<uml::ActivityEdge> 
	(*(obj.getRealizingActivityEdge().get())));

		std::shared_ptr< Bag<uml::Connector> >
	 _realizingConnector = obj.getRealizingConnector();
	m_realizingConnector.reset(new 	 Bag<uml::Connector> 
	(*(obj.getRealizingConnector().get())));

		std::shared_ptr< Bag<uml::Message> >
	 _realizingMessage = obj.getRealizingMessage();
	m_realizingMessage.reset(new 	 Bag<uml::Message> 
	(*(obj.getRealizingMessage().get())));

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _informationSourceList = obj.getInformationSource();
	for(std::shared_ptr<uml::NamedElement> _informationSource : *_informationSourceList)
	{
		this->getInformationSource()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_informationSource->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_informationSource" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::NamedElement>> _informationTargetList = obj.getInformationTarget();
	for(std::shared_ptr<uml::NamedElement> _informationTarget : *_informationTargetList)
	{
		this->getInformationTarget()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_informationTarget->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_informationTarget" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getOwningTemplateParameter()!=nullptr)
	{
		m_owningTemplateParameter.reset(dynamic_cast<uml::TemplateParameter*>(obj.getOwningTemplateParameter()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_owningTemplateParameter" << std::endl;
	#endif


}

ecore::EObject *  InformationFlowImpl::copy() const
{
	return new InformationFlowImpl(*this);
}

std::shared_ptr<ecore::EClass> InformationFlowImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInformationFlow();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InformationFlowImpl::convey_classifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InformationFlowImpl::must_conform(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InformationFlowImpl::sources_and_targets_kind(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Classifier> >
 InformationFlowImpl::getConveyed() const
{
//assert(m_conveyed);
    return m_conveyed;
}


		std::shared_ptr<Subset<uml::NamedElement, uml::Element > >
 InformationFlowImpl::getInformationSource() const
{
//assert(m_informationSource);
    return m_informationSource;
}


		std::shared_ptr<Subset<uml::NamedElement, uml::Element > >
 InformationFlowImpl::getInformationTarget() const
{
//assert(m_informationTarget);
    return m_informationTarget;
}


	std::shared_ptr< Bag<uml::Relationship> >
 InformationFlowImpl::getRealization() const
{

    return m_realization;
}


	std::shared_ptr< Bag<uml::ActivityEdge> >
 InformationFlowImpl::getRealizingActivityEdge() const
{

    return m_realizingActivityEdge;
}


	std::shared_ptr< Bag<uml::Connector> >
 InformationFlowImpl::getRealizingConnector() const
{

    return m_realizingConnector;
}


	std::shared_ptr< Bag<uml::Message> >
 InformationFlowImpl::getRealizingMessage() const
{

    return m_realizingMessage;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > InformationFlowImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<uml::Element > InformationFlowImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > InformationFlowImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 InformationFlowImpl::getTarget() const
{
	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 InformationFlowImpl::getSource() const
{
	return m_source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InformationFlowImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2094
		case UmlPackage::INFORMATIONFLOW_CONVEYED:
			return getConveyed(); //20915
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2090
		case UmlPackage::INFORMATIONFLOW_INFORMATIONSOURCE:
			return getInformationSource(); //20916
		case UmlPackage::INFORMATIONFLOW_INFORMATIONTARGET:
			return getInformationTarget(); //20917
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2095
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2096
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2097
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2091
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2092
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2093
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2094
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2098
		case UmlPackage::INFORMATIONFLOW_REALIZATION:
			return getRealization(); //20918
		case UmlPackage::INFORMATIONFLOW_REALIZINGACTIVITYEDGE:
			return getRealizingActivityEdge(); //20919
		case UmlPackage::INFORMATIONFLOW_REALIZINGCONNECTOR:
			return getRealizingConnector(); //20920
		case UmlPackage::INFORMATIONFLOW_REALIZINGMESSAGE:
			return getRealizingMessage(); //20921
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //2094
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //2095
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //2096
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2095
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2099
	}
	return boost::any();
}

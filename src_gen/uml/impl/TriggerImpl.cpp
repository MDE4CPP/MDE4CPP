#include "TriggerImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Event.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "Port.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TriggerImpl::TriggerImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_port.reset(new Bag<uml::Port>());
	
	

	//Init references
	

	
	
}

TriggerImpl::~TriggerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Trigger "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

TriggerImpl::TriggerImpl(const TriggerImpl & obj):TriggerImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Trigger "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

	m_event  = obj.getEvent();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

		std::shared_ptr< Bag<uml::Port> >
	 _port = obj.getPort();
	m_port.reset(new 	 Bag<uml::Port> 
	(*(obj.getPort().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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


}

ecore::EObject *  TriggerImpl::copy() const
{
	return new TriggerImpl(*this);
}

std::shared_ptr<ecore::EClass> TriggerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTrigger();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 TriggerImpl::trigger_with_ports(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Event > TriggerImpl::getEvent() const
{
//assert(m_event);
    return m_event;
}
void TriggerImpl::setEvent(std::shared_ptr<uml::Event> _event)
{
    m_event = _event;
}

	std::shared_ptr< Bag<uml::Port> >
 TriggerImpl::getPort() const
{

    return m_port;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > TriggerImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<uml::Element > TriggerImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TriggerImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //654
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //650
		case UmlPackage::TRIGGER_EVENT:
			return getEvent(); //6510
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //655
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //656
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //657
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //651
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //652
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //653
		case UmlPackage::TRIGGER_PORT:
			return getPort(); //6511
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //658
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //659
	}
	return boost::any();
}

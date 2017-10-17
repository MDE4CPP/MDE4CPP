#include "TimeEventImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Event.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "TimeExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeEventImpl::TimeEventImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

TimeEventImpl::~TimeEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeEventImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeEventImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeEventImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeEventImpl::TimeEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeEventImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






TimeEventImpl::TimeEventImpl(const TimeEventImpl & obj):TimeEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isRelative = obj.getIsRelative();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getWhen()!=nullptr)
	{
		m_when = std::dynamic_pointer_cast<uml::TimeExpression>(obj.getWhen()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_when" << std::endl;
	#endif

	
}

std::shared_ptr<ecore::EObject>  TimeEventImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TimeEventImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TimeEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeEvent();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeEventImpl::setIsRelative(bool _isRelative)
{
	m_isRelative = _isRelative;
} 

bool TimeEventImpl::getIsRelative() const 
{
	return m_isRelative;
}

//*********************************
// Operations
//*********************************
bool TimeEventImpl::when_non_negative(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::TimeExpression > TimeEventImpl::getWhen() const
{
//assert(m_when);
    return m_when;
}
void TimeEventImpl::setWhen(std::shared_ptr<uml::TimeExpression> _when)
{
    m_when = _when;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeEventImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TimeEventImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeEventImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeEventImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2024
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2020
		case UmlPackage::TIMEEVENT_ISRELATIVE:
			return getIsRelative(); //20213
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2025
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2026
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2027
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2021
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2022
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2023
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //20212
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2024
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2028
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2025
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2029
		case UmlPackage::TIMEEVENT_WHEN:
			return getWhen(); //20214
	}
	return boost::any();
}

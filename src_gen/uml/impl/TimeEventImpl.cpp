#include "uml/impl/TimeEventImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Event.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TimeExpression.hpp"


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
	return UmlPackageImpl::eInstance()->getTimeEvent_EClass();
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


std::shared_ptr<ecore::EObject> TimeEventImpl::eContainer() const
{
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2024
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2020
		case UmlPackage::TIMEEVENT_EATTRIBUTE_ISRELATIVE:
			return getIsRelative(); //20213
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2025
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2026
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2027
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2021
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2022
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2023
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //20212
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2024
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2028
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2025
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2029
		case UmlPackage::TIMEEVENT_EREFERENCE_WHEN:
			return getWhen(); //20214
	}
	return boost::any();
}

void TimeEventImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TIMEEVENT_EATTRIBUTE_ISRELATIVE:
		{
			// BOOST CAST
			bool _isRelative = boost::any_cast<bool>(newValue);
			setIsRelative(_isRelative); //20213
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2025
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2026
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //20212
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2024
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2025
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2029
			break;
		}
		case UmlPackage::TIMEEVENT_EREFERENCE_WHEN:
		{
			// BOOST CAST
			std::shared_ptr<uml::TimeExpression> _when = boost::any_cast<std::shared_ptr<uml::TimeExpression>>(newValue);
			setWhen(_when); //20214
			break;
		}
	}
}

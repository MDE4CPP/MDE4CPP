#include "uml/impl/MessageEventImpl.hpp"
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


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageEventImpl::MessageEventImpl()
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

MessageEventImpl::~MessageEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MessageEventImpl::MessageEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:MessageEventImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			MessageEventImpl::MessageEventImpl(std::weak_ptr<uml::Element > par_owner)
			:MessageEventImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			MessageEventImpl::MessageEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:MessageEventImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			MessageEventImpl::MessageEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:MessageEventImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






MessageEventImpl::MessageEventImpl(const MessageEventImpl & obj):MessageEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

}

std::shared_ptr<ecore::EObject>  MessageEventImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new MessageEventImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> MessageEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessageEvent_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > MessageEventImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > MessageEventImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > MessageEventImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> MessageEventImpl::eContainer() const
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
boost::any MessageEventImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1964
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1960
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1965
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1966
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1967
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1961
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1962
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1963
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //19612
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1964
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1968
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1965
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1969
	}
	return boost::any();
}

void MessageEventImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1965
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1966
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //19612
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //1964
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //1965
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1969
			break;
		}
	}
}

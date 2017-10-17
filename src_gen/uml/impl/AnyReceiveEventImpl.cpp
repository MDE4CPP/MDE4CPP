#include "AnyReceiveEventImpl.hpp"
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

#include "MessageEvent.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AnyReceiveEventImpl::AnyReceiveEventImpl()
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

AnyReceiveEventImpl::~AnyReceiveEventImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AnyReceiveEvent "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:AnyReceiveEventImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Element > par_owner)
			:AnyReceiveEventImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:AnyReceiveEventImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			AnyReceiveEventImpl::AnyReceiveEventImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:AnyReceiveEventImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






AnyReceiveEventImpl::AnyReceiveEventImpl(const AnyReceiveEventImpl & obj):AnyReceiveEventImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AnyReceiveEvent "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  AnyReceiveEventImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new AnyReceiveEventImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> AnyReceiveEventImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAnyReceiveEvent();
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
std::weak_ptr<uml::Namespace > AnyReceiveEventImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > AnyReceiveEventImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > AnyReceiveEventImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AnyReceiveEventImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1954
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1950
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1955
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1956
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1957
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1951
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1952
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1953
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //19512
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1954
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1958
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1955
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1959
	}
	return boost::any();
}

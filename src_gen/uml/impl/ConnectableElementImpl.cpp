#include "ConnectableElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "ConnectorEnd.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "ParameterableElement.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "TypedElement.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectableElementImpl::ConnectableElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_end.reset(new Bag<uml::ConnectorEnd>());
	
	

	//Init references
	
	
}

ConnectableElementImpl::~ConnectableElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectableElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ConnectableElementImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::Element > par_owner)
			:ConnectableElementImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ConnectableElementImpl::ConnectableElementImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ConnectableElementImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






ConnectableElementImpl::ConnectableElementImpl(const ConnectableElementImpl & obj):ConnectableElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectableElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::ConnectorEnd> > _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


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

std::shared_ptr<ecore::EObject>  ConnectableElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ConnectableElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ConnectableElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectableElement();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::ConnectorEnd> > ConnectableElementImpl::getEnds() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::ConnectorEnd> > ConnectableElementImpl::getEnd() const
{

    return m_end;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ConnectableElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ConnectableElementImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectableElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //294
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //290
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //2913
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //295
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //296
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //297
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //291
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //292
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //293
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //294
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //298
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //295
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //2910
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //299
	}
	return boost::any();
}

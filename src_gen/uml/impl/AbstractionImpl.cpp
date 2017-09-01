#include "AbstractionImpl.hpp"
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

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "OpaqueExpression.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AbstractionImpl::AbstractionImpl()
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

AbstractionImpl::~AbstractionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Abstraction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			AbstractionImpl::AbstractionImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:AbstractionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			AbstractionImpl::AbstractionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:AbstractionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}





//Additional constructor for the containments back reference
			AbstractionImpl::AbstractionImpl(std::weak_ptr<uml::Element > par_owner)
			:AbstractionImpl()
			{
			    m_owner = par_owner;
			}






AbstractionImpl::AbstractionImpl(const AbstractionImpl & obj):AbstractionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Abstraction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_templateParameter  = obj.getTemplateParameter();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::NamedElement>> _clientList = obj.getClient();
	for(std::shared_ptr<uml::NamedElement> _client : *_clientList)
	{
		this->getClient()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_client->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_client" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMapping()!=nullptr)
	{
		m_mapping.reset(dynamic_cast<uml::OpaqueExpression*>(obj.getMapping()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_mapping" << std::endl;
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
	std::shared_ptr<Bag<uml::NamedElement>> _supplierList = obj.getSupplier();
	for(std::shared_ptr<uml::NamedElement> _supplier : *_supplierList)
	{
		this->getSupplier()->add(std::shared_ptr<uml::NamedElement>(dynamic_cast<uml::NamedElement*>(_supplier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_supplier" << std::endl;
	#endif

	

}

ecore::EObject *  AbstractionImpl::copy() const
{
	return new AbstractionImpl(*this);
}

std::shared_ptr<ecore::EClass> AbstractionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getAbstraction();
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
std::shared_ptr<uml::OpaqueExpression > AbstractionImpl::getMapping() const
{

    return m_mapping;
}
void AbstractionImpl::setMapping(std::shared_ptr<uml::OpaqueExpression> _mapping)
{
    m_mapping = _mapping;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > AbstractionImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > AbstractionImpl::getTarget() const
{
	return m_target;
}
std::weak_ptr<uml::Element > AbstractionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > AbstractionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > AbstractionImpl::getSource() const
{
	return m_source;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any AbstractionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //4215
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //424
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //420
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //4217
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //425
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //426
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //427
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //421
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //422
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //423
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //424
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //428
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //424
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //425
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //4216
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //426
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //425
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //429
	}
	return boost::any();
}

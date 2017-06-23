#include "AbstractionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
	
}

AbstractionImpl::~AbstractionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Abstraction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

AbstractionImpl::AbstractionImpl(const AbstractionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > >
	 _client = obj.getClient();
	m_client.reset(new 		SubsetUnion<uml::NamedElement, uml::Element > 
	(*(obj.getClient().get())));// this->getClient()->insert(this->getClient()->end(), _client->begin(), _client->end());

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element > >
	 _supplier = obj.getSupplier();
	m_supplier.reset(new 		SubsetUnion<uml::NamedElement, uml::Element > 
	(*(obj.getSupplier().get())));// this->getSupplier()->insert(this->getSupplier()->end(), _supplier->begin(), _supplier->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getMapping()!=nullptr)
	{
		m_mapping.reset(dynamic_cast<uml::OpaqueExpression*>(obj.getMapping()->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
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
// Attribute Setter Gettter
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
std::shared_ptr<uml::Element > AbstractionImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 AbstractionImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<Union<uml::Element> > AbstractionImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<Union<uml::Element> > AbstractionImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 AbstractionImpl::getTarget() const
{
	

	return m_target;
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

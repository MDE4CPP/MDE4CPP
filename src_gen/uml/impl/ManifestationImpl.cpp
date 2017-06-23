#include "ManifestationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ManifestationImpl::ManifestationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
}

ManifestationImpl::~ManifestationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Manifestation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ManifestationImpl::ManifestationImpl(const ManifestationImpl & obj)
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

	m_utilizedElement  = obj.getUtilizedElement();


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

ecore::EObject *  ManifestationImpl::copy() const
{
	return new ManifestationImpl(*this);
}

std::shared_ptr<ecore::EClass> ManifestationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getManifestation();
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
std::shared_ptr<uml::PackageableElement > ManifestationImpl::getUtilizedElement() const
{
//assert(m_utilizedElement);
    return m_utilizedElement;
}
void ManifestationImpl::setUtilizedElement(std::shared_ptr<uml::PackageableElement> _utilizedElement)
{
    m_utilizedElement = _utilizedElement;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ManifestationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ManifestationImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<Union<uml::Element> > ManifestationImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ManifestationImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<Union<uml::Element> > ManifestationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ManifestationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //4115
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //414
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //410
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //4117
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //415
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //416
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //417
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //411
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //412
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //413
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //414
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //418
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //414
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //415
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //4116
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //416
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //415
		case UmlPackage::MANIFESTATION_UTILIZEDELEMENT:
			return getUtilizedElement(); //4118
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //419
	}
	return boost::any();
}

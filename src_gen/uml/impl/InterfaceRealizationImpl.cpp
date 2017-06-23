#include "InterfaceRealizationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceRealizationImpl::InterfaceRealizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

InterfaceRealizationImpl::~InterfaceRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterfaceRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InterfaceRealizationImpl::InterfaceRealizationImpl(const InterfaceRealizationImpl & obj)
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

	m_contract  = obj.getContract();

	m_implementingClassifier  = obj.getImplementingClassifier();

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

ecore::EObject *  InterfaceRealizationImpl::copy() const
{
	return new InterfaceRealizationImpl(*this);
}

std::shared_ptr<ecore::EClass> InterfaceRealizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterfaceRealization();
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
std::shared_ptr<uml::Interface > InterfaceRealizationImpl::getContract() const
{
//assert(m_contract);
    return m_contract;
}
void InterfaceRealizationImpl::setContract(std::shared_ptr<uml::Interface> _contract)
{
    m_contract = _contract;
}

std::shared_ptr<uml::BehavioredClassifier > InterfaceRealizationImpl::getImplementingClassifier() const
{
//assert(m_implementingClassifier);
    return m_implementingClassifier;
}
void InterfaceRealizationImpl::setImplementingClassifier(std::shared_ptr<uml::BehavioredClassifier> _implementingClassifier)
{
    m_implementingClassifier = _implementingClassifier;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 InterfaceRealizationImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 InterfaceRealizationImpl::getTarget() const
{
	

	return m_target;
}
std::shared_ptr<uml::Element > InterfaceRealizationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > InterfaceRealizationImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<Union<uml::Element> > InterfaceRealizationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterfaceRealizationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //10515
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1054
		case UmlPackage::INTERFACEREALIZATION_CONTRACT:
			return getContract(); //10518
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1050
		case UmlPackage::INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER:
			return getImplementingClassifier(); //10519
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //10517
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1055
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1056
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1057
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1051
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1052
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1053
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1054
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1058
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //1054
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //1055
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //10516
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //1056
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1055
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1059
	}
	return boost::any();
}

#include "ComponentRealizationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ComponentRealizationImpl::ComponentRealizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
		/*Subset*/
		m_realizingClassifier.reset(new Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ >(m_client));//(m_client));
	
	
}

ComponentRealizationImpl::~ComponentRealizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ComponentRealization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ComponentRealizationImpl::ComponentRealizationImpl(const ComponentRealizationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_abstraction  = obj.getAbstraction();

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

			std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ > >
	 _realizingClassifier = obj.getRealizingClassifier();
	m_realizingClassifier.reset(new 		Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ > 
	(*(obj.getRealizingClassifier().get())));// this->getRealizingClassifier()->insert(this->getRealizingClassifier()->end(), _realizingClassifier->begin(), _realizingClassifier->end());

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

ecore::EObject *  ComponentRealizationImpl::copy() const
{
	return new ComponentRealizationImpl(*this);
}

std::shared_ptr<ecore::EClass> ComponentRealizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getComponentRealization();
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
std::shared_ptr<uml::Component > ComponentRealizationImpl::getAbstraction() const
{

    return m_abstraction;
}
void ComponentRealizationImpl::setAbstraction(std::shared_ptr<uml::Component> _abstraction)
{
    m_abstraction = _abstraction;
}

		std::shared_ptr<Subset<uml::Classifier, uml::NamedElement /*Subset does not reference a union*/ > >
 ComponentRealizationImpl::getRealizingClassifier() const
{
//assert(m_realizingClassifier);
    return m_realizingClassifier;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ComponentRealizationImpl::getSource() const
{
	

	return m_source;
}
std::shared_ptr<uml::Element > ComponentRealizationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ComponentRealizationImpl::getTarget() const
{
	

	return m_target;
}
		std::shared_ptr<Union<uml::Element> > ComponentRealizationImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<Union<uml::Element> > ComponentRealizationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ComponentRealizationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COMPONENTREALIZATION_ABSTRACTION:
			return getAbstraction(); //24019
		case UmlPackage::DEPENDENCY_CLIENT:
			return getClient(); //24015
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2404
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2400
		case UmlPackage::ABSTRACTION_MAPPING:
			return getMapping(); //24017
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2405
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2406
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2407
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2401
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2402
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2403
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2404
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2408
		case UmlPackage::COMPONENTREALIZATION_REALIZINGCLASSIFIER:
			return getRealizingClassifier(); //24018
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //2404
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //2405
		case UmlPackage::DEPENDENCY_SUPPLIER:
			return getSupplier(); //24016
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //2406
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2405
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2409
	}
	return boost::any();
}

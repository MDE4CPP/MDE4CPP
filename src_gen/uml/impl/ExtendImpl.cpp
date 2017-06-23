#include "ExtendImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtendImpl::ExtendImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
	
		m_extensionLocation.reset(new Bag<uml::ExtensionPoint>());
	
	
}

ExtendImpl::~ExtendImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extend "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExtendImpl::ExtendImpl(const ExtendImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_extendedCase  = obj.getExtendedCase();

	m_extension  = obj.getExtension();

		std::shared_ptr< Bag<uml::ExtensionPoint> >
	 _extensionLocation = obj.getExtensionLocation();
	m_extensionLocation.reset(new 	 Bag<uml::ExtensionPoint> 
	(*(obj.getExtensionLocation().get())));// this->getExtensionLocation()->insert(this->getExtensionLocation()->end(), _extensionLocation->begin(), _extensionLocation->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));// this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _source = obj.getSource();
	m_source.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getSource().get())));// this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());

			std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
	 _target = obj.getTarget();
	m_target.reset(new 		SubsetUnion<uml::Element, uml::Element > 
	(*(obj.getTarget().get())));// this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());


	//clone containt lists
	if(obj.getCondition()!=nullptr)
	{
		m_condition.reset(dynamic_cast<uml::Constraint*>(obj.getCondition()->copy()));
	}
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
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

ecore::EObject *  ExtendImpl::copy() const
{
	return new ExtendImpl(*this);
}

std::shared_ptr<ecore::EClass> ExtendImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtend();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ExtendImpl::extension_points(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Constraint > ExtendImpl::getCondition() const
{

    return m_condition;
}
void ExtendImpl::setCondition(std::shared_ptr<uml::Constraint> _condition)
{
    m_condition = _condition;
}

std::shared_ptr<uml::UseCase > ExtendImpl::getExtendedCase() const
{
//assert(m_extendedCase);
    return m_extendedCase;
}
void ExtendImpl::setExtendedCase(std::shared_ptr<uml::UseCase> _extendedCase)
{
    m_extendedCase = _extendedCase;
}

std::shared_ptr<uml::UseCase > ExtendImpl::getExtension() const
{
//assert(m_extension);
    return m_extension;
}
void ExtendImpl::setExtension(std::shared_ptr<uml::UseCase> _extension)
{
    m_extension = _extension;
}

	std::shared_ptr< Bag<uml::ExtensionPoint> >
 ExtendImpl::getExtensionLocation() const
{
//assert(m_extensionLocation);
    return m_extensionLocation;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ExtendImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > ExtendImpl::getOwner() const
{
	

	return m_owner;
}
std::shared_ptr<uml::Namespace > ExtendImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > ExtendImpl::getRelatedElement() const
{
	

	return m_relatedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ExtendImpl::getSource() const
{
	

	return m_source;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ExtendImpl::getTarget() const
{
	

	return m_target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtendImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //994
		case UmlPackage::EXTEND_CONDITION:
			return getCondition(); //9913
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //990
		case UmlPackage::EXTEND_EXTENDEDCASE:
			return getExtendedCase(); //9914
		case UmlPackage::EXTEND_EXTENSION:
			return getExtension(); //9916
		case UmlPackage::EXTEND_EXTENSIONLOCATION:
			return getExtensionLocation(); //9915
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //995
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //996
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //997
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //991
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //992
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //993
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //998
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //994
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //995
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //996
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //999
	}
	return boost::any();
}

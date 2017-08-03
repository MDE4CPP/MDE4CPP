#include "ExtendImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ExtensionPoint.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "UseCase.hpp"


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
	//References
	

	

	

		m_extensionLocation.reset(new Bag<uml::ExtensionPoint>());
	
	

	//Init references
	

	

	

	
	
}

ExtendImpl::~ExtendImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extend "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExtendImpl::ExtendImpl(const ExtendImpl & obj):ExtendImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Extend "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

		std::shared_ptr< Bag<uml::ExtensionPoint> >
	 _extensionLocation = obj.getExtensionLocation();
	m_extensionLocation.reset(new 	 Bag<uml::ExtensionPoint> 
	(*(obj.getExtensionLocation().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));


    
	//Clone references with containment (deep copy)

	if(obj.getCondition()!=nullptr)
	{
		m_condition.reset(dynamic_cast<uml::Constraint*>(obj.getCondition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_condition" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getExtendedCase()!=nullptr)
	{
		m_extendedCase.reset(dynamic_cast<uml::UseCase*>(obj.getExtendedCase()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extendedCase" << std::endl;
	#endif
	if(obj.getExtension()!=nullptr)
	{
		m_extension.reset(dynamic_cast<uml::UseCase*>(obj.getExtension()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extension" << std::endl;
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
std::shared_ptr<uml::Namespace > ExtendImpl::getNamespace() const
{
	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > ExtendImpl::getRelatedElement() const
{
	return m_relatedElement;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ExtendImpl::getTarget() const
{
	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 ExtendImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<uml::Element > ExtendImpl::getOwner() const
{
	return m_owner;
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

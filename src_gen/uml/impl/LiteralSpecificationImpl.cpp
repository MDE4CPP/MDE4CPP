#include "LiteralSpecificationImpl.hpp"
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

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralSpecificationImpl::LiteralSpecificationImpl()
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

LiteralSpecificationImpl::~LiteralSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LiteralSpecificationImpl::LiteralSpecificationImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:LiteralSpecificationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LiteralSpecificationImpl::LiteralSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:LiteralSpecificationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






LiteralSpecificationImpl::LiteralSpecificationImpl(const LiteralSpecificationImpl & obj):LiteralSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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

ecore::EObject *  LiteralSpecificationImpl::copy() const
{
	return new LiteralSpecificationImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralSpecification();
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
std::weak_ptr<uml::Element > LiteralSpecificationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > LiteralSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2494
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2490
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2495
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2496
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2497
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2491
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2492
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2493
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2494
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2498
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2495
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24910
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2499
	}
	return boost::any();
}

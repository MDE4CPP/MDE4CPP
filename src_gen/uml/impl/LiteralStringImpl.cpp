#include "LiteralStringImpl.hpp"
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

#include "LiteralSpecification.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "Slot.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralStringImpl::LiteralStringImpl()
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

LiteralStringImpl::~LiteralStringImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralString "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:LiteralStringImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Element > par_owner)
			:LiteralStringImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:LiteralStringImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:LiteralStringImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			LiteralStringImpl::LiteralStringImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:LiteralStringImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






LiteralStringImpl::LiteralStringImpl(const LiteralStringImpl & obj):LiteralStringImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralString "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_value = obj.getValue();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

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

std::shared_ptr<ecore::EObject>  LiteralStringImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralStringImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralStringImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralString();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LiteralStringImpl::setValue(std::string _value)
{
	m_value = _value;
} 

std::string LiteralStringImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > LiteralStringImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > LiteralStringImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > LiteralStringImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralStringImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2534
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2530
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2535
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2536
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2537
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2531
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2532
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2533
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //25312
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //25314
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2534
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2538
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2535
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //25310
		case UmlPackage::LITERALSTRING_VALUE:
			return getValue(); //25315
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2539
	}
	return boost::any();
}

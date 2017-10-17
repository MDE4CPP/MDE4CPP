#include "LiteralUnlimitedNaturalImpl.hpp"
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
LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl()
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

LiteralUnlimitedNaturalImpl::~LiteralUnlimitedNaturalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralUnlimitedNatural "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:LiteralUnlimitedNaturalImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Element > par_owner)
			:LiteralUnlimitedNaturalImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:LiteralUnlimitedNaturalImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:LiteralUnlimitedNaturalImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:LiteralUnlimitedNaturalImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






LiteralUnlimitedNaturalImpl::LiteralUnlimitedNaturalImpl(const LiteralUnlimitedNaturalImpl & obj):LiteralUnlimitedNaturalImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralUnlimitedNatural "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  LiteralUnlimitedNaturalImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LiteralUnlimitedNaturalImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LiteralUnlimitedNaturalImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralUnlimitedNatural();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LiteralUnlimitedNaturalImpl::setValue(int _value)
{
	m_value = _value;
} 

int LiteralUnlimitedNaturalImpl::getValue() const 
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
std::weak_ptr<uml::Namespace > LiteralUnlimitedNaturalImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > LiteralUnlimitedNaturalImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > LiteralUnlimitedNaturalImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralUnlimitedNaturalImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2544
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2540
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2545
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2546
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2547
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2541
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2542
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2543
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //25412
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //25414
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2544
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2548
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2545
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //25410
		case UmlPackage::LITERALUNLIMITEDNATURAL_VALUE:
			return getValue(); //25415
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2549
	}
	return boost::any();
}

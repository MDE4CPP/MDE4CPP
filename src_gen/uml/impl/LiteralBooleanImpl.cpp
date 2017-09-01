#include "LiteralBooleanImpl.hpp"
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

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LiteralBooleanImpl::LiteralBooleanImpl()
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

LiteralBooleanImpl::~LiteralBooleanImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LiteralBoolean "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:LiteralBooleanImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			LiteralBooleanImpl::LiteralBooleanImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:LiteralBooleanImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






LiteralBooleanImpl::LiteralBooleanImpl(const LiteralBooleanImpl & obj):LiteralBooleanImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LiteralBoolean "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_value = obj.getValue();
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

ecore::EObject *  LiteralBooleanImpl::copy() const
{
	return new LiteralBooleanImpl(*this);
}

std::shared_ptr<ecore::EClass> LiteralBooleanImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLiteralBoolean();
}

//*********************************
// Attribute Setter Getter
//*********************************
void LiteralBooleanImpl::setValue(bool _value)
{
	m_value = _value;
} 

bool LiteralBooleanImpl::getValue() const 
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
std::weak_ptr<uml::Element > LiteralBooleanImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > LiteralBooleanImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LiteralBooleanImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2484
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2480
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2485
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2486
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2487
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2481
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2482
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2483
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2484
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2488
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2485
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24810
		case UmlPackage::LITERALBOOLEAN_VALUE:
			return getValue(); //24813
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2489
	}
	return boost::any();
}

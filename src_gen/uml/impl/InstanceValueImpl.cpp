#include "InstanceValueImpl.hpp"
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

#include "InstanceSpecification.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceValueImpl::InstanceValueImpl()
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

InstanceValueImpl::~InstanceValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InstanceValueImpl::InstanceValueImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:InstanceValueImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InstanceValueImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






InstanceValueImpl::InstanceValueImpl(const InstanceValueImpl & obj):InstanceValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_instance  = obj.getInstance();

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

ecore::EObject *  InstanceValueImpl::copy() const
{
	return new InstanceValueImpl(*this);
}

std::shared_ptr<ecore::EClass> InstanceValueImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceValue();
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
std::shared_ptr<uml::InstanceSpecification > InstanceValueImpl::getInstance() const
{
//assert(m_instance);
    return m_instance;
}
void InstanceValueImpl::setInstance(std::shared_ptr<uml::InstanceSpecification> _instance)
{
    m_instance = _instance;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Element > InstanceValueImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > InstanceValueImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InstanceValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1944
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1940
		case UmlPackage::INSTANCEVALUE_INSTANCE:
			return getInstance(); //19413
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1945
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1946
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1947
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1941
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1942
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1943
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1944
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1948
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1945
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //19410
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1949
	}
	return boost::any();
}

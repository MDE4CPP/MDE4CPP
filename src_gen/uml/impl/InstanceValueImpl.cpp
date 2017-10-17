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

#include "Package.hpp"

#include "Slot.hpp"

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
			InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InstanceValueImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Element > par_owner)
			:InstanceValueImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InstanceValueImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InstanceValueImpl::InstanceValueImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:InstanceValueImpl()
			{
			    m_owningSlot = par_owningSlot;
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

std::shared_ptr<ecore::EObject>  InstanceValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InstanceValueImpl(*this));
	return element;
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
std::weak_ptr<uml::Namespace > InstanceValueImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InstanceValueImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InstanceValueImpl::getOwner() const
{
	return m_owner;
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
			return getInstance(); //19415
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
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //19412
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //19414
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

#include "IntervalImpl.hpp"
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
IntervalImpl::IntervalImpl()
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

IntervalImpl::~IntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			IntervalImpl::IntervalImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:IntervalImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			IntervalImpl::IntervalImpl(std::weak_ptr<uml::Element > par_owner)
			:IntervalImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			IntervalImpl::IntervalImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:IntervalImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			IntervalImpl::IntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:IntervalImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			IntervalImpl::IntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:IntervalImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






IntervalImpl::IntervalImpl(const IntervalImpl & obj):IntervalImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Interval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_max  = obj.getMax();

	m_min  = obj.getMin();

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

std::shared_ptr<ecore::EObject>  IntervalImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new IntervalImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> IntervalImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterval();
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
std::shared_ptr<uml::ValueSpecification > IntervalImpl::getMax() const
{
//assert(m_max);
    return m_max;
}
void IntervalImpl::setMax(std::shared_ptr<uml::ValueSpecification> _max)
{
    m_max = _max;
}

std::shared_ptr<uml::ValueSpecification > IntervalImpl::getMin() const
{
//assert(m_min);
    return m_min;
}
void IntervalImpl::setMin(std::shared_ptr<uml::ValueSpecification> _min)
{
    m_min = _min;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > IntervalImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > IntervalImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > IntervalImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IntervalImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2454
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2450
		case UmlPackage::INTERVAL_MAX:
			return getMax(); //24515
		case UmlPackage::INTERVAL_MIN:
			return getMin(); //24516
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2455
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2456
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2457
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2451
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2452
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2453
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //24512
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //24514
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2454
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2458
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2455
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24510
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2459
	}
	return boost::any();
}

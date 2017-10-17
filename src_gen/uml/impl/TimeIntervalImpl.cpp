#include "TimeIntervalImpl.hpp"
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

#include "Interval.hpp"

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
TimeIntervalImpl::TimeIntervalImpl()
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

TimeIntervalImpl::~TimeIntervalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeInterval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeIntervalImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeIntervalImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeIntervalImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:TimeIntervalImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			TimeIntervalImpl::TimeIntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeIntervalImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






TimeIntervalImpl::TimeIntervalImpl(const TimeIntervalImpl & obj):TimeIntervalImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeInterval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  TimeIntervalImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TimeIntervalImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TimeIntervalImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeInterval();
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
std::weak_ptr<uml::Namespace > TimeIntervalImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TimeIntervalImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeIntervalImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeIntervalImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2564
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2560
		case UmlPackage::INTERVAL_MAX:
			return getMax(); //25615
		case UmlPackage::INTERVAL_MIN:
			return getMin(); //25616
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2565
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2566
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2567
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2561
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2562
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2563
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //25612
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //25614
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2564
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2568
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2565
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //25610
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2569
	}
	return boost::any();
}

#include "TimeConstraintImpl.hpp"
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

#include "IntervalConstraint.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeConstraintImpl::TimeConstraintImpl()
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

TimeConstraintImpl::~TimeConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:TimeConstraintImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::CONSTRAINT_CONTEXT:
					 m_context = par_Namespace;
					 return;
				case UmlPackage::NAMEDELEMENT_NAMESPACE:
					 m_namespace = par_Namespace;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






TimeConstraintImpl::TimeConstraintImpl(const TimeConstraintImpl & obj):TimeConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firstEvent = obj.getFirstEvent();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Element> > _constrainedElement = obj.getConstrainedElement();
	m_constrainedElement.reset(new Bag<uml::Element>(*(obj.getConstrainedElement().get())));

	m_context  = obj.getContext();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


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
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specification" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  TimeConstraintImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TimeConstraintImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TimeConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeConstraint();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeConstraintImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool TimeConstraintImpl::has_one_constrainedElement(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TimeConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeConstraintImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2554
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //25513
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //25514
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2550
		case UmlPackage::TIMECONSTRAINT_FIRSTEVENT:
			return getFirstEvent(); //25516
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2555
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2556
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2557
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2551
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2552
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2553
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //25512
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2554
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2558
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //25515
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2555
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2559
	}
	return boost::any();
}

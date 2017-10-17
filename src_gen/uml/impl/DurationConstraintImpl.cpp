#include "DurationConstraintImpl.hpp"
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
DurationConstraintImpl::DurationConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_firstEvent.reset(new Bag<bool>());
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

DurationConstraintImpl::~DurationConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:DurationConstraintImpl()
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
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:DurationConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:DurationConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DurationConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






DurationConstraintImpl::DurationConstraintImpl(const DurationConstraintImpl & obj):DurationConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  DurationConstraintImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DurationConstraintImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DurationConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDurationConstraint();
}

//*********************************
// Attribute Setter Getter
//*********************************


std::shared_ptr<Bag<bool> > DurationConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool DurationConstraintImpl::first_event_multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool DurationConstraintImpl::has_one_or_two_constrainedElements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::weak_ptr<uml::Namespace > DurationConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > DurationConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DurationConstraintImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DurationConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2434
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //24313
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //24314
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2430
		case UmlPackage::DURATIONCONSTRAINT_FIRSTEVENT:
			return getFirstEvent(); //24316
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2435
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2436
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2437
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2431
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2432
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2433
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //24312
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2434
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2438
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //24315
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2435
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2439
	}
	return boost::any();
}

#include "uml/impl/IntervalConstraintImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IntervalConstraintImpl::IntervalConstraintImpl()
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

IntervalConstraintImpl::~IntervalConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntervalConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:IntervalConstraintImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
					 m_context = par_Namespace;
					 return;
				case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
					 m_namespace = par_Namespace;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:IntervalConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:IntervalConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:IntervalConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






IntervalConstraintImpl::IntervalConstraintImpl(const IntervalConstraintImpl & obj):IntervalConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntervalConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  IntervalConstraintImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new IntervalConstraintImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> IntervalConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getIntervalConstraint_EClass();
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
std::weak_ptr<uml::Namespace > IntervalConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > IntervalConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > IntervalConstraintImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> IntervalConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
	{
		return wp;
	}
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}


	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IntervalConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2444
		case UmlPackage::CONSTRAINT_EREFERENCE_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //24413
		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
			return getContext(); //24414
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2440
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2445
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2446
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2447
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2441
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2442
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2443
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //24412
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2444
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2448
		case UmlPackage::CONSTRAINT_EREFERENCE_SPECIFICATION:
			return getSpecification(); //24415
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2445
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2449
	}
	return boost::any();
}

void IntervalConstraintImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Namespace> _context = boost::any_cast<std::shared_ptr<uml::Namespace>>(newValue);
			setContext(_context); //24414
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2445
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2446
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //24412
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2444
			break;
		}
		case UmlPackage::CONSTRAINT_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //24415
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2445
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2449
			break;
		}
	}
}

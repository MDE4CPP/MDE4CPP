#include "InteractionConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionConstraintImpl::InteractionConstraintImpl()
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

InteractionConstraintImpl::~InteractionConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:InteractionConstraintImpl()
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
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InteractionConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InteractionConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






InteractionConstraintImpl::InteractionConstraintImpl(const InteractionConstraintImpl & obj):InteractionConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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
	if(obj.getMaxint()!=nullptr)
	{
		m_maxint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMaxint()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_maxint" << std::endl;
	#endif
	if(obj.getMinint()!=nullptr)
	{
		m_minint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMinint()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_minint" << std::endl;
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

std::shared_ptr<ecore::EObject>  InteractionConstraintImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InteractionConstraintImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InteractionConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionConstraint();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionConstraintImpl::dynamic_variables(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::global_data(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_greater_equal_minint(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_positive(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_maxint(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_non_negative(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMaxint() const
{

    return m_maxint;
}
void InteractionConstraintImpl::setMaxint(std::shared_ptr<uml::ValueSpecification> _maxint)
{
    m_maxint = _maxint;
}

std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMinint() const
{

    return m_minint;
}
void InteractionConstraintImpl::setMinint(std::shared_ptr<uml::ValueSpecification> _minint)
{
    m_minint = _minint;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InteractionConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InteractionConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionConstraintImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InteractionConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2194
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //21913
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //21914
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2190
		case UmlPackage::INTERACTIONCONSTRAINT_MAXINT:
			return getMaxint(); //21916
		case UmlPackage::INTERACTIONCONSTRAINT_MININT:
			return getMinint(); //21917
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2195
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2196
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2197
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2191
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2192
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2193
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //21912
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2194
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2198
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //21915
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2195
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2199
	}
	return boost::any();
}

#include "uml/impl/InteractionConstraintImpl.hpp"
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


std::shared_ptr<ecore::EObject> InteractionConstraintImpl::eContainer() const
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
boost::any InteractionConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void InteractionConstraintImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CONSTRAINT_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Namespace> _context = boost::any_cast<std::shared_ptr<uml::Namespace>>(newValue);
			setContext(_context); //21914
			break;
		}
		case UmlPackage::INTERACTIONCONSTRAINT_MAXINT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _maxint = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setMaxint(_maxint); //21916
			break;
		}
		case UmlPackage::INTERACTIONCONSTRAINT_MININT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _minint = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setMinint(_minint); //21917
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2195
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2196
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //21912
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //2194
			break;
		}
		case UmlPackage::CONSTRAINT_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //21915
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //2195
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2199
			break;
		}
	}
}

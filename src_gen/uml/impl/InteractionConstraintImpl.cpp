#include "InteractionConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionConstraintImpl::InteractionConstraintImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

InteractionConstraintImpl::~InteractionConstraintImpl()
{
	if(m_maxint!=nullptr)
	{
		if(m_maxint)
		{
			delete(m_maxint);
			m_maxint = nullptr;
		}
	}
	if(m_minint!=nullptr)
	{
		if(m_minint)
		{
			delete(m_minint);
			m_minint = nullptr;
		}
	}
	
}

InteractionConstraintImpl::InteractionConstraintImpl(const InteractionConstraintImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Element * > *  _constrainedElement = obj.getConstrainedElement();
	this->getConstrainedElement()->insert(this->getConstrainedElement()->end(), _constrainedElement->begin(), _constrainedElement->end());

	m_context  = obj.getContext();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getMaxint()!=nullptr)
	{
		m_maxint = dynamic_cast<uml::ValueSpecification * >(obj.getMaxint()->copy());
	}
	if(obj.getMinint()!=nullptr)
	{
		m_minint = dynamic_cast<uml::ValueSpecification * >(obj.getMinint()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = dynamic_cast<uml::ValueSpecification * >(obj.getSpecification()->copy());
	}
}

ecore::EObject *  InteractionConstraintImpl::copy() const
{
	return new InteractionConstraintImpl(*this);
}

ecore::EClass* InteractionConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionConstraint();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionConstraintImpl::dynamic_variables(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::global_data(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_greater_equal_minint(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_positive(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_maxint(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_non_negative(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ValueSpecification *  InteractionConstraintImpl::getMaxint() const
{
	
	return m_maxint;
}
void InteractionConstraintImpl::setMaxint(uml::ValueSpecification *  _maxint)
{
	m_maxint = _maxint;
}

uml::ValueSpecification *  InteractionConstraintImpl::getMinint() const
{
	
	return m_minint;
}
void InteractionConstraintImpl::setMinint(uml::ValueSpecification *  _minint)
{
	m_minint = _minint;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InteractionConstraintImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getMaxint());
	_ownedElement->push_back(getMinint());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getSpecification());

	return _ownedElement;
}
uml::Namespace *  InteractionConstraintImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContext()!=nullptr)
	{
		_namespace = getContext();
	}

	return _namespace;
}
uml::Element *  InteractionConstraintImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
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
			return getConstrainedElement(); //21912
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //21913
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2190
		case UmlPackage::INTERACTIONCONSTRAINT_MAXINT:
			return getMaxint(); //21915
		case UmlPackage::INTERACTIONCONSTRAINT_MININT:
			return getMinint(); //21916
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
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2194
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2198
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //21914
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2195
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2199
	}
	return boost::any();
}

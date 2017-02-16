#include "ConstraintImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConstraintImpl::ConstraintImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_constrainedElement == nullptr)
	{
		m_constrainedElement = new std::vector<uml::Element * >();
	}
	
	
}

ConstraintImpl::~ConstraintImpl()
{
	if(m_constrainedElement!=nullptr)
	{
		delete(m_constrainedElement);
	 	m_constrainedElement = nullptr;
	}
	if(m_specification!=nullptr)
	{
		if(m_specification)
		{
			delete(m_specification);
			m_specification = nullptr;
		}
	}
	
}

ConstraintImpl::ConstraintImpl(const ConstraintImpl & obj)
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

ecore::EObject *  ConstraintImpl::copy() const
{
	return new ConstraintImpl(*this);
}

ecore::EClass* ConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConstraint();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ConstraintImpl::boolean_value(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::no_side_effects(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::not_apply_to_self(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Element * > *  ConstraintImpl::getConstrainedElement() const
{
	
	return m_constrainedElement;
}


uml::Namespace *  ConstraintImpl::getContext() const
{
	
	return m_context;
}
void ConstraintImpl::setContext(uml::Namespace *  _context)
{
	m_context = _context;
}

uml::ValueSpecification *  ConstraintImpl::getSpecification() const
{
	//assert(m_specification);
	return m_specification;
}
void ConstraintImpl::setSpecification(uml::ValueSpecification *  _specification)
{
	m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ConstraintImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getSpecification());

	return _ownedElement;
}
uml::Element *  ConstraintImpl::getOwner() const
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
uml::Namespace *  ConstraintImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getContext()!=nullptr)
	{
		_namespace = getContext();
	}

	return _namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConstraintImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //534
		case UmlPackage::CONSTRAINT_CONSTRAINEDELEMENT:
			return getConstrainedElement(); //5312
		case UmlPackage::CONSTRAINT_CONTEXT:
			return getContext(); //5313
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //530
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //535
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //536
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //537
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //531
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //532
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //533
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //534
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //538
		case UmlPackage::CONSTRAINT_SPECIFICATION:
			return getSpecification(); //5314
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //535
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //539
	}
	return boost::any();
}

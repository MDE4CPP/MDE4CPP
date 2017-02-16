#include "DurationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DurationImpl::DurationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_observation == nullptr)
	{
		m_observation = new std::vector<uml::Observation * >();
	}
}

DurationImpl::~DurationImpl()
{
	if(m_expr!=nullptr)
	{
		if(m_expr)
		{
			delete(m_expr);
			m_expr = nullptr;
		}
	}
	if(m_observation!=nullptr)
	{
		delete(m_observation);
	 	m_observation = nullptr;
	}
	
}

DurationImpl::DurationImpl(const DurationImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Observation * > *  _observation = obj.getObservation();
	this->getObservation()->insert(this->getObservation()->end(), _observation->begin(), _observation->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getExpr()!=nullptr)
	{
		m_expr = dynamic_cast<uml::ValueSpecification * >(obj.getExpr()->copy());
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  DurationImpl::copy() const
{
	return new DurationImpl(*this);
}

ecore::EClass* DurationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDuration();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool DurationImpl::no_expr_requires_observation(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ValueSpecification *  DurationImpl::getExpr() const
{
	
	return m_expr;
}
void DurationImpl::setExpr(uml::ValueSpecification *  _expr)
{
	m_expr = _expr;
}

std::vector<uml::Observation * > *  DurationImpl::getObservation() const
{
	
	return m_observation;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  DurationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getExpr());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  DurationImpl::getOwner() const
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
boost::any DurationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2424
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2420
		case UmlPackage::DURATION_EXPR:
			return getExpr(); //24213
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2425
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2426
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2427
		case UmlPackage::DURATION_OBSERVATION:
			return getObservation(); //24214
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2421
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2422
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2423
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2424
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2428
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2425
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //24210
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2429
	}
	return boost::any();
}

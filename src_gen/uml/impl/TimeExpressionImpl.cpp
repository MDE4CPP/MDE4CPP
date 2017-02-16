#include "TimeExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeExpressionImpl::TimeExpressionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_observation == nullptr)
	{
		m_observation = new std::vector<uml::Observation * >();
	}
}

TimeExpressionImpl::~TimeExpressionImpl()
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

TimeExpressionImpl::TimeExpressionImpl(const TimeExpressionImpl & obj)
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

ecore::EObject *  TimeExpressionImpl::copy() const
{
	return new TimeExpressionImpl(*this);
}

ecore::EClass* TimeExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeExpression();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TimeExpressionImpl::no_expr_requires_observation(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ValueSpecification *  TimeExpressionImpl::getExpr() const
{
	
	return m_expr;
}
void TimeExpressionImpl::setExpr(uml::ValueSpecification *  _expr)
{
	m_expr = _expr;
}

std::vector<uml::Observation * > *  TimeExpressionImpl::getObservation() const
{
	
	return m_observation;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TimeExpressionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getExpr());
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  TimeExpressionImpl::getOwner() const
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
boost::any TimeExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2034
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2030
		case UmlPackage::TIMEEXPRESSION_EXPR:
			return getExpr(); //20313
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2035
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2036
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2037
		case UmlPackage::TIMEEXPRESSION_OBSERVATION:
			return getObservation(); //20314
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2031
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2032
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2033
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2034
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2038
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2035
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //20310
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2039
	}
	return boost::any();
}

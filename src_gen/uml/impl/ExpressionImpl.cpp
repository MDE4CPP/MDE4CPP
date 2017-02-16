#include "ExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionImpl::ExpressionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_operand == nullptr)
	{
		m_operand = new std::vector<uml::ValueSpecification * >();
	}
}

ExpressionImpl::~ExpressionImpl()
{
	if(m_operand!=nullptr)
	{
		for(auto c :*m_operand)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ExpressionImpl::ExpressionImpl(const ExpressionImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_symbol = obj.getSymbol();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::ValueSpecification * 	_operand : *obj.getOperand())
	{
		this->getOperand()->push_back(dynamic_cast<uml::ValueSpecification * >(_operand->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  ExpressionImpl::copy() const
{
	return new ExpressionImpl(*this);
}

ecore::EClass* ExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExpression();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ExpressionImpl::setSymbol (std::string _symbol)
{
	m_symbol = _symbol;
} 

std::string ExpressionImpl::getSymbol() const 
{
	return m_symbol;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::vector<uml::ValueSpecification * > *  ExpressionImpl::getOperand() const
{
	
	return m_operand;
}


//*********************************
// Union Getter
//*********************************
uml::Element *  ExpressionImpl::getOwner() const
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
std::vector<uml::Element * > *  ExpressionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  operand = (std::vector<uml::Element * > * ) getOperand();
	_ownedElement->insert(_ownedElement->end(), operand->begin(), operand->end());

	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //884
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //880
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //885
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //886
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //887
		case UmlPackage::EXPRESSION_OPERAND:
			return getOperand(); //8813
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //881
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //882
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //883
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //884
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //888
		case UmlPackage::EXPRESSION_SYMBOL:
			return getSymbol(); //8814
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //885
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //8810
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //889
	}
	return boost::any();
}

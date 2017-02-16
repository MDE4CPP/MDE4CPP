#include "StringExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StringExpressionImpl::StringExpressionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_subExpression == nullptr)
	{
		m_subExpression = new std::vector<uml::StringExpression * >();
	}
}

StringExpressionImpl::~StringExpressionImpl()
{
	if(m_subExpression!=nullptr)
	{
		for(auto c :*m_subExpression)
		{
			delete(c);
			c = 0;
		}
	}
	
}

StringExpressionImpl::StringExpressionImpl(const StringExpressionImpl & obj)
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

	m_owningExpression  = obj.getOwningExpression();

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
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::StringExpression * 	_subExpression : *obj.getSubExpression())
	{
		this->getSubExpression()->push_back(dynamic_cast<uml::StringExpression * >(_subExpression->copy()));
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  StringExpressionImpl::copy() const
{
	return new StringExpressionImpl(*this);
}

ecore::EClass* StringExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStringExpression();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool StringExpressionImpl::operands(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StringExpressionImpl::subexpressions(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::StringExpression *  StringExpressionImpl::getOwningExpression() const
{
	
	return m_owningExpression;
}
void StringExpressionImpl::setOwningExpression(uml::StringExpression *  _owningExpression)
{
	m_owningExpression = _owningExpression;
}

std::vector<uml::StringExpression * > *  StringExpressionImpl::getSubExpression() const
{
	
	return m_subExpression;
}


//*********************************
// Union Getter
//*********************************
uml::Element *  StringExpressionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}
	if(getOwningExpression()!=nullptr)
	{
		_owner = getOwningExpression();
	}
	if(getOwningTemplateParameter()!=nullptr)
	{
		_owner = getOwningTemplateParameter();
	}

	return _owner;
}
std::vector<uml::Element * > *  StringExpressionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  operand = (std::vector<uml::Element * > * ) getOperand();
	_ownedElement->insert(_ownedElement->end(), operand->begin(), operand->end());

	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  subExpression = (std::vector<uml::Element * > * ) getSubExpression();
	_ownedElement->insert(_ownedElement->end(), subExpression->begin(), subExpression->end());

	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StringExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //874
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //870
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //875
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //876
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //877
		case UmlPackage::EXPRESSION_OPERAND:
			return getOperand(); //8713
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //871
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //872
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //875
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //873
		case UmlPackage::STRINGEXPRESSION_OWNINGEXPRESSION:
			return getOwningExpression(); //8717
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //874
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //878
		case UmlPackage::STRINGEXPRESSION_SUBEXPRESSION:
			return getSubExpression(); //8718
		case UmlPackage::EXPRESSION_SYMBOL:
			return getSymbol(); //8714
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //874
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //875
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //8710
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //879
	}
	return boost::any();
}

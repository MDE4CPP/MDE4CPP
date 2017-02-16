#include "OpaqueExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueExpressionImpl::OpaqueExpressionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

OpaqueExpressionImpl::~OpaqueExpressionImpl()
{
	
}

OpaqueExpressionImpl::OpaqueExpressionImpl(const OpaqueExpressionImpl & obj)
{
	//create copy of all Attributes
	m_body = obj.getBody();
	m_language = obj.getLanguage();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_behavior  = obj.getBehavior();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_result  = obj.getResult();

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
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  OpaqueExpressionImpl::copy() const
{
	return new OpaqueExpressionImpl(*this);
}

ecore::EClass* OpaqueExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOpaqueExpression();
}

//*********************************
// Attribute Setter Gettter
//*********************************


std::vector<std::string> *  OpaqueExpressionImpl::getBody() const 
{
	return m_body;
}



std::vector<std::string> *  OpaqueExpressionImpl::getLanguage() const 
{
	return m_language;
}

//*********************************
// Operations
//*********************************


bool OpaqueExpressionImpl::isIntegral() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isNonNegative() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isPositive() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::language_body_size(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::one_return_result_parameter(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::only_return_result_parameters(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OpaqueExpressionImpl::value() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Behavior *  OpaqueExpressionImpl::getBehavior() const
{
	
	return m_behavior;
}
void OpaqueExpressionImpl::setBehavior(uml::Behavior *  _behavior)
{
	m_behavior = _behavior;
}

uml::Parameter *  OpaqueExpressionImpl::getResult() const
{
	
	return m_result;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  OpaqueExpressionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  OpaqueExpressionImpl::getOwner() const
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
boost::any OpaqueExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::OPAQUEEXPRESSION_BEHAVIOR:
			return getBehavior(); //4313
		case UmlPackage::OPAQUEEXPRESSION_BODY:
			return getBody(); //4314
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //434
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //430
		case UmlPackage::OPAQUEEXPRESSION_LANGUAGE:
			return getLanguage(); //4315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //435
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //436
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //437
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //431
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //432
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //433
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //434
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //438
		case UmlPackage::OPAQUEEXPRESSION_RESULT:
			return getResult(); //4316
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //435
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //4310
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //439
	}
	return boost::any();
}

#include "EnumerationLiteralImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
	
}

EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Classifier * > *  _classifier = obj.getClassifier();
	this->getClassifier()->insert(this->getClassifier()->end(), _classifier->begin(), _classifier->end());

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::PackageableElement * > *  _deployedElement = obj.getDeployedElement();
	this->getDeployedElement()->insert(this->getDeployedElement()->end(), _deployedElement->begin(), _deployedElement->end());

	m_enumeration  = obj.getEnumeration();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	for(uml::Deployment * 	_deployment : *obj.getDeployment())
	{
		this->getDeployment()->push_back(dynamic_cast<uml::Deployment * >(_deployment->copy()));
	}
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
	for(uml::Slot * 	_slot : *obj.getSlot())
	{
		this->getSlot()->push_back(dynamic_cast<uml::Slot * >(_slot->copy()));
	}
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = dynamic_cast<uml::ValueSpecification * >(obj.getSpecification()->copy());
	}
}

ecore::EObject *  EnumerationLiteralImpl::copy() const
{
	return new EnumerationLiteralImpl(*this);
}

ecore::EClass* EnumerationLiteralImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getEnumerationLiteral();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************


std::vector<uml::Classifier * > *  EnumerationLiteralImpl::getClassifiers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Enumeration *  EnumerationLiteralImpl::getEnumeration() const
{
	//assert(m_enumeration);
	return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(uml::Enumeration *  _enumeration)
{
	m_enumeration = _enumeration;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  EnumerationLiteralImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  deployment = (std::vector<uml::Element * > * ) getDeployment();
	_ownedElement->insert(_ownedElement->end(), deployment->begin(), deployment->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  slot = (std::vector<uml::Element * > * ) getSlot();
	_ownedElement->insert(_ownedElement->end(), slot->begin(), slot->end());

	_ownedElement->push_back(getSpecification());

	return _ownedElement;
}
uml::Element *  EnumerationLiteralImpl::getOwner() const
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
uml::Namespace *  EnumerationLiteralImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getEnumeration()!=nullptr)
	{
		_namespace = getEnumeration();
	}

	return _namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EnumerationLiteralImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7814
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //784
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7810
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7811
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //780
		case UmlPackage::ENUMERATIONLITERAL_ENUMERATION:
			return getEnumeration(); //7817
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //785
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //786
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //787
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //781
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //782
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //783
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //784
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //788
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7815
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7816
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //785
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //789
	}
	return boost::any();
}

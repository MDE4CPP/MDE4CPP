#include "InstanceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceSpecificationImpl::InstanceSpecificationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_classifier == nullptr)
	{
		m_classifier = new std::vector<uml::Classifier * >();
	}
	if( m_slot == nullptr)
	{
		m_slot = new std::vector<uml::Slot * >();
	}
	
}

InstanceSpecificationImpl::~InstanceSpecificationImpl()
{
	if(m_classifier!=nullptr)
	{
		delete(m_classifier);
	 	m_classifier = nullptr;
	}
	if(m_slot!=nullptr)
	{
		for(auto c :*m_slot)
		{
			delete(c);
			c = 0;
		}
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

InstanceSpecificationImpl::InstanceSpecificationImpl(const InstanceSpecificationImpl & obj)
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

ecore::EObject *  InstanceSpecificationImpl::copy() const
{
	return new InstanceSpecificationImpl(*this);
}

ecore::EClass* InstanceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool InstanceSpecificationImpl::defining_feature(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_artifact(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::structural_feature(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Classifier * > *  InstanceSpecificationImpl::getClassifier() const
{
	
	return m_classifier;
}


std::vector<uml::Slot * > *  InstanceSpecificationImpl::getSlot() const
{
	
	return m_slot;
}


uml::ValueSpecification *  InstanceSpecificationImpl::getSpecification() const
{
	
	return m_specification;
}
void InstanceSpecificationImpl::setSpecification(uml::ValueSpecification *  _specification)
{
	m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  InstanceSpecificationImpl::getOwnedElement() const
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
uml::Element *  InstanceSpecificationImpl::getOwner() const
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
boost::any InstanceSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7914
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //794
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7910
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7911
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //790
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //795
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //796
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //797
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //791
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //792
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //793
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //794
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //798
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7915
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7916
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //795
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //799
	}
	return boost::any();
}

#include "OperationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationImpl::OperationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	
	if( m_postcondition == nullptr)
	{
		m_postcondition = new std::vector<uml::Constraint * >();
	}
	if( m_precondition == nullptr)
	{
		m_precondition = new std::vector<uml::Constraint * >();
	}
	if( m_redefinedOperation == nullptr)
	{
		m_redefinedOperation = new std::vector<uml::Operation * >();
	}
	
}

OperationImpl::~OperationImpl()
{
	if(m_postcondition!=nullptr)
	{
		delete(m_postcondition);
	 	m_postcondition = nullptr;
	}
	if(m_precondition!=nullptr)
	{
		delete(m_precondition);
	 	m_precondition = nullptr;
	}
	if(m_redefinedOperation!=nullptr)
	{
		delete(m_redefinedOperation);
	 	m_redefinedOperation = nullptr;
	}
	
}

OperationImpl::OperationImpl(const OperationImpl & obj)
{
	//create copy of all Attributes
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isQuery = obj.getIsQuery();
	m_isStatic = obj.getIsStatic();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_bodyCondition  = obj.getBodyCondition();

	m_class  = obj.getClass();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_datatype  = obj.getDatatype();

	std::vector<uml::Classifier * > *  _featuringClassifier = obj.getFeaturingClassifier();
	this->getFeaturingClassifier()->insert(this->getFeaturingClassifier()->end(), _featuringClassifier->begin(), _featuringClassifier->end());
	delete(_featuringClassifier);

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	m_interface  = obj.getInterface();

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	std::vector<uml::Behavior * > *  _method = obj.getMethod();
	this->getMethod()->insert(this->getMethod()->end(), _method->begin(), _method->end());

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::vector<uml::Constraint * > *  _postcondition = obj.getPostcondition();
	this->getPostcondition()->insert(this->getPostcondition()->end(), _postcondition->begin(), _postcondition->end());

	std::vector<uml::Constraint * > *  _precondition = obj.getPrecondition();
	this->getPrecondition()->insert(this->getPrecondition()->end(), _precondition->begin(), _precondition->end());

	std::vector<uml::Type * > *  _raisedException = obj.getRaisedException();
	this->getRaisedException()->insert(this->getRaisedException()->end(), _raisedException->begin(), _raisedException->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Operation * > *  _redefinedOperation = obj.getRedefinedOperation();
	this->getRedefinedOperation()->insert(this->getRedefinedOperation()->end(), _redefinedOperation->begin(), _redefinedOperation->end());

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Parameter * 	_ownedParameter : *obj.getOwnedParameter())
	{
		this->getOwnedParameter()->push_back(dynamic_cast<uml::Parameter * >(_ownedParameter->copy()));
	}
	for(uml::ParameterSet * 	_ownedParameterSet : *obj.getOwnedParameterSet())
	{
		this->getOwnedParameterSet()->push_back(dynamic_cast<uml::ParameterSet * >(_ownedParameterSet->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  OperationImpl::copy() const
{
	return new OperationImpl(*this);
}

ecore::EClass* OperationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOperation();
}

//*********************************
// Attribute Setter Gettter
//*********************************


bool OperationImpl::getIsOrdered() const 
{
	return m_isOrdered;
}

void OperationImpl::setIsQuery (bool _isQuery)
{
	m_isQuery = _isQuery;
} 

bool OperationImpl::getIsQuery() const 
{
	return m_isQuery;
}



bool OperationImpl::getIsUnique() const 
{
	return m_isUnique;
}



int OperationImpl::getLower() const 
{
	return m_lower;
}



int OperationImpl::getUpper() const 
{
	return m_upper;
}

//*********************************
// Operations
//*********************************
bool OperationImpl::at_most_one_return(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OperationImpl::getLower() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Parameter *  OperationImpl::getReturnResult() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



int OperationImpl::getUpper() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isOrdered() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isUnique() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::only_body_for_query(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Parameter * > *  OperationImpl::returnResult() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setIsOrdered(bool newIsOrdered) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setIsUnique(bool newIsUnique) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setLower(int newLower) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setType(uml::Type *  newType) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setUpper(int newUpper) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::Constraint *  OperationImpl::getBodyCondition() const
{
	
	return m_bodyCondition;
}
void OperationImpl::setBodyCondition(uml::Constraint *  _bodyCondition)
{
	m_bodyCondition = _bodyCondition;
}

uml::Class *  OperationImpl::getClass() const
{
	
	return m_class;
}
void OperationImpl::setClass(uml::Class *  _class)
{
	m_class = _class;
}

uml::DataType *  OperationImpl::getDatatype() const
{
	
	return m_datatype;
}
void OperationImpl::setDatatype(uml::DataType *  _datatype)
{
	m_datatype = _datatype;
}

uml::Interface *  OperationImpl::getInterface() const
{
	
	return m_interface;
}
void OperationImpl::setInterface(uml::Interface *  _interface)
{
	m_interface = _interface;
}

std::vector<uml::Constraint * > *  OperationImpl::getPostcondition() const
{
	
	return m_postcondition;
}


std::vector<uml::Constraint * > *  OperationImpl::getPrecondition() const
{
	
	return m_precondition;
}


std::vector<uml::Operation * > *  OperationImpl::getRedefinedOperation() const
{
	
	return m_redefinedOperation;
}


uml::Type *  OperationImpl::getType() const
{
	
	return m_type;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Classifier * > *  OperationImpl::getFeaturingClassifier() const
{
	std::vector<uml::Classifier * > *  _featuringClassifier =  new std::vector<uml::Classifier * >() ;
	
	_featuringClassifier->push_back(getClass());
	_featuringClassifier->push_back(getDatatype());
	_featuringClassifier->push_back(getInterface());

	return _featuringClassifier;
}
std::vector<uml::NamedElement * > *  OperationImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedParameter = (std::vector<uml::NamedElement * > * ) getOwnedParameter();
	_ownedMember->insert(_ownedMember->end(), ownedParameter->begin(), ownedParameter->end());

	std::vector<uml::NamedElement * > *  ownedParameterSet = (std::vector<uml::NamedElement * > * ) getOwnedParameterSet();
	_ownedMember->insert(_ownedMember->end(), ownedParameterSet->begin(), ownedParameterSet->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());


	return _ownedMember;
}
uml::Element *  OperationImpl::getOwner() const
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
std::vector<uml::RedefinableElement * > *  OperationImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedOperation = (std::vector<uml::RedefinableElement * > * ) getRedefinedOperation();
	_redefinedElement->insert(_redefinedElement->end(), redefinedOperation->begin(), redefinedOperation->end());


	return _redefinedElement;
}
uml::Namespace *  OperationImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getClass()!=nullptr)
	{
		_namespace = getClass();
	}
	if(getDatatype()!=nullptr)
	{
		_namespace = getDatatype();
	}
	if(getInterface()!=nullptr)
	{
		_namespace = getInterface();
	}

	return _namespace;
}
std::vector<uml::Element * > *  OperationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}
std::vector<uml::NamedElement * > *  OperationImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::Classifier * > *  OperationImpl::getRedefinitionContext() const
{
	std::vector<uml::Classifier * > *  _redefinitionContext =  new std::vector<uml::Classifier * >() ;
	
	_redefinitionContext->push_back(getClass());
	_redefinitionContext->push_back(getDatatype());
	_redefinitionContext->push_back(getInterface());

	return _redefinitionContext;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OperationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::OPERATION_BODYCONDITION:
			return getBodyCondition(); //4731
		case UmlPackage::OPERATION_CLASS:
			return getClass(); //4732
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //474
		case UmlPackage::BEHAVIORALFEATURE_CONCURRENCY:
			return getConcurrency(); //4721
		case UmlPackage::OPERATION_DATATYPE:
			return getDatatype(); //4733
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //470
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //4711
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4713
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //4714
		case UmlPackage::OPERATION_INTERFACE:
			return getInterface(); //4734
		case UmlPackage::BEHAVIORALFEATURE_ISABSTRACT:
			return getIsAbstract(); //4722
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //4710
		case UmlPackage::OPERATION_ISORDERED:
			return getIsOrdered(); //4735
		case UmlPackage::OPERATION_ISQUERY:
			return getIsQuery(); //4736
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //4714
		case UmlPackage::OPERATION_ISUNIQUE:
			return getIsUnique(); //4737
		case UmlPackage::OPERATION_LOWER:
			return getLower(); //4738
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //4715
		case UmlPackage::BEHAVIORALFEATURE_METHOD:
			return getMethod(); //4723
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //475
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //476
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //477
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //471
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //472
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //4713
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //4724
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //4725
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //4710
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //475
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //473
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //474
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //4712
		case UmlPackage::OPERATION_POSTCONDITION:
			return getPostcondition(); //4739
		case UmlPackage::OPERATION_PRECONDITION:
			return getPrecondition(); //4740
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //478
		case UmlPackage::BEHAVIORALFEATURE_RAISEDEXCEPTION:
			return getRaisedException(); //4726
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //4711
		case UmlPackage::OPERATION_REDEFINEDOPERATION:
			return getRedefinedOperation(); //4741
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4712
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //474
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //475
		case UmlPackage::OPERATION_TYPE:
			return getType(); //4742
		case UmlPackage::OPERATION_UPPER:
			return getUpper(); //4743
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //479
	}
	return boost::any();
}

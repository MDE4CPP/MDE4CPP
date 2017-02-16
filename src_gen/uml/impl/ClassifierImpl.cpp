#include "ClassifierImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierImpl::ClassifierImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_attribute == nullptr)
	{
		m_attribute = new std::vector<uml::Property * >();
	}
	if( m_collaborationUse == nullptr)
	{
		m_collaborationUse = new std::vector<uml::CollaborationUse * >();
	}
	if( m_feature == nullptr)
	{
		m_feature = new std::vector<uml::Feature * >();
	}
	if( m_general == nullptr)
	{
		m_general = new std::vector<uml::Classifier * >();
	}
	if( m_generalization == nullptr)
	{
		m_generalization = new std::vector<uml::Generalization * >();
	}
	if( m_inheritedMember == nullptr)
	{
		m_inheritedMember = new std::vector<uml::NamedElement * >();
	}
	if( m_ownedUseCase == nullptr)
	{
		m_ownedUseCase = new std::vector<uml::UseCase * >();
	}
	if( m_powertypeExtent == nullptr)
	{
		m_powertypeExtent = new std::vector<uml::GeneralizationSet * >();
	}
	if( m_redefinedClassifier == nullptr)
	{
		m_redefinedClassifier = new std::vector<uml::Classifier * >();
	}
	
	if( m_substitution == nullptr)
	{
		m_substitution = new std::vector<uml::Substitution * >();
	}
	if( m_useCase == nullptr)
	{
		m_useCase = new std::vector<uml::UseCase * >();
	}
}

ClassifierImpl::~ClassifierImpl()
{
	if(m_feature!=nullptr)
	{
		delete(m_feature);
	 	m_feature = nullptr;
	}
	if(m_attribute!=nullptr)
	{
		delete(m_attribute);
	 	m_attribute = nullptr;
	}
	if(m_collaborationUse!=nullptr)
	{
		for(auto c :*m_collaborationUse)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_general!=nullptr)
	{
		delete(m_general);
	 	m_general = nullptr;
	}
	if(m_generalization!=nullptr)
	{
		for(auto c :*m_generalization)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_powertypeExtent!=nullptr)
	{
		delete(m_powertypeExtent);
	 	m_powertypeExtent = nullptr;
	}
	if(m_inheritedMember!=nullptr)
	{
		delete(m_inheritedMember);
	 	m_inheritedMember = nullptr;
	}
	if(m_ownedUseCase!=nullptr)
	{
		for(auto c :*m_ownedUseCase)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_useCase!=nullptr)
	{
		delete(m_useCase);
	 	m_useCase = nullptr;
	}
	if(m_redefinedClassifier!=nullptr)
	{
		delete(m_redefinedClassifier);
	 	m_redefinedClassifier = nullptr;
	}
	if(m_substitution!=nullptr)
	{
		for(auto c :*m_substitution)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ClassifierImpl::ClassifierImpl(const ClassifierImpl & obj)
{
	//create copy of all Attributes
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Property * > *  _attribute = obj.getAttribute();
	this->getAttribute()->insert(this->getAttribute()->end(), _attribute->begin(), _attribute->end());
	delete(_attribute);

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Feature * > *  _feature = obj.getFeature();
	this->getFeature()->insert(this->getFeature()->end(), _feature->begin(), _feature->end());
	delete(_feature);

	std::vector<uml::Classifier * > *  _general = obj.getGeneral();
	this->getGeneral()->insert(this->getGeneral()->end(), _general->begin(), _general->end());

	std::vector<uml::PackageableElement * > *  _importedMember = obj.getImportedMember();
	this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

	std::vector<uml::NamedElement * > *  _inheritedMember = obj.getInheritedMember();
	this->getInheritedMember()->insert(this->getInheritedMember()->end(), _inheritedMember->begin(), _inheritedMember->end());

	std::vector<uml::NamedElement * > *  _member = obj.getMember();
	this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());
	delete(_member);

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	std::vector<uml::NamedElement * > *  _ownedMember = obj.getOwnedMember();
	this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());
	delete(_ownedMember);

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

	std::vector<uml::GeneralizationSet * > *  _powertypeExtent = obj.getPowertypeExtent();
	this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

	std::vector<uml::Classifier * > *  _redefinedClassifier = obj.getRedefinedClassifier();
	this->getRedefinedClassifier()->insert(this->getRedefinedClassifier()->end(), _redefinedClassifier->begin(), _redefinedClassifier->end());

	std::vector<uml::RedefinableElement * > *  _redefinedElement = obj.getRedefinedElement();
	this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());
	delete(_redefinedElement);

	std::vector<uml::Classifier * > *  _redefinitionContext = obj.getRedefinitionContext();
	this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());
	delete(_redefinitionContext);

	m_representation  = obj.getRepresentation();

	m_templateParameter  = obj.getTemplateParameter();

	std::vector<uml::UseCase * > *  _useCase = obj.getUseCase();
	this->getUseCase()->insert(this->getUseCase()->end(), _useCase->begin(), _useCase->end());


	//clone containt lists
	for(uml::CollaborationUse * 	_collaborationUse : *obj.getCollaborationUse())
	{
		this->getCollaborationUse()->push_back(dynamic_cast<uml::CollaborationUse * >(_collaborationUse->copy()));
	}
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::ElementImport * 	_elementImport : *obj.getElementImport())
	{
		this->getElementImport()->push_back(dynamic_cast<uml::ElementImport * >(_elementImport->copy()));
	}
	for(uml::Generalization * 	_generalization : *obj.getGeneralization())
	{
		this->getGeneralization()->push_back(dynamic_cast<uml::Generalization * >(_generalization->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Constraint * 	_ownedRule : *obj.getOwnedRule())
	{
		this->getOwnedRule()->push_back(dynamic_cast<uml::Constraint * >(_ownedRule->copy()));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = dynamic_cast<uml::TemplateSignature * >(obj.getOwnedTemplateSignature()->copy());
	}
	for(uml::UseCase * 	_ownedUseCase : *obj.getOwnedUseCase())
	{
		this->getOwnedUseCase()->push_back(dynamic_cast<uml::UseCase * >(_ownedUseCase->copy()));
	}
	for(uml::PackageImport * 	_packageImport : *obj.getPackageImport())
	{
		this->getPackageImport()->push_back(dynamic_cast<uml::PackageImport * >(_packageImport->copy()));
	}
	for(uml::Substitution * 	_substitution : *obj.getSubstitution())
	{
		this->getSubstitution()->push_back(dynamic_cast<uml::Substitution * >(_substitution->copy()));
	}
	for(uml::TemplateBinding * 	_templateBinding : *obj.getTemplateBinding())
	{
		this->getTemplateBinding()->push_back(dynamic_cast<uml::TemplateBinding * >(_templateBinding->copy()));
	}
}

ecore::EObject *  ClassifierImpl::copy() const
{
	return new ClassifierImpl(*this);
}

ecore::EClass* ClassifierImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClassifier();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ClassifierImpl::setIsAbstract (bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool ClassifierImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

void ClassifierImpl::setIsFinalSpecialization (bool _isFinalSpecialization)
{
	m_isFinalSpecialization = _isFinalSpecialization;
} 

bool ClassifierImpl::getIsFinalSpecialization() const 
{
	return m_isFinalSpecialization;
}

//*********************************
// Operations
//*********************************
std::vector<uml::Property * > *  ClassifierImpl::allAttributes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Feature * > *  ClassifierImpl::allFeatures() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Classifier * > *  ClassifierImpl::allParents() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::allRealizedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::StructuralFeature * > *  ClassifierImpl::allSlottableFeatures() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::allUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::directlyRealizedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::directlyUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Property * > *  ClassifierImpl::getAllAttributes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Operation * > *  ClassifierImpl::getAllOperations() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::getAllUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Classifier * > *  ClassifierImpl::getGenerals() 
{
	//generated from body annotation
	return parents();
}

std::vector<uml::NamedElement * > *  ClassifierImpl::getInheritedMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Operation *  ClassifierImpl::getOperation(std::string name,std::vector<std::string> *  parameterNames,std::vector<uml::Type * > *  parameterTypes) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Operation *  ClassifierImpl::getOperation(std::string name,std::vector<std::string> *  parameterNames,std::vector<uml::Type * > *  parameterTypes,bool ignoreCase) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Operation * > *  ClassifierImpl::getOperations() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Interface * > *  ClassifierImpl::getUsedInterfaces() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::hasVisibilityOf(uml::NamedElement *  n) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::NamedElement * > *  ClassifierImpl::inherit(std::vector<uml::NamedElement * > *  inhs) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::NamedElement * > *  ClassifierImpl::inheritableMembers(uml::Classifier *  c) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::isSubstitutableFor(uml::Classifier *  contract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maps_to_generalization_set(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maySpecializeType(uml::Classifier *  c) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::no_cycles_in_generalization(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::non_final_parents(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Classifier * > *  ClassifierImpl::parents() 
{
	//generated from body annotation
	auto returnList = new std::vector<uml::Classifier *>();

for(Generalization * gen : *m_generalization)
{
    returnList->push_back(gen->getGeneral());
}

return returnList;
}

bool ClassifierImpl::specialize_type(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************



std::vector<uml::CollaborationUse * > *  ClassifierImpl::getCollaborationUse() const
{
	
	return m_collaborationUse;
}





std::vector<uml::Classifier * > *  ClassifierImpl::getGeneral() const
{
	
	return m_general;
}


std::vector<uml::Generalization * > *  ClassifierImpl::getGeneralization() const
{
	
	return m_generalization;
}


std::vector<uml::NamedElement * > *  ClassifierImpl::getInheritedMember() const
{
	
	return m_inheritedMember;
}


std::vector<uml::UseCase * > *  ClassifierImpl::getOwnedUseCase() const
{
	
	return m_ownedUseCase;
}


std::vector<uml::GeneralizationSet * > *  ClassifierImpl::getPowertypeExtent() const
{
	
	return m_powertypeExtent;
}


std::vector<uml::Classifier * > *  ClassifierImpl::getRedefinedClassifier() const
{
	
	return m_redefinedClassifier;
}


uml::CollaborationUse *  ClassifierImpl::getRepresentation() const
{
	
	return m_representation;
}
void ClassifierImpl::setRepresentation(uml::CollaborationUse *  _representation)
{
	m_representation = _representation;
}

std::vector<uml::Substitution * > *  ClassifierImpl::getSubstitution() const
{
	
	return m_substitution;
}


std::vector<uml::UseCase * > *  ClassifierImpl::getUseCase() const
{
	
	return m_useCase;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Feature * > *  ClassifierImpl::getFeature() const
{
	std::vector<uml::Feature * > *  _feature =  new std::vector<uml::Feature * >() ;
	
	std::vector<uml::Feature * > *  attribute = (std::vector<uml::Feature * > * ) getAttribute();
	_feature->insert(_feature->end(), attribute->begin(), attribute->end());

	delete(attribute);

	return _feature;
}
std::vector<uml::Element * > *  ClassifierImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  collaborationUse = (std::vector<uml::Element * > * ) getCollaborationUse();
	_ownedElement->insert(_ownedElement->end(), collaborationUse->begin(), collaborationUse->end());

	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	std::vector<uml::Element * > *  generalization = (std::vector<uml::Element * > * ) getGeneralization();
	_ownedElement->insert(_ownedElement->end(), generalization->begin(), generalization->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  ownedMember = (std::vector<uml::Element * > * ) getOwnedMember();
	_ownedElement->insert(_ownedElement->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);
	_ownedElement->push_back(getOwnedTemplateSignature());
	std::vector<uml::Element * > *  packageImport = (std::vector<uml::Element * > * ) getPackageImport();
	_ownedElement->insert(_ownedElement->end(), packageImport->begin(), packageImport->end());

	std::vector<uml::Element * > *  substitution = (std::vector<uml::Element * > * ) getSubstitution();
	_ownedElement->insert(_ownedElement->end(), substitution->begin(), substitution->end());

	std::vector<uml::Element * > *  templateBinding = (std::vector<uml::Element * > * ) getTemplateBinding();
	_ownedElement->insert(_ownedElement->end(), templateBinding->begin(), templateBinding->end());


	return _ownedElement;
}
uml::Namespace *  ClassifierImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getPackage()!=nullptr)
	{
		_namespace = getPackage();
	}

	return _namespace;
}
uml::Element *  ClassifierImpl::getOwner() const
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
std::vector<uml::Property * > *  ClassifierImpl::getAttribute() const
{
	std::vector<uml::Property * > *  _attribute =  new std::vector<uml::Property * >() ;
	

	return _attribute;
}
std::vector<uml::NamedElement * > *  ClassifierImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  ownedUseCase = (std::vector<uml::NamedElement * > * ) getOwnedUseCase();
	_ownedMember->insert(_ownedMember->end(), ownedUseCase->begin(), ownedUseCase->end());


	return _ownedMember;
}
std::vector<uml::NamedElement * > *  ClassifierImpl::getMember() const
{
	std::vector<uml::NamedElement * > *  _member =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  feature = (std::vector<uml::NamedElement * > * ) getFeature();
	_member->insert(_member->end(), feature->begin(), feature->end());

	delete(feature);
	std::vector<uml::NamedElement * > *  importedMember = (std::vector<uml::NamedElement * > * ) getImportedMember();
	_member->insert(_member->end(), importedMember->begin(), importedMember->end());

	std::vector<uml::NamedElement * > *  inheritedMember = (std::vector<uml::NamedElement * > * ) getInheritedMember();
	_member->insert(_member->end(), inheritedMember->begin(), inheritedMember->end());

	std::vector<uml::NamedElement * > *  ownedMember = (std::vector<uml::NamedElement * > * ) getOwnedMember();
	_member->insert(_member->end(), ownedMember->begin(), ownedMember->end());

	delete(ownedMember);

	return _member;
}
std::vector<uml::RedefinableElement * > *  ClassifierImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedClassifier = (std::vector<uml::RedefinableElement * > * ) getRedefinedClassifier();
	_redefinedElement->insert(_redefinedElement->end(), redefinedClassifier->begin(), redefinedClassifier->end());


	return _redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClassifierImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //525
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //54
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //526
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //50
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //511
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //524
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //527
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //528
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //514
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //530
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //531
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //532
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //510
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //515
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //55
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //56
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //57
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //51
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //52
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //513
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //510
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //55
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //533
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //53
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //54
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //512
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //512
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //529
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //58
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //535
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //511
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //512
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //536
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //537
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //54
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //55
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //534
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //59
	}
	return boost::any();
}

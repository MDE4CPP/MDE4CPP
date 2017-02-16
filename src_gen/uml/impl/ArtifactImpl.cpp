#include "ArtifactImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ArtifactImpl::ArtifactImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_manifestation == nullptr)
	{
		m_manifestation = new std::vector<uml::Manifestation * >();
	}
	if( m_nestedArtifact == nullptr)
	{
		m_nestedArtifact = new std::vector<uml::Artifact * >();
	}
	if( m_ownedAttribute == nullptr)
	{
		m_ownedAttribute = new std::vector<uml::Property * >();
	}
	if( m_ownedOperation == nullptr)
	{
		m_ownedOperation = new std::vector<uml::Operation * >();
	}
}

ArtifactImpl::~ArtifactImpl()
{
	if(m_manifestation!=nullptr)
	{
		for(auto c :*m_manifestation)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_nestedArtifact!=nullptr)
	{
		for(auto c :*m_nestedArtifact)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedAttribute!=nullptr)
	{
		for(auto c :*m_ownedAttribute)
		{
			delete(c);
			c = 0;
		}
	}
	if(m_ownedOperation!=nullptr)
	{
		for(auto c :*m_ownedOperation)
		{
			delete(c);
			c = 0;
		}
	}
	
}

ArtifactImpl::ArtifactImpl(const ArtifactImpl & obj)
{
	//create copy of all Attributes
	m_fileName = obj.getFileName();
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
	for(uml::Manifestation * 	_manifestation : *obj.getManifestation())
	{
		this->getManifestation()->push_back(dynamic_cast<uml::Manifestation * >(_manifestation->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Artifact * 	_nestedArtifact : *obj.getNestedArtifact())
	{
		this->getNestedArtifact()->push_back(dynamic_cast<uml::Artifact * >(_nestedArtifact->copy()));
	}
	for(uml::Property * 	_ownedAttribute : *obj.getOwnedAttribute())
	{
		this->getOwnedAttribute()->push_back(dynamic_cast<uml::Property * >(_ownedAttribute->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::Operation * 	_ownedOperation : *obj.getOwnedOperation())
	{
		this->getOwnedOperation()->push_back(dynamic_cast<uml::Operation * >(_ownedOperation->copy()));
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

ecore::EObject *  ArtifactImpl::copy() const
{
	return new ArtifactImpl(*this);
}

ecore::EClass* ArtifactImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getArtifact();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ArtifactImpl::setFileName (std::string _fileName)
{
	m_fileName = _fileName;
} 

std::string ArtifactImpl::getFileName() const 
{
	return m_fileName;
}

//*********************************
// Operations
//*********************************
uml::Property *  ArtifactImpl::createOwnedAttribute(std::string name,uml::Type *  type,int lower,int upper) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Operation *  ArtifactImpl::createOwnedOperation(std::string name,std::vector<std::string> *  parameterNames,std::vector<uml::Type * > *  parameterTypes,uml::Type *  returnType) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Manifestation * > *  ArtifactImpl::getManifestation() const
{
	
	return m_manifestation;
}


std::vector<uml::Artifact * > *  ArtifactImpl::getNestedArtifact() const
{
	
	return m_nestedArtifact;
}


std::vector<uml::Property * > *  ArtifactImpl::getOwnedAttribute() const
{
	
	return m_ownedAttribute;
}


std::vector<uml::Operation * > *  ArtifactImpl::getOwnedOperation() const
{
	
	return m_ownedOperation;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ArtifactImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  collaborationUse = (std::vector<uml::Element * > * ) getCollaborationUse();
	_ownedElement->insert(_ownedElement->end(), collaborationUse->begin(), collaborationUse->end());

	std::vector<uml::Element * > *  elementImport = (std::vector<uml::Element * > * ) getElementImport();
	_ownedElement->insert(_ownedElement->end(), elementImport->begin(), elementImport->end());

	std::vector<uml::Element * > *  generalization = (std::vector<uml::Element * > * ) getGeneralization();
	_ownedElement->insert(_ownedElement->end(), generalization->begin(), generalization->end());

	std::vector<uml::Element * > *  manifestation = (std::vector<uml::Element * > * ) getManifestation();
	_ownedElement->insert(_ownedElement->end(), manifestation->begin(), manifestation->end());

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
std::vector<uml::RedefinableElement * > *  ArtifactImpl::getRedefinedElement() const
{
	std::vector<uml::RedefinableElement * > *  _redefinedElement =  new std::vector<uml::RedefinableElement * >() ;
	
	std::vector<uml::RedefinableElement * > *  redefinedClassifier = (std::vector<uml::RedefinableElement * > * ) getRedefinedClassifier();
	_redefinedElement->insert(_redefinedElement->end(), redefinedClassifier->begin(), redefinedClassifier->end());


	return _redefinedElement;
}
uml::Element *  ArtifactImpl::getOwner() const
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
std::vector<uml::Property * > *  ArtifactImpl::getAttribute() const
{
	std::vector<uml::Property * > *  _attribute =  new std::vector<uml::Property * >() ;
	
	std::vector<uml::Property * > *  ownedAttribute = (std::vector<uml::Property * > * ) getOwnedAttribute();
	_attribute->insert(_attribute->end(), ownedAttribute->begin(), ownedAttribute->end());


	return _attribute;
}
std::vector<uml::NamedElement * > *  ArtifactImpl::getMember() const
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
std::vector<uml::Feature * > *  ArtifactImpl::getFeature() const
{
	std::vector<uml::Feature * > *  _feature =  new std::vector<uml::Feature * >() ;
	
	std::vector<uml::Feature * > *  attribute = (std::vector<uml::Feature * > * ) getAttribute();
	_feature->insert(_feature->end(), attribute->begin(), attribute->end());

	delete(attribute);
	std::vector<uml::Feature * > *  ownedOperation = (std::vector<uml::Feature * > * ) getOwnedOperation();
	_feature->insert(_feature->end(), ownedOperation->begin(), ownedOperation->end());


	return _feature;
}
uml::Namespace *  ArtifactImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getPackage()!=nullptr)
	{
		_namespace = getPackage();
	}

	return _namespace;
}
std::vector<uml::NamedElement * > *  ArtifactImpl::getOwnedMember() const
{
	std::vector<uml::NamedElement * > *  _ownedMember =  new std::vector<uml::NamedElement * >() ;
	
	std::vector<uml::NamedElement * > *  nestedArtifact = (std::vector<uml::NamedElement * > * ) getNestedArtifact();
	_ownedMember->insert(_ownedMember->end(), nestedArtifact->begin(), nestedArtifact->end());

	std::vector<uml::NamedElement * > *  ownedAttribute = (std::vector<uml::NamedElement * > * ) getOwnedAttribute();
	_ownedMember->insert(_ownedMember->end(), ownedAttribute->begin(), ownedAttribute->end());

	std::vector<uml::NamedElement * > *  ownedOperation = (std::vector<uml::NamedElement * > * ) getOwnedOperation();
	_ownedMember->insert(_ownedMember->end(), ownedOperation->begin(), ownedOperation->end());

	std::vector<uml::NamedElement * > *  ownedRule = (std::vector<uml::NamedElement * > * ) getOwnedRule();
	_ownedMember->insert(_ownedMember->end(), ownedRule->begin(), ownedRule->end());

	std::vector<uml::NamedElement * > *  ownedUseCase = (std::vector<uml::NamedElement * > * ) getOwnedUseCase();
	_ownedMember->insert(_ownedMember->end(), ownedUseCase->begin(), ownedUseCase->end());


	return _ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ArtifactImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //3925
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //394
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //3926
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //390
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //3911
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //3924
		case UmlPackage::ARTIFACT_FILENAME:
			return getFileName(); //3938
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //3927
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //3928
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //3914
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //3930
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //3931
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //3932
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //3910
		case UmlPackage::ARTIFACT_MANIFESTATION:
			return getManifestation(); //3939
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //3915
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //395
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //396
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //397
		case UmlPackage::ARTIFACT_NESTEDARTIFACT:
			return getNestedArtifact(); //3940
		case UmlPackage::ARTIFACT_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //3941
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //391
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //392
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //3913
		case UmlPackage::ARTIFACT_OWNEDOPERATION:
			return getOwnedOperation(); //3942
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //3910
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //395
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //3933
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //393
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //394
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //3912
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //3912
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //3929
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //398
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //3935
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //3911
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //3912
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //3936
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //3937
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //394
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //395
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //3934
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //399
	}
	return boost::any();
}

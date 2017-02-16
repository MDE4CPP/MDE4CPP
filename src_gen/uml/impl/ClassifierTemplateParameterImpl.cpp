#include "ClassifierTemplateParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_constrainingClassifier == nullptr)
	{
		m_constrainingClassifier = new std::vector<uml::Classifier * >();
	}
}

ClassifierTemplateParameterImpl::~ClassifierTemplateParameterImpl()
{
	if(m_constrainingClassifier!=nullptr)
	{
		delete(m_constrainingClassifier);
	 	m_constrainingClassifier = nullptr;
	}
	
}

ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(const ClassifierTemplateParameterImpl & obj)
{
	//create copy of all Attributes
	m_allowSubstitutable = obj.getAllowSubstitutable();

	//copy references with now containment
	
	std::vector<uml::Classifier * > *  _constrainingClassifier = obj.getConstrainingClassifier();
	this->getConstrainingClassifier()->insert(this->getConstrainingClassifier()->end(), _constrainingClassifier->begin(), _constrainingClassifier->end());

	m_default  = obj.getDefault();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault = dynamic_cast<uml::ParameterableElement * >(obj.getOwnedDefault()->copy());
	}
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement = dynamic_cast<uml::ParameterableElement * >(obj.getOwnedParameteredElement()->copy());
	}
}

ecore::EObject *  ClassifierTemplateParameterImpl::copy() const
{
	return new ClassifierTemplateParameterImpl(*this);
}

ecore::EClass* ClassifierTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getClassifierTemplateParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ClassifierTemplateParameterImpl::setAllowSubstitutable (bool _allowSubstitutable)
{
	m_allowSubstitutable = _allowSubstitutable;
} 

bool ClassifierTemplateParameterImpl::getAllowSubstitutable() const 
{
	return m_allowSubstitutable;
}

//*********************************
// Operations
//*********************************
bool ClassifierTemplateParameterImpl::actual_is_classifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_args(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_parametered_element(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::has_constraining_classifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::matching_abstract(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierTemplateParameterImpl::parametered_element_no_features(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Classifier * > *  ClassifierTemplateParameterImpl::getConstrainingClassifier() const
{
	
	return m_constrainingClassifier;
}


//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  ClassifierTemplateParameterImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getOwnedDefault());
	_ownedElement->push_back(getOwnedParameteredElement());

	return _ownedElement;
}
uml::Element *  ClassifierTemplateParameterImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getSignature()!=nullptr)
	{
		_owner = getSignature();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ClassifierTemplateParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_ALLOWSUBSTITUTABLE:
			return getAllowSubstitutable(); //1049
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_CONSTRAININGCLASSIFIER:
			return getConstrainingClassifier(); //10410
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
			return getDefault(); //1044
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1040
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1041
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
			return getOwnedDefault(); //1045
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1042
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //1048
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1043
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
			return getParameteredElement(); //1046
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
			return getSignature(); //1047
	}
	return boost::any();
}

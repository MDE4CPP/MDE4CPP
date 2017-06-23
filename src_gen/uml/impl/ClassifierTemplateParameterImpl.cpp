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
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
		m_constrainingClassifier.reset(new Bag<uml::Classifier>());
	
	
}

ClassifierTemplateParameterImpl::~ClassifierTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(const ClassifierTemplateParameterImpl & obj)
{
	//create copy of all Attributes
	m_allowSubstitutable = obj.getAllowSubstitutable();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Classifier> >
	 _constrainingClassifier = obj.getConstrainingClassifier();
	m_constrainingClassifier.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getConstrainingClassifier().get())));// this->getConstrainingClassifier()->insert(this->getConstrainingClassifier()->end(), _constrainingClassifier->begin(), _constrainingClassifier->end());

	m_default  = obj.getDefault();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_parameteredElement  = obj.getParameteredElement();

	m_signature  = obj.getSignature();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	if(obj.getOwnedDefault()!=nullptr)
	{
		m_ownedDefault.reset(dynamic_cast<uml::ParameterableElement*>(obj.getOwnedDefault()->copy()));
	}
	if(obj.getOwnedParameteredElement()!=nullptr)
	{
		m_ownedParameteredElement.reset(dynamic_cast<uml::ParameterableElement*>(obj.getOwnedParameteredElement()->copy()));
	}
}

ecore::EObject *  ClassifierTemplateParameterImpl::copy() const
{
	return new ClassifierTemplateParameterImpl(*this);
}

std::shared_ptr<ecore::EClass> ClassifierTemplateParameterImpl::eStaticClass() const
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
bool
 ClassifierTemplateParameterImpl::actual_is_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierTemplateParameterImpl::constraining_classifiers_constrain_args(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierTemplateParameterImpl::constraining_classifiers_constrain_parametered_element(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierTemplateParameterImpl::has_constraining_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierTemplateParameterImpl::matching_abstract(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ClassifierTemplateParameterImpl::parametered_element_no_features(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Classifier> >
 ClassifierTemplateParameterImpl::getConstrainingClassifier() const
{

    return m_constrainingClassifier;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ClassifierTemplateParameterImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > ClassifierTemplateParameterImpl::getOwnedElement() const
{
	

	return m_ownedElement;
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

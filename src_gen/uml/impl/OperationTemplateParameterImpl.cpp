#include "OperationTemplateParameterImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationTemplateParameterImpl::OperationTemplateParameterImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

OperationTemplateParameterImpl::~OperationTemplateParameterImpl()
{
	
}

OperationTemplateParameterImpl::OperationTemplateParameterImpl(const OperationTemplateParameterImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
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

ecore::EObject *  OperationTemplateParameterImpl::copy() const
{
	return new OperationTemplateParameterImpl(*this);
}

ecore::EClass* OperationTemplateParameterImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOperationTemplateParameter();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool OperationTemplateParameterImpl::match_default_signature(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  OperationTemplateParameterImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getOwnedDefault());
	_ownedElement->push_back(getOwnedParameteredElement());

	return _ownedElement;
}
uml::Element *  OperationTemplateParameterImpl::getOwner() const
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
boost::any OperationTemplateParameterImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETER_DEFAULT:
			return getDefault(); //724
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //720
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //721
		case UmlPackage::TEMPLATEPARAMETER_OWNEDDEFAULT:
			return getOwnedDefault(); //725
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //722
		case UmlPackage::TEMPLATEPARAMETER_OWNEDPARAMETEREDELEMENT:
			return getOwnedParameteredElement(); //728
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //723
		case UmlPackage::TEMPLATEPARAMETER_PARAMETEREDELEMENT:
			return getParameteredElement(); //726
		case UmlPackage::TEMPLATEPARAMETER_SIGNATURE:
			return getSignature(); //727
	}
	return boost::any();
}

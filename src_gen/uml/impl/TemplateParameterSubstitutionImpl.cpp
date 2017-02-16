#include "TemplateParameterSubstitutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
	
	
}

TemplateParameterSubstitutionImpl::~TemplateParameterSubstitutionImpl()
{
	if(m_ownedActual!=nullptr)
	{
		if(m_ownedActual)
		{
			delete(m_ownedActual);
			m_ownedActual = nullptr;
		}
	}
	
}

TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(const TemplateParameterSubstitutionImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_actual  = obj.getActual();

	m_formal  = obj.getFormal();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_templateBinding  = obj.getTemplateBinding();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	if(obj.getOwnedActual()!=nullptr)
	{
		m_ownedActual = dynamic_cast<uml::ParameterableElement * >(obj.getOwnedActual()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  TemplateParameterSubstitutionImpl::copy() const
{
	return new TemplateParameterSubstitutionImpl(*this);
}

ecore::EClass* TemplateParameterSubstitutionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateParameterSubstitution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterSubstitutionImpl::must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::ParameterableElement *  TemplateParameterSubstitutionImpl::getActual() const
{
	//assert(m_actual);
	return m_actual;
}
void TemplateParameterSubstitutionImpl::setActual(uml::ParameterableElement *  _actual)
{
	m_actual = _actual;
}

uml::TemplateParameter *  TemplateParameterSubstitutionImpl::getFormal() const
{
	//assert(m_formal);
	return m_formal;
}
void TemplateParameterSubstitutionImpl::setFormal(uml::TemplateParameter *  _formal)
{
	m_formal = _formal;
}

uml::ParameterableElement *  TemplateParameterSubstitutionImpl::getOwnedActual() const
{
	
	return m_ownedActual;
}
void TemplateParameterSubstitutionImpl::setOwnedActual(uml::ParameterableElement *  _ownedActual)
{
	m_ownedActual = _ownedActual;
}

uml::TemplateBinding *  TemplateParameterSubstitutionImpl::getTemplateBinding() const
{
	//assert(m_templateBinding);
	return m_templateBinding;
}
void TemplateParameterSubstitutionImpl::setTemplateBinding(uml::TemplateBinding *  _templateBinding)
{
	m_templateBinding = _templateBinding;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TemplateParameterSubstitutionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getOwnedActual());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  TemplateParameterSubstitutionImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getTemplateBinding()!=nullptr)
	{
		_owner = getTemplateBinding();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateParameterSubstitutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_ACTUAL:
			return getActual(); //224
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //220
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_FORMAL:
			return getFormal(); //225
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_OWNEDACTUAL:
			return getOwnedActual(); //226
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //221
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //222
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //223
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_TEMPLATEBINDING:
			return getTemplateBinding(); //227
	}
	return boost::any();
}

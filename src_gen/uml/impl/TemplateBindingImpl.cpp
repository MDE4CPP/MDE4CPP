#include "TemplateBindingImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateBindingImpl::TemplateBindingImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_parameterSubstitution == nullptr)
	{
		m_parameterSubstitution = new std::vector<uml::TemplateParameterSubstitution * >();
	}
	
}

TemplateBindingImpl::~TemplateBindingImpl()
{
	if(m_parameterSubstitution!=nullptr)
	{
		for(auto c :*m_parameterSubstitution)
		{
			delete(c);
			c = 0;
		}
	}
	
}

TemplateBindingImpl::TemplateBindingImpl(const TemplateBindingImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_boundElement  = obj.getBoundElement();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	m_signature  = obj.getSignature();

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	std::vector<uml::Element * > *  _target = obj.getTarget();
	this->getTarget()->insert(this->getTarget()->end(), _target->begin(), _target->end());
	delete(_target);


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
	for(uml::TemplateParameterSubstitution * 	_parameterSubstitution : *obj.getParameterSubstitution())
	{
		this->getParameterSubstitution()->push_back(dynamic_cast<uml::TemplateParameterSubstitution * >(_parameterSubstitution->copy()));
	}
}

ecore::EObject *  TemplateBindingImpl::copy() const
{
	return new TemplateBindingImpl(*this);
}

ecore::EClass* TemplateBindingImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateBinding();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateBindingImpl::one_parameter_substitution(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateBindingImpl::parameter_substitution_formal(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::TemplateableElement *  TemplateBindingImpl::getBoundElement() const
{
	//assert(m_boundElement);
	return m_boundElement;
}
void TemplateBindingImpl::setBoundElement(uml::TemplateableElement *  _boundElement)
{
	m_boundElement = _boundElement;
}

std::vector<uml::TemplateParameterSubstitution * > *  TemplateBindingImpl::getParameterSubstitution() const
{
	
	return m_parameterSubstitution;
}


uml::TemplateSignature *  TemplateBindingImpl::getSignature() const
{
	//assert(m_signature);
	return m_signature;
}
void TemplateBindingImpl::setSignature(uml::TemplateSignature *  _signature)
{
	m_signature = _signature;
}

//*********************************
// Union Getter
//*********************************
std::vector<uml::Element * > *  TemplateBindingImpl::getRelatedElement() const
{
	std::vector<uml::Element * > *  _relatedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  source = (std::vector<uml::Element * > * ) getSource();
	_relatedElement->insert(_relatedElement->end(), source->begin(), source->end());

	delete(source);
	std::vector<uml::Element * > *  target = (std::vector<uml::Element * > * ) getTarget();
	_relatedElement->insert(_relatedElement->end(), target->begin(), target->end());

	delete(target);

	return _relatedElement;
}
std::vector<uml::Element * > *  TemplateBindingImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	std::vector<uml::Element * > *  parameterSubstitution = (std::vector<uml::Element * > * ) getParameterSubstitution();
	_ownedElement->insert(_ownedElement->end(), parameterSubstitution->begin(), parameterSubstitution->end());


	return _ownedElement;
}
std::vector<uml::Element * > *  TemplateBindingImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getBoundElement());

	return _source;
}
uml::Element *  TemplateBindingImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getBoundElement()!=nullptr)
	{
		_owner = getBoundElement();
	}

	return _owner;
}
std::vector<uml::Element * > *  TemplateBindingImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getSignature());

	return _target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateBindingImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEBINDING_BOUNDELEMENT:
			return getBoundElement(); //199
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //190
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //191
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //192
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //193
		case UmlPackage::TEMPLATEBINDING_PARAMETERSUBSTITUTION:
			return getParameterSubstitution(); //197
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //194
		case UmlPackage::TEMPLATEBINDING_SIGNATURE:
			return getSignature(); //198
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //195
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //196
	}
	return boost::any();
}

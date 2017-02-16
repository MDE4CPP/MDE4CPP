#include "GeneralizationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationImpl::GeneralizationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_generalizationSet == nullptr)
	{
		m_generalizationSet = new std::vector<uml::GeneralizationSet * >();
	}
	
}

GeneralizationImpl::~GeneralizationImpl()
{
	if(m_generalizationSet!=nullptr)
	{
		delete(m_generalizationSet);
	 	m_generalizationSet = nullptr;
	}
	
}

GeneralizationImpl::GeneralizationImpl(const GeneralizationImpl & obj)
{
	//create copy of all Attributes
	m_isSubstitutable = obj.getIsSubstitutable();

	//copy references with now containment
	
	m_general  = obj.getGeneral();

	std::vector<uml::GeneralizationSet * > *  _generalizationSet = obj.getGeneralizationSet();
	this->getGeneralizationSet()->insert(this->getGeneralizationSet()->end(), _generalizationSet->begin(), _generalizationSet->end());

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	std::vector<uml::Element * > *  _relatedElement = obj.getRelatedElement();
	this->getRelatedElement()->insert(this->getRelatedElement()->end(), _relatedElement->begin(), _relatedElement->end());
	delete(_relatedElement);

	std::vector<uml::Element * > *  _source = obj.getSource();
	this->getSource()->insert(this->getSource()->end(), _source->begin(), _source->end());
	delete(_source);

	m_specific  = obj.getSpecific();

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
}

ecore::EObject *  GeneralizationImpl::copy() const
{
	return new GeneralizationImpl(*this);
}

ecore::EClass* GeneralizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralization();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void GeneralizationImpl::setIsSubstitutable (bool _isSubstitutable)
{
	m_isSubstitutable = _isSubstitutable;
} 

bool GeneralizationImpl::getIsSubstitutable() const 
{
	return m_isSubstitutable;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
uml::Classifier *  GeneralizationImpl::getGeneral() const
{
	//assert(m_general);
	return m_general;
}
void GeneralizationImpl::setGeneral(uml::Classifier *  _general)
{
	m_general = _general;
}

std::vector<uml::GeneralizationSet * > *  GeneralizationImpl::getGeneralizationSet() const
{
	
	return m_generalizationSet;
}


uml::Classifier *  GeneralizationImpl::getSpecific() const
{
	//assert(m_specific);
	return m_specific;
}
void GeneralizationImpl::setSpecific(uml::Classifier *  _specific)
{
	m_specific = _specific;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  GeneralizationImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getSpecific()!=nullptr)
	{
		_owner = getSpecific();
	}

	return _owner;
}
std::vector<uml::Element * > *  GeneralizationImpl::getRelatedElement() const
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
std::vector<uml::Element * > *  GeneralizationImpl::getTarget() const
{
	std::vector<uml::Element * > *  _target =  new std::vector<uml::Element * >() ;
	
	_target->push_back(getGeneral());

	return _target;
}
std::vector<uml::Element * > *  GeneralizationImpl::getSource() const
{
	std::vector<uml::Element * > *  _source =  new std::vector<uml::Element * >() ;
	
	_source->push_back(getSpecific());

	return _source;
}
std::vector<uml::Element * > *  GeneralizationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralizationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //950
		case UmlPackage::GENERALIZATION_GENERAL:
			return getGeneral(); //957
		case UmlPackage::GENERALIZATION_GENERALIZATIONSET:
			return getGeneralizationSet(); //958
		case UmlPackage::GENERALIZATION_ISSUBSTITUTABLE:
			return getIsSubstitutable(); //959
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //951
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //952
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //953
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //954
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //955
		case UmlPackage::GENERALIZATION_SPECIFIC:
			return getSpecific(); //9510
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //956
	}
	return boost::any();
}

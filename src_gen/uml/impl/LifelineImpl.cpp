#include "LifelineImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LifelineImpl::LifelineImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_coveredBy == nullptr)
	{
		m_coveredBy = new std::vector<uml::InteractionFragment * >();
	}
	
	
	
	
}

LifelineImpl::~LifelineImpl()
{
	if(m_selector!=nullptr)
	{
		if(m_selector)
		{
			delete(m_selector);
			m_selector = nullptr;
		}
	}
	if(m_coveredBy!=nullptr)
	{
		delete(m_coveredBy);
	 	m_coveredBy = nullptr;
	}
	
}

LifelineImpl::LifelineImpl(const LifelineImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::InteractionFragment * > *  _coveredBy = obj.getCoveredBy();
	this->getCoveredBy()->insert(this->getCoveredBy()->end(), _coveredBy->begin(), _coveredBy->end());

	m_decomposedAs  = obj.getDecomposedAs();

	m_interaction  = obj.getInteraction();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_represents  = obj.getRepresents();


	//clone containt lists
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
	if(obj.getSelector()!=nullptr)
	{
		m_selector = dynamic_cast<uml::ValueSpecification * >(obj.getSelector()->copy());
	}
}

ecore::EObject *  LifelineImpl::copy() const
{
	return new LifelineImpl(*this);
}

ecore::EClass* LifelineImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLifeline();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool LifelineImpl::interaction_uses_share_lifeline(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::same_classifier(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_int_or_string(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LifelineImpl::selector_specified(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::InteractionFragment * > *  LifelineImpl::getCoveredBy() const
{
	
	return m_coveredBy;
}


uml::PartDecomposition *  LifelineImpl::getDecomposedAs() const
{
	
	return m_decomposedAs;
}
void LifelineImpl::setDecomposedAs(uml::PartDecomposition *  _decomposedAs)
{
	m_decomposedAs = _decomposedAs;
}

uml::Interaction *  LifelineImpl::getInteraction() const
{
	//assert(m_interaction);
	return m_interaction;
}
void LifelineImpl::setInteraction(uml::Interaction *  _interaction)
{
	m_interaction = _interaction;
}

uml::ConnectableElement *  LifelineImpl::getRepresents() const
{
	
	return m_represents;
}
void LifelineImpl::setRepresents(uml::ConnectableElement *  _represents)
{
	m_represents = _represents;
}

uml::ValueSpecification *  LifelineImpl::getSelector() const
{
	
	return m_selector;
}
void LifelineImpl::setSelector(uml::ValueSpecification *  _selector)
{
	m_selector = _selector;
}

//*********************************
// Union Getter
//*********************************
uml::Namespace *  LifelineImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getInteraction()!=nullptr)
	{
		_namespace = getInteraction();
	}

	return _namespace;
}
std::vector<uml::Element * > *  LifelineImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getSelector());

	return _ownedElement;
}
uml::Element *  LifelineImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LifelineImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2134
		case UmlPackage::LIFELINE_COVEREDBY:
			return getCoveredBy(); //21314
		case UmlPackage::LIFELINE_DECOMPOSEDAS:
			return getDecomposedAs(); //21310
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2130
		case UmlPackage::LIFELINE_INTERACTION:
			return getInteraction(); //21311
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2135
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2136
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2137
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2131
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2132
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2133
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2138
		case UmlPackage::LIFELINE_REPRESENTS:
			return getRepresents(); //21312
		case UmlPackage::LIFELINE_SELECTOR:
			return getSelector(); //21313
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2139
	}
	return boost::any();
}

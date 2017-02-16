#include "InteractionFragmentImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionFragmentImpl::InteractionFragmentImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_covered == nullptr)
	{
		m_covered = new std::vector<uml::Lifeline * >();
	}
	
	
	if( m_generalOrdering == nullptr)
	{
		m_generalOrdering = new std::vector<uml::GeneralOrdering * >();
	}
}

InteractionFragmentImpl::~InteractionFragmentImpl()
{
	if(m_covered!=nullptr)
	{
		delete(m_covered);
	 	m_covered = nullptr;
	}
	if(m_generalOrdering!=nullptr)
	{
		for(auto c :*m_generalOrdering)
		{
			delete(c);
			c = 0;
		}
	}
	
}

InteractionFragmentImpl::InteractionFragmentImpl(const InteractionFragmentImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	std::vector<uml::Lifeline * > *  _covered = obj.getCovered();
	this->getCovered()->insert(this->getCovered()->end(), _covered->begin(), _covered->end());

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();


	//clone containt lists
	for(ecore::EAnnotation * 	_eAnnotations : *obj.getEAnnotations())
	{
		this->getEAnnotations()->push_back(dynamic_cast<ecore::EAnnotation * >(_eAnnotations->copy()));
	}
	for(uml::GeneralOrdering * 	_generalOrdering : *obj.getGeneralOrdering())
	{
		this->getGeneralOrdering()->push_back(dynamic_cast<uml::GeneralOrdering * >(_generalOrdering->copy()));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  InteractionFragmentImpl::copy() const
{
	return new InteractionFragmentImpl(*this);
}

ecore::EClass* InteractionFragmentImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionFragment();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::vector<uml::Lifeline * > *  InteractionFragmentImpl::getCovered() const
{
	
	return m_covered;
}


uml::Interaction *  InteractionFragmentImpl::getEnclosingInteraction() const
{
	
	return m_enclosingInteraction;
}
void InteractionFragmentImpl::setEnclosingInteraction(uml::Interaction *  _enclosingInteraction)
{
	m_enclosingInteraction = _enclosingInteraction;
}

uml::InteractionOperand *  InteractionFragmentImpl::getEnclosingOperand() const
{
	
	return m_enclosingOperand;
}
void InteractionFragmentImpl::setEnclosingOperand(uml::InteractionOperand *  _enclosingOperand)
{
	m_enclosingOperand = _enclosingOperand;
}

std::vector<uml::GeneralOrdering * > *  InteractionFragmentImpl::getGeneralOrdering() const
{
	
	return m_generalOrdering;
}


//*********************************
// Union Getter
//*********************************
uml::Namespace *  InteractionFragmentImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	
	if(getEnclosingInteraction()!=nullptr)
	{
		_namespace = getEnclosingInteraction();
	}
	if(getEnclosingOperand()!=nullptr)
	{
		_namespace = getEnclosingOperand();
	}

	return _namespace;
}
std::vector<uml::Element * > *  InteractionFragmentImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Element *  InteractionFragmentImpl::getOwner() const
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
boost::any InteractionFragmentImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2124
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21210
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2120
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21212
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21211
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21213
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2125
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2126
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2127
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2121
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2122
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2123
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2128
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2129
	}
	return boost::any();
}

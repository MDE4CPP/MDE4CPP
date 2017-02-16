#include "PartDecompositionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PartDecompositionImpl::PartDecompositionImpl()
{
	//*********************************
	// Reference Members
	//*********************************

}

PartDecompositionImpl::~PartDecompositionImpl()
{
	
}

PartDecompositionImpl::PartDecompositionImpl(const PartDecompositionImpl & obj)
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

	m_refersTo  = obj.getRefersTo();

	m_returnValueRecipient  = obj.getReturnValueRecipient();


	//clone containt lists
	for(uml::Gate * 	_actualGate : *obj.getActualGate())
	{
		this->getActualGate()->push_back(dynamic_cast<uml::Gate * >(_actualGate->copy()));
	}
	for(uml::ValueSpecification * 	_argument : *obj.getArgument())
	{
		this->getArgument()->push_back(dynamic_cast<uml::ValueSpecification * >(_argument->copy()));
	}
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
	if(obj.getReturnValue()!=nullptr)
	{
		m_returnValue = dynamic_cast<uml::ValueSpecification * >(obj.getReturnValue()->copy());
	}
}

ecore::EObject *  PartDecompositionImpl::copy() const
{
	return new PartDecompositionImpl(*this);
}

ecore::EClass* PartDecompositionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPartDecomposition();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool PartDecompositionImpl::assume(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::commutativity_of_decomposition(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PartDecompositionImpl::parts_of_internal_structures(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
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
uml::Namespace *  PartDecompositionImpl::getNamespace() const
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
std::vector<uml::Element * > *  PartDecompositionImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  actualGate = (std::vector<uml::Element * > * ) getActualGate();
	_ownedElement->insert(_ownedElement->end(), actualGate->begin(), actualGate->end());

	std::vector<uml::Element * > *  argument = (std::vector<uml::Element * > * ) getArgument();
	_ownedElement->insert(_ownedElement->end(), argument->begin(), argument->end());

	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());

	_ownedElement->push_back(getReturnValue());

	return _ownedElement;
}
uml::Element *  PartDecompositionImpl::getOwner() const
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
boost::any PartDecompositionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ACTUALGATE:
			return getActualGate(); //21414
		case UmlPackage::INTERACTIONUSE_ARGUMENT:
			return getArgument(); //21415
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2144
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //21410
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2140
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //21412
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //21411
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //21413
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2145
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2146
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2147
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2141
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2142
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2143
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2148
		case UmlPackage::INTERACTIONUSE_REFERSTO:
			return getRefersTo(); //21416
		case UmlPackage::INTERACTIONUSE_RETURNVALUE:
			return getReturnValue(); //21417
		case UmlPackage::INTERACTIONUSE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient(); //21418
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2149
	}
	return boost::any();
}

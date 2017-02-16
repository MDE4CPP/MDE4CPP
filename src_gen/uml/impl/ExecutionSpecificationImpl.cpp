#include "ExecutionSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionSpecificationImpl::ExecutionSpecificationImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

ExecutionSpecificationImpl::~ExecutionSpecificationImpl()
{
	
}

ExecutionSpecificationImpl::ExecutionSpecificationImpl(const ExecutionSpecificationImpl & obj)
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

	m_finish  = obj.getFinish();

	m_namespace  = obj.getNamespace();

	std::vector<uml::Element * > *  _ownedElement = obj.getOwnedElement();
	this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());
	delete(_ownedElement);

	m_owner  = obj.getOwner();

	m_start  = obj.getStart();


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

ecore::EObject *  ExecutionSpecificationImpl::copy() const
{
	return new ExecutionSpecificationImpl(*this);
}

ecore::EClass* ExecutionSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExecutionSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool ExecutionSpecificationImpl::same_lifeline(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::OccurrenceSpecification *  ExecutionSpecificationImpl::getFinish() const
{
	//assert(m_finish);
	return m_finish;
}
void ExecutionSpecificationImpl::setFinish(uml::OccurrenceSpecification *  _finish)
{
	m_finish = _finish;
}

uml::OccurrenceSpecification *  ExecutionSpecificationImpl::getStart() const
{
	//assert(m_start);
	return m_start;
}
void ExecutionSpecificationImpl::setStart(uml::OccurrenceSpecification *  _start)
{
	m_start = _start;
}

//*********************************
// Union Getter
//*********************************
uml::Namespace *  ExecutionSpecificationImpl::getNamespace() const
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
uml::Element *  ExecutionSpecificationImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  ExecutionSpecificationImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	std::vector<uml::Element * > *  generalOrdering = (std::vector<uml::Element * > * ) getGeneralOrdering();
	_ownedElement->insert(_ownedElement->end(), generalOrdering->begin(), generalOrdering->end());

	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExecutionSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2264
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //22610
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2260
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //22612
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //22611
		case UmlPackage::EXECUTIONSPECIFICATION_FINISH:
			return getFinish(); //22614
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //22613
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2265
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2266
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2267
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2261
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2262
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2263
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2268
		case UmlPackage::EXECUTIONSPECIFICATION_START:
			return getStart(); //22615
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2269
	}
	return boost::any();
}

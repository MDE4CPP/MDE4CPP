#include "GeneralOrderingImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralOrderingImpl::GeneralOrderingImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	
}

GeneralOrderingImpl::~GeneralOrderingImpl()
{
	
}

GeneralOrderingImpl::GeneralOrderingImpl(const GeneralOrderingImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
	m_after  = obj.getAfter();

	m_before  = obj.getBefore();

	std::vector<uml::Dependency * > *  _clientDependency = obj.getClientDependency();
	this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = dynamic_cast<uml::StringExpression * >(obj.getNameExpression()->copy());
	}
	for(uml::Comment * 	_ownedComment : *obj.getOwnedComment())
	{
		this->getOwnedComment()->push_back(dynamic_cast<uml::Comment * >(_ownedComment->copy()));
	}
}

ecore::EObject *  GeneralOrderingImpl::copy() const
{
	return new GeneralOrderingImpl(*this);
}

ecore::EClass* GeneralOrderingImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralOrdering();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool GeneralOrderingImpl::irreflexive_transitive_closure(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
uml::OccurrenceSpecification *  GeneralOrderingImpl::getAfter() const
{
	//assert(m_after);
	return m_after;
}
void GeneralOrderingImpl::setAfter(uml::OccurrenceSpecification *  _after)
{
	m_after = _after;
}

uml::OccurrenceSpecification *  GeneralOrderingImpl::getBefore() const
{
	//assert(m_before);
	return m_before;
}
void GeneralOrderingImpl::setBefore(uml::OccurrenceSpecification *  _before)
{
	m_before = _before;
}

//*********************************
// Union Getter
//*********************************
uml::Element *  GeneralOrderingImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  GeneralOrderingImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralOrderingImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::GENERALORDERING_AFTER:
			return getAfter(); //22010
		case UmlPackage::GENERALORDERING_BEFORE:
			return getBefore(); //22011
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2204
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2200
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2205
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2206
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2207
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2201
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2202
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2203
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2208
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2209
	}
	return boost::any();
}

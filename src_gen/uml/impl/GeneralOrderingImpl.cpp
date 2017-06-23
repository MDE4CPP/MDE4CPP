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
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	
	
}

GeneralOrderingImpl::~GeneralOrderingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralOrdering "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
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

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  GeneralOrderingImpl::copy() const
{
	return new GeneralOrderingImpl(*this);
}

std::shared_ptr<ecore::EClass> GeneralOrderingImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralOrdering();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 GeneralOrderingImpl::irreflexive_transitive_closure(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::OccurrenceSpecification > GeneralOrderingImpl::getAfter() const
{
//assert(m_after);
    return m_after;
}
void GeneralOrderingImpl::setAfter(std::shared_ptr<uml::OccurrenceSpecification> _after)
{
    m_after = _after;
}

std::shared_ptr<uml::OccurrenceSpecification > GeneralOrderingImpl::getBefore() const
{
//assert(m_before);
    return m_before;
}
void GeneralOrderingImpl::setBefore(std::shared_ptr<uml::OccurrenceSpecification> _before)
{
    m_before = _before;
}

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > GeneralOrderingImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > GeneralOrderingImpl::getOwner() const
{
	

	return m_owner;
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

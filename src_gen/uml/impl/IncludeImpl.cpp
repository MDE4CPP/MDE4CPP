#include "uml/impl/IncludeImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

#include "uml/UseCase.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IncludeImpl::IncludeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

IncludeImpl::~IncludeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Include "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			IncludeImpl::IncludeImpl(std::weak_ptr<uml::UseCase > par_includingCase)
			:IncludeImpl()
			{
			    m_includingCase = par_includingCase;
			}





//Additional constructor for the containments back reference
			IncludeImpl::IncludeImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:IncludeImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			IncludeImpl::IncludeImpl(std::weak_ptr<uml::Element > par_owner)
			:IncludeImpl()
			{
			    m_owner = par_owner;
			}






IncludeImpl::IncludeImpl(const IncludeImpl & obj):IncludeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Include "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_includingCase  = obj.getIncludingCase();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getAddition()!=nullptr)
	{
		m_addition = std::dynamic_pointer_cast<uml::UseCase>(obj.getAddition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_addition" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  IncludeImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new IncludeImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> IncludeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInclude_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::UseCase > IncludeImpl::getAddition() const
{
//assert(m_addition);
    return m_addition;
}
void IncludeImpl::setAddition(std::shared_ptr<uml::UseCase> _addition)
{
    m_addition = _addition;
}

std::weak_ptr<uml::UseCase > IncludeImpl::getIncludingCase() const
{
//assert(m_includingCase);
    return m_includingCase;
}
void IncludeImpl::setIncludingCase(std::shared_ptr<uml::UseCase> _includingCase)
{
    m_includingCase = _includingCase;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > IncludeImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > IncludeImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > IncludeImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > IncludeImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > IncludeImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > IncludeImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> IncludeImpl::eContainer() const
{
	if(auto wp = m_includingCase.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any IncludeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INCLUDE_EREFERENCE_ADDITION:
			return getAddition(); //10113
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //1014
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //1010
		case UmlPackage::INCLUDE_EREFERENCE_INCLUDINGCASE:
			return getIncludingCase(); //10114
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //1015
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //1016
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //1017
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //1011
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //1012
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //1013
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //1018
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //1014
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //1015
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //1016
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //1019
	}
	return boost::any();
}

void IncludeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INCLUDE_EREFERENCE_ADDITION:
		{
			// BOOST CAST
			std::shared_ptr<uml::UseCase> _addition = boost::any_cast<std::shared_ptr<uml::UseCase>>(newValue);
			setAddition(_addition); //10113
			break;
		}
		case UmlPackage::INCLUDE_EREFERENCE_INCLUDINGCASE:
		{
			// BOOST CAST
			std::shared_ptr<uml::UseCase> _includingCase = boost::any_cast<std::shared_ptr<uml::UseCase>>(newValue);
			setIncludingCase(_includingCase); //10114
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //1015
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //1016
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //1019
			break;
		}
	}
}

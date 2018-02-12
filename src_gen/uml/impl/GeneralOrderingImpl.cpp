#include "uml/impl/GeneralOrderingImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/OccurrenceSpecification.hpp"

#include "uml/StringExpression.hpp"


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
	//References
	

	

	//Init references
	

	
}

GeneralOrderingImpl::~GeneralOrderingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralOrdering "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:GeneralOrderingImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			GeneralOrderingImpl::GeneralOrderingImpl(std::weak_ptr<uml::Element > par_owner)
			:GeneralOrderingImpl()
			{
			    m_owner = par_owner;
			}






GeneralOrderingImpl::GeneralOrderingImpl(const GeneralOrderingImpl & obj):GeneralOrderingImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralOrdering "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_after  = obj.getAfter();

	m_before  = obj.getBefore();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

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

std::shared_ptr<ecore::EObject>  GeneralOrderingImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new GeneralOrderingImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> GeneralOrderingImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralOrdering_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool GeneralOrderingImpl::irreflexive_transitive_closure(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::weak_ptr<uml::Element > GeneralOrderingImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> GeneralOrderingImpl::eContainer() const
{
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
boost::any GeneralOrderingImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::GENERALORDERING_EREFERENCE_AFTER:
			return getAfter(); //22010
		case UmlPackage::GENERALORDERING_EREFERENCE_BEFORE:
			return getBefore(); //22011
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //2204
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //2200
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //2205
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //2206
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //2207
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //2201
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //2202
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //2203
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //2208
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //2209
	}
	return boost::any();
}

void GeneralOrderingImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::GENERALORDERING_EREFERENCE_AFTER:
		{
			// BOOST CAST
			std::shared_ptr<uml::OccurrenceSpecification> _after = boost::any_cast<std::shared_ptr<uml::OccurrenceSpecification>>(newValue);
			setAfter(_after); //22010
			break;
		}
		case UmlPackage::GENERALORDERING_EREFERENCE_BEFORE:
		{
			// BOOST CAST
			std::shared_ptr<uml::OccurrenceSpecification> _before = boost::any_cast<std::shared_ptr<uml::OccurrenceSpecification>>(newValue);
			setBefore(_before); //22011
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //2205
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //2206
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //2209
			break;
		}
	}
}

#include "uml/impl/ExtendImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ExtensionPoint.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

#include "uml/UseCase.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExtendImpl::ExtendImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

		m_extensionLocation.reset(new Bag<uml::ExtensionPoint>());
	
	

	//Init references
	

	

	

	
	
}

ExtendImpl::~ExtendImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Extend "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ExtendImpl::ExtendImpl(std::weak_ptr<uml::UseCase > par_extension)
			:ExtendImpl()
			{
			    m_extension = par_extension;
			}





//Additional constructor for the containments back reference
			ExtendImpl::ExtendImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ExtendImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ExtendImpl::ExtendImpl(std::weak_ptr<uml::Element > par_owner)
			:ExtendImpl()
			{
			    m_owner = par_owner;
			}






ExtendImpl::ExtendImpl(const ExtendImpl & obj):ExtendImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Extend "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_extension  = obj.getExtension();

	std::shared_ptr< Bag<uml::ExtensionPoint> > _extensionLocation = obj.getExtensionLocation();
	m_extensionLocation.reset(new Bag<uml::ExtensionPoint>(*(obj.getExtensionLocation().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getCondition()!=nullptr)
	{
		m_condition = std::dynamic_pointer_cast<uml::Constraint>(obj.getCondition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_condition" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getExtendedCase()!=nullptr)
	{
		m_extendedCase = std::dynamic_pointer_cast<uml::UseCase>(obj.getExtendedCase()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extendedCase" << std::endl;
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

std::shared_ptr<ecore::EObject>  ExtendImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExtendImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExtendImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExtend();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExtendImpl::extension_points(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Constraint > ExtendImpl::getCondition() const
{

    return m_condition;
}
void ExtendImpl::setCondition(std::shared_ptr<uml::Constraint> _condition)
{
    m_condition = _condition;
}

std::shared_ptr<uml::UseCase > ExtendImpl::getExtendedCase() const
{
//assert(m_extendedCase);
    return m_extendedCase;
}
void ExtendImpl::setExtendedCase(std::shared_ptr<uml::UseCase> _extendedCase)
{
    m_extendedCase = _extendedCase;
}

std::weak_ptr<uml::UseCase > ExtendImpl::getExtension() const
{
//assert(m_extension);
    return m_extension;
}
void ExtendImpl::setExtension(std::shared_ptr<uml::UseCase> _extension)
{
    m_extension = _extension;
}

std::shared_ptr< Bag<uml::ExtensionPoint> > ExtendImpl::getExtensionLocation() const
{
//assert(m_extensionLocation);
    return m_extensionLocation;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExtendImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ExtendImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExtendImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ExtendImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ExtendImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ExtendImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> ExtendImpl::eContainer() const
{
	if(auto wp = m_extension.lock())
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
boost::any ExtendImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //994
		case UmlPackage::EXTEND_CONDITION:
			return getCondition(); //9913
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //990
		case UmlPackage::EXTEND_EXTENDEDCASE:
			return getExtendedCase(); //9914
		case UmlPackage::EXTEND_EXTENSION:
			return getExtension(); //9916
		case UmlPackage::EXTEND_EXTENSIONLOCATION:
			return getExtensionLocation(); //9915
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //995
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //996
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //997
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //991
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //992
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //993
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //998
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //994
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //995
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //996
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //999
	}
	return boost::any();
}

void ExtendImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::EXTEND_CONDITION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Constraint> _condition = boost::any_cast<std::shared_ptr<uml::Constraint>>(newValue);
			setCondition(_condition); //9913
			break;
		}
		case UmlPackage::EXTEND_EXTENDEDCASE:
		{
			// BOOST CAST
			std::shared_ptr<uml::UseCase> _extendedCase = boost::any_cast<std::shared_ptr<uml::UseCase>>(newValue);
			setExtendedCase(_extendedCase); //9914
			break;
		}
		case UmlPackage::EXTEND_EXTENSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::UseCase> _extension = boost::any_cast<std::shared_ptr<uml::UseCase>>(newValue);
			setExtension(_extension); //9916
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //995
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //996
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //999
			break;
		}
	}
}

#include "uml/impl/NamedElementImpl.hpp"
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

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Usage.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamedElementImpl::NamedElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_clientDependency.reset(new Bag<uml::Dependency>());
	
	

	

	

	//Init references
	
	

	

	
}

NamedElementImpl::~NamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			NamedElementImpl::NamedElementImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:NamedElementImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			NamedElementImpl::NamedElementImpl(std::weak_ptr<uml::Element > par_owner)
			:NamedElementImpl()
			{
			    m_owner = par_owner;
			}






NamedElementImpl::NamedElementImpl(const NamedElementImpl & obj):NamedElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
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

std::shared_ptr<ecore::EObject>  NamedElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new NamedElementImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> NamedElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getNamedElement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void NamedElementImpl::setName(std::string _name)
{
	m_name = _name;
} 

std::string NamedElementImpl::getName() const 
{
	return m_name;
}





void NamedElementImpl::setVisibility(VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind NamedElementImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Namespace> > NamedElementImpl::allNamespaces()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Namespace> > allNS(new Bag<uml::Namespace>());
    if (getNamespace().lock() == nullptr)
    {
        return allNS;
    }
    else
    {
    	std::shared_ptr<Bag<uml::Namespace> > currentNSList = getNamespace().lock()->allNamespaces();
        allNS->insert(allNS->end(), currentNSList->begin(), currentNSList->end());
        currentNSList = nullptr;

        std::shared_ptr<uml::Namespace> currentNS = getNamespace().lock();
        if (currentNS != nullptr)
        {
            allNS->push_back(currentNS);
        }
        return allNS;
    }
	//end of body
}

std::shared_ptr<Bag<uml::Package> > NamedElementImpl::allOwningPackages() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Dependency> NamedElementImpl::createDependency(std::shared_ptr<uml::NamedElement>  supplier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Usage> NamedElementImpl::createUsage(std::shared_ptr<uml::NamedElement>  supplier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Dependency> > NamedElementImpl::getClientDependencies() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::getLabel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::getLabel(bool localize) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::string NamedElementImpl::getQualifiedName()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<uml::Namespace> >  allNS = allNamespaces();

    if(!this->getName().empty() && std::none_of(allNS->cbegin(), allNS->cend(), [](std::shared_ptr<uml::Namespace> ns){ return ns->getName().empty(); }))
    {
        std::string ret;
        for(std::shared_ptr<uml::Namespace> ns : *allNS )
        {
            ret = ns->getName() + separator() + ret;
        }
        ret += getName();
        return ret;
    }
    else
    {
        return std::string();
    }
	//end of body
}

bool NamedElementImpl::has_no_qualified_name(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::has_qualified_name(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::isDistinguishableFrom(std::shared_ptr<uml::NamedElement>  n,std::shared_ptr<uml::Namespace>  ns) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::separator()  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "::";
	//end of body
}

bool NamedElementImpl::visibility_needs_ownership(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Dependency> > NamedElementImpl::getClientDependency() const
{

    return m_clientDependency;
}


std::shared_ptr<uml::StringExpression > NamedElementImpl::getNameExpression() const
{

    return m_nameExpression;
}
void NamedElementImpl::setNameExpression(std::shared_ptr<uml::StringExpression> _nameExpression)
{
    m_nameExpression = _nameExpression;
}




//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > NamedElementImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > NamedElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > NamedElementImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> NamedElementImpl::eContainer() const
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
boost::any NamedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //74
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //70
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //75
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //76
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //77
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //71
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //72
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //73
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //78
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //79
	}
	return boost::any();
}

void NamedElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //75
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //76
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //79
			break;
		}
	}
}

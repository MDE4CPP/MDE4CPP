#include "NamedElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamedElementImpl::NamedElementImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_clientDependency == nullptr)
	{
		m_clientDependency = new std::vector<uml::Dependency * >();
	}
	
	
}

NamedElementImpl::~NamedElementImpl()
{
	if(m_clientDependency!=nullptr)
	{
		delete(m_clientDependency);
	 	m_clientDependency = nullptr;
	}
	if(m_nameExpression!=nullptr)
	{
		if(m_nameExpression)
		{
			delete(m_nameExpression);
			m_nameExpression = nullptr;
		}
	}
	
}

NamedElementImpl::NamedElementImpl(const NamedElementImpl & obj)
{
	//create copy of all Attributes
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
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

ecore::EObject *  NamedElementImpl::copy() const
{
	return new NamedElementImpl(*this);
}

ecore::EClass* NamedElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getNamedElement();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void NamedElementImpl::setName (std::string _name)
{
	m_name = _name;
} 

std::string NamedElementImpl::getName() const 
{
	return m_name;
}



std::string NamedElementImpl::getQualifiedName() const 
{
	return m_qualifiedName;
}

void NamedElementImpl::setVisibility (VisibilityKind _visibility)
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
std::vector<uml::Namespace * > *  NamedElementImpl::allNamespaces() 
{
	//generated from body annotation
	std::vector<uml::Namespace * > * allNS = new std::vector<uml::Namespace * >();

    if (getNamespace()==nullptr)
    {
        return allNS;
    }
    else
    {
        std::vector<uml::Namespace * > * currentNSList = getNamespace()->allNamespaces();
        allNS->insert(allNS->end(), currentNSList->begin(), currentNSList->end());
        delete(currentNSList);
        currentNSList = nullptr;

        uml::Namespace * currentNS = getNamespace();
        if (currentNS != nullptr)
        {
            allNS->insert(allNS->begin(), currentNS);
            delete(currentNS);
        }
        return allNS;
    }
}

std::vector<uml::Package * > *  NamedElementImpl::allOwningPackages() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Dependency *  NamedElementImpl::createDependency(uml::NamedElement *  supplier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

uml::Usage *  NamedElementImpl::createUsage(uml::NamedElement *  supplier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::vector<uml::Dependency * > *  NamedElementImpl::getClientDependencies() 
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



std::string NamedElementImpl::getQualifiedName() 
{
	//generated from body annotation
	auto allNS = allNamespaces();

    if(!this->getName().empty() && std::none_of(allNS->cbegin(), allNS->cend(), [](Namespace * ns){ return ns->getName().empty(); }))
    {
        std::string ret;
        for(Namespace * ns : *allNS )
        {
            ret = ns->getName()+separator() +ret;
        }
        ret +=getName();
	return ret;
    }
    else
    {
        return std::string();
    }
}

bool NamedElementImpl::has_no_qualified_name(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::has_qualified_name(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::isDistinguishableFrom(uml::NamedElement *  n,uml::Namespace *  ns) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::separator() 
{
	//generated from body annotation
	return "::";
}

bool NamedElementImpl::visibility_needs_ownership(boost::any diagnostics,std::map <   boost::any, boost::any > * context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::vector<uml::Dependency * > *  NamedElementImpl::getClientDependency() const
{
	
	return m_clientDependency;
}


uml::StringExpression *  NamedElementImpl::getNameExpression() const
{
	
	return m_nameExpression;
}
void NamedElementImpl::setNameExpression(uml::StringExpression *  _nameExpression)
{
	m_nameExpression = _nameExpression;
}




//*********************************
// Union Getter
//*********************************
uml::Element *  NamedElementImpl::getOwner() const
{
	uml::Element *  _owner =   nullptr ;
	
	if(getNamespace()!=nullptr)
	{
		_owner = getNamespace();
	}

	return _owner;
}
std::vector<uml::Element * > *  NamedElementImpl::getOwnedElement() const
{
	std::vector<uml::Element * > *  _ownedElement =  new std::vector<uml::Element * >() ;
	
	_ownedElement->push_back(getNameExpression());
	std::vector<uml::Element * > *  ownedComment = (std::vector<uml::Element * > * ) getOwnedComment();
	_ownedElement->insert(_ownedElement->end(), ownedComment->begin(), ownedComment->end());


	return _ownedElement;
}
uml::Namespace *  NamedElementImpl::getNamespace() const
{
	uml::Namespace *  _namespace =   nullptr ;
	

	return _namespace;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any NamedElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
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

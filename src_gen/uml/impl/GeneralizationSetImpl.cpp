#include "uml/impl/GeneralizationSetImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Generalization.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationSetImpl::GeneralizationSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_generalization.reset(new Bag<uml::Generalization>());
	
	

	

	//Init references
	
	

	
}

GeneralizationSetImpl::~GeneralizationSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralizationSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:GeneralizationSetImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Element > par_owner)
			:GeneralizationSetImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:GeneralizationSetImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:GeneralizationSetImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






GeneralizationSetImpl::GeneralizationSetImpl(const GeneralizationSetImpl & obj):GeneralizationSetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralizationSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isCovering = obj.getIsCovering();
	m_isDisjoint = obj.getIsDisjoint();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Generalization> > _generalization = obj.getGeneralization();
	m_generalization.reset(new Bag<uml::Generalization>(*(obj.getGeneralization().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_powertype  = obj.getPowertype();

	m_templateParameter  = obj.getTemplateParameter();


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

std::shared_ptr<ecore::EObject>  GeneralizationSetImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new GeneralizationSetImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> GeneralizationSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralizationSet();
}

//*********************************
// Attribute Setter Getter
//*********************************
void GeneralizationSetImpl::setIsCovering(bool _isCovering)
{
	m_isCovering = _isCovering;
} 

bool GeneralizationSetImpl::getIsCovering() const 
{
	return m_isCovering;
}

void GeneralizationSetImpl::setIsDisjoint(bool _isDisjoint)
{
	m_isDisjoint = _isDisjoint;
} 

bool GeneralizationSetImpl::getIsDisjoint() const 
{
	return m_isDisjoint;
}

//*********************************
// Operations
//*********************************
bool GeneralizationSetImpl::generalization_same_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool GeneralizationSetImpl::maps_to_generalization_set(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Generalization> > GeneralizationSetImpl::getGeneralization() const
{

    return m_generalization;
}


std::shared_ptr<uml::Classifier > GeneralizationSetImpl::getPowertype() const
{

    return m_powertype;
}
void GeneralizationSetImpl::setPowertype(std::shared_ptr<uml::Classifier> _powertype)
{
    m_powertype = _powertype;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > GeneralizationSetImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > GeneralizationSetImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > GeneralizationSetImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> GeneralizationSetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralizationSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //964
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //960
		case UmlPackage::GENERALIZATIONSET_GENERALIZATION:
			return getGeneralization(); //9616
		case UmlPackage::GENERALIZATIONSET_ISCOVERING:
			return getIsCovering(); //9613
		case UmlPackage::GENERALIZATIONSET_ISDISJOINT:
			return getIsDisjoint(); //9614
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //965
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //966
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //967
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //961
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //962
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //963
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //9612
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //964
		case UmlPackage::GENERALIZATIONSET_POWERTYPE:
			return getPowertype(); //9615
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //968
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //965
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //969
	}
	return boost::any();
}

void GeneralizationSetImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATIONSET_ISCOVERING:
		{
			// BOOST CAST
			bool _isCovering = boost::any_cast<bool>(newValue);
			setIsCovering(_isCovering); //9613
			break;
		}
		case UmlPackage::GENERALIZATIONSET_ISDISJOINT:
		{
			// BOOST CAST
			bool _isDisjoint = boost::any_cast<bool>(newValue);
			setIsDisjoint(_isDisjoint); //9614
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //965
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //966
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //9612
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //964
			break;
		}
		case UmlPackage::GENERALIZATIONSET_POWERTYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _powertype = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setPowertype(_powertype); //9615
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //965
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //969
			break;
		}
	}
}

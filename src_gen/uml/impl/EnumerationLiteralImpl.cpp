#include "uml/impl/EnumerationLiteralImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Deployment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Enumeration.hpp"

#include "uml/InstanceSpecification.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
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

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration > par_enumeration)
			:EnumerationLiteralImpl()
			{
			    m_enumeration = par_enumeration;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:EnumerationLiteralImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Element > par_owner)
			:EnumerationLiteralImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:EnumerationLiteralImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:EnumerationLiteralImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj):EnumerationLiteralImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Classifier> > _classifier = obj.getClassifier();
	m_classifier.reset(new Bag<uml::Classifier>(*(obj.getClassifier().get())));

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::PackageableElement> > _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	m_enumeration  = obj.getEnumeration();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployment" << std::endl;
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
	std::shared_ptr<Bag<uml::Slot>> _slotList = obj.getSlot();
	for(std::shared_ptr<uml::Slot> _slot : *_slotList)
	{
		this->getSlot()->add(std::shared_ptr<uml::Slot>(std::dynamic_pointer_cast<uml::Slot>(_slot->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_slot" << std::endl;
	#endif
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specification" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EnumerationLiteralImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EnumerationLiteralImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> EnumerationLiteralImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getEnumerationLiteral();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<Bag<uml::Classifier> > EnumerationLiteralImpl::getClassifiers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Enumeration > EnumerationLiteralImpl::getEnumeration() const
{
//assert(m_enumeration);
    return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(std::shared_ptr<uml::Enumeration> _enumeration)
{
    m_enumeration = _enumeration;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > EnumerationLiteralImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > EnumerationLiteralImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > EnumerationLiteralImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> EnumerationLiteralImpl::eContainer() const
{
	if(auto wp = m_enumeration.lock())
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
boost::any EnumerationLiteralImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7815
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //784
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7810
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7811
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //780
		case UmlPackage::ENUMERATIONLITERAL_ENUMERATION:
			return getEnumeration(); //7818
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //785
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //786
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //787
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //781
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //782
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //783
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //7812
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //784
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //788
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7816
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7817
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //785
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //789
	}
	return boost::any();
}

void EnumerationLiteralImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ENUMERATIONLITERAL_ENUMERATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::Enumeration> _enumeration = boost::any_cast<std::shared_ptr<uml::Enumeration>>(newValue);
			setEnumeration(_enumeration); //7818
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //785
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //786
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //7812
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //784
			break;
		}
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //7817
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //785
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //789
			break;
		}
	}
}

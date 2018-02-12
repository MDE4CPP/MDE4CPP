#include "uml/impl/InstanceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/DeployedArtifact.hpp"

#include "uml/Deployment.hpp"

#include "uml/DeploymentTarget.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

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
InstanceSpecificationImpl::InstanceSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_classifier.reset(new Bag<uml::Classifier>());
	
	

		/*Subset*/
		m_slot.reset(new Subset<uml::Slot, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_slot - Subset<uml::Slot, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	
	

		/*Subset*/
		m_slot->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

InstanceSpecificationImpl::~InstanceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InstanceSpecificationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:InstanceSpecificationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InstanceSpecificationImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InstanceSpecificationImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






InstanceSpecificationImpl::InstanceSpecificationImpl(const InstanceSpecificationImpl & obj):InstanceSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

		/*Subset*/
		m_slot->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

std::shared_ptr<ecore::EObject>  InstanceSpecificationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new InstanceSpecificationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> InstanceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInstanceSpecification_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InstanceSpecificationImpl::defining_feature(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_artifact(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::structural_feature(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Classifier> > InstanceSpecificationImpl::getClassifier() const
{

    return m_classifier;
}


std::shared_ptr<Subset<uml::Slot, uml::Element > > InstanceSpecificationImpl::getSlot() const
{

    return m_slot;
}


std::shared_ptr<uml::ValueSpecification > InstanceSpecificationImpl::getSpecification() const
{

    return m_specification;
}
void InstanceSpecificationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InstanceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > InstanceSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InstanceSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> InstanceSpecificationImpl::eContainer() const
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
boost::any InstanceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_CLASSIFIER:
			return getClassifier(); //7915
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //794
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYEDELEMENT:
			return getDeployedElement(); //7910
		case UmlPackage::DEPLOYMENTTARGET_EREFERENCE_DEPLOYMENT:
			return getDeployment(); //7911
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //790
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //795
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //796
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //797
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //791
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //792
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //793
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //7912
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //794
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //798
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SLOT:
			return getSlot(); //7916
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION:
			return getSpecification(); //7917
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //795
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //799
	}
	return boost::any();
}

void InstanceSpecificationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //795
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //796
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //7912
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //794
			break;
		}
		case UmlPackage::INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setSpecification(_specification); //7917
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //795
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //799
			break;
		}
	}
}

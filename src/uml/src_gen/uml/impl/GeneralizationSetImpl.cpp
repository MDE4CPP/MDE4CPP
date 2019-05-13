#include "uml/impl/GeneralizationSetImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Generalization.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
				m_owner = par_namespace;
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
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:GeneralizationSetImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
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
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Generalization>> _generalization = obj.getGeneralization();
	m_generalization.reset(new Bag<uml::Generalization>(*(obj.getGeneralization().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_powertype  = obj.getPowertype();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

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
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl(*this));
	element->setThisGeneralizationSetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> GeneralizationSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralizationSet_EClass();
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
bool GeneralizationSetImpl::generalization_same_classifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool GeneralizationSetImpl::maps_to_generalization_set(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Generalization>> GeneralizationSetImpl::getGeneralization() const
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
std::shared_ptr<Union<uml::Element>> GeneralizationSetImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > GeneralizationSetImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<GeneralizationSet> GeneralizationSetImpl::getThisGeneralizationSetPtr() const
{
	return m_thisGeneralizationSetPtr.lock();
}
void GeneralizationSetImpl::setThisGeneralizationSetPtr(std::weak_ptr<GeneralizationSet> thisGeneralizationSetPtr)
{
	m_thisGeneralizationSetPtr = thisGeneralizationSetPtr;
	setThisPackageableElementPtr(thisGeneralizationSetPtr);
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
Any GeneralizationSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_GENERALIZATION:
			return eAny(getGeneralization()); //11015
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISCOVERING:
			return eAny(getIsCovering()); //11012
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISDISJOINT:
			return eAny(getIsDisjoint()); //11013
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_POWERTYPE:
			return eAny(getPowertype()); //11014
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool GeneralizationSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_GENERALIZATION:
			return getGeneralization() != nullptr; //11015
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISCOVERING:
			return getIsCovering() != false; //11012
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISDISJOINT:
			return getIsDisjoint() != false; //11013
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_POWERTYPE:
			return getPowertype() != nullptr; //11014
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool GeneralizationSetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISCOVERING:
		{
			// BOOST CAST
			bool _isCovering = newValue->get<bool>();
			setIsCovering(_isCovering); //11012
			return true;
		}
		case UmlPackage::GENERALIZATIONSET_EATTRIBUTE_ISDISJOINT:
		{
			// BOOST CAST
			bool _isDisjoint = newValue->get<bool>();
			setIsDisjoint(_isDisjoint); //11013
			return true;
		}
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_POWERTYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _powertype = newValue->get<std::shared_ptr<uml::Classifier>>();
			setPowertype(_powertype); //11014
			return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void GeneralizationSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void GeneralizationSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCovering");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCovering(value);
		}

		iter = attr_list.find("isDisjoint");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDisjoint(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("generalization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertype");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertype")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void GeneralizationSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void GeneralizationSetImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATIONSET_EREFERENCE_GENERALIZATION:
		{
			std::shared_ptr<Bag<uml::Generalization>> _generalization = getGeneralization();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Generalization> _r = std::dynamic_pointer_cast<uml::Generalization>(ref);
				if (_r != nullptr)
				{
					_generalization->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::GENERALIZATIONSET_EREFERENCE_POWERTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _powertype = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setPowertype(_powertype);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void GeneralizationSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void GeneralizationSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getGeneralizationSet_EAttribute_isCovering()) )
		{
			saveHandler->addAttribute("isCovering", this->getIsCovering());
		}

		if ( this->eIsSet(package->getGeneralizationSet_EAttribute_isDisjoint()) )
		{
			saveHandler->addAttribute("isDisjoint", this->getIsDisjoint());
		}

		// Add references
		std::shared_ptr<Bag<uml::Generalization>> generalization_list = this->getGeneralization();
		for (std::shared_ptr<uml::Generalization > object : *generalization_list)
		{ 
			saveHandler->addReferences("generalization", object);
		}
		saveHandler->addReference("powertype", this->getPowertype());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


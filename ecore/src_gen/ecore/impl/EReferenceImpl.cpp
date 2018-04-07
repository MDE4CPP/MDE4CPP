#include "ecore/impl/EReferenceImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EAttribute.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EReferenceImpl::EReferenceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eKeys.reset(new Bag<ecore::EAttribute>());
	
	

	

	

	//Init references
	
	

	

	
}

EReferenceImpl::~EReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EReferenceImpl::EReferenceImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EReferenceImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EReferenceImpl::EReferenceImpl(const EReferenceImpl & obj):EReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_changeable = obj.isChangeable();
	m_container = obj.isContainer();
	m_containerClass = obj.getContainerClass();
	m_containment = obj.isContainment();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_resolveProxies = obj.isResolveProxies();
	m_transient = obj.isTransient();
	m_unique = obj.isUnique();
	m_unsettable = obj.isUnsettable();
	m_upperBound = obj.getUpperBound();
	m_volatile = obj.isVolatile();

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

	std::shared_ptr<Bag<ecore::EAttribute>> _eKeys = obj.getEKeys();
	m_eKeys.reset(new Bag<ecore::EAttribute>(*(obj.getEKeys().get())));

	m_eOpposite  = obj.getEOpposite();

	m_eReferenceType  = obj.getEReferenceType();

	m_eType  = obj.getEType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EReferenceImpl::copy() const
{
	std::shared_ptr<EReferenceImpl> element(new EReferenceImpl(*this));
	element->setThisEReferencePtr(element);
	return element;
}

std::shared_ptr<EClass> EReferenceImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEReference_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************


bool EReferenceImpl::isContainer() const 
{
	return m_container;
}

void EReferenceImpl::setContainment(bool _containment)
{
	m_containment = _containment;
} 

bool EReferenceImpl::isContainment() const 
{
	return m_containment;
}

void EReferenceImpl::setResolveProxies(bool _resolveProxies)
{
	m_resolveProxies = _resolveProxies;
} 

bool EReferenceImpl::isResolveProxies() const 
{
	return m_resolveProxies;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Bag<ecore::EAttribute>> EReferenceImpl::getEKeys() const
{

    return m_eKeys;
}


std::shared_ptr<ecore::EReference > EReferenceImpl::getEOpposite() const
{

    return m_eOpposite;
}
void EReferenceImpl::setEOpposite(std::shared_ptr<ecore::EReference> _eOpposite)
{
    m_eOpposite = _eOpposite;
}

std::shared_ptr<ecore::EClass > EReferenceImpl::getEReferenceType() const
{
//assert(m_eReferenceType);
    return m_eReferenceType;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<EReference> EReferenceImpl::getThisEReferencePtr()
{
	return m_thisEReferencePtr.lock();
}
void EReferenceImpl::setThisEReferencePtr(std::weak_ptr<EReference> thisEReferencePtr)
{
	m_thisEReferencePtr = thisEReferencePtr;
	setThisEStructuralFeaturePtr(thisEReferencePtr);
}
std::shared_ptr<ecore::EObject> EReferenceImpl::eContainer() const
{
	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EREFERENCE_EATTRIBUTE_CONTAINER:
			return isContainer(); //1421
		case EcorePackage::EREFERENCE_EATTRIBUTE_CONTAINMENT:
			return isContainment(); //1420
		case EcorePackage::EREFERENCE_EREFERENCE_EKEYS:
			return getEKeys(); //1425
		case EcorePackage::EREFERENCE_EREFERENCE_EOPPOSITE:
			return getEOpposite(); //1423
		case EcorePackage::EREFERENCE_EREFERENCE_EREFERENCETYPE:
			return getEReferenceType(); //1424
		case EcorePackage::EREFERENCE_EATTRIBUTE_RESOLVEPROXIES:
			return isResolveProxies(); //1422
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}
bool EReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EREFERENCE_EATTRIBUTE_CONTAINER:
			return isContainer() != false; //1421
		case EcorePackage::EREFERENCE_EATTRIBUTE_CONTAINMENT:
			return isContainment() != false; //1420
		case EcorePackage::EREFERENCE_EREFERENCE_EKEYS:
			return getEKeys() != nullptr; //1425
		case EcorePackage::EREFERENCE_EREFERENCE_EOPPOSITE:
			return getEOpposite() != nullptr; //1423
		case EcorePackage::EREFERENCE_EREFERENCE_EREFERENCETYPE:
			return getEReferenceType() != nullptr; //1424
		case EcorePackage::EREFERENCE_EATTRIBUTE_RESOLVEPROXIES:
			return isResolveProxies() != true; //1422
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}
bool EReferenceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EREFERENCE_EATTRIBUTE_CONTAINMENT:
		{
			// BOOST CAST
			bool _containment = boost::any_cast<bool>(newValue);
			setContainment(_containment); //1420
			return true;
		}
		case EcorePackage::EREFERENCE_EREFERENCE_EOPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EReference> _eOpposite = boost::any_cast<std::shared_ptr<ecore::EReference>>(newValue);
			setEOpposite(_eOpposite); //1423
			return true;
		}
		case EcorePackage::EREFERENCE_EATTRIBUTE_RESOLVEPROXIES:
		{
			// BOOST CAST
			bool _resolveProxies = boost::any_cast<bool>(newValue);
			setResolveProxies(_resolveProxies); //1422
			return true;
		}
	}

	return EStructuralFeatureImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get EcoreFactory
	std::shared_ptr<ecore::EcoreFactory> modelFactory = ecore::EcoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void EReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("containment");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setContainment(value);
		}

		iter = attr_list.find("resolveProxies");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setResolveProxies(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eKeys");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eKeys")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eOpposite");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eOpposite")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EStructuralFeatureImpl::loadAttributes(loadHandler, attr_list);
}

void EReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	EStructuralFeatureImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case EcorePackage::EREFERENCE_EREFERENCE_EKEYS:
		{
			std::shared_ptr<Bag<ecore::EAttribute>> _eKeys = getEKeys();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EAttribute> _r = std::dynamic_pointer_cast<ecore::EAttribute>(ref);
				if (_r != nullptr)
				{
					_eKeys->push_back(_r);
				}				
			}
			return;
		}

		case EcorePackage::EREFERENCE_EREFERENCE_EOPPOSITE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EReference> _eOpposite = std::dynamic_pointer_cast<ecore::EReference>( references.front() );
				setEOpposite(_eOpposite);
			}
			
			return;
		}
	}
	EStructuralFeatureImpl::resolveReferences(featureID, references);
}

void EReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EStructuralFeatureImpl::saveContent(saveHandler);
	
	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEReference_EAttribute_containment()) )
		{
			saveHandler->addAttribute("containment", this->isContainment());
		}

		if ( this->eIsSet(package->getEReference_EAttribute_resolveProxies()) )
		{
			saveHandler->addAttribute("resolveProxies", this->isResolveProxies());
		}

		// Add references
		std::shared_ptr<Bag<ecore::EAttribute>> eKeys_list = this->getEKeys();
		for (std::shared_ptr<ecore::EAttribute > object : *eKeys_list)
		{ 
			saveHandler->addReferences("eKeys", object);
		}
		saveHandler->addReference("eOpposite", this->getEOpposite());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


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
#include <sstream>
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EAttribute.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"

//Factories an Package includes
#include "ecore/impl/EcoreFactoryImpl.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EReferenceImpl::EReferenceImpl()
{	
}

EReferenceImpl::~EReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EReferenceImpl::EReferenceImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EReferenceImpl()
{
	m_eContainer = par_eContainer;
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
	m_containment = obj.isContainment();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_metaElementID = obj.getMetaElementID();
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
	
	m_eContainer  = obj.getEContainer();

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
	return ecore::EcorePackage::eInstance()->getEReference_Class();
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
	if(m_eKeys == nullptr)
	{
		m_eKeys.reset(new Bag<ecore::EAttribute>());
		
		
	}

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
void EReferenceImpl::setEReferenceType(std::shared_ptr<ecore::EClass> _eReferenceType)
{
    m_eReferenceType = _eReferenceType;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EReferenceImpl::getEContens() const
{
	if(m_eContens == nullptr)
	{
		/*Union*/
		m_eContens.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContens - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContens;
}




std::shared_ptr<EReference> EReferenceImpl::getThisEReferencePtr() const
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
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_CONTAINER:
			return eAny(isContainer()); //4323
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_CONTAINMENT:
			return eAny(isContainment()); //4322
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EKEYS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EAttribute>::iterator iter = m_eKeys->begin();
			Bag<ecore::EAttribute>::iterator end = m_eKeys->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4327
		}
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EOPPOSITE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEOpposite())); //4325
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EREFERENCETYPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEReferenceType())); //4326
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_RESOLVEPROXIES:
			return eAny(isResolveProxies()); //4324
	}
	return EStructuralFeatureImpl::eGet(featureID, resolve, coreType);
}
bool EReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_CONTAINER:
			return isContainer() != false; //4323
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_CONTAINMENT:
			return isContainment() != false; //4322
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EKEYS:
			return getEKeys() != nullptr; //4327
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EOPPOSITE:
			return getEOpposite() != nullptr; //4325
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EREFERENCETYPE:
			return getEReferenceType() != nullptr; //4326
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_RESOLVEPROXIES:
			return isResolveProxies() != true; //4324
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}
bool EReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_CONTAINMENT:
		{
			// BOOST CAST
			bool _containment = newValue->get<bool>();
			setContainment(_containment); //4322
			return true;
		}
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EKEYS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EAttribute>> eKeysList(new Bag<ecore::EAttribute>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eKeysList->add(std::dynamic_pointer_cast<ecore::EAttribute>(*iter));
				iter++;
			}
			
			Bag<ecore::EAttribute>::iterator iterEKeys = m_eKeys->begin();
			Bag<ecore::EAttribute>::iterator endEKeys = m_eKeys->end();
			while (iterEKeys != endEKeys)
			{
				if (eKeysList->find(*iterEKeys) == -1)
				{
					m_eKeys->erase(*iterEKeys);
				}
				iterEKeys++;
			}

			iterEKeys = eKeysList->begin();
			endEKeys = eKeysList->end();
			while (iterEKeys != endEKeys)
			{
				if (m_eKeys->find(*iterEKeys) == -1)
				{
					m_eKeys->add(*iterEKeys);
				}
				iterEKeys++;			
			}
			return true;
		}
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EOPPOSITE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EReference> _eOpposite = std::dynamic_pointer_cast<ecore::EReference>(_temp);
			setEOpposite(_eOpposite); //4325
			return true;
		}
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EREFERENCETYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EClass> _eReferenceType = std::dynamic_pointer_cast<ecore::EClass>(_temp);
			setEReferenceType(_eReferenceType); //4326
			return true;
		}
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_RESOLVEPROXIES:
		{
			// BOOST CAST
			bool _resolveProxies = newValue->get<bool>();
			setResolveProxies(_resolveProxies); //4324
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
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

		iter = attr_list.find("eReferenceType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eReferenceType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::EcoreFactory> modelFactory=ecore::EcoreFactory::eInstance();

	//load BasePackage Nodes
	EStructuralFeatureImpl::loadNode(nodeName, loadHandler);
}

void EReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EKEYS:
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

		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EOPPOSITE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EReference> _eOpposite = std::dynamic_pointer_cast<ecore::EReference>( references.front() );
				setEOpposite(_eOpposite);
			}
			
			return;
		}

		case ecore::EcorePackage::EREFERENCE_ATTRIBUTE_EREFERENCETYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EClass> _eReferenceType = std::dynamic_pointer_cast<ecore::EClass>( references.front() );
				setEReferenceType(_eReferenceType);
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
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void EReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getEReference_Attribute_containment()) )
		{
			saveHandler->addAttribute("containment", this->isContainment());
		}

		if ( this->eIsSet(package->getEReference_Attribute_resolveProxies()) )
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
		saveHandler->addReference("eReferenceType", this->getEReferenceType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "ecore/impl/EStructuralFeatureImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/ETypedElement.hpp"

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
EStructuralFeatureImpl::EStructuralFeatureImpl()
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

EStructuralFeatureImpl::~EStructuralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EStructuralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EStructuralFeatureImpl::EStructuralFeatureImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EStructuralFeatureImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EStructuralFeatureImpl::EStructuralFeatureImpl(const EStructuralFeatureImpl & obj):EStructuralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EStructuralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_changeable = obj.isChangeable();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_transient = obj.isTransient();
	m_unique = obj.isUnique();
	m_unsettable = obj.isUnsettable();
	m_upperBound = obj.getUpperBound();
	m_volatile = obj.isVolatile();

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

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

std::shared_ptr<ecore::EObject>  EStructuralFeatureImpl::copy() const
{
	std::shared_ptr<EStructuralFeatureImpl> element(new EStructuralFeatureImpl(*this));
	element->setThisEStructuralFeaturePtr(element);
	return element;
}

std::shared_ptr<EClass> EStructuralFeatureImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEStructuralFeature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EStructuralFeatureImpl::setChangeable(bool _changeable)
{
	m_changeable = _changeable;
} 

bool EStructuralFeatureImpl::isChangeable() const 
{
	return m_changeable;
}



Any EStructuralFeatureImpl::getDefaultValue() const 
{
	return m_defaultValue;
}

void EStructuralFeatureImpl::setDefaultValueLiteral(std::string _defaultValueLiteral)
{
	m_defaultValueLiteral = _defaultValueLiteral;
} 

std::string EStructuralFeatureImpl::getDefaultValueLiteral() const 
{
	return m_defaultValueLiteral;
}

void EStructuralFeatureImpl::setDerived(bool _derived)
{
	m_derived = _derived;
} 

bool EStructuralFeatureImpl::isDerived() const 
{
	return m_derived;
}

void EStructuralFeatureImpl::setFeatureID(int _featureID)
{
	m_featureID = _featureID;
} 

int EStructuralFeatureImpl::getFeatureID() const 
{
	return m_featureID;
}

void EStructuralFeatureImpl::setTransient(bool _transient)
{
	m_transient = _transient;
} 

bool EStructuralFeatureImpl::isTransient() const 
{
	return m_transient;
}

void EStructuralFeatureImpl::setUnsettable(bool _unsettable)
{
	m_unsettable = _unsettable;
} 

bool EStructuralFeatureImpl::isUnsettable() const 
{
	return m_unsettable;
}

void EStructuralFeatureImpl::setVolatile(bool _volatile)
{
	m_volatile = _volatile;
} 

bool EStructuralFeatureImpl::isVolatile() const 
{
	return m_volatile;
}

//*********************************
// Operations
//*********************************
void * EStructuralFeatureImpl::getContainerClass()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



//*********************************
// References
//*********************************
std::weak_ptr<ecore::EClass > EStructuralFeatureImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<EStructuralFeature> EStructuralFeatureImpl::getThisEStructuralFeaturePtr() const
{
	return m_thisEStructuralFeaturePtr.lock();
}
void EStructuralFeatureImpl::setThisEStructuralFeaturePtr(std::weak_ptr<EStructuralFeature> thisEStructuralFeaturePtr)
{
	m_thisEStructuralFeaturePtr = thisEStructuralFeaturePtr;
	setThisETypedElementPtr(thisEStructuralFeaturePtr);
}
std::shared_ptr<ecore::EObject> EStructuralFeatureImpl::eContainer() const
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
Any EStructuralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE:
			return eAny(isChangeable()); //1510
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUE:
			return eAny(getDefaultValue()); //1514
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL:
			return eAny(getDefaultValueLiteral()); //1513
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED:
			return eAny(isDerived()); //1516
		case EcorePackage::ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS:
			return eAny(getEContainingClass()); //1518
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_FEATUREID:
			return eAny(getFeatureID()); //1517
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT:
			return eAny(isTransient()); //1512
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE:
			return eAny(isUnsettable()); //1515
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE:
			return eAny(isVolatile()); //1511
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}
bool EStructuralFeatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE:
			return isChangeable() != true; //1510
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUE:
			return !getDefaultValue()->isEmpty(); //1514
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral() != ""; //1513
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED:
			return isDerived() != false; //1516
		case EcorePackage::ESTRUCTURALFEATURE_EREFERENCE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //1518
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_FEATUREID:
			return getFeatureID() != -1; //1517
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT:
			return isTransient() != false; //1512
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE:
			return isUnsettable() != false; //1515
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE:
			return isVolatile() != false; //1511
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}
bool EStructuralFeatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_CHANGEABLE:
		{
			// BOOST CAST
			bool _changeable = newValue->get<bool>();
			setChangeable(_changeable); //1510
			return true;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DEFAULTVALUELITERAL:
		{
			// BOOST CAST
			std::string _defaultValueLiteral = newValue->get<std::string>();
			setDefaultValueLiteral(_defaultValueLiteral); //1513
			return true;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_DERIVED:
		{
			// BOOST CAST
			bool _derived = newValue->get<bool>();
			setDerived(_derived); //1516
			return true;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_TRANSIENT:
		{
			// BOOST CAST
			bool _transient = newValue->get<bool>();
			setTransient(_transient); //1512
			return true;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_UNSETTABLE:
		{
			// BOOST CAST
			bool _unsettable = newValue->get<bool>();
			setUnsettable(_unsettable); //1515
			return true;
		}
		case EcorePackage::ESTRUCTURALFEATURE_EATTRIBUTE_VOLATILE:
		{
			// BOOST CAST
			bool _volatile = newValue->get<bool>();
			setVolatile(_volatile); //1511
			return true;
		}
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EStructuralFeatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EStructuralFeatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("changeable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setChangeable(value);
		}

		iter = attr_list.find("defaultValueLiteral");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setDefaultValueLiteral(value);
		}

		iter = attr_list.find("derived");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setDerived(value);
		}

		iter = attr_list.find("featureID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setFeatureID(value);
		}

		iter = attr_list.find("transient");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setTransient(value);
		}

		iter = attr_list.find("unsettable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setUnsettable(value);
		}

		iter = attr_list.find("volatile");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setVolatile(value);
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

	ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EStructuralFeatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	ETypedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EStructuralFeatureImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EStructuralFeatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void EStructuralFeatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_changeable()) )
		{
			saveHandler->addAttribute("changeable", this->isChangeable());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_defaultValueLiteral()) )
		{
			saveHandler->addAttribute("defaultValueLiteral", this->getDefaultValueLiteral());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_derived()) )
		{
			saveHandler->addAttribute("derived", this->isDerived());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_featureID()) )
		{
			saveHandler->addAttribute("featureID", this->getFeatureID());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_transient()) )
		{
			saveHandler->addAttribute("transient", this->isTransient());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_unsettable()) )
		{
			saveHandler->addAttribute("unsettable", this->isUnsettable());
		}

		if ( this->eIsSet(package->getEStructuralFeature_EAttribute_volatile()) )
		{
			saveHandler->addAttribute("volatile", this->isVolatile());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


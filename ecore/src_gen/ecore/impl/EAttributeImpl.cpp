#include "ecore/impl/EAttributeImpl.hpp"

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
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EDataType.hpp"

#include "ecore/EGenericType.hpp"

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
EAttributeImpl::EAttributeImpl()
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

EAttributeImpl::~EAttributeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAttribute "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EAttributeImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EAttributeImpl::EAttributeImpl(const EAttributeImpl & obj):EAttributeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAttribute "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_changeable = obj.isChangeable();
	m_containerClass = obj.getContainerClass();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_iD = obj.isID();
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
	
	m_eAttributeType  = obj.getEAttributeType();

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

std::shared_ptr<ecore::EObject>  EAttributeImpl::copy() const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl(*this));
	element->setThisEAttributePtr(element);
	return element;
}

std::shared_ptr<EClass> EAttributeImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEAttribute_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EAttributeImpl::setID(bool _iD)
{
	m_iD = _iD;
} 

bool EAttributeImpl::isID() const 
{
	return m_iD;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<ecore::EDataType > EAttributeImpl::getEAttributeType() const
{
//assert(m_eAttributeType);
    return m_eAttributeType;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<EAttribute> EAttributeImpl::getThisEAttributePtr()
{
	return m_thisEAttributePtr.lock();
}
void EAttributeImpl::setThisEAttributePtr(std::weak_ptr<EAttribute> thisEAttributePtr)
{
	m_thisEAttributePtr = thisEAttributePtr;
	setThisEStructuralFeaturePtr(thisEAttributePtr);
}
std::shared_ptr<ecore::EObject> EAttributeImpl::eContainer() const
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
boost::any EAttributeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EATTRIBUTE_EREFERENCE_EATTRIBUTETYPE:
			return getEAttributeType(); //021
		case EcorePackage::EATTRIBUTE_EATTRIBUTE_ID:
			return isID(); //020
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}
bool EAttributeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EATTRIBUTE_EREFERENCE_EATTRIBUTETYPE:
			return getEAttributeType() != nullptr; //021
		case EcorePackage::EATTRIBUTE_EATTRIBUTE_ID:
			return isID() != false; //020
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}
bool EAttributeImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EATTRIBUTE_EATTRIBUTE_ID:
		{
			// BOOST CAST
			bool _iD = boost::any_cast<bool>(newValue);
			setID(_iD); //020
			return true;
		}
	}

	return EStructuralFeatureImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EAttributeImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void EAttributeImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("iD");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setID(value);
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

void EAttributeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	EStructuralFeatureImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EAttributeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	EStructuralFeatureImpl::resolveReferences(featureID, references);
}

void EAttributeImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EStructuralFeatureImpl::saveContent(saveHandler);
	
	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EAttributeImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEAttribute_EAttribute_iD()) )
		{
			saveHandler->addAttribute("iD", this->isID());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


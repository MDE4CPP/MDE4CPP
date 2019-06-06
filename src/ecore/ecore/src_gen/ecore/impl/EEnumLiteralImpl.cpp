#include "ecore/impl/EEnumLiteralImpl.hpp"

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

#include "ecore/EEnum.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EObject.hpp"

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
EEnumLiteralImpl::EEnumLiteralImpl()
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

EEnumLiteralImpl::~EEnumLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnumLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EEnumLiteralImpl::EEnumLiteralImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EEnumLiteralImpl()
			{
			    m_eContainer = par_eContainer;
			}





//Additional constructor for the containments back reference
			EEnumLiteralImpl::EEnumLiteralImpl(std::weak_ptr<ecore::EEnum > par_eEnum)
			:EEnumLiteralImpl()
			{
			    m_eEnum = par_eEnum;
			}






EEnumLiteralImpl::EEnumLiteralImpl(const EEnumLiteralImpl & obj):EEnumLiteralImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnumLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_instance = obj.getInstance();
	m_literal = obj.getLiteral();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

	m_eEnum  = obj.getEEnum();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EEnumLiteralImpl::copy() const
{
	std::shared_ptr<EEnumLiteralImpl> element(new EEnumLiteralImpl(*this));
	element->setThisEEnumLiteralPtr(element);
	return element;
}

std::shared_ptr<EClass> EEnumLiteralImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEEnumLiteral_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EEnumLiteralImpl::setInstance(Any _instance)
{
	m_instance = _instance;
} 

Any EEnumLiteralImpl::getInstance() const 
{
	return m_instance;
}

void EEnumLiteralImpl::setLiteral(std::string _literal)
{
	m_literal = _literal;
} 

std::string EEnumLiteralImpl::getLiteral() const 
{
	return m_literal;
}

void EEnumLiteralImpl::setValue(int _value)
{
	m_value = _value;
} 

int EEnumLiteralImpl::getValue() const 
{
	return m_value;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EEnum > EEnumLiteralImpl::getEEnum() const
{

    return m_eEnum;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EEnumLiteralImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EEnumLiteral> EEnumLiteralImpl::getThisEEnumLiteralPtr() const
{
	return m_thisEEnumLiteralPtr.lock();
}
void EEnumLiteralImpl::setThisEEnumLiteralPtr(std::weak_ptr<EEnumLiteral> thisEEnumLiteralPtr)
{
	m_thisEEnumLiteralPtr = thisEEnumLiteralPtr;
	setThisENamedElementPtr(thisEEnumLiteralPtr);
}
std::shared_ptr<ecore::EObject> EEnumLiteralImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eEnum.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EEnumLiteralImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_EENUM:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEEnum().lock())); //218
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_INSTANCE:
			return eAny(getInstance()); //216
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_LITERAL:
			return eAny(getLiteral()); //217
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_VALUE:
			return eAny(getValue()); //215
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}
bool EEnumLiteralImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_EENUM:
			return getEEnum().lock() != nullptr; //218
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_INSTANCE:
			return !getInstance()->isEmpty(); //216
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_LITERAL:
			return getLiteral() != ""; //217
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_VALUE:
			return getValue() != 0; //215
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}
bool EEnumLiteralImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_INSTANCE:
		{
			// BOOST CAST
			Any _instance = newValue->get<Any>();
			setInstance(_instance); //216
			return true;
		}
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_LITERAL:
		{
			// BOOST CAST
			std::string _literal = newValue->get<std::string>();
			setLiteral(_literal); //217
			return true;
		}
		case EcorePackage::EENUMLITERAL_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			int _value = newValue->get<int>();
			setValue(_value); //215
			return true;
		}
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EEnumLiteralImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EEnumLiteralImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("literal");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setLiteral(value);
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setValue(value);
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

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EEnumLiteralImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{


	ENamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EEnumLiteralImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ENamedElementImpl::resolveReferences(featureID, references);
}

void EEnumLiteralImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void EEnumLiteralImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEEnumLiteral_Attribute_literal()) )
		{
			saveHandler->addAttribute("literal", this->getLiteral());
		}

		if ( this->eIsSet(package->getEEnumLiteral_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


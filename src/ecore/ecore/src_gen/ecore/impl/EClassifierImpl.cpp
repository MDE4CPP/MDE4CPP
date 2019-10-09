#include "ecore/impl/EClassifierImpl.hpp"

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

#include "ecore/ENamedElement.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"

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
EClassifierImpl::EClassifierImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
	
	

	//Init references
	

	
	
}

EClassifierImpl::~EClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EClassifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EClassifierImpl::EClassifierImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EClassifierImpl()
			{
			    m_eContainer = par_eContainer;
			}





//Additional constructor for the containments back reference
			EClassifierImpl::EClassifierImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EClassifierImpl()
			{
			    m_ePackage = par_ePackage;
			}






EClassifierImpl::EClassifierImpl(const EClassifierImpl & obj):EClassifierImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EClassifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

	m_ePackage  = obj.getEPackage();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(std::dynamic_pointer_cast<ecore::ETypeParameter>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  EClassifierImpl::copy() const
{
	std::shared_ptr<EClassifierImpl> element(new EClassifierImpl(*this));
	element->setThisEClassifierPtr(element);
	return element;
}

std::shared_ptr<EClass> EClassifierImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EClassifierImpl::setDefaultValue(Any _defaultValue)
{
	m_defaultValue = _defaultValue;
} 

Any EClassifierImpl::getDefaultValue() const 
{
	return m_defaultValue;
}



void *  EClassifierImpl::getInstanceClass() const 
{
	return m_instanceClass;
}

void EClassifierImpl::setInstanceClassName(std::string _instanceClassName)
{
	m_instanceClassName = _instanceClassName;
} 

std::string EClassifierImpl::getInstanceClassName() const 
{
	return m_instanceClassName;
}

void EClassifierImpl::setInstanceTypeName(std::string _instanceTypeName)
{
	m_instanceTypeName = _instanceTypeName;
} 

std::string EClassifierImpl::getInstanceTypeName() const 
{
	return m_instanceTypeName;
}

//*********************************
// Operations
//*********************************
int EClassifierImpl::getClassifierID()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return getMetaElementID();
	//end of body
}

bool EClassifierImpl::isInstance(Any object) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EPackage > EClassifierImpl::getEPackage() const
{

    return m_ePackage;
}


std::shared_ptr<Bag<ecore::ETypeParameter>> EClassifierImpl::getETypeParameters() const
{

    return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EClassifierImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EClassifier> EClassifierImpl::getThisEClassifierPtr() const
{
	return m_thisEClassifierPtr.lock();
}
void EClassifierImpl::setThisEClassifierPtr(std::weak_ptr<EClassifier> thisEClassifierPtr)
{
	m_thisEClassifierPtr = thisEClassifierPtr;
	setThisENamedElementPtr(thisEClassifierPtr);
}
std::shared_ptr<ecore::EObject> EClassifierImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
			return eAny(getDefaultValue()); //137
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEPackage().lock())); //139
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::ETypeParameter>::iterator iter = m_eTypeParameters->begin();
			Bag<ecore::ETypeParameter>::iterator end = m_eTypeParameters->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1310
		}
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASS:
			return eAny(getInstanceClass()); //136
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
			return eAny(getInstanceClassName()); //135
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
			return eAny(getInstanceTypeName()); //138
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}
bool EClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //137
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_EPACKAGE:
			return getEPackage().lock() != nullptr; //139
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //1310
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASS:
			return getInstanceClass() != nullptr; //136
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
			return getInstanceClassName() != ""; //135
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
			return getInstanceTypeName() != ""; //138
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}
bool EClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE:
		{
			// BOOST CAST
			Any _defaultValue = newValue->get<Any>();
			setDefaultValue(_defaultValue); //137
			return true;
		}
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::ETypeParameter>> eTypeParametersList(new Bag<ecore::ETypeParameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eTypeParametersList->add(std::dynamic_pointer_cast<ecore::ETypeParameter>(*iter));
				iter++;
			}
			
			Bag<ecore::ETypeParameter>::iterator iterETypeParameters = m_eTypeParameters->begin();
			Bag<ecore::ETypeParameter>::iterator endETypeParameters = m_eTypeParameters->end();
			while (iterETypeParameters != endETypeParameters)
			{
				if (eTypeParametersList->find(*iterETypeParameters) == -1)
				{
					m_eTypeParameters->erase(*iterETypeParameters);
				}
				iterETypeParameters++;
			}

			iterETypeParameters = eTypeParametersList->begin();
			endETypeParameters = eTypeParametersList->end();
			while (iterETypeParameters != endETypeParameters)
			{
				if (m_eTypeParameters->find(*iterETypeParameters) == -1)
				{
					m_eTypeParameters->add(*iterETypeParameters);
				}
				iterETypeParameters++;			
			}
			return true;
		}
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME:
		{
			// BOOST CAST
			std::string _instanceClassName = newValue->get<std::string>();
			setInstanceClassName(_instanceClassName); //135
			return true;
		}
		case EcorePackage::ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME:
		{
			// BOOST CAST
			std::string _instanceTypeName = newValue->get<std::string>();
			setInstanceTypeName(_instanceTypeName); //138
			return true;
		}
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("instanceClassName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setInstanceClassName(value);
		}

		iter = attr_list.find("instanceTypeName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setInstanceTypeName(value);
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

void EClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("eTypeParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ETypeParameter";
			}
			std::shared_ptr<ecore::ETypeParameter> eTypeParameters = std::dynamic_pointer_cast<ecore::ETypeParameter>(modelFactory->create(typeName));
			if (eTypeParameters != nullptr)
			{
				std::shared_ptr<Bag<ecore::ETypeParameter>> list_eTypeParameters = this->getETypeParameters();
				list_eTypeParameters->push_back(eTypeParameters);
				loadHandler->handleChild(eTypeParameters);
			}
			return;
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

	ENamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EClassifierImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ENamedElementImpl::resolveReferences(featureID, references);
}

void EClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void EClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEClassifier_Attribute_instanceClassName()) )
		{
			saveHandler->addAttribute("instanceClassName", this->getInstanceClassName());
		}

		if ( this->eIsSet(package->getEClassifier_Attribute_instanceTypeName()) )
		{
			saveHandler->addAttribute("instanceTypeName", this->getInstanceTypeName());
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eTypeParameters'
		std::shared_ptr<Bag<ecore::ETypeParameter>> list_eTypeParameters = this->getETypeParameters();
		for (std::shared_ptr<ecore::ETypeParameter> eTypeParameters : *list_eTypeParameters) 
		{
			saveHandler->addReference(eTypeParameters, "eTypeParameters", eTypeParameters->eClass() != package->getETypeParameter_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


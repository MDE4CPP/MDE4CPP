#include "ecore/impl/EDataTypeImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ecore/Impl/EcoreFactoryImpl.hpp"
#include "ecore/Impl/EcorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EDataTypeImpl::EDataTypeImpl()
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

EDataTypeImpl::~EDataTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EDataType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EDataTypeImpl::EDataTypeImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EDataTypeImpl()
			{
			    m_eContainer = par_eContainer;
			}


//Additional constructor for the containments back reference
			EDataTypeImpl::EDataTypeImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EDataTypeImpl()
			{
			    m_ePackage = par_ePackage;
			}



EDataTypeImpl::EDataTypeImpl(const EDataTypeImpl & obj):EDataTypeImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EDataType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();
	m_serializable = obj.isSerializable();

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

std::shared_ptr<ecore::EObject>  EDataTypeImpl::copy() const
{
	std::shared_ptr<EDataTypeImpl> element(new EDataTypeImpl(*this));
	element->setThisEDataTypePtr(element);
	return element;
}

std::shared_ptr<EClass> EDataTypeImpl::eStaticClass() const
{
	return ecore::EcorePackage::eInstance()->getEDataType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EDataTypeImpl::setSerializable(bool _serializable)
{
	m_serializable = _serializable;
} 

bool EDataTypeImpl::isSerializable() const 
{
	return m_serializable;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EDataTypeImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EDataType> EDataTypeImpl::getThisEDataTypePtr() const
{
	return m_thisEDataTypePtr.lock();
}
void EDataTypeImpl::setThisEDataTypePtr(std::weak_ptr<EDataType> thisEDataTypePtr)
{
	m_thisEDataTypePtr = thisEDataTypePtr;
	setThisEClassifierPtr(thisEDataTypePtr);
}
std::shared_ptr<ecore::EObject> EDataTypeImpl::eContainer() const
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
Any EDataTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EDATATYPE_ATTRIBUTE_SERIALIZABLE:
			return eAny(isSerializable()); //1411
	}
	return EClassifierImpl::eGet(featureID, resolve, coreType);
}
bool EDataTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EDATATYPE_ATTRIBUTE_SERIALIZABLE:
			return isSerializable() != true; //1411
	}
	return EClassifierImpl::internalEIsSet(featureID);
}
bool EDataTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::EcorePackage::EDATATYPE_ATTRIBUTE_SERIALIZABLE:
		{
			// BOOST CAST
			bool _serializable = newValue->get<bool>();
			setSerializable(_serializable); //1411
			return true;
		}
	}

	return EClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EDataTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EDataTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("serializable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setSerializable(value);
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

	EClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void EDataTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::EcoreFactory> modelFactory=ecore::EcoreFactory::eInstance();

	//load BasePackage Nodes
	EClassifierImpl::loadNode(nodeName, loadHandler);
}

void EDataTypeImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	EClassifierImpl::resolveReferences(featureID, references);
}

void EDataTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EClassifierImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EDataTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getEDataType_Attribute_serializable()) )
		{
			saveHandler->addAttribute("serializable", this->isSerializable());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "ecore/impl/ETypeParameterImpl.hpp"

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

#include "ecore/EGenericType.hpp"

#include "ecore/ENamedElement.hpp"

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
ETypeParameterImpl::ETypeParameterImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eBounds.reset(new Bag<ecore::EGenericType>());
	
	

	//Init references
	
	
}

ETypeParameterImpl::~ETypeParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ETypeParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj):ETypeParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypeParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EGenericType>> _eBoundsList = obj.getEBounds();
	for(std::shared_ptr<ecore::EGenericType> _eBounds : *_eBoundsList)
	{
		this->getEBounds()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eBounds->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eBounds" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  ETypeParameterImpl::copy() const
{
	std::shared_ptr<ETypeParameterImpl> element(new ETypeParameterImpl(*this));
	element->setThisETypeParameterPtr(element);
	return element;
}

std::shared_ptr<EClass> ETypeParameterImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getETypeParameter_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Bag<ecore::EGenericType>> ETypeParameterImpl::getEBounds() const
{

    return m_eBounds;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ETypeParameter> ETypeParameterImpl::getThisETypeParameterPtr()
{
	return m_thisETypeParameterPtr.lock();
}
void ETypeParameterImpl::setThisETypeParameterPtr(std::weak_ptr<ETypeParameter> thisETypeParameterPtr)
{
	m_thisETypeParameterPtr = thisETypeParameterPtr;
	setThisENamedElementPtr(thisETypeParameterPtr);
}
std::shared_ptr<ecore::EObject> ETypeParameterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ETypeParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::ETYPEPARAMETER_EREFERENCE_EBOUNDS:
			return eAny(getEBounds()); //512
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}
bool ETypeParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::ETYPEPARAMETER_EREFERENCE_EBOUNDS:
			return getEBounds() != nullptr; //512
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}
bool ETypeParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ETypeParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ETypeParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ETypeParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("eBounds") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			std::shared_ptr<ecore::EGenericType> eBounds = std::dynamic_pointer_cast<ecore::EGenericType>(modelFactory->create(typeName));
			if (eBounds != nullptr)
			{
				std::shared_ptr<Bag<ecore::EGenericType>> list_eBounds = this->getEBounds();
				list_eBounds->push_back(eBounds);
				loadHandler->handleChild(eBounds);
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

void ETypeParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ENamedElementImpl::resolveReferences(featureID, references);
}

void ETypeParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ETypeParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eBounds'
		std::shared_ptr<Bag<ecore::EGenericType>> list_eBounds = this->getEBounds();
		for (std::shared_ptr<ecore::EGenericType> eBounds : *list_eBounds) 
		{
			saveHandler->addReference(eBounds, "eBounds", eBounds->eClass() != package->getEGenericType_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


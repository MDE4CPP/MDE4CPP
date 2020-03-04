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

#include "ecore/EGenericType.hpp"

#include "ecore/ENamedElement.hpp"

#include "ecore/EObject.hpp"

//Factories an Package includes
#include "ecore/Impl/EcoreFactoryImpl.hpp"
#include "ecore/Impl/EcorePackageImpl.hpp"


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


//Additional constructor for the containments back reference
			ETypeParameterImpl::ETypeParameterImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:ETypeParameterImpl()
			{
			    m_eContainer = par_eContainer;
			}



ETypeParameterImpl::ETypeParameterImpl(const ETypeParameterImpl & obj):ETypeParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ETypeParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();


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
	return ecore::EcorePackage::eInstance()->getETypeParameter_Class();
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
std::shared_ptr<Union<ecore::EObject>> ETypeParameterImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<ETypeParameter> ETypeParameterImpl::getThisETypeParameterPtr() const
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
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ETypeParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EGenericType>::iterator iter = m_eBounds->begin();
			Bag<ecore::EGenericType>::iterator end = m_eBounds->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //525
		}
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}
bool ETypeParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
			return getEBounds() != nullptr; //525
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}
bool ETypeParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::EcorePackage::ETYPEPARAMETER_ATTRIBUTE_EBOUNDS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EGenericType>> eBoundsList(new Bag<ecore::EGenericType>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eBoundsList->add(std::dynamic_pointer_cast<ecore::EGenericType>(*iter));
				iter++;
			}
			
			Bag<ecore::EGenericType>::iterator iterEBounds = m_eBounds->begin();
			Bag<ecore::EGenericType>::iterator endEBounds = m_eBounds->end();
			while (iterEBounds != endEBounds)
			{
				if (eBoundsList->find(*iterEBounds) == -1)
				{
					m_eBounds->erase(*iterEBounds);
				}
				iterEBounds++;
			}

			iterEBounds = eBoundsList->begin();
			endEBounds = eBoundsList->end();
			while (iterEBounds != endEBounds)
			{
				if (m_eBounds->find(*iterEBounds) == -1)
				{
					m_eBounds->add(*iterEBounds);
				}
				iterEBounds++;			
			}
			return true;
		}
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
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ETypeParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ETypeParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::EcoreFactory> modelFactory=ecore::EcoreFactory::eInstance();

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
	//load BasePackage Nodes
	ENamedElementImpl::loadNode(nodeName, loadHandler);
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
	
	EObjectImpl::saveContent(saveHandler);
	
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
			saveHandler->addReference(eBounds, "eBounds", eBounds->eClass() !=ecore::EcorePackage::eInstance()->getEGenericType_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


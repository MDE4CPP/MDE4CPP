#include "ecore/impl/EObjectImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "ecore/EClass.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EReference.hpp"

#include "ecore/EStructuralFeature.hpp"

//Factories an Package includes
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EObjectImpl::EObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EObjectImpl::~EObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObject "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EObjectImpl::EObjectImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EObjectImpl()
{
	m_eContainer = par_eContainer;
}


EObjectImpl::EObjectImpl(const EObjectImpl & obj):EObjectImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  EObjectImpl::copy() const
{
	std::shared_ptr<EObjectImpl> element(new EObjectImpl(*this));
	element->setThisEObjectPtr(element);
	return element;
}

EObjectImpl& EObjectImpl::operator=(const EObjectImpl & obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EObject "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_metaElementID = obj.getMetaElementID();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();


	//Clone references with containment (deep copy)



	return *this;
}

std::shared_ptr<EClass> EObjectImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEObject_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute metaElementID
*/
int EObjectImpl::getMetaElementID() const 
{
	return m_metaElementID;
}

void EObjectImpl::setMetaElementID(int _metaElementID)
{
	m_metaElementID = _metaElementID;
} 



//*********************************
// Operations
//*********************************
std::shared_ptr<Bag <   ecore::EObject > > EObjectImpl::eAllContents() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> EObjectImpl::eClass() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eStaticClass();
	//end of body
}



std::shared_ptr<ecore::EStructuralFeature> EObjectImpl::eContainingFeature() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EReference> EObjectImpl::eContainmentFeature() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag <   ecore::EObject > > EObjectImpl::eContents() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag <   ecore::EObject > > EObjectImpl::eCrossReferences() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature,false);
	//end of body
}

Any EObjectImpl::eGet(std::shared_ptr<ecore::EStructuralFeature>  feature,bool resolve) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->eGet(feature->getFeatureID(),resolve,false);
	//end of body
}

Any EObjectImpl::eInvoke(std::shared_ptr<ecore::EOperation>  operation,Bag <   Any >  arguments) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsProxy() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool EObjectImpl::eIsSet(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->internalEIsSet(feature->getFeatureID());
	//end of body
}

int EObjectImpl::eResource() const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void EObjectImpl::eSet(std::shared_ptr<ecore::EStructuralFeature>  feature,Any newValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->eSet(feature->getFeatureID(), newValue);
	//end of body
}

void EObjectImpl::eUnset(std::shared_ptr<ecore::EStructuralFeature>  feature) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference eContainer
*/
std::weak_ptr<ecore::EObject > EObjectImpl::getEContainer() const
{

    return m_eContainer;
}

void EObjectImpl::setEContainer(std::shared_ptr<ecore::EObject> _eContainer)
{
    m_eContainer = _eContainer;
}



/*
Getter & Setter for reference eContens
*/






//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EObjectImpl::getEContens() const
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




std::shared_ptr<EObject> EObjectImpl::getThisEObjectPtr() const
{
	return m_thisEObjectPtr.lock();
}
void EObjectImpl::setThisEObjectPtr(std::weak_ptr<EObject> thisEObjectPtr)
{
	m_thisEObjectPtr = thisEObjectPtr;
}
std::shared_ptr<ecore::EObject> EObjectImpl::eContainer() const
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
Any EObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEContainer().lock())); //391
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = m_eContens->begin();
			Bag<ecore::EObject>::iterator end = m_eContens->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //390
		}
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
			return eAny(getMetaElementID()); //392
	}
	Any result;
	return result;
}
bool EObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
			return getEContainer().lock() != nullptr; //391
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:
			return getEContens() != nullptr; //390
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
			return getMetaElementID() != 0; //392
	}
	bool result = false;
	return result;
}
bool EObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EObject> _eContainer = std::dynamic_pointer_cast<ecore::EObject>(_temp);
			setEContainer(_eContainer); //391
			return true;
		}
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTENS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EObject>> eContensList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eContensList->add(std::dynamic_pointer_cast<ecore::EObject>(*iter));
				iter++;
			}
			
			Bag<ecore::EObject>::iterator iterEContens = m_eContens->begin();
			Bag<ecore::EObject>::iterator endEContens = m_eContens->end();
			while (iterEContens != endEContens)
			{
				if (eContensList->find(*iterEContens) == -1)
				{
					m_eContens->erase(*iterEContens);
				}
				iterEContens++;
			}

			iterEContens = eContensList->begin();
			endEContens = eContensList->end();
			while (iterEContens != endEContens)
			{
				if (m_eContens->find(*iterEContens) == -1)
				{
					m_eContens->add(*iterEContens);
				}
				iterEContens++;			
			}
			return true;
		}
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_METAELEMENTID:
		{
			// BOOST CAST
			int _metaElementID = newValue->get<int>();
			setMetaElementID(_metaElementID); //392
			return true;
		}
	}

	bool result = false;
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void EObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("metaElementID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setMetaElementID(value);
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

}

void EObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::ecoreFactory> modelFactory=ecore::ecoreFactory::eInstance();

	try
	{
		if ( nodeName.compare("eContens") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EObject";
			}
			std::shared_ptr<ecore::EObject> eContens = modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER);
			if (eContens != nullptr)
			{
				loadHandler->handleChild(eContens);
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
}

void EObjectImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECT_ATTRIBUTE_ECONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EObject> _eContainer = std::dynamic_pointer_cast<ecore::EObject>( references.front() );
				setEContainer(_eContainer);
			}
			
			return;
		}
	}
}

void EObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getEObject_Attribute_metaElementID()) )
		{
			saveHandler->addAttribute("metaElementID", this->getMetaElementID());
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eContens'
		std::shared_ptr<Union<ecore::EObject>> list_eContens = this->getEContens();
		for (std::shared_ptr<ecore::EObject> eContens : *list_eContens) 
		{
			saveHandler->addReference(eContens, "eContens", eContens->eClass() !=ecore::ecorePackage::eInstance()->getEObject_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


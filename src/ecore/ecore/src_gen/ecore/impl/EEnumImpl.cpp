#include "ecore/impl/EEnumImpl.hpp"

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
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ecore/impl/ecoreFactoryImpl.hpp"
#include "ecore/impl/ecorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EEnumImpl::EEnumImpl()
{	
}

EEnumImpl::~EEnumImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnum "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EEnumImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:EEnumImpl()
{
	m_ePackage = par_ePackage;
}

EEnumImpl::EEnumImpl(const EEnumImpl & obj): EDataTypeImpl(obj), EEnum(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnum "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> eLiteralsContainer = getELiterals();
	for(auto _eLiterals : *obj.getELiterals()) 
	{
		eLiteralsContainer->push_back(std::dynamic_pointer_cast<ecore::EEnumLiteral>(_eLiterals->copy()));
	}
	/*Subset*/
	m_eLiterals->initSubset(getEContens());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContens())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  EEnumImpl::copy() const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(*this));
	element->setThisEEnumPtr(element);
	return element;
}

std::shared_ptr<EClass> EEnumImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEEnum_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(std::string name) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getName()==name)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();
	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(int value) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getValue()==value)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();

	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteralByLiteral(std::string literal) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getLiteral()==literal)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>  ();
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference eLiterals
*/
std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> EEnumImpl::getELiterals() const
{
	if(m_eLiterals == nullptr)
	{
		/*Subset*/
		m_eLiterals.reset(new Subset<ecore::EEnumLiteral, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eLiterals->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eLiterals;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EEnumImpl::getEContens() const
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




std::shared_ptr<EEnum> EEnumImpl::getThisEEnumPtr() const
{
	return m_thisEEnumPtr.lock();
}
void EEnumImpl::setThisEEnumPtr(std::weak_ptr<EEnum> thisEEnumPtr)
{
	m_thisEEnumPtr = thisEEnumPtr;
	setThisEDataTypePtr(thisEEnumPtr);
}
std::shared_ptr<ecore::EObject> EEnumImpl::eContainer() const
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
Any EEnumImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
		{
			return eAny(getELiterals()); //2012			
		}
	}
	return EDataTypeImpl::eGet(featureID, resolve, coreType);
}
bool EEnumImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
			return getELiterals() != nullptr; //2012
	}
	return EDataTypeImpl::internalEIsSet(featureID);
}
bool EEnumImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EEnumLiteral>> eLiteralsList(new Bag<ecore::EEnumLiteral>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eLiteralsList->add(std::dynamic_pointer_cast<ecore::EEnumLiteral>(*iter));
				iter++;
			}
			
			Bag<ecore::EEnumLiteral>::iterator iterELiterals = m_eLiterals->begin();
			Bag<ecore::EEnumLiteral>::iterator endELiterals = m_eLiterals->end();
			while (iterELiterals != endELiterals)
			{
				if (eLiteralsList->find(*iterELiterals) == -1)
				{
					m_eLiterals->erase(*iterELiterals);
				}
				iterELiterals++;
			}
 
			iterELiterals = eLiteralsList->begin();
			endELiterals = eLiteralsList->end();
			while (iterELiterals != endELiterals)
			{
				if (m_eLiterals->find(*iterELiterals) == -1)
				{
					m_eLiterals->add(*iterELiterals);
				}
				iterELiterals++;			
			}
			return true;
		}
	}

	return EDataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EEnumImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EEnumImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EDataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void EEnumImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::ecoreFactory> modelFactory=ecore::ecoreFactory::eInstance();

	try
	{
		if ( nodeName.compare("eLiterals") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EEnumLiteral";
			}
		loadHandler->handleChildContainer<ecore::EEnumLiteral>(this->getELiterals());  

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
	EDataTypeImpl::loadNode(nodeName, loadHandler);
}

void EEnumImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	EDataTypeImpl::resolveReferences(featureID, references);
}

void EEnumImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EDataTypeImpl::saveContent(saveHandler);
	
	EClassifierImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void EEnumImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eLiterals'
		for (std::shared_ptr<ecore::EEnumLiteral> eLiterals : *this->getELiterals()) 
		{
			saveHandler->addReference(eLiterals, "eLiterals", eLiterals->eClass() != package->getEEnumLiteral_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


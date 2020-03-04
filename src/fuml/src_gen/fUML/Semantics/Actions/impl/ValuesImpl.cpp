#include "fUML/Semantics/Actions/impl/ValuesImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/Actions/Impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/Impl/ActionsPackageImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ValuesImpl::ValuesImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_values.reset(new Bag<fUML::Semantics::Values::Value>());
	
	

	//Init references
	
	
}

ValuesImpl::~ValuesImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Values "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ValuesImpl::ValuesImpl(const ValuesImpl & obj):ValuesImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Values "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<fUML::Semantics::Values::Value>> _values = obj.getValues();
	m_values.reset(new Bag<fUML::Semantics::Values::Value>(*(obj.getValues().get())));


	//Clone references with containment (deep copy)


}

std::shared_ptr<ecore::EObject>  ValuesImpl::copy() const
{
	std::shared_ptr<ValuesImpl> element(new ValuesImpl(*this));
	element->setThisValuesPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ValuesImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getValues_Class();
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
std::shared_ptr<Bag<fUML::Semantics::Values::Value>> ValuesImpl::getValues() const
{

    return m_values;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Values> ValuesImpl::getThisValuesPtr() const
{
	return m_thisValuesPtr.lock();
}
void ValuesImpl::setThisValuesPtr(std::weak_ptr<Values> thisValuesPtr)
{
	m_thisValuesPtr = thisValuesPtr;
}
std::shared_ptr<ecore::EObject> ValuesImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ValuesImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<fUML::Semantics::Values::Value>::iterator iter = m_values->begin();
			Bag<fUML::Semantics::Values::Value>::iterator end = m_values->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1200
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ValuesImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
			return getValues() != nullptr; //1200
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ValuesImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> valuesList(new Bag<fUML::Semantics::Values::Value>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				valuesList->add(std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(*iter));
				iter++;
			}
			
			Bag<fUML::Semantics::Values::Value>::iterator iterValues = m_values->begin();
			Bag<fUML::Semantics::Values::Value>::iterator endValues = m_values->end();
			while (iterValues != endValues)
			{
				if (valuesList->find(*iterValues) == -1)
				{
					m_values->erase(*iterValues);
				}
				iterValues++;
			}

			iterValues = valuesList->begin();
			endValues = valuesList->end();
			while (iterValues != endValues)
			{
				if (m_values->find(*iterValues) == -1)
				{
					m_values->add(*iterValues);
				}
				iterValues++;			
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ValuesImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ValuesImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("values");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("values")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ValuesImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::Actions::ActionsFactory> modelFactory=fUML::Semantics::Actions::ActionsFactory::eInstance();

	//load BasePackage Nodes
}

void ValuesImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::VALUES_ATTRIBUTE_VALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> _values = getValues();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<fUML::Semantics::Values::Value> _r = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(ref);
				if (_r != nullptr)
				{
					_values->push_back(_r);
				}				
			}
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ValuesImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ValuesImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values_list = this->getValues();
		for (std::shared_ptr<fUML::Semantics::Values::Value > object : *values_list)
		{ 
			saveHandler->addReferences("values", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


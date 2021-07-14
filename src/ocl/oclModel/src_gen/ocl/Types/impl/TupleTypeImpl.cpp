#include "ocl/Types/impl/TupleTypeImpl.hpp"

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
#include "ocl/Values/ValuesFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Types/TypesFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"
#include "ocl/Types/NameTypeBinding.hpp"
#include "ocl/Values/TupleValue.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
TupleTypeImpl::TupleTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleTypeImpl::~TupleTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TupleTypeImpl::TupleTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:TupleTypeImpl()
{
	m_ePackage = par_ePackage;
}

TupleTypeImpl::TupleTypeImpl(const TupleTypeImpl & obj): TupleTypeImpl()
{
	*this = obj;
}

TupleTypeImpl& TupleTypeImpl::operator=(const TupleTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EDataTypeImpl::operator=(obj);
	TupleType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_instance  = obj.getInstance();
	std::shared_ptr<Bag<ocl::Types::NameTypeBinding>> _parts = obj.getParts();
	m_parts.reset(new Bag<ocl::Types::NameTypeBinding>(*(obj.getParts().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TupleTypeImpl::copy() const
{
	std::shared_ptr<TupleTypeImpl> element(new TupleTypeImpl());
	*element =(*this);
	element->setThisTupleTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TupleTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getTupleType_Class();
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
/*
Getter & Setter for reference instance
*/
std::shared_ptr<ocl::Values::TupleValue> TupleTypeImpl::getInstance() const
{

    return m_instance;
}
void TupleTypeImpl::setInstance(std::shared_ptr<ocl::Values::TupleValue> _instance)
{
    m_instance = _instance;
}


/*
Getter & Setter for reference parts
*/
std::shared_ptr<Bag<ocl::Types::NameTypeBinding>> TupleTypeImpl::getParts() const
{
	if(m_parts == nullptr)
	{
		m_parts.reset(new Bag<ocl::Types::NameTypeBinding>());
		
		
	}

    return m_parts;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<TupleType> TupleTypeImpl::getThisTupleTypePtr() const
{
	return m_thisTupleTypePtr.lock();
}
void TupleTypeImpl::setThisTupleTypePtr(std::weak_ptr<TupleType> thisTupleTypePtr)
{
	m_thisTupleTypePtr = thisTupleTypePtr;
	setThisEDataTypePtr(thisTupleTypePtr);
}
std::shared_ptr<ecore::EObject> TupleTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TupleTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_INSTANCE:
			return eAny(getInstance()); //889
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_PARTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Types::NameTypeBinding>::iterator iter = getParts()->begin();
			Bag<ocl::Types::NameTypeBinding>::iterator end = getParts()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //8810			
		}
	}
	return ecore::EDataTypeImpl::eGet(featureID, resolve, coreType);
}
bool TupleTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_INSTANCE:
			return getInstance() != nullptr; //889
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_PARTS:
			return getParts() != nullptr; //8810
	}
	return ecore::EDataTypeImpl::internalEIsSet(featureID);
}
bool TupleTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_INSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::TupleValue> _instance = std::dynamic_pointer_cast<ocl::Values::TupleValue>(_temp);
			setInstance(_instance); //889
			return true;
		}
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_PARTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Types::NameTypeBinding>> partsList(new Bag<ocl::Types::NameTypeBinding>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				partsList->add(std::dynamic_pointer_cast<ocl::Types::NameTypeBinding>(*iter));
				iter++;
			}
			
			Bag<ocl::Types::NameTypeBinding>::iterator iterParts = getParts()->begin();
			Bag<ocl::Types::NameTypeBinding>::iterator endParts = getParts()->end();
			while (iterParts != endParts)
			{
				if (partsList->find(*iterParts) == -1)
				{
					getParts()->erase(*iterParts);
				}
				iterParts++;
			}
 
			iterParts = partsList->begin();
			endParts = partsList->end();
			while (iterParts != endParts)
			{
				if (getParts()->find(*iterParts) == -1)
				{
					getParts()->add(*iterParts);
				}
				iterParts++;			
			}
			return true;
		}
	}

	return ecore::EDataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TupleTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EDataTypeImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void TupleTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void TupleTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("instance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("instance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("parts");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parts")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EDataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void TupleTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::EDataTypeImpl::loadNode(nodeName, loadHandler);
}

void TupleTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_INSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::TupleValue> _instance = std::dynamic_pointer_cast<ocl::Values::TupleValue>( references.front() );
				setInstance(_instance);
			}
			
			return;
		}

		case ocl::Types::TypesPackage::TUPLETYPE_ATTRIBUTE_PARTS:
		{
			std::shared_ptr<Bag<ocl::Types::NameTypeBinding>> _parts = getParts();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Types::NameTypeBinding>  _r = std::dynamic_pointer_cast<ocl::Types::NameTypeBinding>(ref);
				if (_r != nullptr)
				{
					_parts->push_back(_r);
				}
			}
			return;
		}
	}
	ecore::EDataTypeImpl::resolveReferences(featureID, references);
}

void TupleTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EDataTypeImpl::saveContent(saveHandler);
	
	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void TupleTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Types::TypesPackage> package = ocl::Types::TypesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInstance(), "instance", getInstance()->eClass() != ocl::Values::ValuesPackage::eInstance()->getTupleValue_Class()); 
		saveHandler->addReferences<ocl::Types::NameTypeBinding>("parts", this->getParts());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


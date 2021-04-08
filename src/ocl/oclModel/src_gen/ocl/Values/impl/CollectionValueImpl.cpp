#include "ocl/Values/impl/CollectionValueImpl.hpp"

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
#include "ocl/Types/TypesFactory.hpp"
#include "ocl/Values/ValuesFactory.hpp"


#include "ocl/Types/CollectionType.hpp"
#include "ocl/Values/Element.hpp"
#include "ocl/Values/StaticValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
CollectionValueImpl::CollectionValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionValueImpl::~CollectionValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionValueImpl::CollectionValueImpl(const CollectionValueImpl & obj): CollectionValueImpl()
{
	*this = obj;
}

CollectionValueImpl& CollectionValueImpl::operator=(const CollectionValueImpl & obj)
{
	//call overloaded =Operator for each base class
	StaticValueImpl::operator=(obj);
	CollectionValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Values::Element>> _elements = obj.getElements();
	m_elements.reset(new Bag<ocl::Values::Element>(*(obj.getElements().get())));
	m_model  = obj.getModel();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionValueImpl::copy() const
{
	std::shared_ptr<CollectionValueImpl> element(new CollectionValueImpl());
	*element =(*this);
	element->setThisCollectionValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollectionValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getCollectionValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CollectionValueImpl::addValue(std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollectionValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(otherValue != nullptr)
    {
        std::shared_ptr<ocl::Values::CollectionValue> otherBag = std::dynamic_pointer_cast<ocl::Values::CollectionValue>(otherValue);

	if(otherBag != nullptr && otherBag->getModel() != nullptr && 
           this->getModel()->kindOf(otherBag->getModel()) &&
           otherBag->getElements()->size() == this->getElements()->size()) {

           for(size_t i = 0; i < this->getElements()->size(); i++) {
                auto item1 = this->getElements()->at(i)->getValue();
                auto item2 = otherBag->getElements()->at(i)->getValue();
                
                if(!item1->equals(item2)) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
   
	//end of body
}

bool CollectionValueImpl::find(std::shared_ptr<fUML::Semantics::Values::Value> value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (Bag<ocl::Values::Element>::const_iterator it_elem = this->getElements()->begin(); it_elem != this->getElements()->end(); ++it_elem)
    {
        if ((*it_elem)->getValue()->equals(value)) {
            return true;
        }
    }
    return false;
	//end of body
}

std::string CollectionValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::string result = "";

Bag<Element>::const_iterator endIt_elem = this->getElements()->end();
for (Bag<Element>::const_iterator it_reference = this->getElements()->begin();
	 it_reference != endIt_elem; ++it_reference)
{
       if(!result.empty()) {
            result += "\n";
        }
	result += (*it_reference)->getValue()->toString();
}
return result;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference elements
*/
std::shared_ptr<Bag<ocl::Values::Element>> CollectionValueImpl::getElements() const
{
	if(m_elements == nullptr)
	{
		m_elements.reset(new Bag<ocl::Values::Element>());
		
		
	}

    return m_elements;
}



/*
Getter & Setter for reference model
*/
std::shared_ptr<ocl::Types::CollectionType> CollectionValueImpl::getModel() const
{
//assert(m_model);
    return m_model;
}
void CollectionValueImpl::setModel(std::shared_ptr<ocl::Types::CollectionType> _model)
{
    m_model = _model;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CollectionValue> CollectionValueImpl::getThisCollectionValuePtr() const
{
	return m_thisCollectionValuePtr.lock();
}
void CollectionValueImpl::setThisCollectionValuePtr(std::weak_ptr<CollectionValue> thisCollectionValuePtr)
{
	m_thisCollectionValuePtr = thisCollectionValuePtr;
	setThisStaticValuePtr(thisCollectionValuePtr);
}
std::shared_ptr<ecore::EObject> CollectionValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CollectionValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Values::Element>::iterator iter = m_elements->begin();
			Bag<ocl::Values::Element>::iterator end = m_elements->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //210
		}
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_MODEL:
			return eAny(getModel()); //211
	}
	return StaticValueImpl::eGet(featureID, resolve, coreType);
}
bool CollectionValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
			return getElements() != nullptr; //210
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_MODEL:
			return getModel() != nullptr; //211
	}
	return StaticValueImpl::internalEIsSet(featureID);
}
bool CollectionValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::Element>> elementsList(new Bag<ocl::Values::Element>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				elementsList->add(std::dynamic_pointer_cast<ocl::Values::Element>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::Element>::iterator iterElements = m_elements->begin();
			Bag<ocl::Values::Element>::iterator endElements = m_elements->end();
			while (iterElements != endElements)
			{
				if (elementsList->find(*iterElements) == -1)
				{
					m_elements->erase(*iterElements);
				}
				iterElements++;
			}
 
			iterElements = elementsList->begin();
			endElements = elementsList->end();
			while (iterElements != endElements)
			{
				if (m_elements->find(*iterElements) == -1)
				{
					m_elements->add(*iterElements);
				}
				iterElements++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_MODEL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Types::CollectionType> _model = std::dynamic_pointer_cast<ocl::Types::CollectionType>(_temp);
			setModel(_model); //211
			return true;
		}
	}

	return StaticValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CollectionValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("elements");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("elements")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("model");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("model")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StaticValueImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StaticValueImpl::loadNode(nodeName, loadHandler);
}

void CollectionValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_ELEMENTS:
		{
			std::shared_ptr<Bag<ocl::Values::Element>> _elements = getElements();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::Element>  _r = std::dynamic_pointer_cast<ocl::Values::Element>(ref);
				if (_r != nullptr)
				{
					_elements->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::COLLECTIONVALUE_ATTRIBUTE_MODEL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Types::CollectionType> _model = std::dynamic_pointer_cast<ocl::Types::CollectionType>( references.front() );
				setModel(_model);
			}
			
			return;
		}
	}
	StaticValueImpl::resolveReferences(featureID, references);
}

void CollectionValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StaticValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CollectionValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Values::Element>("elements", this->getElements());
		saveHandler->addReference(this->getModel(), "model", getModel()->eClass() != ocl::Types::TypesPackage::eInstance()->getCollectionType_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


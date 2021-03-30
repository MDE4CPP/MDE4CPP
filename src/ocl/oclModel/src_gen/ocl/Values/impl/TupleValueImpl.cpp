#include "ocl/Values/impl/TupleValueImpl.hpp"

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


#include "ocl/Values/NameValueBinding.hpp"
#include "ocl/Values/StaticValue.hpp"
#include "ocl/Types/TupleType.hpp"
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
TupleValueImpl::TupleValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleValueImpl::~TupleValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TupleValueImpl::TupleValueImpl(const TupleValueImpl & obj): TupleValueImpl()
{
	*this = obj;
}

TupleValueImpl& TupleValueImpl::operator=(const TupleValueImpl & obj)
{
	//call overloaded =Operator for each base class
	StaticValueImpl::operator=(obj);
	TupleValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _elements = obj.getElements();
	m_elements.reset(new Bag<ocl::Values::NameValueBinding>(*(obj.getElements().get())));
	m_model  = obj.getModel();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TupleValueImpl::copy() const
{
	std::shared_ptr<TupleValueImpl> element(new TupleValueImpl());
	*element =(*this);
	element->setThisTupleValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TupleValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getTupleValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TupleValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(otherValue != nullptr)
    {
        std::shared_ptr<ocl::Values::TupleValue> otherBag = std::dynamic_pointer_cast<ocl::Values::TupleValue>(otherValue);

	if(otherBag != nullptr && otherBag->getElements()->size() == this->getElements()->size()) {

           for(size_t i = 0; i < this->getElements()->size(); i++) {
                auto item1 = this->getElements()->at(i);
                auto item2 = otherBag->getElements()->at(i);
                
                if(item1->getName() != item2->getName() || !item1->getValue()->equals(item2->getValue())) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
   
	//end of body
}

std::string TupleValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::string result = "";

Bag<NameValueBinding>::const_iterator endIt_elem = this->getElements()->end();
for (Bag<NameValueBinding>::const_iterator it_reference = this->getElements()->begin();
	 it_reference != endIt_elem; ++it_reference)
{
       if(!result.empty()) {
            result += "\n";
        }
	result += (*it_reference)->getName() + " : " + (*it_reference)->getValue()->toString();
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
std::shared_ptr<Bag<ocl::Values::NameValueBinding>> TupleValueImpl::getElements() const
{
	if(m_elements == nullptr)
	{
		m_elements.reset(new Bag<ocl::Values::NameValueBinding>());
		
		
	}

    return m_elements;
}



/*
Getter & Setter for reference model
*/
std::shared_ptr<ocl::Types::TupleType> TupleValueImpl::getModel() const
{

    return m_model;
}
void TupleValueImpl::setModel(std::shared_ptr<ocl::Types::TupleType> _model)
{
    m_model = _model;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<TupleValue> TupleValueImpl::getThisTupleValuePtr() const
{
	return m_thisTupleValuePtr.lock();
}
void TupleValueImpl::setThisTupleValuePtr(std::weak_ptr<TupleValue> thisTupleValuePtr)
{
	m_thisTupleValuePtr = thisTupleValuePtr;
	setThisStaticValuePtr(thisTupleValuePtr);
}
std::shared_ptr<ecore::EObject> TupleValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TupleValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_ELEMENTS:
		{
			return eAny(getElements()); //890			
		}
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_MODEL:
			return eAny(getModel()); //891
	}
	return StaticValueImpl::eGet(featureID, resolve, coreType);
}
bool TupleValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_ELEMENTS:
			return getElements() != nullptr; //890
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_MODEL:
			return getModel() != nullptr; //891
	}
	return StaticValueImpl::internalEIsSet(featureID);
}
bool TupleValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_ELEMENTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> elementsList(new Bag<ocl::Values::NameValueBinding>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				elementsList->add(std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::NameValueBinding>::iterator iterElements = m_elements->begin();
			Bag<ocl::Values::NameValueBinding>::iterator endElements = m_elements->end();
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
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_MODEL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Types::TupleType> _model = std::dynamic_pointer_cast<ocl::Types::TupleType>(_temp);
			setModel(_model); //891
			return true;
		}
	}

	return StaticValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TupleValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TupleValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void TupleValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StaticValueImpl::loadNode(nodeName, loadHandler);
}

void TupleValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_ELEMENTS:
		{
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _elements = getElements();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::NameValueBinding>  _r = std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(ref);
				if (_r != nullptr)
				{
					_elements->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::TUPLEVALUE_ATTRIBUTE_MODEL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Types::TupleType> _model = std::dynamic_pointer_cast<ocl::Types::TupleType>( references.front() );
				setModel(_model);
			}
			
			return;
		}
	}
	StaticValueImpl::resolveReferences(featureID, references);
}

void TupleValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StaticValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void TupleValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Values::NameValueBinding>("elements", this->getElements());
		saveHandler->addReference(this->getModel(), "model", getModel()->eClass() != ocl::Types::TypesPackage::eInstance()->getTupleType_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


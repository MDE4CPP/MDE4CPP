#include "ocl/Values/impl/ObjectValueImpl.hpp"

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
#include "fUML/fUMLFactory.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/ETypedElement.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "uml/TypedElement.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Type.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ocl/Values/ValuesFactory.hpp"


#include "ecore/EObject.hpp"
#include "ocl/Values/LocalSnapshot.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
ObjectValueImpl::ObjectValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectValueImpl::~ObjectValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ObjectValueImpl::ObjectValueImpl(const ObjectValueImpl & obj): ObjectValueImpl()
{
	*this = obj;
}

ObjectValueImpl& ObjectValueImpl::operator=(const ObjectValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	ObjectValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> _history = obj.getHistory();
	m_history.reset(new Bag<ocl::Values::LocalSnapshot>(*(obj.getHistory().get())));
	m_value  = obj.getValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectValueImpl::copy() const
{
	std::shared_ptr<ObjectValueImpl> element(new ObjectValueImpl());
	*element =(*this);
	element->setThisObjectValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getObjectValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ObjectValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == this->eClass()->getClassifierID()) {
        std::shared_ptr<ocl::Values::ObjectValue> otherObj = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(otherValue);
        return otherObj != nullptr && otherObj->getValue().get() == this->getValue().get();
    }
    return false;
   
	//end of body
}

std::string ObjectValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(m_value != nullptr) {
        uml::NamedElement* uname = dynamic_cast<uml::NamedElement*>(m_value.get());
        if(uname != nullptr) {
            uml::Operation* uope = dynamic_cast<uml::Operation*>(m_value.get());
            if(uope != nullptr) {
                std::string result = "<Operation> " + uope->getName() + "(";
                Bag<uml::Parameter>* ebag = dynamic_cast<Bag<uml::Parameter>*>(uope->getOwnedParameter().get());
                for(unsigned int i = 0; i < ebag->size(); i++) {
                    if(i > 0) result += ", ";
                    result += ebag->at(i)->getName() + " : ";
                    if(ebag->at(i)->getType() != nullptr) {
                        if(ebag->at(i)->getUpper() > 1 || ebag->at(i)->getUpper() < 0)
                            result += ebag->at(i)->getType()->getName()+ " ["
                                +  std::to_string(ebag->at(i)->getLower()) + "..*]";
                        else
                            result += ebag->at(i)->getType()->getName()+ " ["
                                +  std::to_string(ebag->at(i)->getLower()) + ".." + std::to_string(ebag->at(i)->getUpper()) + "]";
                    }
                    else
                        result += "[Not set in Model]";
                }
                result += ")";
                return result;
            }
            uml::Property* uprop = dynamic_cast<uml::Property*>(m_value.get());
            if(uprop != nullptr) {
                if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
                    return "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                        +  std::to_string(uprop->getLower()) + "..*]";
                else
                    return "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                        +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]";
            }
            uml::TypedElement* utyped = dynamic_cast<uml::TypedElement*>(m_value.get());
            if(utyped != nullptr) {
                return utyped->getName() + " : " + utyped->getType()->getName();
            }
            return uname->getName();
        }

        ecore::EOperation* eope = dynamic_cast<ecore::EOperation*>(m_value.get());
        if(eope != nullptr) {
            std::string result = eope->getName() + "(";
            Bag<ecore::EParameter>* ebag = dynamic_cast<Bag<ecore::EParameter>*>(eope->getEParameters().get());
            for(unsigned int i = 0; i < ebag->size(); i++) {
                if(i > 0) result += ", ";
                result += ebag->at(i)->getName() + " : ";
                if(ebag->at(i)->getEType() != nullptr)
                    result += ebag->at(i)->getEType()->getName();
                else
                    result += "[Not set in Model]";
            }
            result += ")";
            return result;
        }
        ecore::EAttribute* eattr = dynamic_cast<ecore::EAttribute*>(m_value.get());
        if(eattr != nullptr) {
            if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
                return "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " ["
                    +  std::to_string(eattr->getLowerBound()) + "..*]";
            else
                return "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " ["
                        +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]";
        }
        ecore::EReference* eref = dynamic_cast<ecore::EReference*>(m_value.get());
        if(eref != nullptr) {
            if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
                return "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " ["
                    +  std::to_string(eref->getLowerBound()) + "..*]";
            else
                return "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " ["
                    +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]";
        }
        ecore::ETypedElement* etyped = dynamic_cast<ecore::ETypedElement*>(m_value.get());
        if(etyped != nullptr) {
            if(etyped->isMany())
                return etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..*]";
            else
                return etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..1]";
        }
        ecore::ENamedElement* ename = dynamic_cast<ecore::ENamedElement*>(m_value.get());
        if(ename != nullptr) {
            return ename->getName();
        }
    }
    return "";
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference history
*/
std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> ObjectValueImpl::getHistory() const
{
	if(m_history == nullptr)
	{
		m_history.reset(new Bag<ocl::Values::LocalSnapshot>());
		
		
	}

    return m_history;
}



/*
Getter & Setter for reference value
*/
std::shared_ptr<ecore::EObject> ObjectValueImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void ObjectValueImpl::setValue(std::shared_ptr<ecore::EObject> _value)
{
    m_value = _value;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<ObjectValue> ObjectValueImpl::getThisObjectValuePtr() const
{
	return m_thisObjectValuePtr.lock();
}
void ObjectValueImpl::setThisObjectValuePtr(std::weak_ptr<ObjectValue> thisObjectValuePtr)
{
	m_thisObjectValuePtr = thisObjectValuePtr;
	setThisValuePtr(thisObjectValuePtr);
}
std::shared_ptr<ecore::EObject> ObjectValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ObjectValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_HISTORY:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Values::LocalSnapshot>::iterator iter = getHistory()->begin();
			Bag<ocl::Values::LocalSnapshot>::iterator end = getHistory()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //580			
		}
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue()); //581
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}
bool ObjectValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_HISTORY:
			return getHistory() != nullptr; //580
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //581
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}
bool ObjectValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_HISTORY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> historyList(new Bag<ocl::Values::LocalSnapshot>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				historyList->add(std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::LocalSnapshot>::iterator iterHistory = getHistory()->begin();
			Bag<ocl::Values::LocalSnapshot>::iterator endHistory = getHistory()->end();
			while (iterHistory != endHistory)
			{
				if (historyList->find(*iterHistory) == -1)
				{
					getHistory()->erase(*iterHistory);
				}
				iterHistory++;
			}
 
			iterHistory = historyList->begin();
			endHistory = historyList->end();
			while (iterHistory != endHistory)
			{
				if (getHistory()->find(*iterHistory) == -1)
				{
					getHistory()->add(*iterHistory);
				}
				iterHistory++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EObject> _value = std::dynamic_pointer_cast<ecore::EObject>(_temp);
			setValue(_value); //581
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ObjectValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5813
		case ValuesPackage::OBJECTVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue));
			break;
		}
		
		// 5812
		case ValuesPackage::OBJECTVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
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
void ObjectValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("history");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("history")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void ObjectValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_HISTORY:
		{
			std::shared_ptr<Bag<ocl::Values::LocalSnapshot>> _history = getHistory();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::LocalSnapshot>  _r = std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>(ref);
				if (_r != nullptr)
				{
					_history->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::OBJECTVALUE_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EObject> _value = std::dynamic_pointer_cast<ecore::EObject>( references.front() );
				setValue(_value);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void ObjectValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ObjectValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Values::LocalSnapshot>("history", this->getHistory());
		saveHandler->addReference(this->getValue(),"value", getValue()->eClass() != ecore::ecorePackage::eInstance()->getEObject_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


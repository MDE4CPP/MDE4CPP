#include "ocl/Values/impl/OclMessageValueImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Values/ValuesFactory.hpp"


#include "ocl/Values/NameValueBinding.hpp"
#include "ocl/Values/ObjectValue.hpp"
#include "ocl/Values/OclMessageValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
OclMessageValueImpl::OclMessageValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclMessageValueImpl::~OclMessageValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclMessageValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclMessageValueImpl::OclMessageValueImpl(const OclMessageValueImpl & obj): OclMessageValueImpl()
{
	*this = obj;
}

OclMessageValueImpl& OclMessageValueImpl::operator=(const OclMessageValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	OclMessageValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclMessageValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isAsyncOperation = obj.getIsAsyncOperation();
	m_isSignal = obj.getIsSignal();
	m_isSyncOperation = obj.getIsSyncOperation();
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _arguments = obj.getArguments();
	m_arguments.reset(new Bag<ocl::Values::NameValueBinding>(*(obj.getArguments().get())));
	m_returnMessage  = obj.getReturnMessage();
	m_source  = obj.getSource();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclMessageValueImpl::copy() const
{
	std::shared_ptr<OclMessageValueImpl> element(new OclMessageValueImpl());
	*element =(*this);
	element->setThisOclMessageValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OclMessageValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getOclMessageValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isAsyncOperation
*/
bool OclMessageValueImpl::getIsAsyncOperation() const 
{
	return m_isAsyncOperation;
}
void OclMessageValueImpl::setIsAsyncOperation(bool _isAsyncOperation)
{
	m_isAsyncOperation = _isAsyncOperation;
	
} 


/*
Getter & Setter for attribute isSignal
*/
bool OclMessageValueImpl::getIsSignal() const 
{
	return m_isSignal;
}
void OclMessageValueImpl::setIsSignal(bool _isSignal)
{
	m_isSignal = _isSignal;
	
} 


/*
Getter & Setter for attribute isSyncOperation
*/
bool OclMessageValueImpl::getIsSyncOperation() const 
{
	return m_isSyncOperation;
}
void OclMessageValueImpl::setIsSyncOperation(bool _isSyncOperation)
{
	m_isSyncOperation = _isSyncOperation;
	
} 


/*
Getter & Setter for attribute name
*/
std::string OclMessageValueImpl::getName() const 
{
	return m_name;
}
void OclMessageValueImpl::setName(std::string _name)
{
	m_name = _name;
	
} 


//*********************************
// Operations
//*********************************
std::string OclMessageValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "";
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference arguments
*/
std::shared_ptr<Bag<ocl::Values::NameValueBinding>> OclMessageValueImpl::getArguments() const
{
	if(m_arguments == nullptr)
	{
		m_arguments.reset(new Bag<ocl::Values::NameValueBinding>());
		
		
	}

    return m_arguments;
}



/*
Getter & Setter for reference returnMessage
*/
std::shared_ptr<ocl::Values::OclMessageValue> OclMessageValueImpl::getReturnMessage() const
{

    return m_returnMessage;
}
void OclMessageValueImpl::setReturnMessage(std::shared_ptr<ocl::Values::OclMessageValue> _returnMessage)
{
    m_returnMessage = _returnMessage;
	
}


/*
Getter & Setter for reference source
*/
std::shared_ptr<ocl::Values::ObjectValue> OclMessageValueImpl::getSource() const
{

    return m_source;
}
void OclMessageValueImpl::setSource(std::shared_ptr<ocl::Values::ObjectValue> _source)
{
    m_source = _source;
	
}


/*
Getter & Setter for reference target
*/
std::shared_ptr<ocl::Values::ObjectValue> OclMessageValueImpl::getTarget() const
{

    return m_target;
}
void OclMessageValueImpl::setTarget(std::shared_ptr<ocl::Values::ObjectValue> _target)
{
    m_target = _target;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<OclMessageValue> OclMessageValueImpl::getThisOclMessageValuePtr() const
{
	return m_thisOclMessageValuePtr.lock();
}
void OclMessageValueImpl::setThisOclMessageValuePtr(std::weak_ptr<OclMessageValue> thisOclMessageValuePtr)
{
	m_thisOclMessageValuePtr = thisOclMessageValuePtr;
	setThisValuePtr(thisOclMessageValuePtr);
}
std::shared_ptr<ecore::EObject> OclMessageValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OclMessageValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ARGUMENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Values::NameValueBinding>::iterator iter = getArguments()->begin();
			Bag<ocl::Values::NameValueBinding>::iterator end = getArguments()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //637			
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISASYNCOPERATION:
			return eAny(getIsAsyncOperation()); //632
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSIGNAL:
			return eAny(getIsSignal()); //633
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSYNCOPERATION:
			return eAny(getIsSyncOperation()); //631
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_NAME:
			return eAny(getName()); //630
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_RETURNMESSAGE:
			return eAny(getReturnMessage()); //634
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_SOURCE:
			return eAny(getSource()); //636
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_TARGET:
			return eAny(getTarget()); //635
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}
bool OclMessageValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ARGUMENTS:
			return getArguments() != nullptr; //637
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISASYNCOPERATION:
			return getIsAsyncOperation() != false; //632
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSIGNAL:
			return getIsSignal() != false; //633
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSYNCOPERATION:
			return getIsSyncOperation() != false; //631
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_NAME:
			return getName() != ""; //630
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_RETURNMESSAGE:
			return getReturnMessage() != nullptr; //634
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_SOURCE:
			return getSource() != nullptr; //636
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //635
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}
bool OclMessageValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ARGUMENTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> argumentsList(new Bag<ocl::Values::NameValueBinding>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				argumentsList->add(std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::NameValueBinding>::iterator iterArguments = getArguments()->begin();
			Bag<ocl::Values::NameValueBinding>::iterator endArguments = getArguments()->end();
			while (iterArguments != endArguments)
			{
				if (argumentsList->find(*iterArguments) == -1)
				{
					getArguments()->erase(*iterArguments);
				}
				iterArguments++;
			}
 
			iterArguments = argumentsList->begin();
			endArguments = argumentsList->end();
			while (iterArguments != endArguments)
			{
				if (getArguments()->find(*iterArguments) == -1)
				{
					getArguments()->add(*iterArguments);
				}
				iterArguments++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISASYNCOPERATION:
		{
			// BOOST CAST
			bool _isAsyncOperation = newValue->get<bool>();
			setIsAsyncOperation(_isAsyncOperation); //632
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSIGNAL:
		{
			// BOOST CAST
			bool _isSignal = newValue->get<bool>();
			setIsSignal(_isSignal); //633
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ISSYNCOPERATION:
		{
			// BOOST CAST
			bool _isSyncOperation = newValue->get<bool>();
			setIsSyncOperation(_isSyncOperation); //631
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = newValue->get<std::string>();
			setName(_name); //630
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_RETURNMESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::OclMessageValue> _returnMessage = std::dynamic_pointer_cast<ocl::Values::OclMessageValue>(_temp);
			setReturnMessage(_returnMessage); //634
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::ObjectValue> _source = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(_temp);
			setSource(_source); //636
			return true;
		}
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::ObjectValue> _target = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(_temp);
			setTarget(_target); //635
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OclMessageValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 6318
		case ValuesPackage::OCLMESSAGEVALUE_OPERATION_TOSTRING:
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
void OclMessageValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclMessageValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isAsyncOperation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAsyncOperation(value);
		}

		iter = attr_list.find("isSignal");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSignal(value);
		}

		iter = attr_list.find("isSyncOperation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSyncOperation(value);
		}

		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("arguments");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("arguments")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("returnMessage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("returnMessage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("source")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void OclMessageValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void OclMessageValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_ARGUMENTS:
		{
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _arguments = getArguments();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::NameValueBinding>  _r = std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(ref);
				if (_r != nullptr)
				{
					_arguments->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_RETURNMESSAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::OclMessageValue> _returnMessage = std::dynamic_pointer_cast<ocl::Values::OclMessageValue>( references.front() );
				setReturnMessage(_returnMessage);
			}
			
			return;
		}

		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_SOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::ObjectValue> _source = std::dynamic_pointer_cast<ocl::Values::ObjectValue>( references.front() );
				setSource(_source);
			}
			
			return;
		}

		case ocl::Values::ValuesPackage::OCLMESSAGEVALUE_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::ObjectValue> _target = std::dynamic_pointer_cast<ocl::Values::ObjectValue>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void OclMessageValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void OclMessageValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOclMessageValue_Attribute_isAsyncOperation()) )
		{
			saveHandler->addAttribute("isAsyncOperation", this->getIsAsyncOperation());
		}

		if ( this->eIsSet(package->getOclMessageValue_Attribute_isSignal()) )
		{
			saveHandler->addAttribute("isSignal", this->getIsSignal());
		}

		if ( this->eIsSet(package->getOclMessageValue_Attribute_isSyncOperation()) )
		{
			saveHandler->addAttribute("isSyncOperation", this->getIsSyncOperation());
		}

		if ( this->eIsSet(package->getOclMessageValue_Attribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}
	// Add references
		saveHandler->addReferences<ocl::Values::NameValueBinding>("arguments", this->getArguments());
		saveHandler->addReference(this->getReturnMessage(), "returnMessage", getReturnMessage()->eClass() != ocl::Values::ValuesPackage::eInstance()->getOclMessageValue_Class()); 
		saveHandler->addReference(this->getSource(), "source", getSource()->eClass() != ocl::Values::ValuesPackage::eInstance()->getObjectValue_Class()); 
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != ocl::Values::ValuesPackage::eInstance()->getObjectValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


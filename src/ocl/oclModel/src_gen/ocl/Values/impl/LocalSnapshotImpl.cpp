#include "ocl/Values/impl/LocalSnapshotImpl.hpp"

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


#include "ocl/Values/LocalSnapshot.hpp"
#include "ocl/Values/NameValueBinding.hpp"
#include "ocl/Values/OclMessageValue.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
LocalSnapshotImpl::LocalSnapshotImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LocalSnapshotImpl::~LocalSnapshotImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LocalSnapshot "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


LocalSnapshotImpl::LocalSnapshotImpl(const LocalSnapshotImpl & obj): LocalSnapshotImpl()
{
	*this = obj;
}

LocalSnapshotImpl& LocalSnapshotImpl::operator=(const LocalSnapshotImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	LocalSnapshot::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LocalSnapshot "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isPost = obj.getIsPost();
	m_isPre = obj.getIsPre();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _bindings = obj.getBindings();
	m_bindings.reset(new Bag<ocl::Values::NameValueBinding>(*(obj.getBindings().get())));
	std::shared_ptr<Bag<ocl::Values::OclMessageValue>> _inputQ = obj.getInputQ();
	m_inputQ.reset(new Bag<ocl::Values::OclMessageValue>(*(obj.getInputQ().get())));
	std::shared_ptr<Bag<ocl::Values::OclMessageValue>> _outputQ = obj.getOutputQ();
	m_outputQ.reset(new Bag<ocl::Values::OclMessageValue>(*(obj.getOutputQ().get())));
	m_pred  = obj.getPred();
	m_succ  = obj.getSucc();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LocalSnapshotImpl::copy() const
{
	std::shared_ptr<LocalSnapshotImpl> element(new LocalSnapshotImpl());
	*element =(*this);
	element->setThisLocalSnapshotPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LocalSnapshotImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getLocalSnapshot_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isPost
*/
bool LocalSnapshotImpl::getIsPost() const 
{
	return m_isPost;
}
void LocalSnapshotImpl::setIsPost(bool _isPost)
{
	m_isPost = _isPost;
} 


/*
Getter & Setter for attribute isPre
*/
bool LocalSnapshotImpl::getIsPre() const 
{
	return m_isPre;
}
void LocalSnapshotImpl::setIsPre(bool _isPre)
{
	m_isPre = _isPre;
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference bindings
*/
std::shared_ptr<Bag<ocl::Values::NameValueBinding>> LocalSnapshotImpl::getBindings() const
{
	if(m_bindings == nullptr)
	{
		m_bindings.reset(new Bag<ocl::Values::NameValueBinding>());
		
		
	}

    return m_bindings;
}



/*
Getter & Setter for reference inputQ
*/
std::shared_ptr<Bag<ocl::Values::OclMessageValue>> LocalSnapshotImpl::getInputQ() const
{
	if(m_inputQ == nullptr)
	{
		m_inputQ.reset(new Bag<ocl::Values::OclMessageValue>());
		
		
	}

    return m_inputQ;
}



/*
Getter & Setter for reference outputQ
*/
std::shared_ptr<Bag<ocl::Values::OclMessageValue>> LocalSnapshotImpl::getOutputQ() const
{
	if(m_outputQ == nullptr)
	{
		m_outputQ.reset(new Bag<ocl::Values::OclMessageValue>());
		
		
	}

    return m_outputQ;
}



/*
Getter & Setter for reference pred
*/
std::shared_ptr<ocl::Values::LocalSnapshot> LocalSnapshotImpl::getPred() const
{

    return m_pred;
}
void LocalSnapshotImpl::setPred(std::shared_ptr<ocl::Values::LocalSnapshot> _pred)
{
    m_pred = _pred;
}


/*
Getter & Setter for reference succ
*/
std::shared_ptr<ocl::Values::LocalSnapshot> LocalSnapshotImpl::getSucc() const
{

    return m_succ;
}
void LocalSnapshotImpl::setSucc(std::shared_ptr<ocl::Values::LocalSnapshot> _succ)
{
    m_succ = _succ;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<LocalSnapshot> LocalSnapshotImpl::getThisLocalSnapshotPtr() const
{
	return m_thisLocalSnapshotPtr.lock();
}
void LocalSnapshotImpl::setThisLocalSnapshotPtr(std::weak_ptr<LocalSnapshot> thisLocalSnapshotPtr)
{
	m_thisLocalSnapshotPtr = thisLocalSnapshotPtr;
}
std::shared_ptr<ecore::EObject> LocalSnapshotImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LocalSnapshotImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_BINDINGS:
		{
			return eAny(getBindings()); //452			
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_INPUTQ:
		{
			return eAny(getInputQ()); //455			
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPOST:
			return eAny(getIsPost()); //453
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPRE:
			return eAny(getIsPre()); //454
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_OUTPUTQ:
		{
			return eAny(getOutputQ()); //456			
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_PRED:
			return eAny(getPred()); //451
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_SUCC:
			return eAny(getSucc()); //450
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool LocalSnapshotImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_BINDINGS:
			return getBindings() != nullptr; //452
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_INPUTQ:
			return getInputQ() != nullptr; //455
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPOST:
			return getIsPost() != false; //453
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPRE:
			return getIsPre() != false; //454
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_OUTPUTQ:
			return getOutputQ() != nullptr; //456
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_PRED:
			return getPred() != nullptr; //451
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_SUCC:
			return getSucc() != nullptr; //450
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool LocalSnapshotImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_BINDINGS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> bindingsList(new Bag<ocl::Values::NameValueBinding>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				bindingsList->add(std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::NameValueBinding>::iterator iterBindings = m_bindings->begin();
			Bag<ocl::Values::NameValueBinding>::iterator endBindings = m_bindings->end();
			while (iterBindings != endBindings)
			{
				if (bindingsList->find(*iterBindings) == -1)
				{
					m_bindings->erase(*iterBindings);
				}
				iterBindings++;
			}
 
			iterBindings = bindingsList->begin();
			endBindings = bindingsList->end();
			while (iterBindings != endBindings)
			{
				if (m_bindings->find(*iterBindings) == -1)
				{
					m_bindings->add(*iterBindings);
				}
				iterBindings++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_INPUTQ:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::OclMessageValue>> inputQList(new Bag<ocl::Values::OclMessageValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputQList->add(std::dynamic_pointer_cast<ocl::Values::OclMessageValue>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::OclMessageValue>::iterator iterInputQ = m_inputQ->begin();
			Bag<ocl::Values::OclMessageValue>::iterator endInputQ = m_inputQ->end();
			while (iterInputQ != endInputQ)
			{
				if (inputQList->find(*iterInputQ) == -1)
				{
					m_inputQ->erase(*iterInputQ);
				}
				iterInputQ++;
			}
 
			iterInputQ = inputQList->begin();
			endInputQ = inputQList->end();
			while (iterInputQ != endInputQ)
			{
				if (m_inputQ->find(*iterInputQ) == -1)
				{
					m_inputQ->add(*iterInputQ);
				}
				iterInputQ++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPOST:
		{
			// BOOST CAST
			bool _isPost = newValue->get<bool>();
			setIsPost(_isPost); //453
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_ISPRE:
		{
			// BOOST CAST
			bool _isPre = newValue->get<bool>();
			setIsPre(_isPre); //454
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_OUTPUTQ:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Values::OclMessageValue>> outputQList(new Bag<ocl::Values::OclMessageValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputQList->add(std::dynamic_pointer_cast<ocl::Values::OclMessageValue>(*iter));
				iter++;
			}
			
			Bag<ocl::Values::OclMessageValue>::iterator iterOutputQ = m_outputQ->begin();
			Bag<ocl::Values::OclMessageValue>::iterator endOutputQ = m_outputQ->end();
			while (iterOutputQ != endOutputQ)
			{
				if (outputQList->find(*iterOutputQ) == -1)
				{
					m_outputQ->erase(*iterOutputQ);
				}
				iterOutputQ++;
			}
 
			iterOutputQ = outputQList->begin();
			endOutputQ = outputQList->end();
			while (iterOutputQ != endOutputQ)
			{
				if (m_outputQ->find(*iterOutputQ) == -1)
				{
					m_outputQ->add(*iterOutputQ);
				}
				iterOutputQ++;			
			}
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_PRED:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::LocalSnapshot> _pred = std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>(_temp);
			setPred(_pred); //451
			return true;
		}
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_SUCC:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Values::LocalSnapshot> _succ = std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>(_temp);
			setSucc(_succ); //450
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any LocalSnapshotImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
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
void LocalSnapshotImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LocalSnapshotImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isPost");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsPost(value);
		}

		iter = attr_list.find("isPre");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsPre(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bindings");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bindings")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("inputQ");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputQ")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outputQ");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outputQ")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("pred");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("pred")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("succ");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("succ")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LocalSnapshotImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void LocalSnapshotImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_BINDINGS:
		{
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _bindings = getBindings();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::NameValueBinding>  _r = std::dynamic_pointer_cast<ocl::Values::NameValueBinding>(ref);
				if (_r != nullptr)
				{
					_bindings->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_INPUTQ:
		{
			std::shared_ptr<Bag<ocl::Values::OclMessageValue>> _inputQ = getInputQ();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::OclMessageValue>  _r = std::dynamic_pointer_cast<ocl::Values::OclMessageValue>(ref);
				if (_r != nullptr)
				{
					_inputQ->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_OUTPUTQ:
		{
			std::shared_ptr<Bag<ocl::Values::OclMessageValue>> _outputQ = getOutputQ();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Values::OclMessageValue>  _r = std::dynamic_pointer_cast<ocl::Values::OclMessageValue>(ref);
				if (_r != nullptr)
				{
					_outputQ->push_back(_r);
				}
			}
			return;
		}

		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_PRED:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::LocalSnapshot> _pred = std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>( references.front() );
				setPred(_pred);
			}
			
			return;
		}

		case ocl::Values::ValuesPackage::LOCALSNAPSHOT_ATTRIBUTE_SUCC:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Values::LocalSnapshot> _succ = std::dynamic_pointer_cast<ocl::Values::LocalSnapshot>( references.front() );
				setSucc(_succ);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void LocalSnapshotImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void LocalSnapshotImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getLocalSnapshot_Attribute_isPost()) )
		{
			saveHandler->addAttribute("isPost", this->getIsPost());
		}

		if ( this->eIsSet(package->getLocalSnapshot_Attribute_isPre()) )
		{
			saveHandler->addAttribute("isPre", this->getIsPre());
		}
	// Add references
		saveHandler->addReferences<ocl::Values::NameValueBinding>("bindings", this->getBindings());
		saveHandler->addReferences<ocl::Values::OclMessageValue>("inputQ", this->getInputQ());
		saveHandler->addReferences<ocl::Values::OclMessageValue>("outputQ", this->getOutputQ());
		saveHandler->addReference(this->getPred(), "pred", getPred()->eClass() != ocl::Values::ValuesPackage::eInstance()->getLocalSnapshot_Class()); 
		saveHandler->addReference(this->getSucc(), "succ", getSucc()->eClass() != ocl::Values::ValuesPackage::eInstance()->getLocalSnapshot_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


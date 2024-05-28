
#include "ocl/Expressions/impl/LoopExpImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/VarDeclarationExp.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
LoopExpImpl::LoopExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopExpImpl::~LoopExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:LoopExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
		m_elseOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
		m_ifOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
		m_thenOwner = par_IfExp;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:LoopExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
		m_firstOwner = par_CollectionRange;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
		m_lastOwner = par_CollectionRange;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}



//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:LoopExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPBODYOWNER:
		m_loopBodyOwner = par_LoopExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LOOPEXP:
		m_loopExp = par_LoopExp;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:LoopExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:LoopExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
LoopExpImpl::LoopExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:LoopExpImpl()
{
	m_topExpression = par_topExpression;
}

LoopExpImpl::LoopExpImpl(const LoopExpImpl & obj): LoopExpImpl()
{
	*this = obj;
}

LoopExpImpl& LoopExpImpl::operator=(const LoopExpImpl & obj)
{
	//call overloaded =Operator for each base class
	CallExpImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LoopExp 
	 * which is generated by the compiler (as LoopExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LoopExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isCollectionOperation = obj.isIsCollectionOperation();
	m_isImplCollectIterator = obj.isIsImplCollectIterator();
	m_iterName = obj.getIterName();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'body'
	if(obj.getBody()!=nullptr)
	{
		m_body = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getBody()->copy());
	}

	//clone reference 'iterator'
	const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& iteratorList = obj.getIterator();
	if(iteratorList)
	{
		m_iterator.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
		for(const std::shared_ptr<ocl::Expressions::OclExpression>& iteratorindexElem: *iteratorList) 
		{
			const std::shared_ptr<ocl::Expressions::OclExpression>& temp = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>((iteratorindexElem)->copy());
			m_iterator->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for iterator.")
	}
	
	
	return *this;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isCollectionOperation */
bool LoopExpImpl::isIsCollectionOperation() const 
{
	return m_isCollectionOperation;
}
void LoopExpImpl::setIsCollectionOperation(bool _isCollectionOperation)
{
	m_isCollectionOperation = _isCollectionOperation;
	
}

/* Getter & Setter for attribute isImplCollectIterator */
bool LoopExpImpl::isIsImplCollectIterator() const 
{
	return m_isImplCollectIterator;
}
void LoopExpImpl::setIsImplCollectIterator(bool _isImplCollectIterator)
{
	m_isImplCollectIterator = _isImplCollectIterator;
	
}

/* Getter & Setter for attribute iterName */
std::string LoopExpImpl::getIterName() const 
{
	return m_iterName;
}
void LoopExpImpl::setIterName(std::string _iterName)
{
	m_iterName = _iterName;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference body */
const std::shared_ptr<ocl::Expressions::OclExpression>& LoopExpImpl::getBody() const
{
    return m_body;
}
void LoopExpImpl::setBody(const std::shared_ptr<ocl::Expressions::OclExpression>& _body)
{
    m_body = _body;
	
}

/* Getter & Setter for reference iterator */
const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& LoopExpImpl::getIterator() const
{
	if(m_iterator == nullptr)
	{
		m_iterator.reset(new Bag<ocl::Expressions::OclExpression>());
		
		
	}
    return m_iterator;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LoopExpImpl::eContainer() const
{
	if(auto wp = m_elseOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_ifOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_thenOwner.lock())
	{
		return wp;
	}

	if(auto wp = m_firstOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_lastOwner.lock())
	{
		return wp;
	}



	if(auto wp = m_loopBodyOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_loopExp.lock())
	{
		return wp;
	}


	if(auto wp = m_parentCall.lock())
	{
		return wp;
	}

	if(auto wp = m_parentNav.lock())
	{
		return wp;
	}


	if(auto wp = m_topExpression.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void LoopExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LoopExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCollectionOperation");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCollectionOperation(value);
		}

		iter = attr_list.find("isImplCollectIterator");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsImplCollectIterator(value);
		}

		iter = attr_list.find("iterName");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setIterName(value);
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

	CallExpImpl::loadAttributes(loadHandler, attr_list);
}

void LoopExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("body") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("ocl::Expressions/]"))
				{
					typeName = "ocl::Expressions::"+typeName;
				}
			}
			loadHandler->handleChild(this->getBody()); 

			return; 
		}

		if ( nodeName.compare("iterator") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("ocl::Expressions/]"))
				{
					typeName = "ocl::Expressions::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<ocl::Expressions::OclExpression> new_iterator = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(modelFactory->create(typeName, loadHandler->getCurrentObject(), ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR));
			if(new_iterator)
			{
				loadHandler->handleChild(new_iterator);
				getIterator()->push_back(new_iterator);
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
	CallExpImpl::loadNode(nodeName, loadHandler);
}

void LoopExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	CallExpImpl::resolveReferences(featureID, references);
}

void LoopExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LoopExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getLoopExp_Attribute_isCollectionOperation()) )
          {
			saveHandler->addAttribute("isCollectionOperation", this->isIsCollectionOperation());
          }

          if ( this->eIsSet(package->getLoopExp_Attribute_isImplCollectIterator()) )
          {
			saveHandler->addAttribute("isImplCollectIterator", this->isIsImplCollectIterator());
          }

          if ( this->eIsSet(package->getLoopExp_Attribute_iterName()) )
          {
			saveHandler->addAttribute("iterName", this->getIterName());
          }
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'body'
	    if ( this->eIsSet(package->getLoopExp_Attribute_body()) )
	    {
		saveHandler->addReference(this->getBody(), "body", getBody()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	    }

		// Save 'iterator'
	    if ( this->eIsSet(package->getLoopExp_Attribute_iterator()) )
	    {
		saveHandler->addReferences<ocl::Expressions::OclExpression>("iterator", this->getIterator());
	    }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& LoopExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getLoopExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LoopExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:
			return eAny(getBody(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS,false); //4624
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISCOLLECTIONOPERATION:
			return eAny(isIsCollectionOperation(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //4627
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISIMPLCOLLECTITERATOR:
			return eAny(isIsImplCollectIterator(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //4628
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERNAME:
			return eAny(getIterName(),ecore::ecorePackage::ESTRING_CLASS,false); //4626
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:
			return eEcoreContainerAny(getIterator(),ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_CLASS); //4625
	}
	return CallExpImpl::eGet(featureID, resolve, coreType);
}

bool LoopExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:
			return getBody() != nullptr; //4624
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISCOLLECTIONOPERATION:
			return isIsCollectionOperation() != false; //4627
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISIMPLCOLLECTITERATOR:
			return isIsImplCollectIterator() != false; //4628
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERNAME:
			return getIterName() != ""; //4626
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:
			return getIterator() != nullptr; //4625
	}
	return CallExpImpl::internalEIsSet(featureID);
}

bool LoopExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_BODY:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ocl::Expressions::OclExpression> _body = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(eObject);
					if(_body)
					{
						setBody(_body); //4624
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'body'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'body'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISCOLLECTIONOPERATION:
		{
			try
			{
				bool _isCollectionOperation = newValue->get<bool>();
				setIsCollectionOperation(_isCollectionOperation); //4627
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isCollectionOperation'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ISIMPLCOLLECTITERATOR:
		{
			try
			{
				bool _isImplCollectIterator = newValue->get<bool>();
				setIsImplCollectIterator(_isImplCollectIterator); //4628
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isImplCollectIterator'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERNAME:
		{
			try
			{
				std::string _iterName = newValue->get<std::string>();
				setIterName(_iterName); //4626
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'iterName'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::LOOPEXP_ATTRIBUTE_ITERATOR:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ocl::Expressions::OclExpression>>& _iterator = getIterator();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::OclExpression> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_iterator->includes(valueToAdd)))
								{
									_iterator->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'iterator'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'iterator'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return CallExpImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LoopExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CallExpImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::LoopExp> LoopExpImpl::getThisLoopExpPtr() const
{
	return m_thisLoopExpPtr.lock();
}
void LoopExpImpl::setThisLoopExpPtr(std::weak_ptr<ocl::Expressions::LoopExp> thisLoopExpPtr)
{
	m_thisLoopExpPtr = thisLoopExpPtr;
	setThisCallExpPtr(thisLoopExpPtr);
}




#include "ocl/Expressions/impl/PackageDeclarationExpImpl.hpp"
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
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ocl/Expressions/ContextDeclarationExp.hpp"
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
PackageDeclarationExpImpl::PackageDeclarationExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PackageDeclarationExpImpl::~PackageDeclarationExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageDeclarationExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:PackageDeclarationExpImpl()
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
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:PackageDeclarationExpImpl()
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
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_LoopExp, const int reference_id)
:PackageDeclarationExpImpl()
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
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:PackageDeclarationExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:PackageDeclarationExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
PackageDeclarationExpImpl::PackageDeclarationExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:PackageDeclarationExpImpl()
{
	m_topExpression = par_topExpression;
}

PackageDeclarationExpImpl::PackageDeclarationExpImpl(const PackageDeclarationExpImpl & obj): PackageDeclarationExpImpl()
{
	*this = obj;
}

PackageDeclarationExpImpl& PackageDeclarationExpImpl::operator=(const PackageDeclarationExpImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpressionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PackageDeclarationExp 
	 * which is generated by the compiler (as PackageDeclarationExp is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PackageDeclarationExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageDeclarationExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_path = obj.getPath();

	//copy references with no containment (soft copy)
	m_contextDeclarations  = obj.getContextDeclarations();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PackageDeclarationExpImpl::copy() const
{
	std::shared_ptr<PackageDeclarationExpImpl> element(new PackageDeclarationExpImpl());
	*element =(*this);
	element->setThisPackageDeclarationExpPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute path */
std::string PackageDeclarationExpImpl::getPath() const 
{
	return m_path;
}
void PackageDeclarationExpImpl::setPath(std::string _path)
{
	m_path = _path;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference contextDeclarations */
const std::shared_ptr<Bag<ocl::Expressions::ContextDeclarationExp>>& PackageDeclarationExpImpl::getContextDeclarations() const
{
	if(m_contextDeclarations == nullptr)
	{
		m_contextDeclarations.reset(new Bag<ocl::Expressions::ContextDeclarationExp>());
		
		
	}
    return m_contextDeclarations;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PackageDeclarationExpImpl::eContainer() const
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
void PackageDeclarationExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageDeclarationExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("path");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setPath(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("contextDeclarations");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("contextDeclarations")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpressionImpl::loadAttributes(loadHandler, attr_list);
}

void PackageDeclarationExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpressionImpl::loadNode(nodeName, loadHandler);
}

void PackageDeclarationExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS:
		{
			const std::shared_ptr<Bag<ocl::Expressions::ContextDeclarationExp>>& _contextDeclarations = getContextDeclarations();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<ocl::Expressions::ContextDeclarationExp>  _r = std::dynamic_pointer_cast<ocl::Expressions::ContextDeclarationExp>(ref);
				if (_r != nullptr)
				{
					_contextDeclarations->push_back(_r);
				}
			}
			return;
		}
	}
	OclExpressionImpl::resolveReferences(featureID, references);
}

void PackageDeclarationExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PackageDeclarationExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getPackageDeclarationExp_Attribute_path()) )
          {
			saveHandler->addAttribute("path", this->getPath());
          }
	// Add references
	if ( this->eIsSet(package->getPackageDeclarationExp_Attribute_contextDeclarations()) )
	{
		saveHandler->addReferences<ocl::Expressions::ContextDeclarationExp>("contextDeclarations", this->getContextDeclarations());
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& PackageDeclarationExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getPackageDeclarationExp_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PackageDeclarationExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS:
			return eEcoreContainerAny(getContextDeclarations(),ocl::Expressions::ExpressionsPackage::CONTEXTDECLARATIONEXP_CLASS); //6624
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_PATH:
			return eAny(getPath(),ecore::ecorePackage::ESTRING_CLASS,false); //6623
	}
	return OclExpressionImpl::eGet(featureID, resolve, coreType);
}

bool PackageDeclarationExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS:
			return getContextDeclarations() != nullptr; //6624
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_PATH:
			return getPath() != ""; //6623
	}
	return OclExpressionImpl::internalEIsSet(featureID);
}

bool PackageDeclarationExpImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_CONTEXTDECLARATIONS:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<ocl::Expressions::ContextDeclarationExp>>& _contextDeclarations = getContextDeclarations();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<ocl::Expressions::ContextDeclarationExp> valueToAdd = std::dynamic_pointer_cast<ocl::Expressions::ContextDeclarationExp>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_contextDeclarations->includes(valueToAdd)))
								{
									_contextDeclarations->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'contextDeclarations'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'contextDeclarations'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case ocl::Expressions::ExpressionsPackage::PACKAGEDECLARATIONEXP_ATTRIBUTE_PATH:
		{
			try
			{
				std::string _path = newValue->get<std::string>();
				setPath(_path); //6623
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'path'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return OclExpressionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PackageDeclarationExpImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpressionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::PackageDeclarationExp> PackageDeclarationExpImpl::getThisPackageDeclarationExpPtr() const
{
	return m_thisPackageDeclarationExpPtr.lock();
}
void PackageDeclarationExpImpl::setThisPackageDeclarationExpPtr(std::weak_ptr<ocl::Expressions::PackageDeclarationExp> thisPackageDeclarationExpPtr)
{
	m_thisPackageDeclarationExpPtr = thisPackageDeclarationExpPtr;
	setThisOclExpressionPtr(thisPackageDeclarationExpPtr);
}




#include "ocl/Evaluations/impl/EvalEnvironmentImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "ocl/Values/UndefinedValue.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Values/ValuesFactory.hpp"
#include "ocl/Values/NameValueBinding.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
EvalEnvironmentImpl::EvalEnvironmentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EvalEnvironmentImpl::~EvalEnvironmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EvalEnvironment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EvalEnvironmentImpl::EvalEnvironmentImpl(const EvalEnvironmentImpl & obj): EvalEnvironmentImpl()
{
	*this = obj;
}

EvalEnvironmentImpl& EvalEnvironmentImpl::operator=(const EvalEnvironmentImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EvalEnvironment 
	 * which is generated by the compiler (as EvalEnvironment is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EvalEnvironment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EvalEnvironment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_bindings  = obj.getBindings();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EvalEnvironmentImpl::copy() const
{
	std::shared_ptr<EvalEnvironmentImpl> element(new EvalEnvironmentImpl());
	*element =(*this);
	element->setThisEvalEnvironmentPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void EvalEnvironmentImpl::add(std::shared_ptr<ocl::Values::NameValueBinding> n)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//std::shared_ptr<ocl::Values::NameValueBinding> nvb = this->find(n->getName());
//if(nvb != nullptr)
	m_bindings->add(n);


	//end of body
}

void EvalEnvironmentImpl::addAll(std::shared_ptr<Bag<ocl::Values::NameValueBinding>> nvbs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (Bag<ocl::Values::NameValueBinding>::const_iterator it_attribute = nvbs->begin(); it_attribute != nvbs->end(); ++it_attribute)
    {
        if (this->find((*it_attribute)->getName()) == nullptr) {
           m_bindings->add(*it_attribute);
        }
    }

	//end of body
}

std::shared_ptr<ocl::Values::NameValueBinding> EvalEnvironmentImpl::find(std::string name)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (Bag<ocl::Values::NameValueBinding>::const_iterator it_attribute = m_bindings->begin(); it_attribute != m_bindings->end(); ++it_attribute)
    {
        if ((*it_attribute)->getName() == name) {
            return *it_attribute;
        }
    }
    return nullptr;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> EvalEnvironmentImpl::getValueOf(std::string n)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ocl::Values::NameValueBinding> nvb = this->find(n);
if(nvb != nullptr)
	return nvb->getValue();
else
       return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
	//end of body
}

void EvalEnvironmentImpl::replace(std::shared_ptr<ocl::Values::NameValueBinding> n)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<ocl::Values::NameValueBinding> nvb = this->find(n->getName());
if(nvb != nullptr)
	return nvb->setValue(n->getValue());


	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bindings */
std::shared_ptr<Bag<ocl::Values::NameValueBinding>> EvalEnvironmentImpl::getBindings() const
{
	if(m_bindings == nullptr)
	{
		m_bindings.reset(new Bag<ocl::Values::NameValueBinding>());
		
		
	}
    return m_bindings;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EvalEnvironmentImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EvalEnvironmentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EvalEnvironmentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bindings");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bindings")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EvalEnvironmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void EvalEnvironmentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_ATTRIBUTE_BINDINGS:
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
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EvalEnvironmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EvalEnvironmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Values::NameValueBinding>("bindings", this->getBindings());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> EvalEnvironmentImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EvalEnvironmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_ATTRIBUTE_BINDINGS:
		{
			return eAnyBag(getBindings(),ocl::Values::ValuesPackage::NAMEVALUEBINDING_CLASS); //260
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EvalEnvironmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_ATTRIBUTE_BINDINGS:
			return getBindings() != nullptr; //260
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool EvalEnvironmentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::EVALENVIRONMENT_ATTRIBUTE_BINDINGS:
		{
			// CAST Any to Bag<ocl::Values::NameValueBinding>
			if((newValue->isContainer()) && (ocl::Values::ValuesPackage::NAMEVALUEBINDING_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Values::NameValueBinding>> bindingsList= newValue->get<std::shared_ptr<Bag<ocl::Values::NameValueBinding>>>();
					std::shared_ptr<Bag<ocl::Values::NameValueBinding>> _bindings=getBindings();
					for(const std::shared_ptr<ocl::Values::NameValueBinding> indexBindings: *_bindings)
					{
						if (bindingsList->find(indexBindings) == -1)
						{
							_bindings->erase(indexBindings);
						}
					}

					for(const std::shared_ptr<ocl::Values::NameValueBinding> indexBindings: *bindingsList)
					{
						if (_bindings->find(indexBindings) == -1)
						{
							_bindings->add(indexBindings);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EvalEnvironmentImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ocl::Evaluations::EvalEnvironment::add(ocl::Values::NameValueBinding): 1479022861
		case EvaluationsPackage::EVALENVIRONMENT_OPERATION_ADD_NAMEVALUEBINDING:
		{
			//Retrieve input parameter 'n'
			//parameter 0
			std::shared_ptr<ocl::Values::NameValueBinding> incoming_param_n;
			std::list<Any>::const_iterator incoming_param_n_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_n = (*incoming_param_n_arguments_citer)->get<std::shared_ptr<ocl::Values::NameValueBinding> >();
			this->add(incoming_param_n);
		}
		// ocl::Evaluations::EvalEnvironment::addAll(ocl::Values::NameValueBinding[*]): 1063443542
		case EvaluationsPackage::EVALENVIRONMENT_OPERATION_ADDALL_NAMEVALUEBINDING:
		{
			//Retrieve input parameter 'nvbs'
			//parameter 0
			std::shared_ptr<Bag<ocl::Values::NameValueBinding>> incoming_param_nvbs;
			std::list<Any>::const_iterator incoming_param_nvbs_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_nvbs = (*incoming_param_nvbs_arguments_citer)->get<std::shared_ptr<Bag<ocl::Values::NameValueBinding>> >();
			this->addAll(incoming_param_nvbs);
		}
		// ocl::Evaluations::EvalEnvironment::find(std::string) : ocl::Values::NameValueBinding: 946058698
		case EvaluationsPackage::EVALENVIRONMENT_OPERATION_FIND_STRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string >();
			result = eAny(this->find(incoming_param_name), ocl::Values::ValuesPackage::NAMEVALUEBINDING_CLASS,false);
			break;
		}
		// ocl::Evaluations::EvalEnvironment::getValueOf(std::string) : fUML::Semantics::Values::Value: 1187543967
		case EvaluationsPackage::EVALENVIRONMENT_OPERATION_GETVALUEOF_ESTRING:
		{
			//Retrieve input parameter 'n'
			//parameter 0
			std::string incoming_param_n;
			std::list<Any>::const_iterator incoming_param_n_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_n = (*incoming_param_n_arguments_citer)->get<std::string >();
			result = eAny(this->getValueOf(incoming_param_n), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// ocl::Evaluations::EvalEnvironment::replace(ocl::Values::NameValueBinding): 483482254
		case EvaluationsPackage::EVALENVIRONMENT_OPERATION_REPLACE_NAMEVALUEBINDING:
		{
			//Retrieve input parameter 'n'
			//parameter 0
			std::shared_ptr<ocl::Values::NameValueBinding> incoming_param_n;
			std::list<Any>::const_iterator incoming_param_n_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_n = (*incoming_param_n_arguments_citer)->get<std::shared_ptr<ocl::Values::NameValueBinding> >();
			this->replace(incoming_param_n);
		}

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

std::shared_ptr<ocl::Evaluations::EvalEnvironment> EvalEnvironmentImpl::getThisEvalEnvironmentPtr() const
{
	return m_thisEvalEnvironmentPtr.lock();
}
void EvalEnvironmentImpl::setThisEvalEnvironmentPtr(std::weak_ptr<ocl::Evaluations::EvalEnvironment> thisEvalEnvironmentPtr)
{
	m_thisEvalEnvironmentPtr = thisEvalEnvironmentPtr;
}



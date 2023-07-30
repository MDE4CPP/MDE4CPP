
#include "uml/impl/ExpressionImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionImpl::ExpressionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpressionImpl::~ExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Expression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Element> par_owner)
:ExpressionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:ExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:ExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

ExpressionImpl::ExpressionImpl(const ExpressionImpl & obj): ExpressionImpl()
{
	*this = obj;
}

ExpressionImpl& ExpressionImpl::operator=(const ExpressionImpl & obj)
{
	//call overloaded =Operator for each base class
	ValueSpecificationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Expression 
	 * which is generated by the compiler (as Expression is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Expression::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Expression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_symbol = obj.getSymbol();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'operand'
	std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> operandList = obj.getOperand();
	if(operandList)
	{
		/*Subset*/
		m_operand.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getOperand()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ValueSpecification> operandindexElem: *operandList) 
		{
			std::shared_ptr<uml::ValueSpecification> temp = std::dynamic_pointer_cast<uml::ValueSpecification>((operandindexElem)->copy());
			m_operand->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr operand."<< std::endl;)
	}
	/*Subset*/
	getOperand()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExpressionImpl::copy() const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl());
	*element =(*this);
	element->setThisExpressionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute symbol */
std::string ExpressionImpl::getSymbol() const
{
	return m_symbol;
}
void ExpressionImpl::setSymbol(std::string _symbol)
{
	m_symbol = _symbol;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference operand */
const std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>>& ExpressionImpl::getOperand() const
{
	if(m_operand == nullptr)
	{
		/*Subset*/
		m_operand.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getOperand()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_operand;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ExpressionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ExpressionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ExpressionImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExpressionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningSlot.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_valueSpecificationAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("symbol");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSymbol(value);
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("operand") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ValueSpecification>(this->getOperand());  

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
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void ExpressionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void ExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'operand'
		for (const std::shared_ptr<uml::ValueSpecification>& operand : *this->getOperand()) 
		{
			saveHandler->addReference(operand, "operand", operand->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getExpression_Attribute_symbol()) )
		{
			saveHandler->addAttribute("symbol", this->getSymbol());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ExpressionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExpression_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
			return eAnyBag(getOperand(),uml::umlPackage::VALUESPECIFICATION_CLASS); //9515
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
			return eAny(getSymbol(),ecore::ecorePackage::ESTRING_CLASS,false); //9516
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}

bool ExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
			return getOperand() != nullptr; //9515
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
			return getSymbol() != ""; //9516
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}

bool ExpressionImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
		{
			// CAST Any to Bag<uml::ValueSpecification>
			if((newValue->isContainer()) && (uml::umlPackage::VALUESPECIFICATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ValueSpecification>> operandList= newValue->get<std::shared_ptr<Bag<uml::ValueSpecification>>>();
					std::shared_ptr<Bag<uml::ValueSpecification>> _operand=getOperand();
					for(const std::shared_ptr<uml::ValueSpecification> indexOperand: *_operand)
					{
						if (!(operandList->includes(indexOperand)))
						{
							_operand->erase(indexOperand);
						}
					}

					for(const std::shared_ptr<uml::ValueSpecification> indexOperand: *operandList)
					{
						if (!(_operand->includes(indexOperand)))
						{
							_operand->add(indexOperand);
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
		case uml::umlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
		{
			// CAST Any to std::string
			std::string _symbol = newValue->get<std::string>();
			setSymbol(_symbol); //9516
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExpressionImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ValueSpecificationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Expression> ExpressionImpl::getThisExpressionPtr() const
{
	return m_thisExpressionPtr.lock();
}
void ExpressionImpl::setThisExpressionPtr(std::weak_ptr<uml::Expression> thisExpressionPtr)
{
	m_thisExpressionPtr = thisExpressionPtr;
	setThisValueSpecificationPtr(thisExpressionPtr);
}



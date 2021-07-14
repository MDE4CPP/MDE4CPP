#include "uml/impl/StringExpressionImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Expression.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/ValueSpecificationAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StringExpressionImpl::StringExpressionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StringExpressionImpl::~StringExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StringExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Element> par_owner)
:StringExpressionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::StringExpression> par_owningExpression)
:StringExpressionImpl()
{
	m_owningExpression = par_owningExpression;
	m_owner = par_owningExpression;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Package> par_owningPackage)
:StringExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Slot> par_owningSlot)
:StringExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:StringExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction)
:StringExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}

StringExpressionImpl::StringExpressionImpl(const StringExpressionImpl & obj): StringExpressionImpl()
{
	*this = obj;
}

StringExpressionImpl& StringExpressionImpl::operator=(const StringExpressionImpl & obj)
{
	//call overloaded =Operator for each base class
	ExpressionImpl::operator=(obj);
	TemplateableElementImpl::operator=(obj);
	StringExpression::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_owningExpression  = obj.getOwningExpression();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::StringExpression, uml::Element>> subExpressionContainer = getSubExpression();
	if(nullptr != subExpressionContainer )
	{
		int size = subExpressionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _subExpression=(*subExpressionContainer)[i];
			if(nullptr != _subExpression)
			{
				subExpressionContainer->push_back(std::dynamic_pointer_cast<uml::StringExpression>(_subExpression->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container subExpression."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr subExpression."<< std::endl;)
	}
	/*Subset*/
	m_subExpression->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StringExpressionImpl::copy() const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl());
	*element =(*this);
	element->setThisStringExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StringExpressionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStringExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool StringExpressionImpl::operands(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StringExpressionImpl::subexpressions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference owningExpression
*/
std::weak_ptr<uml::StringExpression> StringExpressionImpl::getOwningExpression() const
{

    return m_owningExpression;
}
void StringExpressionImpl::setOwningExpression(std::weak_ptr<uml::StringExpression> _owningExpression)
{
    m_owningExpression = _owningExpression;
	m_owner = this->getOwningExpression().lock();
	
	
}


/*
Getter & Setter for reference subExpression
*/
std::shared_ptr<Subset<uml::StringExpression, uml::Element>> StringExpressionImpl::getSubExpression() const
{
	if(m_subExpression == nullptr)
	{
		/*Subset*/
		m_subExpression.reset(new Subset<uml::StringExpression, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_subExpression->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_subExpression;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> StringExpressionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StringExpressionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> StringExpressionImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<StringExpression> StringExpressionImpl::getThisStringExpressionPtr() const
{
	return m_thisStringExpressionPtr.lock();
}
void StringExpressionImpl::setThisStringExpressionPtr(std::weak_ptr<StringExpression> thisStringExpressionPtr)
{
	m_thisStringExpressionPtr = thisStringExpressionPtr;
	setThisExpressionPtr(thisStringExpressionPtr);
	setThisTemplateableElementPtr(thisStringExpressionPtr);
}
std::shared_ptr<ecore::EObject> StringExpressionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningExpression.lock())
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
// Structural Feature Getter/Setter
//*********************************
Any StringExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
			return eAny(getOwningExpression().lock()); //22419
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StringExpression>::iterator iter = getSubExpression()->begin();
			Bag<uml::StringExpression>::iterator end = getSubExpression()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22420			
		}
	}
	Any result;
	result = ExpressionImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool StringExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
			return getOwningExpression().lock() != nullptr; //22419
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
			return getSubExpression() != nullptr; //22420
	}
	bool result = false;
	result = ExpressionImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	return result;
}
bool StringExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StringExpression> _owningExpression = std::dynamic_pointer_cast<uml::StringExpression>(_temp);
			setOwningExpression(_owningExpression); //22419
			return true;
		}
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::StringExpression>> subExpressionList(new Bag<uml::StringExpression>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subExpressionList->add(std::dynamic_pointer_cast<uml::StringExpression>(*iter));
				iter++;
			}
			
			Bag<uml::StringExpression>::iterator iterSubExpression = getSubExpression()->begin();
			Bag<uml::StringExpression>::iterator endSubExpression = getSubExpression()->end();
			while (iterSubExpression != endSubExpression)
			{
				if (subExpressionList->find(*iterSubExpression) == -1)
				{
					getSubExpression()->erase(*iterSubExpression);
				}
				iterSubExpression++;
			}
 
			iterSubExpression = subExpressionList->begin();
			endSubExpression = subExpressionList->end();
			while (iterSubExpression != endSubExpression)
			{
				if (getSubExpression()->find(*iterSubExpression) == -1)
				{
					getSubExpression()->add(*iterSubExpression);
				}
				iterSubExpression++;			
			}
			return true;
		}
	}

	bool result = false;
	result = ExpressionImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any StringExpressionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 22489
		case umlPackage::STRINGEXPRESSION_OPERATION_OPERANDS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->operands(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22490
		case umlPackage::STRINGEXPRESSION_OPERATION_SUBEXPRESSIONS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->subexpressions(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ExpressionImpl::eInvoke(operationID, arguments);
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
void StringExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StringExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExpressionImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
}

void StringExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("subExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StringExpression";
			}
			loadHandler->handleChildContainer<uml::StringExpression>(this->getSubExpression());  

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
	ExpressionImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
}

void StringExpressionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StringExpression> _owningExpression = std::dynamic_pointer_cast<uml::StringExpression>( references.front() );
				setOwningExpression(_owningExpression);
			}
			
			return;
		}
	}
	ExpressionImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
}

void StringExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExpressionImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void StringExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'subExpression'
		for (std::shared_ptr<uml::StringExpression> subExpression : *this->getSubExpression()) 
		{
			saveHandler->addReference(subExpression, "subExpression", subExpression->eClass() != package->getStringExpression_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


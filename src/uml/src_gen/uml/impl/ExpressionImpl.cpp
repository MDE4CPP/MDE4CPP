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
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

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

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionImpl::ExpressionImpl()
{	
}

ExpressionImpl::~ExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Expression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExpressionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Element > par_owner)
:ExpressionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
:ExpressionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
:ExpressionImpl()
{
	m_owningSlot = par_owningSlot;
	m_owner = par_owningSlot;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:ExpressionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
:ExpressionImpl()
{
	m_valueSpecificationAction = par_valueSpecificationAction;
	m_owner = par_valueSpecificationAction;
}


ExpressionImpl::ExpressionImpl(const ExpressionImpl & obj):ExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Expression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_symbol = obj.getSymbol();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();

	m_valueSpecificationAction  = obj.getValueSpecificationAction();


	//Clone references with containment (deep copy)

	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ValueSpecification>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::ValueSpecification> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_operand->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_operand" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

	/*Subset*/
	m_operand->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  ExpressionImpl::copy() const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(*this));
	element->setThisExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpressionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ExpressionImpl::setSymbol(std::string _symbol)
{
	m_symbol = _symbol;
} 
std::string ExpressionImpl::getSymbol() const 
{
	return m_symbol;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> ExpressionImpl::getOperand() const
{
	if(m_operand == nullptr)
	{
		/*Subset*/
		m_operand.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_operand->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_operand;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExpressionImpl::getNamespace() const
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

std::weak_ptr<uml::Element > ExpressionImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Expression> ExpressionImpl::getThisExpressionPtr() const
{
	return m_thisExpressionPtr.lock();
}
void ExpressionImpl::setThisExpressionPtr(std::weak_ptr<Expression> thisExpressionPtr)
{
	m_thisExpressionPtr = thisExpressionPtr;
	setThisValueSpecificationPtr(thisExpressionPtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ValueSpecification>::iterator iter = m_operand->begin();
			Bag<uml::ValueSpecification>::iterator end = m_operand->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //9615
		}
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
			return eAny(getSymbol()); //9616
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool ExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
			return getOperand() != nullptr; //9615
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
			return getSymbol() != ""; //9616
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}
bool ExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_OPERAND:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ValueSpecification>> operandList(new Bag<uml::ValueSpecification>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				operandList->add(std::dynamic_pointer_cast<uml::ValueSpecification>(*iter));
				iter++;
			}
			
			Bag<uml::ValueSpecification>::iterator iterOperand = m_operand->begin();
			Bag<uml::ValueSpecification>::iterator endOperand = m_operand->end();
			while (iterOperand != endOperand)
			{
				if (operandList->find(*iterOperand) == -1)
				{
					m_operand->erase(*iterOperand);
				}
				iterOperand++;
			}

			iterOperand = operandList->begin();
			endOperand = operandList->end();
			while (iterOperand != endOperand)
			{
				if (m_operand->find(*iterOperand) == -1)
				{
					m_operand->add(*iterOperand);
				}
				iterOperand++;			
			}
			return true;
		}
		case uml::UmlPackage::EXPRESSION_ATTRIBUTE_SYMBOL:
		{
			// BOOST CAST
			std::string _symbol = newValue->get<std::string>();
			setSymbol(_symbol); //9616
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
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
	// get UmlFactory
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
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

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
			std::shared_ptr<uml::ValueSpecification> operand = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (operand != nullptr)
			{
				std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> list_operand = this->getOperand();
				list_operand->push_back(operand);
				loadHandler->handleChild(operand);
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
	ValueSpecificationImpl::loadNode(nodeName, loadHandler);
}

void ExpressionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'operand'
		for (std::shared_ptr<uml::ValueSpecification> operand : *this->getOperand()) 
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


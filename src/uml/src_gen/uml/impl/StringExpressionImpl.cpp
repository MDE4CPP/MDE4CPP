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
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StringExpressionImpl::StringExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_subExpression.reset(new Subset<uml::StringExpression, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_subExpression->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

StringExpressionImpl::~StringExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StringExpressionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:StringExpressionImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::StringExpression > par_owningExpression)
			:StringExpressionImpl()
			{
			    m_owningExpression = par_owningExpression;
				m_owner = par_owningExpression;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:StringExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:StringExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
				m_owner = par_owningSlot;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:StringExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction)
			:StringExpressionImpl()
			{
			    m_valueSpecificationAction = par_valueSpecificationAction;
				m_owner = par_valueSpecificationAction;
			}



StringExpressionImpl::StringExpressionImpl(const StringExpressionImpl & obj):StringExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_owningExpression  = obj.getOwningExpression();

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
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::StringExpression>> _subExpressionList = obj.getSubExpression();
	for(std::shared_ptr<uml::StringExpression> _subExpression : *_subExpressionList)
	{
		this->getSubExpression()->add(std::shared_ptr<uml::StringExpression>(std::dynamic_pointer_cast<uml::StringExpression>(_subExpression->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

		/*Subset*/
		m_subExpression->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  StringExpressionImpl::copy() const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(*this));
	element->setThisStringExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StringExpressionImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getStringExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool StringExpressionImpl::operands(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StringExpressionImpl::subexpressions(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::StringExpression > StringExpressionImpl::getOwningExpression() const
{

    return m_owningExpression;
}
void StringExpressionImpl::setOwningExpression(std::shared_ptr<uml::StringExpression> _owningExpression)
{
    m_owningExpression = _owningExpression;
}

std::shared_ptr<Subset<uml::StringExpression, uml::Element>> StringExpressionImpl::getSubExpression() const
{

    return m_subExpression;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > StringExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> StringExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > StringExpressionImpl::getOwner() const
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
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getOwningExpression().lock())); //22519
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::StringExpression>::iterator iter = m_subExpression->begin();
			Bag<uml::StringExpression>::iterator end = m_subExpression->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22520
		}
	}
	Any result;
	result = ExpressionImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
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
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
			return getOwningExpression().lock() != nullptr; //22519
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
			return getSubExpression() != nullptr; //22520
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
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StringExpression> _owningExpression = std::dynamic_pointer_cast<uml::StringExpression>(_temp);
			setOwningExpression(_owningExpression); //22519
			return true;
		}
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION:
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
			
			Bag<uml::StringExpression>::iterator iterSubExpression = m_subExpression->begin();
			Bag<uml::StringExpression>::iterator endSubExpression = m_subExpression->end();
			while (iterSubExpression != endSubExpression)
			{
				if (subExpressionList->find(*iterSubExpression) == -1)
				{
					m_subExpression->erase(*iterSubExpression);
				}
				iterSubExpression++;
			}

			iterSubExpression = subExpressionList->begin();
			endSubExpression = subExpressionList->end();
			while (iterSubExpression != endSubExpression)
			{
				if (m_subExpression->find(*iterSubExpression) == -1)
				{
					m_subExpression->add(*iterSubExpression);
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
// Persistence Functions
//*********************************
void StringExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StringExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExpressionImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
}

void StringExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("subExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StringExpression";
			}
			std::shared_ptr<ecore::EObject> subExpression = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION);
			if (subExpression != nullptr)
			{
				loadHandler->handleChild(subExpression);
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
	ExpressionImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
}

void StringExpressionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

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


#include "uml/impl/ParameterSetImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Parameter.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterSetImpl::ParameterSetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ParameterSetImpl::~ParameterSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ParameterSetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Element> par_owner)
:ParameterSetImpl()
{
	m_owner = par_owner;
}

ParameterSetImpl::ParameterSetImpl(const ParameterSetImpl & obj): ParameterSetImpl()
{
	*this = obj;
}

ParameterSetImpl& ParameterSetImpl::operator=(const ParameterSetImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	ParameterSet::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Parameter>> _parameter = obj.getParameter();
	m_parameter.reset(new Bag<uml::Parameter>(*(obj.getParameter().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Constraint, uml::Element>> conditionContainer = getCondition();
	if(nullptr != conditionContainer )
	{
		int size = conditionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _condition=(*conditionContainer)[i];
			if(nullptr != _condition)
			{
				conditionContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_condition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container condition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr condition."<< std::endl;)
	}
	/*Subset*/
	m_condition->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ParameterSetImpl::copy() const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl());
	*element =(*this);
	element->setThisParameterSetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ParameterSetImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getParameterSet_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterSetImpl::input(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::same_parameterized_entity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::two_parameter_sets(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference condition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ParameterSetImpl::getCondition() const
{
	if(m_condition == nullptr)
	{
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_condition->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_condition;
}



/*
Getter & Setter for reference parameter
*/
std::shared_ptr<Bag<uml::Parameter>> ParameterSetImpl::getParameter() const
{
	if(m_parameter == nullptr)
	{
		m_parameter.reset(new Bag<uml::Parameter>());
		
		
	}
//assert(m_parameter);
    return m_parameter;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ParameterSetImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ParameterSetImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ParameterSet> ParameterSetImpl::getThisParameterSetPtr() const
{
	return m_thisParameterSetPtr.lock();
}
void ParameterSetImpl::setThisParameterSetPtr(std::weak_ptr<ParameterSet> thisParameterSetPtr)
{
	m_thisParameterSetPtr = thisParameterSetPtr;
	setThisNamedElementPtr(thisParameterSetPtr);
}
std::shared_ptr<ecore::EObject> ParameterSetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ParameterSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = m_condition->begin();
			Bag<uml::Constraint>::iterator end = m_condition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1779
		}
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Parameter>::iterator iter = m_parameter->begin();
			Bag<uml::Parameter>::iterator end = m_parameter->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //17710
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool ParameterSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
			return getCondition() != nullptr; //1779
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //17710
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool ParameterSetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_CONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> conditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				conditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterCondition = m_condition->begin();
			Bag<uml::Constraint>::iterator endCondition = m_condition->end();
			while (iterCondition != endCondition)
			{
				if (conditionList->find(*iterCondition) == -1)
				{
					m_condition->erase(*iterCondition);
				}
				iterCondition++;
			}
 
			iterCondition = conditionList->begin();
			endCondition = conditionList->end();
			while (iterCondition != endCondition)
			{
				if (m_condition->find(*iterCondition) == -1)
				{
					m_condition->add(*iterCondition);
				}
				iterCondition++;			
			}
			return true;
		}
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Parameter>> parameterList(new Bag<uml::Parameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterList->add(std::dynamic_pointer_cast<uml::Parameter>(*iter));
				iter++;
			}
			
			Bag<uml::Parameter>::iterator iterParameter = m_parameter->begin();
			Bag<uml::Parameter>::iterator endParameter = m_parameter->end();
			while (iterParameter != endParameter)
			{
				if (parameterList->find(*iterParameter) == -1)
				{
					m_parameter->erase(*iterParameter);
				}
				iterParameter++;
			}
 
			iterParameter = parameterList->begin();
			endParameter = parameterList->end();
			while (iterParameter != endParameter)
			{
				if (m_parameter->find(*iterParameter) == -1)
				{
					m_parameter->add(*iterParameter);
				}
				iterParameter++;			
			}
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ParameterSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("condition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getCondition());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void ParameterSetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETERSET_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Bag<uml::Parameter>> _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Parameter>  _r = std::dynamic_pointer_cast<uml::Parameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}
			}
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void ParameterSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ParameterSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'condition'
		for (std::shared_ptr<uml::Constraint> condition : *this->getCondition()) 
		{
			saveHandler->addReference(condition, "condition", condition->eClass() != package->getConstraint_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Parameter>("parameter", this->getParameter());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


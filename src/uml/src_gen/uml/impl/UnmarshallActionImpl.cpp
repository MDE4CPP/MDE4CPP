#include "uml/impl/UnmarshallActionImpl.hpp"

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


#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
UnmarshallActionImpl::UnmarshallActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UnmarshallActionImpl::~UnmarshallActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UnmarshallAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Activity> par_activity)
:UnmarshallActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:UnmarshallActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:UnmarshallActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
UnmarshallActionImpl::UnmarshallActionImpl(std::weak_ptr<uml::Element> par_owner)
:UnmarshallActionImpl()
{
	m_owner = par_owner;
}

UnmarshallActionImpl::UnmarshallActionImpl(const UnmarshallActionImpl & obj): UnmarshallActionImpl()
{
	*this = obj;
}

UnmarshallActionImpl& UnmarshallActionImpl::operator=(const UnmarshallActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	UnmarshallAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UnmarshallAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_unmarshallType  = obj.getUnmarshallType();
	//Clone references with containment (deep copy)
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> resultContainer = getResult();
	if(nullptr != resultContainer )
	{
		int size = resultContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _result=(*resultContainer)[i];
			if(nullptr != _result)
			{
				resultContainer->push_back(std::dynamic_pointer_cast<uml::OutputPin>(_result->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container result."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr result."<< std::endl;)
	}
	
	/*Subset*/
	m_result->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> UnmarshallActionImpl::copy() const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl());
	*element =(*this);
	element->setThisUnmarshallActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UnmarshallActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getUnmarshallAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool UnmarshallActionImpl::multiplicity_of_object(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UnmarshallActionImpl::number_of_result(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UnmarshallActionImpl::object_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UnmarshallActionImpl::structural_feature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool UnmarshallActionImpl::type_ordering_and_multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference object
*/
std::shared_ptr<uml::InputPin> UnmarshallActionImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void UnmarshallActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
}


/*
Getter & Setter for reference result
*/
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> UnmarshallActionImpl::getResult() const
{
	if(m_result == nullptr)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_result->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}
//assert(m_result);
    return m_result;
}



/*
Getter & Setter for reference unmarshallType
*/
std::shared_ptr<uml::Classifier> UnmarshallActionImpl::getUnmarshallType() const
{
//assert(m_unmarshallType);
    return m_unmarshallType;
}
void UnmarshallActionImpl::setUnmarshallType(std::shared_ptr<uml::Classifier> _unmarshallType)
{
    m_unmarshallType = _unmarshallType;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> UnmarshallActionImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> UnmarshallActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> UnmarshallActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> UnmarshallActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> UnmarshallActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> UnmarshallActionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<UnmarshallAction> UnmarshallActionImpl::getThisUnmarshallActionPtr() const
{
	return m_thisUnmarshallActionPtr.lock();
}
void UnmarshallActionImpl::setThisUnmarshallActionPtr(std::weak_ptr<UnmarshallAction> thisUnmarshallActionPtr)
{
	m_thisUnmarshallActionPtr = thisUnmarshallActionPtr;
	setThisActionPtr(thisUnmarshallActionPtr);
}
std::shared_ptr<ecore::EObject> UnmarshallActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

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
Any UnmarshallActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject()); //24627
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
		{
			return eAny(getResult()); //24628			
		}
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
			return eAny(getUnmarshallType()); //24629
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool UnmarshallActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //24627
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //24628
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
			return getUnmarshallType() != nullptr; //24629
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool UnmarshallActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_OBJECT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setObject(_object); //24627
			return true;
		}
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> resultList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				resultList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterResult = m_result->begin();
			Bag<uml::OutputPin>::iterator endResult = m_result->end();
			while (iterResult != endResult)
			{
				if (resultList->find(*iterResult) == -1)
				{
					m_result->erase(*iterResult);
				}
				iterResult++;
			}
 
			iterResult = resultList->begin();
			endResult = resultList->end();
			while (iterResult != endResult)
			{
				if (m_result->find(*iterResult) == -1)
				{
					m_result->add(*iterResult);
				}
				iterResult++;			
			}
			return true;
		}
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _unmarshallType = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setUnmarshallType(_unmarshallType); //24629
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void UnmarshallActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UnmarshallActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("unmarshallType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("unmarshallType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void UnmarshallActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("object") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getObject()); 

			return; 
		}

		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getResult());  

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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void UnmarshallActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _unmarshallType = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setUnmarshallType(_unmarshallType);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void UnmarshallActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void UnmarshallActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'object'
		std::shared_ptr<uml::InputPin> object = this->getObject();
		if (object != nullptr)
		{
			saveHandler->addReference(object, "object", object->eClass() != package->getInputPin_Class());
		}

		// Save 'result'
		for (std::shared_ptr<uml::OutputPin> result : *this->getResult()) 
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}
	// Add references
		saveHandler->addReference(this->getUnmarshallType(), "unmarshallType", getUnmarshallType()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


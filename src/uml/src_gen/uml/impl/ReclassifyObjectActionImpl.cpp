#include "uml/impl/ReclassifyObjectActionImpl.hpp"

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
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReclassifyObjectActionImpl::~ReclassifyObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReclassifyObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ReclassifyObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ReclassifyObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ReclassifyObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(std::weak_ptr<uml::Element> par_owner)
:ReclassifyObjectActionImpl()
{
	m_owner = par_owner;
}

ReclassifyObjectActionImpl::ReclassifyObjectActionImpl(const ReclassifyObjectActionImpl & obj): ReclassifyObjectActionImpl()
{
	*this = obj;
}

ReclassifyObjectActionImpl& ReclassifyObjectActionImpl::operator=(const ReclassifyObjectActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	ReclassifyObjectAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReclassifyObjectAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _newClassifier = obj.getNewClassifier();
	m_newClassifier.reset(new Bag<uml::Classifier>(*(obj.getNewClassifier().get())));
	std::shared_ptr<Bag<uml::Classifier>> _oldClassifier = obj.getOldClassifier();
	m_oldClassifier.reset(new Bag<uml::Classifier>(*(obj.getOldClassifier().get())));
	//Clone references with containment (deep copy)
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ReclassifyObjectActionImpl::copy() const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl());
	*element =(*this);
	element->setThisReclassifyObjectActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReclassifyObjectActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getReclassifyObjectAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isReplaceAll
*/
bool ReclassifyObjectActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void ReclassifyObjectActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
} 


//*********************************
// Operations
//*********************************
bool ReclassifyObjectActionImpl::classifier_not_abstract(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReclassifyObjectActionImpl::input_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReclassifyObjectActionImpl::multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference newClassifier
*/
std::shared_ptr<Bag<uml::Classifier>> ReclassifyObjectActionImpl::getNewClassifier() const
{
	if(m_newClassifier == nullptr)
	{
		m_newClassifier.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_newClassifier;
}



/*
Getter & Setter for reference object
*/
std::shared_ptr<uml::InputPin> ReclassifyObjectActionImpl::getObject() const
{
//assert(m_object);
    return m_object;
}
void ReclassifyObjectActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
}


/*
Getter & Setter for reference oldClassifier
*/
std::shared_ptr<Bag<uml::Classifier>> ReclassifyObjectActionImpl::getOldClassifier() const
{
	if(m_oldClassifier == nullptr)
	{
		m_oldClassifier.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_oldClassifier;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ReclassifyObjectActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ReclassifyObjectActionImpl::getInput() const
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

std::shared_ptr<Union<uml::Element>> ReclassifyObjectActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ReclassifyObjectActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ReclassifyObjectActionImpl::getRedefinedElement() const
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




std::shared_ptr<ReclassifyObjectAction> ReclassifyObjectActionImpl::getThisReclassifyObjectActionPtr() const
{
	return m_thisReclassifyObjectActionPtr.lock();
}
void ReclassifyObjectActionImpl::setThisReclassifyObjectActionPtr(std::weak_ptr<ReclassifyObjectAction> thisReclassifyObjectActionPtr)
{
	m_thisReclassifyObjectActionPtr = thisReclassifyObjectActionPtr;
	setThisActionPtr(thisReclassifyObjectActionPtr);
}
std::shared_ptr<ecore::EObject> ReclassifyObjectActionImpl::eContainer() const
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
Any ReclassifyObjectActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll()); //20327
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
		{
			return eAny(getNewClassifier()); //20328			
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject()); //20329
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
		{
			return eAny(getOldClassifier()); //20330			
		}
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool ReclassifyObjectActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //20327
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
			return getNewClassifier() != nullptr; //20328
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //20329
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
			return getOldClassifier() != nullptr; //20330
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool ReclassifyObjectActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL:
		{
			// BOOST CAST
			bool _isReplaceAll = newValue->get<bool>();
			setIsReplaceAll(_isReplaceAll); //20327
			return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> newClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				newClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterNewClassifier = m_newClassifier->begin();
			Bag<uml::Classifier>::iterator endNewClassifier = m_newClassifier->end();
			while (iterNewClassifier != endNewClassifier)
			{
				if (newClassifierList->find(*iterNewClassifier) == -1)
				{
					m_newClassifier->erase(*iterNewClassifier);
				}
				iterNewClassifier++;
			}
 
			iterNewClassifier = newClassifierList->begin();
			endNewClassifier = newClassifierList->end();
			while (iterNewClassifier != endNewClassifier)
			{
				if (m_newClassifier->find(*iterNewClassifier) == -1)
				{
					m_newClassifier->add(*iterNewClassifier);
				}
				iterNewClassifier++;			
			}
			return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setObject(_object); //20329
			return true;
		}
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> oldClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				oldClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterOldClassifier = m_oldClassifier->begin();
			Bag<uml::Classifier>::iterator endOldClassifier = m_oldClassifier->end();
			while (iterOldClassifier != endOldClassifier)
			{
				if (oldClassifierList->find(*iterOldClassifier) == -1)
				{
					m_oldClassifier->erase(*iterOldClassifier);
				}
				iterOldClassifier++;
			}
 
			iterOldClassifier = oldClassifierList->begin();
			endOldClassifier = oldClassifierList->end();
			while (iterOldClassifier != endOldClassifier)
			{
				if (m_oldClassifier->find(*iterOldClassifier) == -1)
				{
					m_oldClassifier->add(*iterOldClassifier);
				}
				iterOldClassifier++;			
			}
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ReclassifyObjectActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 20398
		case umlPackage::RECLASSIFYOBJECTACTION_OPERATION_CLASSIFIER_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->classifier_not_abstract(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20397
		case umlPackage::RECLASSIFYOBJECTACTION_OPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->input_pin(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20399
		case umlPackage::RECLASSIFYOBJECTACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->multiplicity(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
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
void ReclassifyObjectActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReclassifyObjectActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReplaceAll");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReplaceAll(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("newClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("newClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("oldClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("oldClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReclassifyObjectActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReclassifyObjectActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _newClassifier = getNewClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_newClassifier->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _oldClassifier = getOldClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_oldClassifier->push_back(_r);
				}
			}
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReclassifyObjectActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ReclassifyObjectActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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
		// Add attributes
		if ( this->eIsSet(package->getReclassifyObjectAction_Attribute_isReplaceAll()) )
		{
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("newClassifier", this->getNewClassifier());
		saveHandler->addReferences<uml::Classifier>("oldClassifier", this->getOldClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


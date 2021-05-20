#include "uml/impl/OccurrenceSpecificationImpl.hpp"

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
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OccurrenceSpecificationImpl::~OccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:OccurrenceSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:OccurrenceSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OccurrenceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:OccurrenceSpecificationImpl()
{
	m_owner = par_owner;
}

OccurrenceSpecificationImpl::OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj): OccurrenceSpecificationImpl()
{
	*this = obj;
}

OccurrenceSpecificationImpl& OccurrenceSpecificationImpl::operator=(const OccurrenceSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	InteractionFragmentImpl::operator=(obj);
	OccurrenceSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter = obj.getToAfter();
	m_toAfter.reset(new Bag<uml::GeneralOrdering>(*(obj.getToAfter().get())));
	std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore = obj.getToBefore();
	m_toBefore.reset(new Bag<uml::GeneralOrdering>(*(obj.getToBefore().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl());
	*element =(*this);
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OccurrenceSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOccurrenceSpecification_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


void OccurrenceSpecificationImpl::setCovered(std::shared_ptr<uml::Lifeline> value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference toAfter
*/
std::shared_ptr<Bag<uml::GeneralOrdering>> OccurrenceSpecificationImpl::getToAfter() const
{
	if(m_toAfter == nullptr)
	{
		m_toAfter.reset(new Bag<uml::GeneralOrdering>());
		
		
	}

    return m_toAfter;
}



/*
Getter & Setter for reference toBefore
*/
std::shared_ptr<Bag<uml::GeneralOrdering>> OccurrenceSpecificationImpl::getToBefore() const
{
	if(m_toBefore == nullptr)
	{
		m_toBefore.reset(new Bag<uml::GeneralOrdering>());
		
		
	}

    return m_toBefore;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> OccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OccurrenceSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> OccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<OccurrenceSpecification> OccurrenceSpecificationImpl::getThisOccurrenceSpecificationPtr() const
{
	return m_thisOccurrenceSpecificationPtr.lock();
}
void OccurrenceSpecificationImpl::setThisOccurrenceSpecificationPtr(std::weak_ptr<OccurrenceSpecification> thisOccurrenceSpecificationPtr)
{
	m_thisOccurrenceSpecificationPtr = thisOccurrenceSpecificationPtr;
	setThisInteractionFragmentPtr(thisOccurrenceSpecificationPtr);
}
std::shared_ptr<ecore::EObject> OccurrenceSpecificationImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
Any OccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
		{
			return eAny(getToAfter()); //16313			
		}
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
		{
			return eAny(getToBefore()); //16314			
		}
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool OccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
			return getToAfter() != nullptr; //16313
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
			return getToBefore() != nullptr; //16314
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool OccurrenceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralOrdering>> toAfterList(new Bag<uml::GeneralOrdering>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				toAfterList->add(std::dynamic_pointer_cast<uml::GeneralOrdering>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralOrdering>::iterator iterToAfter = m_toAfter->begin();
			Bag<uml::GeneralOrdering>::iterator endToAfter = m_toAfter->end();
			while (iterToAfter != endToAfter)
			{
				if (toAfterList->find(*iterToAfter) == -1)
				{
					m_toAfter->erase(*iterToAfter);
				}
				iterToAfter++;
			}
 
			iterToAfter = toAfterList->begin();
			endToAfter = toAfterList->end();
			while (iterToAfter != endToAfter)
			{
				if (m_toAfter->find(*iterToAfter) == -1)
				{
					m_toAfter->add(*iterToAfter);
				}
				iterToAfter++;			
			}
			return true;
		}
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralOrdering>> toBeforeList(new Bag<uml::GeneralOrdering>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				toBeforeList->add(std::dynamic_pointer_cast<uml::GeneralOrdering>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralOrdering>::iterator iterToBefore = m_toBefore->begin();
			Bag<uml::GeneralOrdering>::iterator endToBefore = m_toBefore->end();
			while (iterToBefore != endToBefore)
			{
				if (toBeforeList->find(*iterToBefore) == -1)
				{
					m_toBefore->erase(*iterToBefore);
				}
				iterToBefore++;
			}
 
			iterToBefore = toBeforeList->begin();
			endToBefore = toBeforeList->end();
			while (iterToBefore != endToBefore)
			{
				if (m_toBefore->find(*iterToBefore) == -1)
				{
					m_toBefore->add(*iterToBefore);
				}
				iterToBefore++;			
			}
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OccurrenceSpecificationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 16371
		case umlPackage::OCCURRENCESPECIFICATION_OPERATION_GETCOVERED:
		{
			result = eAny(this->getCovered());
			break;
		}
		
		// 16372
		case umlPackage::OCCURRENCESPECIFICATION_OPERATION_SETCOVERED_LIFELINE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<uml::Lifeline> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<uml::Lifeline> >();
			this->setCovered(incoming_param_value);
			break;
		}

		default:
		{
			// call superTypes
			result = InteractionFragmentImpl::eInvoke(operationID, arguments);
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
void OccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("toAfter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("toAfter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("toBefore");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("toBefore")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	InteractionFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void OccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void OccurrenceSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER:
		{
			std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter = getToAfter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralOrdering>  _r = std::dynamic_pointer_cast<uml::GeneralOrdering>(ref);
				if (_r != nullptr)
				{
					_toAfter->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE:
		{
			std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore = getToBefore();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralOrdering>  _r = std::dynamic_pointer_cast<uml::GeneralOrdering>(ref);
				if (_r != nullptr)
				{
					_toBefore->push_back(_r);
				}
			}
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void OccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void OccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::GeneralOrdering>("toAfter", this->getToAfter());
		saveHandler->addReferences<uml::GeneralOrdering>("toBefore", this->getToBefore());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


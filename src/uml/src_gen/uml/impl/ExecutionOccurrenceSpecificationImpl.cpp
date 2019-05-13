#include "uml/impl/ExecutionOccurrenceSpecificationImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ExecutionSpecification.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/OccurrenceSpecification.hpp"

#include "uml/StringExpression.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

ExecutionOccurrenceSpecificationImpl::~ExecutionOccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionOccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:ExecutionOccurrenceSpecificationImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:ExecutionOccurrenceSpecificationImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ExecutionOccurrenceSpecificationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:ExecutionOccurrenceSpecificationImpl()
			{
			    m_owner = par_owner;
			}






ExecutionOccurrenceSpecificationImpl::ExecutionOccurrenceSpecificationImpl(const ExecutionOccurrenceSpecificationImpl & obj):ExecutionOccurrenceSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionOccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Lifeline>> _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_execution  = obj.getExecution();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter = obj.getToAfter();
	m_toAfter.reset(new Bag<uml::GeneralOrdering>(*(obj.getToAfter().get())));

	std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore = obj.getToBefore();
	m_toBefore.reset(new Bag<uml::GeneralOrdering>(*(obj.getToBefore().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExecutionOccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl(*this));
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionOccurrenceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExecutionOccurrenceSpecification_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::ExecutionSpecification > ExecutionOccurrenceSpecificationImpl::getExecution() const
{
//assert(m_execution);
    return m_execution;
}
void ExecutionOccurrenceSpecificationImpl::setExecution(std::shared_ptr<uml::ExecutionSpecification> _execution)
{
    m_execution = _execution;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExecutionOccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ExecutionOccurrenceSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExecutionOccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ExecutionOccurrenceSpecification> ExecutionOccurrenceSpecificationImpl::getThisExecutionOccurrenceSpecificationPtr() const
{
	return m_thisExecutionOccurrenceSpecificationPtr.lock();
}
void ExecutionOccurrenceSpecificationImpl::setThisExecutionOccurrenceSpecificationPtr(std::weak_ptr<ExecutionOccurrenceSpecification> thisExecutionOccurrenceSpecificationPtr)
{
	m_thisExecutionOccurrenceSpecificationPtr = thisExecutionOccurrenceSpecificationPtr;
	setThisOccurrenceSpecificationPtr(thisExecutionOccurrenceSpecificationPtr);
}
std::shared_ptr<ecore::EObject> ExecutionOccurrenceSpecificationImpl::eContainer() const
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
Any ExecutionOccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_EREFERENCE_EXECUTION:
			return eAny(getExecution()); //9015
	}
	return OccurrenceSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool ExecutionOccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_EREFERENCE_EXECUTION:
			return getExecution() != nullptr; //9015
	}
	return OccurrenceSpecificationImpl::internalEIsSet(featureID);
}
bool ExecutionOccurrenceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_EREFERENCE_EXECUTION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ExecutionSpecification> _execution = newValue->get<std::shared_ptr<uml::ExecutionSpecification>>();
			setExecution(_execution); //9015
			return true;
		}
	}

	return OccurrenceSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionOccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ExecutionOccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("execution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("execution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OccurrenceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutionOccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	OccurrenceSpecificationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExecutionOccurrenceSpecificationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_EREFERENCE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExecutionSpecification> _execution = std::dynamic_pointer_cast<uml::ExecutionSpecification>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}
	}
	OccurrenceSpecificationImpl::resolveReferences(featureID, references);
}

void ExecutionOccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OccurrenceSpecificationImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ExecutionOccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("execution", this->getExecution());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


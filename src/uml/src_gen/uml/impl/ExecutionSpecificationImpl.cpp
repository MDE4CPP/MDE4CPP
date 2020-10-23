#include "uml/impl/ExecutionSpecificationImpl.hpp"

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

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/OccurrenceSpecification.hpp"

#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutionSpecificationImpl::ExecutionSpecificationImpl()
{	
}

ExecutionSpecificationImpl::~ExecutionSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutionSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
:ExecutionSpecificationImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
:ExecutionSpecificationImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ExecutionSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExecutionSpecificationImpl::ExecutionSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
:ExecutionSpecificationImpl()
{
	m_owner = par_owner;
}


ExecutionSpecificationImpl::ExecutionSpecificationImpl(const ExecutionSpecificationImpl & obj):ExecutionSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutionSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_finish  = obj.getFinish();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_start  = obj.getStart();


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

std::shared_ptr<ecore::EObject>  ExecutionSpecificationImpl::copy() const
{
	std::shared_ptr<ExecutionSpecificationImpl> element(new ExecutionSpecificationImpl(*this));
	element->setThisExecutionSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutionSpecificationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getExecutionSpecification_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExecutionSpecificationImpl::same_lifeline(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference finish
*/
std::shared_ptr<uml::OccurrenceSpecification > ExecutionSpecificationImpl::getFinish() const
{
//assert(m_finish);
    return m_finish;
}

void ExecutionSpecificationImpl::setFinish(std::shared_ptr<uml::OccurrenceSpecification> _finish)
{
    m_finish = _finish;
}



/*
Getter & Setter for reference start
*/
std::shared_ptr<uml::OccurrenceSpecification > ExecutionSpecificationImpl::getStart() const
{
//assert(m_start);
    return m_start;
}

void ExecutionSpecificationImpl::setStart(std::shared_ptr<uml::OccurrenceSpecification> _start)
{
    m_start = _start;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExecutionSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ExecutionSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > ExecutionSpecificationImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ExecutionSpecification> ExecutionSpecificationImpl::getThisExecutionSpecificationPtr() const
{
	return m_thisExecutionSpecificationPtr.lock();
}
void ExecutionSpecificationImpl::setThisExecutionSpecificationPtr(std::weak_ptr<ExecutionSpecification> thisExecutionSpecificationPtr)
{
	m_thisExecutionSpecificationPtr = thisExecutionSpecificationPtr;
	setThisInteractionFragmentPtr(thisExecutionSpecificationPtr);
}
std::shared_ptr<ecore::EObject> ExecutionSpecificationImpl::eContainer() const
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
Any ExecutionSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getFinish())); //9213
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getStart())); //9214
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool ExecutionSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
			return getFinish() != nullptr; //9213
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
			return getStart() != nullptr; //9214
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool ExecutionSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _finish = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setFinish(_finish); //9213
			return true;
		}
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OccurrenceSpecification> _start = std::dynamic_pointer_cast<uml::OccurrenceSpecification>(_temp);
			setStart(_start); //9214
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExecutionSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutionSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("finish");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("finish")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("start");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("start")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ExecutionSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	InteractionFragmentImpl::loadNode(nodeName, loadHandler);
}

void ExecutionSpecificationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _finish = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setFinish(_finish);
			}
			
			return;
		}

		case uml::UmlPackage::EXECUTIONSPECIFICATION_ATTRIBUTE_START:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OccurrenceSpecification> _start = std::dynamic_pointer_cast<uml::OccurrenceSpecification>( references.front() );
				setStart(_start);
			}
			
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void ExecutionSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ExecutionSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("finish", this->getFinish());
		saveHandler->addReference("start", this->getStart());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/MessageOccurrenceSpecificationImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Message.hpp"

#include "uml/MessageEnd.hpp"

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
MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl()
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

MessageOccurrenceSpecificationImpl::~MessageOccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageOccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:MessageOccurrenceSpecificationImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:MessageOccurrenceSpecificationImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:MessageOccurrenceSpecificationImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:MessageOccurrenceSpecificationImpl()
			{
			    m_owner = par_owner;
			}






MessageOccurrenceSpecificationImpl::MessageOccurrenceSpecificationImpl(const MessageOccurrenceSpecificationImpl & obj):MessageOccurrenceSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageOccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_message  = obj.getMessage();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::GeneralOrdering>> _toAfter = obj.getToAfter();
	m_toAfter.reset(new Bag<uml::GeneralOrdering>(*(obj.getToAfter().get())));

	std::shared_ptr<Bag<uml::GeneralOrdering>> _toBefore = obj.getToBefore();
	m_toBefore.reset(new Bag<uml::GeneralOrdering>(*(obj.getToBefore().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  MessageOccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl(*this));
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> MessageOccurrenceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMessageOccurrenceSpecification_EClass();
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

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > MessageOccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> MessageOccurrenceSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > MessageOccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<MessageOccurrenceSpecification> MessageOccurrenceSpecificationImpl::getThisMessageOccurrenceSpecificationPtr() const
{
	return m_thisMessageOccurrenceSpecificationPtr.lock();
}
void MessageOccurrenceSpecificationImpl::setThisMessageOccurrenceSpecificationPtr(std::weak_ptr<MessageOccurrenceSpecification> thisMessageOccurrenceSpecificationPtr)
{
	m_thisMessageOccurrenceSpecificationPtr = thisMessageOccurrenceSpecificationPtr;
	setThisMessageEndPtr(thisMessageOccurrenceSpecificationPtr);
	setThisOccurrenceSpecificationPtr(thisMessageOccurrenceSpecificationPtr);
}
std::shared_ptr<ecore::EObject> MessageOccurrenceSpecificationImpl::eContainer() const
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
Any MessageOccurrenceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	Any result;
	result = MessageEndImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = OccurrenceSpecificationImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool MessageOccurrenceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	bool result = false;
	result = MessageEndImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = OccurrenceSpecificationImpl::internalEIsSet(featureID);
	return result;
}
bool MessageOccurrenceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = MessageEndImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = OccurrenceSpecificationImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void MessageOccurrenceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void MessageOccurrenceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	MessageEndImpl::loadAttributes(loadHandler, attr_list);
	OccurrenceSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void MessageOccurrenceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	MessageEndImpl::loadNode(nodeName, loadHandler, modelFactory);
	OccurrenceSpecificationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void MessageOccurrenceSpecificationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	MessageEndImpl::resolveReferences(featureID, references);
	OccurrenceSpecificationImpl::resolveReferences(featureID, references);
}

void MessageOccurrenceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageEndImpl::saveContent(saveHandler);
	OccurrenceSpecificationImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void MessageOccurrenceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


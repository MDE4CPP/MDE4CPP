#include "uml/impl/InteractionUseImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Gate.hpp"

#include "uml/GeneralOrdering.hpp"

#include "uml/Interaction.hpp"

#include "uml/InteractionFragment.hpp"

#include "uml/InteractionOperand.hpp"

#include "uml/Lifeline.hpp"

#include "uml/Namespace.hpp"

#include "uml/Property.hpp"

#include "uml/StringExpression.hpp"

#include "uml/ValueSpecification.hpp"

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
InteractionUseImpl::InteractionUseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_actualGate.reset(new Subset<uml::Gate, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	

	

	

	//Init references
		/*Subset*/
		m_actualGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	

	

	
}

InteractionUseImpl::~InteractionUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:InteractionUseImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
				m_namespace = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:InteractionUseImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
				m_namespace = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:InteractionUseImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			InteractionUseImpl::InteractionUseImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionUseImpl()
			{
			    m_owner = par_owner;
			}






InteractionUseImpl::InteractionUseImpl(const InteractionUseImpl & obj):InteractionUseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_refersTo  = obj.getRefersTo();

	m_returnValueRecipient  = obj.getReturnValueRecipient();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Gate>> _actualGateList = obj.getActualGate();
	for(std::shared_ptr<uml::Gate> _actualGate : *_actualGateList)
	{
		this->getActualGate()->add(std::shared_ptr<uml::Gate>(std::dynamic_pointer_cast<uml::Gate>(_actualGate->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_actualGate" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ValueSpecification>> _argumentList = obj.getArgument();
	for(std::shared_ptr<uml::ValueSpecification> _argument : *_argumentList)
	{
		this->getArgument()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_argument->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_argument" << std::endl;
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
	if(obj.getReturnValue()!=nullptr)
	{
		m_returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getReturnValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_returnValue" << std::endl;
	#endif

		/*Subset*/
		m_actualGate->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_actualGate - Subset<uml::Gate, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_argument->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

std::shared_ptr<ecore::EObject>  InteractionUseImpl::copy() const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl(*this));
	element->setThisInteractionUsePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionUse_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionUseImpl::all_lifelines(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_are_constants(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::arguments_correspond_to_parameters(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::gates_match(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValueRecipient_coverage(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionUseImpl::returnValue_type_recipient_correspondence(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Gate, uml::Element>> InteractionUseImpl::getActualGate() const
{

    return m_actualGate;
}


std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> InteractionUseImpl::getArgument() const
{

    return m_argument;
}


std::shared_ptr<uml::Interaction > InteractionUseImpl::getRefersTo() const
{
//assert(m_refersTo);
    return m_refersTo;
}
void InteractionUseImpl::setRefersTo(std::shared_ptr<uml::Interaction> _refersTo)
{
    m_refersTo = _refersTo;
}

std::shared_ptr<uml::ValueSpecification > InteractionUseImpl::getReturnValue() const
{

    return m_returnValue;
}
void InteractionUseImpl::setReturnValue(std::shared_ptr<uml::ValueSpecification> _returnValue)
{
    m_returnValue = _returnValue;
}

std::shared_ptr<uml::Property > InteractionUseImpl::getReturnValueRecipient() const
{

    return m_returnValueRecipient;
}
void InteractionUseImpl::setReturnValueRecipient(std::shared_ptr<uml::Property> _returnValueRecipient)
{
    m_returnValueRecipient = _returnValueRecipient;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InteractionUseImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InteractionUseImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionUseImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<InteractionUse> InteractionUseImpl::getThisInteractionUsePtr() const
{
	return m_thisInteractionUsePtr.lock();
}
void InteractionUseImpl::setThisInteractionUsePtr(std::weak_ptr<InteractionUse> thisInteractionUsePtr)
{
	m_thisInteractionUsePtr = thisInteractionUsePtr;
	setThisInteractionFragmentPtr(thisInteractionUsePtr);
}
std::shared_ptr<ecore::EObject> InteractionUseImpl::eContainer() const
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
Any InteractionUseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Gate>::iterator iter = m_actualGate->begin();
			Bag<uml::Gate>::iterator end = m_actualGate->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12513
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ValueSpecification>::iterator iter = m_argument->begin();
			Bag<uml::ValueSpecification>::iterator end = m_argument->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //12514
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getRefersTo())); //12515
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReturnValue())); //12516
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getReturnValueRecipient())); //12517
	}
	return InteractionFragmentImpl::eGet(featureID, resolve, coreType);
}
bool InteractionUseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
			return getActualGate() != nullptr; //12513
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
			return getArgument() != nullptr; //12514
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
			return getRefersTo() != nullptr; //12515
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
			return getReturnValue() != nullptr; //12516
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
			return getReturnValueRecipient() != nullptr; //12517
	}
	return InteractionFragmentImpl::internalEIsSet(featureID);
}
bool InteractionUseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ACTUALGATE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Gate>> actualGateList(new Bag<uml::Gate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				actualGateList->add(std::dynamic_pointer_cast<uml::Gate>(*iter));
				iter++;
			}
			
			Bag<uml::Gate>::iterator iterActualGate = m_actualGate->begin();
			Bag<uml::Gate>::iterator endActualGate = m_actualGate->end();
			while (iterActualGate != endActualGate)
			{
				if (actualGateList->find(*iterActualGate) == -1)
				{
					m_actualGate->erase(*iterActualGate);
				}
				iterActualGate++;
			}

			iterActualGate = actualGateList->begin();
			endActualGate = actualGateList->end();
			while (iterActualGate != endActualGate)
			{
				if (m_actualGate->find(*iterActualGate) == -1)
				{
					m_actualGate->add(*iterActualGate);
				}
				iterActualGate++;			
			}
			return true;
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_ARGUMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ValueSpecification>> argumentList(new Bag<uml::ValueSpecification>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				argumentList->add(std::dynamic_pointer_cast<uml::ValueSpecification>(*iter));
				iter++;
			}
			
			Bag<uml::ValueSpecification>::iterator iterArgument = m_argument->begin();
			Bag<uml::ValueSpecification>::iterator endArgument = m_argument->end();
			while (iterArgument != endArgument)
			{
				if (argumentList->find(*iterArgument) == -1)
				{
					m_argument->erase(*iterArgument);
				}
				iterArgument++;
			}

			iterArgument = argumentList->begin();
			endArgument = argumentList->end();
			while (iterArgument != endArgument)
			{
				if (m_argument->find(*iterArgument) == -1)
				{
					m_argument->add(*iterArgument);
				}
				iterArgument++;			
			}
			return true;
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _refersTo = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setRefersTo(_refersTo); //12515
			return true;
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setReturnValue(_returnValue); //12516
			return true;
		}
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _returnValueRecipient = std::dynamic_pointer_cast<uml::Property>(_temp);
			setReturnValueRecipient(_returnValueRecipient); //12517
			return true;
		}
	}

	return InteractionFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InteractionUseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionUseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("refersTo");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("refersTo")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("returnValueRecipient");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("returnValueRecipient")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InteractionUseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("actualGate") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Gate";
			}
			std::shared_ptr<uml::Gate> actualGate = std::dynamic_pointer_cast<uml::Gate>(modelFactory->create(typeName));
			if (actualGate != nullptr)
			{
				std::shared_ptr<Subset<uml::Gate, uml::Element>> list_actualGate = this->getActualGate();
				list_actualGate->push_back(actualGate);
				loadHandler->handleChild(actualGate);
			}
			return;
		}

		if ( nodeName.compare("argument") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> argument = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (argument != nullptr)
			{
				std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> list_argument = this->getArgument();
				list_argument->push_back(argument);
				loadHandler->handleChild(argument);
			}
			return;
		}

		if ( nodeName.compare("returnValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> returnValue = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (returnValue != nullptr)
			{
				this->setReturnValue(returnValue);
				loadHandler->handleChild(returnValue);
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

	InteractionFragmentImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InteractionUseImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_REFERSTO:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _refersTo = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setRefersTo(_refersTo);
			}
			
			return;
		}

		case UmlPackage::INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _returnValueRecipient = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setReturnValueRecipient(_returnValueRecipient);
			}
			
			return;
		}
	}
	InteractionFragmentImpl::resolveReferences(featureID, references);
}

void InteractionUseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InteractionUseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'actualGate'
		for (std::shared_ptr<uml::Gate> actualGate : *this->getActualGate()) 
		{
			saveHandler->addReference(actualGate, "actualGate", actualGate->eClass() != package->getGate_Class());
		}

		// Save 'argument'
		for (std::shared_ptr<uml::ValueSpecification> argument : *this->getArgument()) 
		{
			saveHandler->addReference(argument, "argument", argument->eClass() != package->getValueSpecification_Class());
		}

		// Save 'returnValue'
		std::shared_ptr<uml::ValueSpecification > returnValue = this->getReturnValue();
		if (returnValue != nullptr)
		{
			saveHandler->addReference(returnValue, "returnValue", returnValue->eClass() != package->getValueSpecification_Class());
		}
	

		// Add references
		saveHandler->addReference("refersTo", this->getRefersTo());
		saveHandler->addReference("returnValueRecipient", this->getReturnValueRecipient());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


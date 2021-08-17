#include "uml/impl/ConnectorImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Association.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Connector.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Feature.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredClassifier.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorImpl::ConnectorImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectorImpl::~ConnectorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Connector "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConnectorImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectorImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::StructuredClassifier> par_structuredClassifier)
:ConnectorImpl()
{
	m_structuredClassifier = par_structuredClassifier;
	m_namespace = par_structuredClassifier;
}

ConnectorImpl::ConnectorImpl(const ConnectorImpl & obj): ConnectorImpl()
{
	*this = obj;
}

ConnectorImpl& ConnectorImpl::operator=(const ConnectorImpl & obj)
{
	//call overloaded =Operator for each base class
	FeatureImpl::operator=(obj);
	Connector::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Connector "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();

	//copy references with no containment (soft copy)
	m_contract  = obj.getContract();
	m_structuredClassifier  = obj.getStructuredClassifier();
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	//clone reference 'end'
	std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> endList = obj.getEnd();
	if(endList)
	{
		Bag<uml::ConnectorEnd>::iterator endIter = endList->begin();
		Bag<uml::ConnectorEnd>::iterator endEnd = endList->end();
		while (endIter != endEnd) 
		{
			std::shared_ptr<uml::ConnectorEnd> temp = std::dynamic_pointer_cast<uml::ConnectorEnd>((*endIter)->copy());
			getEnd()->push_back(temp);
			endIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr end."<< std::endl;)
	}

	//clone reference 'redefinedConnector'
	std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> redefinedConnectorList = obj.getRedefinedConnector();
	if(redefinedConnectorList)
	{
		Bag<uml::Connector>::iterator redefinedConnectorIter = redefinedConnectorList->begin();
		Bag<uml::Connector>::iterator redefinedConnectorEnd = redefinedConnectorList->end();
		while (redefinedConnectorIter != redefinedConnectorEnd) 
		{
			std::shared_ptr<uml::Connector> temp = std::dynamic_pointer_cast<uml::Connector>((*redefinedConnectorIter)->copy());
			getRedefinedConnector()->push_back(temp);
			redefinedConnectorIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedConnector."<< std::endl;)
	}
	/*Subset*/
	getEnd()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectorImpl::copy() const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl());
	*element =(*this);
	element->setThisConnectorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectorImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnector_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute kind
*/
uml::ConnectorKind ConnectorImpl::getKind() const 
{
	return m_kind;
}



//*********************************
// Operations
//*********************************
uml::ConnectorKind ConnectorImpl::getKind()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorImpl::roles(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorImpl::types(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference contract
*/
std::shared_ptr<Bag<uml::Behavior>> ConnectorImpl::getContract() const
{
	if(m_contract == nullptr)
	{
		m_contract.reset(new Bag<uml::Behavior>());
		
		
	}
    return m_contract;
}



/*
Getter & Setter for reference end
*/
std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> ConnectorImpl::getEnd() const
{
	if(m_end == nullptr)
	{
		/*Subset*/
		m_end.reset(new Subset<uml::ConnectorEnd, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEnd()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_end;
}



/*
Getter & Setter for reference redefinedConnector
*/
std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> ConnectorImpl::getRedefinedConnector() const
{
	if(m_redefinedConnector == nullptr)
	{
		/*Subset*/
		m_redefinedConnector.reset(new Subset<uml::Connector, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedConnector()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}
    return m_redefinedConnector;
}



/*
Getter & Setter for reference structuredClassifier
*/
std::weak_ptr<uml::StructuredClassifier> ConnectorImpl::getStructuredClassifier() const
{
    return m_structuredClassifier;
}
void ConnectorImpl::setStructuredClassifier(std::weak_ptr<uml::StructuredClassifier> _structuredClassifier)
{
    m_structuredClassifier = _structuredClassifier;
	
}


/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::Association> ConnectorImpl::getType() const
{
    return m_type;
}
void ConnectorImpl::setType(std::shared_ptr<uml::Association> _type)
{
    m_type = _type;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> ConnectorImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

std::weak_ptr<uml::Namespace> ConnectorImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConnectorImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConnectorImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ConnectorImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> ConnectorImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}




std::shared_ptr<Connector> ConnectorImpl::getThisConnectorPtr() const
{
	return m_thisConnectorPtr.lock();
}
void ConnectorImpl::setThisConnectorPtr(std::weak_ptr<Connector> thisConnectorPtr)
{
	m_thisConnectorPtr = thisConnectorPtr;
	setThisFeaturePtr(thisConnectorPtr);
}
std::shared_ptr<ecore::EObject> ConnectorImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_structuredClassifier.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Behavior>::iterator iter = getContract()->begin();
			Bag<uml::Behavior>::iterator end = getContract()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5314			
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectorEnd>::iterator iter = getEnd()->begin();
			Bag<uml::ConnectorEnd>::iterator end = getEnd()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5315			
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return eAny(getKind()); //5316
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Connector>::iterator iter = getRedefinedConnector()->begin();
			Bag<uml::Connector>::iterator end = getRedefinedConnector()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5317			
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getStructuredClassifier().lock();
				return eAny(returnValue); //5319
			}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getType();
				return eAny(returnValue); //5318
			}
	}
	return FeatureImpl::eGet(featureID, resolve, coreType);
}
bool ConnectorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //5314
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
			return getEnd() != nullptr; //5315
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return m_kind != ConnectorKind::ASSEMBLY;; //5316
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
			return getRedefinedConnector() != nullptr; //5317
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
			return getStructuredClassifier().lock() != nullptr; //5319
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			return getType() != nullptr; //5318
	}
	return FeatureImpl::internalEIsSet(featureID);
}
bool ConnectorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Behavior>> contractList(new Bag<uml::Behavior>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				contractList->add(std::dynamic_pointer_cast<uml::Behavior>(*iter));
				iter++;
			}
			
			Bag<uml::Behavior>::iterator iterContract = getContract()->begin();
			Bag<uml::Behavior>::iterator endContract = getContract()->end();
			while (iterContract != endContract)
			{
				if (contractList->find(*iterContract) == -1)
				{
					getContract()->erase(*iterContract);
				}
				iterContract++;
			}
 
			iterContract = contractList->begin();
			endContract = contractList->end();
			while (iterContract != endContract)
			{
				if (getContract()->find(*iterContract) == -1)
				{
					getContract()->add(*iterContract);
				}
				iterContract++;			
			}
			return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_END:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ConnectorEnd>> endList(new Bag<uml::ConnectorEnd>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				endList->add(std::dynamic_pointer_cast<uml::ConnectorEnd>(*iter));
				iter++;
			}
			
			Bag<uml::ConnectorEnd>::iterator iterEnd = getEnd()->begin();
			Bag<uml::ConnectorEnd>::iterator endEnd = getEnd()->end();
			while (iterEnd != endEnd)
			{
				if (endList->find(*iterEnd) == -1)
				{
					getEnd()->erase(*iterEnd);
				}
				iterEnd++;
			}
 
			iterEnd = endList->begin();
			endEnd = endList->end();
			while (iterEnd != endEnd)
			{
				if (getEnd()->find(*iterEnd) == -1)
				{
					getEnd()->add(*iterEnd);
				}
				iterEnd++;			
			}
			return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Connector>> redefinedConnectorList(new Bag<uml::Connector>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedConnectorList->add(std::dynamic_pointer_cast<uml::Connector>(*iter));
				iter++;
			}
			
			Bag<uml::Connector>::iterator iterRedefinedConnector = getRedefinedConnector()->begin();
			Bag<uml::Connector>::iterator endRedefinedConnector = getRedefinedConnector()->end();
			while (iterRedefinedConnector != endRedefinedConnector)
			{
				if (redefinedConnectorList->find(*iterRedefinedConnector) == -1)
				{
					getRedefinedConnector()->erase(*iterRedefinedConnector);
				}
				iterRedefinedConnector++;
			}
 
			iterRedefinedConnector = redefinedConnectorList->begin();
			endRedefinedConnector = redefinedConnectorList->end();
			while (iterRedefinedConnector != endRedefinedConnector)
			{
				if (getRedefinedConnector()->find(*iterRedefinedConnector) == -1)
				{
					getRedefinedConnector()->add(*iterRedefinedConnector);
				}
				iterRedefinedConnector++;			
			}
			return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuredClassifier> _structuredClassifier = std::dynamic_pointer_cast<uml::StructuredClassifier>(_temp);
			setStructuredClassifier(_structuredClassifier); //5319
			return true;
		}
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>(_temp);
			setType(_type); //5318
			return true;
		}
	}

	return FeatureImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ConnectorImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5383
		case umlPackage::CONNECTOR_OPERATION_GETKIND:
		{
			result = eAny(this->getKind());
			break;
		}
		
		// 5382
		case umlPackage::CONNECTOR_OPERATION_ROLES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->roles(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5381
		case umlPackage::CONNECTOR_OPERATION_TYPES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->types(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = FeatureImpl::eInvoke(operationID, arguments);
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
void ConnectorImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectorImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("contract");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("contract")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedConnector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedConnector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	FeatureImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectorImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("end") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ConnectorEnd";
			}
			loadHandler->handleChildContainer<uml::ConnectorEnd>(this->getEnd());  

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
	FeatureImpl::loadNode(nodeName, loadHandler);
}

void ConnectorImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<Bag<uml::Behavior>> _contract = getContract();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior>  _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_contract->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> _redefinedConnector = getRedefinedConnector();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Connector>  _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_redefinedConnector->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuredClassifier> _structuredClassifier = std::dynamic_pointer_cast<uml::StructuredClassifier>( references.front() );
				setStructuredClassifier(_structuredClassifier);
			}
			
			return;
		}

		case uml::umlPackage::CONNECTOR_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	FeatureImpl::resolveReferences(featureID, references);
}

void ConnectorImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	FeatureImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ConnectorImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'end'
		for (std::shared_ptr<uml::ConnectorEnd> end : *this->getEnd()) 
		{
			saveHandler->addReference(end, "end", end->eClass() != package->getConnectorEnd_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Behavior>("contract", this->getContract());
		saveHandler->addReferences<uml::Connector>("redefinedConnector", this->getRedefinedConnector());
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getAssociation_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


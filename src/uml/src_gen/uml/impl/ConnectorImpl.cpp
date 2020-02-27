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

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorImpl::ConnectorImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_contract.reset(new Bag<uml::Behavior>());
	
	

		/*Subset*/
		m_end.reset(new Subset<uml::ConnectorEnd, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedConnector.reset(new Subset<uml::Connector, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

	

	//Init references
	
	

		/*Subset*/
		m_end->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedConnector->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedConnector - Subset<uml::Connector, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

	
}

ConnectorImpl::~ConnectorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Connector "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ConnectorImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}


//Additional constructor for the containments back reference
			ConnectorImpl::ConnectorImpl(std::weak_ptr<uml::Element > par_owner)
			:ConnectorImpl()
			{
			    m_owner = par_owner;
			}



ConnectorImpl::ConnectorImpl(const ConnectorImpl & obj):ConnectorImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Connector "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Behavior>> _contract = obj.getContract();
	m_contract.reset(new Bag<uml::Behavior>(*(obj.getContract().get())));

	std::shared_ptr<Union<uml::Classifier>> _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::ConnectorEnd>> _endList = obj.getEnd();
	for(std::shared_ptr<uml::ConnectorEnd> _end : *_endList)
	{
		this->getEnd()->add(std::shared_ptr<uml::ConnectorEnd>(std::dynamic_pointer_cast<uml::ConnectorEnd>(_end->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_end" << std::endl;
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
	std::shared_ptr<Bag<uml::Connector>> _redefinedConnectorList = obj.getRedefinedConnector();
	for(std::shared_ptr<uml::Connector> _redefinedConnector : *_redefinedConnectorList)
	{
		this->getRedefinedConnector()->add(std::shared_ptr<uml::Connector>(std::dynamic_pointer_cast<uml::Connector>(_redefinedConnector->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedConnector" << std::endl;
	#endif

		/*Subset*/
		m_end->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_end - Subset<uml::ConnectorEnd, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ConnectorImpl::copy() const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl(*this));
	element->setThisConnectorPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectorImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getConnector_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************


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

bool ConnectorImpl::roles(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorImpl::types(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Behavior>> ConnectorImpl::getContract() const
{

    return m_contract;
}


std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> ConnectorImpl::getEnd() const
{
//assert(m_end);
    return m_end;
}


std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> ConnectorImpl::getRedefinedConnector() const
{

    return m_redefinedConnector;
}


std::shared_ptr<uml::Association > ConnectorImpl::getType() const
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
std::shared_ptr<Union<uml::Element>> ConnectorImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ConnectorImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::RedefinableElement>> ConnectorImpl::getRedefinedElement() const
{
	return m_redefinedElement;
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectorImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Behavior>::iterator iter = m_contract->begin();
			Bag<uml::Behavior>::iterator end = m_contract->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5414
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_END:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectorEnd>::iterator iter = m_end->begin();
			Bag<uml::ConnectorEnd>::iterator end = m_end->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5415
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return eAny(getKind()); //5416
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Connector>::iterator iter = m_redefinedConnector->begin();
			Bag<uml::Connector>::iterator end = m_redefinedConnector->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5417
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getType())); //5418
	}
	return FeatureImpl::eGet(featureID, resolve, coreType);
}
bool ConnectorImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //5414
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_END:
			return getEnd() != nullptr; //5415
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_KIND:
			return m_kind != ConnectorKind::ASSEMBLY;; //5416
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
			return getRedefinedConnector() != nullptr; //5417
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_TYPE:
			return getType() != nullptr; //5418
	}
	return FeatureImpl::internalEIsSet(featureID);
}
bool ConnectorImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
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
			
			Bag<uml::Behavior>::iterator iterContract = m_contract->begin();
			Bag<uml::Behavior>::iterator endContract = m_contract->end();
			while (iterContract != endContract)
			{
				if (contractList->find(*iterContract) == -1)
				{
					m_contract->erase(*iterContract);
				}
				iterContract++;
			}

			iterContract = contractList->begin();
			endContract = contractList->end();
			while (iterContract != endContract)
			{
				if (m_contract->find(*iterContract) == -1)
				{
					m_contract->add(*iterContract);
				}
				iterContract++;			
			}
			return true;
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_END:
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
			
			Bag<uml::ConnectorEnd>::iterator iterEnd = m_end->begin();
			Bag<uml::ConnectorEnd>::iterator endEnd = m_end->end();
			while (iterEnd != endEnd)
			{
				if (endList->find(*iterEnd) == -1)
				{
					m_end->erase(*iterEnd);
				}
				iterEnd++;
			}

			iterEnd = endList->begin();
			endEnd = endList->end();
			while (iterEnd != endEnd)
			{
				if (m_end->find(*iterEnd) == -1)
				{
					m_end->add(*iterEnd);
				}
				iterEnd++;			
			}
			return true;
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
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
			
			Bag<uml::Connector>::iterator iterRedefinedConnector = m_redefinedConnector->begin();
			Bag<uml::Connector>::iterator endRedefinedConnector = m_redefinedConnector->end();
			while (iterRedefinedConnector != endRedefinedConnector)
			{
				if (redefinedConnectorList->find(*iterRedefinedConnector) == -1)
				{
					m_redefinedConnector->erase(*iterRedefinedConnector);
				}
				iterRedefinedConnector++;
			}

			iterRedefinedConnector = redefinedConnectorList->begin();
			endRedefinedConnector = redefinedConnectorList->end();
			while (iterRedefinedConnector != endRedefinedConnector)
			{
				if (m_redefinedConnector->find(*iterRedefinedConnector) == -1)
				{
					m_redefinedConnector->add(*iterRedefinedConnector);
				}
				iterRedefinedConnector++;			
			}
			return true;
		}
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>(_temp);
			setType(_type); //5418
			return true;
		}
	}

	return FeatureImpl::eSet(featureID, newValue);
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
	// get UmlFactory
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
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	try
	{
		if ( nodeName.compare("end") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ConnectorEnd";
			}
			std::shared_ptr<uml::ConnectorEnd> end = std::dynamic_pointer_cast<uml::ConnectorEnd>(modelFactory->create(typeName));
			if (end != nullptr)
			{
				std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> list_end = this->getEnd();
				list_end->push_back(end);
				loadHandler->handleChild(end);
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
	FeatureImpl::loadNode(nodeName, loadHandler);
}

void ConnectorImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_CONTRACT:
		{
			std::shared_ptr<Bag<uml::Behavior>> _contract = getContract();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Behavior> _r = std::dynamic_pointer_cast<uml::Behavior>(ref);
				if (_r != nullptr)
				{
					_contract->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR:
		{
			std::shared_ptr<Bag<uml::Connector>> _redefinedConnector = getRedefinedConnector();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Connector> _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_redefinedConnector->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::CONNECTOR_ATTRIBUTE_TYPE:
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
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'end'
		for (std::shared_ptr<uml::ConnectorEnd> end : *this->getEnd()) 
		{
			saveHandler->addReference(end, "end", end->eClass() != package->getConnectorEnd_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Behavior>> contract_list = this->getContract();
		for (std::shared_ptr<uml::Behavior > object : *contract_list)
		{ 
			saveHandler->addReferences("contract", object);
		}
		std::shared_ptr<Bag<uml::Connector>> redefinedConnector_list = this->getRedefinedConnector();
		for (std::shared_ptr<uml::Connector > object : *redefinedConnector_list)
		{ 
			saveHandler->addReferences("redefinedConnector", object);
		}
		saveHandler->addReference("type", this->getType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


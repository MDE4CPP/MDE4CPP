#include "fUML/impl/LinkImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Property.hpp"
#include "uml/Association.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Association.hpp"

#include "uml/Classifier.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "uml/Property.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LinkImpl::LinkImpl()
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

LinkImpl::~LinkImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Link "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




LinkImpl::LinkImpl(const LinkImpl & obj):LinkImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Link "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  LinkImpl::copy() const
{
	std::shared_ptr<LinkImpl> element(new LinkImpl(*this));
	element->setThisLinkPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLink_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void LinkImpl::addTo(std::shared_ptr<fUML::Locus>  locus)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<fUML::FeatureValue> > LinkImpl::getOtherFeatureValues(std::shared_ptr<Bag<fUML::ExtensionalValue> >  extent,std::shared_ptr<uml::Property>  end)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > LinkImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());

	if( this->getType() != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
	}
    return types;
	//end of body
}

bool LinkImpl::isMatchingLink(std::shared_ptr<fUML::ExtensionalValue>  link,std::shared_ptr<uml::Property>  end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Property> > ends = this->getType()->getMemberEnd();

	bool matches = true;
	unsigned int i = 0;
	while (matches && i < ends->size()) 
	{
		std::shared_ptr<uml::Property> otherEnd = ends->at(i);
		if (otherEnd != end
				&& !this->retrieveFeatureValue(otherEnd)->getValues()->at(0)
						->equals(
								link->retrieveFeatureValue(otherEnd)->getValues()->at(0))) {
			matches = false;
		}
		i = i + 1;
	}

	return matches;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Association > LinkImpl::getType() const
{

    return m_type;
}
void LinkImpl::setType(std::shared_ptr<uml::Association> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Link> LinkImpl::getThisLinkPtr() const
{
	return m_thisLinkPtr.lock();
}
void LinkImpl::setThisLinkPtr(std::weak_ptr<Link> thisLinkPtr)
{
	m_thisLinkPtr = thisLinkPtr;
	setThisExtensionalValuePtr(thisLinkPtr);
}
std::shared_ptr<ecore::EObject> LinkImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any LinkImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::LINK_EREFERENCE_TYPE:
			return eAny(getType()); //322
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}
bool LinkImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::LINK_EREFERENCE_TYPE:
			return getType() != nullptr; //322
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool LinkImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::LINK_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Association> _type = newValue->get<std::shared_ptr<uml::Association>>();
			setType(_type); //322
			return true;
		}
	}

	return ExtensionalValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LinkImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void LinkImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
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

	ExtensionalValueImpl::loadAttributes(loadHandler, attr_list);
}

void LinkImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ExtensionalValueImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void LinkImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case FUMLPackage::LINK_EREFERENCE_TYPE:
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
	ExtensionalValueImpl::resolveReferences(featureID, references);
}

void LinkImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExtensionalValueImpl::saveContent(saveHandler);
	
	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	ValueImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void LinkImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	

		// Add references
		saveHandler->addReference("type", this->getType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


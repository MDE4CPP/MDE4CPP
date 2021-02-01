#include "fUML/Semantics/StructuredClassifiers/impl/LinkImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "abstractDataTypes/SubsetUnion.hpp"
#include "uml/Property.hpp"
#include "uml/Association.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Association.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "uml/Property.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/fUMLFactory.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
LinkImpl::LinkImpl()
{	
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

	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>(std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(_featureValues->copy())));
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
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getLink_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> LinkImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new link with the same type, locus and feature values as this link.

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> newValue = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::_copy());

newValue->setType(this->getType());

return newValue;
	//end of body
}

void LinkImpl::addTo(std::shared_ptr<fUML::Semantics::Loci::Locus> locus)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Add this link to the extent of its association at the given locus,
	// Shift the positions of ends of other links, as appropriate, for ends
	// that are ordered.

	std::shared_ptr<Bag<uml::Property>> ends = this->getType()->getMemberEnd();
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = locus->retrieveExtent(this->getType());

	unsigned int endsSize = ends->size();
	for (unsigned int i = 0; i < endsSize; i++) {
		std::shared_ptr<uml::Property> end = ends->at(i);
		if (end->getIsOrdered()) {
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue =
					this->retrieveFeatureValue(end);
			std::shared_ptr<
					Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> otherFeatureValues =
					this->getOtherFeatureValues(extent, end);
			int n = otherFeatureValues->size();
			if (featureValue->getPosition() < 0
					|| featureValue->getPosition() > n) {
				featureValue->setPosition(n + 1);
			} else {
				if (featureValue->getPosition() == 0) {
					featureValue->setPosition(-1);
				}
				for (int j = 0; j < n; j++) {
					std::shared_ptr<
							fUML::Semantics::SimpleClassifiers::FeatureValue> otherFeatureValue =
							otherFeatureValues->at(j);
					if (featureValue->getPosition()
							<= otherFeatureValue->getPosition()) {
						otherFeatureValue->setPosition(
								otherFeatureValue->getPosition() + 1);
					}
				}
			}
		}
	}
	locus->add(getThisLinkPtr());
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > LinkImpl::getOtherFeatureValues(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent,std::shared_ptr<uml::Property> end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Return all feature values for the given end of links in the given
	// extent whose other ends match this link.
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues(new Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>());
	unsigned int extentSize = extent->size();
	for(unsigned int i = 0; i < extentSize; i++)
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link = extent->at(i);
		if(link != getThisLinkPtr())
		{
			if(isMatchingLink(link, end))
			{
				featureValues->add(link->retrieveFeatureValue(end));
			}
		}
	}
	return featureValues;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > LinkImpl::getTypes() const
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

bool LinkImpl::isMatchingLink(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link,std::shared_ptr<uml::Property> end)
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
/*
Getter & Setter for reference type
*/
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
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_ATTRIBUTE_TYPE:
			return eAny(getType()); //682
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}
bool LinkImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_ATTRIBUTE_TYPE:
			return getType() != nullptr; //682
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool LinkImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _type = std::dynamic_pointer_cast<uml::Association>(_temp);
			setType(_type); //682
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
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
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

void LinkImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	ExtensionalValueImpl::loadNode(nodeName, loadHandler);
}

void LinkImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_ATTRIBUTE_TYPE:
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
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void LinkImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	// Add references
		saveHandler->addReference("type", this->getType()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "PSCS/Semantics/StructuredClassifiers/impl/CS_LinkImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Association.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/StructuredClassifiers/Link.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

#include "uml/StructuralFeature.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/StructuredClassifiers/Impl/StructuredClassifiersFactoryImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/Impl/StructuredClassifiersPackageImpl.hpp"

#include "PSCS/Semantics/SemanticsFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_LinkImpl::CS_LinkImpl()
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

CS_LinkImpl::~CS_LinkImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_Link "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_LinkImpl::CS_LinkImpl(const CS_LinkImpl & obj):CS_LinkImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_Link "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  CS_LinkImpl::copy() const
{
	std::shared_ptr<CS_LinkImpl> element(new CS_LinkImpl(*this));
	element->setThisCS_LinkPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_LinkImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_Link_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StructuralFeature> CS_LinkImpl::getFeature(std::shared_ptr<fUML::Semantics::Values::Value>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> allFeatureValues = this->getFeatureValues();
	unsigned int i = 1;
	std::shared_ptr<uml::StructuralFeature> feature = nullptr;
	while((i <= allFeatureValues->size()) && (feature == nullptr)) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = allFeatureValues->at(i-1);
		if((!(featureValue->getValues()->empty())) && (featureValue->getValues()->at(0)->equals(value))) {
			feature = featureValue->getFeature();
		}
		i += 1;
	}
	return feature;
	//end of body
}

bool CS_LinkImpl::hasValueForAFeature(std::shared_ptr<fUML::Semantics::Values::Value>  value)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// Returns true if the given value object is used as a value for a FeatureValue of this link
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> allFeatureValues = this->getFeatureValues();
	unsigned int i = 1;
	bool isAValue = false;
	while((i <= allFeatureValues->size()) && (!isAValue)) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = allFeatureValues->at(i-1);
		isAValue = (!(featureValue->getValues()->empty())) && (featureValue->getValues()->at(0)->equals(value));
		i += 1;
	}
	return isAValue;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_Link> CS_LinkImpl::getThisCS_LinkPtr() const
{
	return m_thisCS_LinkPtr.lock();
}
void CS_LinkImpl::setThisCS_LinkPtr(std::weak_ptr<CS_Link> thisCS_LinkPtr)
{
	m_thisCS_LinkPtr = thisCS_LinkPtr;
	setThisLinkPtr(thisCS_LinkPtr);
}
std::shared_ptr<ecore::EObject> CS_LinkImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_LinkImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::LinkImpl::eGet(featureID, resolve, coreType);
}
bool CS_LinkImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::StructuredClassifiers::LinkImpl::internalEIsSet(featureID);
}
bool CS_LinkImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::StructuredClassifiers::LinkImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_LinkImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_LinkImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::StructuredClassifiers::LinkImpl::loadAttributes(loadHandler, attr_list);
}

void CS_LinkImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::StructuredClassifiers::LinkImpl::loadNode(nodeName, loadHandler);
}

void CS_LinkImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::StructuredClassifiers::LinkImpl::resolveReferences(featureID, references);
}

void CS_LinkImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::StructuredClassifiers::LinkImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void CS_LinkImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"

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

#include "fUML/Semantics/SimpleClassifiers/CompoundValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"

#include "fUML/Semantics/Loci/Locus.hpp"

//Factories an Package includes
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersPackageImpl.hpp"

#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/Semantics/SemanticsFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionalValueImpl::ExtensionalValueImpl()
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

ExtensionalValueImpl::~ExtensionalValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionalValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ExtensionalValueImpl::ExtensionalValueImpl(const ExtensionalValueImpl & obj):ExtensionalValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionalValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


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

std::shared_ptr<ecore::EObject>  ExtensionalValueImpl::copy() const
{
	std::shared_ptr<ExtensionalValueImpl> element(new ExtensionalValueImpl(*this));
	element->setThisExtensionalValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExtensionalValueImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getExtensionalValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExtensionalValueImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getLocus() != nullptr)
    {
        this->getLocus()->remove(getThisExtensionalValuePtr());
    }
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Semantics::Loci::Locus > ExtensionalValueImpl::getLocus() const
{

    return m_locus;
}
void ExtensionalValueImpl::setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus)
{
    m_locus = _locus;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ExtensionalValue> ExtensionalValueImpl::getThisExtensionalValuePtr() const
{
	return m_thisExtensionalValuePtr.lock();
}
void ExtensionalValueImpl::setThisExtensionalValuePtr(std::weak_ptr<ExtensionalValue> thisExtensionalValuePtr)
{
	m_thisExtensionalValuePtr = thisExtensionalValuePtr;
	setThisCompoundValuePtr(thisExtensionalValuePtr);
}
std::shared_ptr<ecore::EObject> ExtensionalValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExtensionalValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_ATTRIBUTE_LOCUS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getLocus())); //521
	}
	return fUML::Semantics::SimpleClassifiers::CompoundValueImpl::eGet(featureID, resolve, coreType);
}
bool ExtensionalValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //521
	}
	return fUML::Semantics::SimpleClassifiers::CompoundValueImpl::internalEIsSet(featureID);
}
bool ExtensionalValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>(_temp);
			setLocus(_locus); //521
			return true;
		}
	}

	return fUML::Semantics::SimpleClassifiers::CompoundValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExtensionalValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExtensionalValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("locus");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("locus")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionalValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory> modelFactory=fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance();

	//load BasePackage Nodes
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::loadNode(nodeName, loadHandler);
}

void ExtensionalValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::EXTENSIONALVALUE_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Loci::Locus> _locus = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}
	}
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::resolveReferences(featureID, references);
}

void ExtensionalValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ExtensionalValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();

	

		// Add references
		saveHandler->addReference("locus", this->getLocus());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


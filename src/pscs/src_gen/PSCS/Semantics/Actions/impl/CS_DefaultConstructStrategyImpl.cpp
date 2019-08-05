#include "PSCS/Semantics/Actions/impl/CS_DefaultConstructStrategyImpl.hpp"

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

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/impl/PSCSPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "PSCS/PSCSFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Association.hpp"

#include "PSCS/Semantics/Actions/CS_ConstructStrategy.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"

#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"

#include "uml/Class.hpp"

#include "uml/Connector.hpp"

#include "uml/ConnectorEnd.hpp"

#include "uml/Interface.hpp"

#include "fUML/Locus.hpp"

#include "uml/Property.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/PSCSFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_DefaultConstructStrategyImpl::CS_DefaultConstructStrategyImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_generatedRealizingClasses.reset(new Bag<uml::Class>());
	
	

	

	//Init references
	

	
	

	
}

CS_DefaultConstructStrategyImpl::~CS_DefaultConstructStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DefaultConstructStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




CS_DefaultConstructStrategyImpl::CS_DefaultConstructStrategyImpl(const CS_DefaultConstructStrategyImpl & obj):CS_DefaultConstructStrategyImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DefaultConstructStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


	//Clone references with containment (deep copy)

	if(obj.getDefaultAssociation()!=nullptr)
	{
		m_defaultAssociation = std::dynamic_pointer_cast<uml::Association>(obj.getDefaultAssociation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_defaultAssociation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Class>> _generatedRealizingClassesList = obj.getGeneratedRealizingClasses();
	for(std::shared_ptr<uml::Class> _generatedRealizingClasses : *_generatedRealizingClassesList)
	{
		this->getGeneratedRealizingClasses()->add(std::shared_ptr<uml::Class>(std::dynamic_pointer_cast<uml::Class>(_generatedRealizingClasses->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generatedRealizingClasses" << std::endl;
	#endif

	

	
	
}

std::shared_ptr<ecore::EObject>  CS_DefaultConstructStrategyImpl::copy() const
{
	std::shared_ptr<CS_DefaultConstructStrategyImpl> element(new CS_DefaultConstructStrategyImpl(*this));
	element->setThisCS_DefaultConstructStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DefaultConstructStrategyImpl::eStaticClass() const
{
	return PSCSPackageImpl::eInstance()->getCS_DefaultConstructStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CS_DefaultConstructStrategyImpl::addStructuralFeatureValue(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Property>  feature,Any value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CS_DefaultConstructStrategyImpl::canInstantiate(std::shared_ptr<uml::Property>  p)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any CS_DefaultConstructStrategyImpl::constructObject(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  context,std::shared_ptr<uml::Class>  type)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_DefaultConstructStrategyImpl::generateArrayPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Connector>  connector)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> CS_DefaultConstructStrategyImpl::generateRealizingClass(std::shared_ptr<uml::Interface>  interface_,std::string className)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void CS_DefaultConstructStrategyImpl::generateStarPattern(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::Connector>  connector)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int CS_DefaultConstructStrategyImpl::getCardinality(std::shared_ptr<uml::ConnectorEnd>  end)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::shared_ptr<uml::Class> CS_DefaultConstructStrategyImpl::getRealizingClass(std::shared_ptr<uml::Interface>  interface_)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<Any> > CS_DefaultConstructStrategyImpl::getValuesFromConnectorEnd(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference>  context,std::shared_ptr<uml::ConnectorEnd>  end)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any CS_DefaultConstructStrategyImpl::instantiateInterface(std::shared_ptr<uml::Interface>  interface,Any locus)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CS_DefaultConstructStrategyImpl::isArrayPattern(std::shared_ptr<uml::Connector>  c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CS_DefaultConstructStrategyImpl::isStarPattern(std::shared_ptr<uml::Connector>  c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Association > CS_DefaultConstructStrategyImpl::getDefaultAssociation() const
{
//assert(m_defaultAssociation);
    return m_defaultAssociation;
}
void CS_DefaultConstructStrategyImpl::setDefaultAssociation(std::shared_ptr<uml::Association> _defaultAssociation)
{
    m_defaultAssociation = _defaultAssociation;
}

std::shared_ptr<Bag<uml::Class>> CS_DefaultConstructStrategyImpl::getGeneratedRealizingClasses() const
{

    return m_generatedRealizingClasses;
}


std::shared_ptr<fUML::Locus > CS_DefaultConstructStrategyImpl::getLocus() const
{
//assert(m_locus);
    return m_locus;
}
void CS_DefaultConstructStrategyImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<CS_DefaultConstructStrategy> CS_DefaultConstructStrategyImpl::getThisCS_DefaultConstructStrategyPtr() const
{
	return m_thisCS_DefaultConstructStrategyPtr.lock();
}
void CS_DefaultConstructStrategyImpl::setThisCS_DefaultConstructStrategyPtr(std::weak_ptr<CS_DefaultConstructStrategy> thisCS_DefaultConstructStrategyPtr)
{
	m_thisCS_DefaultConstructStrategyPtr = thisCS_DefaultConstructStrategyPtr;
	setThisCS_ConstructStrategyPtr(thisCS_DefaultConstructStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_DefaultConstructStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DefaultConstructStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDefaultAssociation())); //101
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Class>::iterator iter = m_generatedRealizingClasses->begin();
			Bag<uml::Class>::iterator end = m_generatedRealizingClasses->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //102
		}
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getLocus())); //100
	}
	return CS_ConstructStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_DefaultConstructStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
			return getDefaultAssociation() != nullptr; //101
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
			return getGeneratedRealizingClasses() != nullptr; //102
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
			return getLocus() != nullptr; //100
	}
	return CS_ConstructStrategyImpl::internalEIsSet(featureID);
}
bool CS_DefaultConstructStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Association> _defaultAssociation = std::dynamic_pointer_cast<uml::Association>(_temp);
			setDefaultAssociation(_defaultAssociation); //101
			return true;
		}
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Class>> generatedRealizingClassesList(new Bag<uml::Class>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generatedRealizingClassesList->add(std::dynamic_pointer_cast<uml::Class>(*iter));
				iter++;
			}
			
			Bag<uml::Class>::iterator iterGeneratedRealizingClasses = m_generatedRealizingClasses->begin();
			Bag<uml::Class>::iterator endGeneratedRealizingClasses = m_generatedRealizingClasses->end();
			while (iterGeneratedRealizingClasses != endGeneratedRealizingClasses)
			{
				if (generatedRealizingClassesList->find(*iterGeneratedRealizingClasses) == -1)
				{
					m_generatedRealizingClasses->erase(*iterGeneratedRealizingClasses);
				}
				iterGeneratedRealizingClasses++;
			}

			iterGeneratedRealizingClasses = generatedRealizingClassesList->begin();
			endGeneratedRealizingClasses = generatedRealizingClassesList->end();
			while (iterGeneratedRealizingClasses != endGeneratedRealizingClasses)
			{
				if (m_generatedRealizingClasses->find(*iterGeneratedRealizingClasses) == -1)
				{
					m_generatedRealizingClasses->add(*iterGeneratedRealizingClasses);
				}
				iterGeneratedRealizingClasses++;			
			}
			return true;
		}
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Locus> _locus = std::dynamic_pointer_cast<fUML::Locus>(_temp);
			setLocus(_locus); //100
			return true;
		}
	}

	return CS_ConstructStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CS_DefaultConstructStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	std::shared_ptr<PSCS::PSCSFactory> modelFactory = PSCS::PSCSFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void CS_DefaultConstructStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

	CS_ConstructStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DefaultConstructStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("defaultAssociation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Association";
			}
			std::shared_ptr<uml::Association> defaultAssociation = std::dynamic_pointer_cast<uml::Association>(uml::UmlFactory::eInstance()->create(typeName));
			if (defaultAssociation != nullptr)
			{
				this->setDefaultAssociation(defaultAssociation);
				loadHandler->handleChild(defaultAssociation);
			}
			return;
		}

		if ( nodeName.compare("generatedRealizingClasses") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Class";
			}
			std::shared_ptr<uml::Class> generatedRealizingClasses = std::dynamic_pointer_cast<uml::Class>(uml::UmlFactory::eInstance()->create(typeName));
			if (generatedRealizingClasses != nullptr)
			{
				std::shared_ptr<Bag<uml::Class>> list_generatedRealizingClasses = this->getGeneratedRealizingClasses();
				list_generatedRealizingClasses->push_back(generatedRealizingClasses);
				loadHandler->handleChild(generatedRealizingClasses);
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

	CS_ConstructStrategyImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CS_DefaultConstructStrategyImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::PSCSPackage::CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Locus> _locus = std::dynamic_pointer_cast<fUML::Locus>( references.front() );
				setLocus(_locus);
			}
			
			return;
		}
	}
	CS_ConstructStrategyImpl::resolveReferences(featureID, references);
}

void CS_DefaultConstructStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_ConstructStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_DefaultConstructStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::PSCSPackage> package = PSCS::PSCSPackage::eInstance();

	

		// Add references
		saveHandler->addReference("locus", this->getLocus());


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'defaultAssociation'
		std::shared_ptr<uml::Association > defaultAssociation = this->getDefaultAssociation();
		if (defaultAssociation != nullptr)
		{
			saveHandler->addReference(defaultAssociation, "defaultAssociation", defaultAssociation->eClass() != uml::UmlPackage::eInstance()->getAssociation_Class());
		}

		// Save 'generatedRealizingClasses'
		std::shared_ptr<Bag<uml::Class>> list_generatedRealizingClasses = this->getGeneratedRealizingClasses();
		for (std::shared_ptr<uml::Class> generatedRealizingClasses : *list_generatedRealizingClasses) 
		{
			saveHandler->addReference(generatedRealizingClasses, "generatedRealizingClasses", generatedRealizingClasses->eClass() != uml::UmlPackage::eInstance()->getClass_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


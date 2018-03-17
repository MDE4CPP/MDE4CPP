#include "ecore/impl/EModelElementImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EModelElementImpl::EModelElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eAnnotations.reset(new Bag<ecore::EAnnotation>());
	
	

	//Init references
	
	
}

EModelElementImpl::~EModelElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EModelElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj):EModelElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EModelElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  EModelElementImpl::copy() const
{
	std::shared_ptr<EModelElementImpl> element(new EModelElementImpl(*this));
	element->setThisEModelElementPtr(element);
	return element;
}

std::shared_ptr<EClass> EModelElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEModelElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EAnnotation> EModelElementImpl::getEAnnotation(std::string source) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for(std::shared_ptr<EAnnotation> a : *m_eAnnotations)
    {
	    if(a->getSource()==source)
	    {
		    return a;
	    }
    }
    return std::shared_ptr<ecore::EAnnotation>();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<ecore::EAnnotation>> EModelElementImpl::getEAnnotations() const
{

    return m_eAnnotations;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<EModelElement> EModelElementImpl::getThisEModelElementPtr()
{
	return m_thisEModelElementPtr.lock();
}
void EModelElementImpl::setThisEModelElementPtr(std::weak_ptr<EModelElement> thisEModelElementPtr)
{
	m_thisEModelElementPtr = thisEModelElementPtr;
}
std::shared_ptr<ecore::EObject> EModelElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EModelElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //80
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool EModelElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations() != nullptr; //80
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool EModelElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EModelElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get EcoreFactory
	std::shared_ptr<ecore::EcoreFactory> modelFactory = ecore::EcoreFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void EModelElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EModelElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("eAnnotations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EAnnotation";
			}
			std::shared_ptr<ecore::EObject> eAnnotations = modelFactory->create(typeName, loadHandler->getCurrentObject(), EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT);
			if (eAnnotations != nullptr)
			{
				loadHandler->handleChild(eAnnotations);
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

	ecore::EObjectImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
}

void EModelElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EModelElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EModelElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eAnnotations'
		std::shared_ptr<Bag<ecore::EAnnotation>> list_eAnnotations = this->getEAnnotations();
		for (std::shared_ptr<ecore::EAnnotation> eAnnotations : *list_eAnnotations) 
		{
			saveHandler->addReference(eAnnotations, "eAnnotations", eAnnotations->eClass() != package->getEAnnotation_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


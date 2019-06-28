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
#include <sstream>

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
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

#include "ecore/EObject.hpp"

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
		/*Subset*/
		m_eAnnotations.reset(new Subset<ecore::EAnnotation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_eAnnotations->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(m_eContens)" << std::endl;
		#endif
	
	
}

EModelElementImpl::~EModelElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EModelElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EModelElementImpl::EModelElementImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EModelElementImpl()
			{
			    m_eContainer = par_eContainer;
			}






EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj):EModelElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EModelElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_metaElementID = obj.getMetaElementID();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

		/*Subset*/
		m_eAnnotations->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(m_eContens)" << std::endl;
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
	return EcorePackageImpl::eInstance()->getEModelElement_Class();
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
std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> EModelElementImpl::getEAnnotations() const
{

    return m_eAnnotations;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EModelElementImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EModelElement> EModelElementImpl::getThisEModelElementPtr() const
{
	return m_thisEModelElementPtr.lock();
}
void EModelElementImpl::setThisEModelElementPtr(std::weak_ptr<EModelElement> thisEModelElementPtr)
{
	m_thisEModelElementPtr = thisEModelElementPtr;
	setThisEObjectPtr(thisEModelElementPtr);
}
std::shared_ptr<ecore::EObject> EModelElementImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EModelElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EAnnotation>::iterator iter = m_eAnnotations->begin();
			Bag<ecore::EAnnotation>::iterator end = m_eAnnotations->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //373
		}
	}
	return EObjectImpl::eGet(featureID, resolve, coreType);
}
bool EModelElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
			return getEAnnotations() != nullptr; //373
	}
	return EObjectImpl::internalEIsSet(featureID);
}
bool EModelElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EAnnotation>> eAnnotationsList(new Bag<ecore::EAnnotation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eAnnotationsList->add(std::dynamic_pointer_cast<ecore::EAnnotation>(*iter));
				iter++;
			}
			
			Bag<ecore::EAnnotation>::iterator iterEAnnotations = m_eAnnotations->begin();
			Bag<ecore::EAnnotation>::iterator endEAnnotations = m_eAnnotations->end();
			while (iterEAnnotations != endEAnnotations)
			{
				if (eAnnotationsList->find(*iterEAnnotations) == -1)
				{
					m_eAnnotations->erase(*iterEAnnotations);
				}
				iterEAnnotations++;
			}

			iterEAnnotations = eAnnotationsList->begin();
			endEAnnotations = eAnnotationsList->end();
			while (iterEAnnotations != endEAnnotations)
			{
				if (m_eAnnotations->find(*iterEAnnotations) == -1)
				{
					m_eAnnotations->add(*iterEAnnotations);
				}
				iterEAnnotations++;			
			}
			return true;
		}
	}

	return EObjectImpl::eSet(featureID, newValue);
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

	EObjectImpl::loadAttributes(loadHandler, attr_list);
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
			std::shared_ptr<ecore::EObject> eAnnotations = modelFactory->create(typeName, loadHandler->getCurrentObject(), EcorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT);
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

	EObjectImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EModelElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	EObjectImpl::resolveReferences(featureID, references);
}

void EModelElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void EModelElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

		// Save 'eAnnotations'
		for (std::shared_ptr<ecore::EAnnotation> eAnnotations : *this->getEAnnotations()) 
		{
			saveHandler->addReference(eAnnotations, "eAnnotations", eAnnotations->eClass() != package->getEAnnotation_Class());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


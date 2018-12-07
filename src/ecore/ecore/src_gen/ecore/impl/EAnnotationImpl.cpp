#include "ecore/impl/EAnnotationImpl.hpp"

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

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EStringToStringMapEntry.hpp"

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
EAnnotationImpl::EAnnotationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_contents.reset(new Subset<ecore::EObject, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >()" << std::endl;
		#endif
	
	

		m_details.reset(new Bag<ecore::EStringToStringMapEntry>());
	
	

	

		m_references.reset(new Bag<ecore::EObject>());
	
	

	//Init references
		/*Subset*/
		m_contents->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(m_eContens)" << std::endl;
		#endif
	
	

	
	

	

	
	
}

EAnnotationImpl::~EAnnotationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAnnotation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EAnnotationImpl()
			{
			    m_eContainer = par_eContainer;
			}





//Additional constructor for the containments back reference
			EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EModelElement > par_eModelElement)
			:EAnnotationImpl()
			{
			    m_eModelElement = par_eModelElement;
			}






EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj):EAnnotationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAnnotation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_source = obj.getSource();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

	m_eModelElement  = obj.getEModelElement();

	std::shared_ptr<Bag<ecore::EObject>> _references = obj.getReferences();
	m_references.reset(new Bag<ecore::EObject>(*(obj.getReferences().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EObject>> _contentsList = obj.getContents();
	for(std::shared_ptr<ecore::EObject> _contents : *_contentsList)
	{
		this->getContents()->add(std::shared_ptr<ecore::EObject>(std::dynamic_pointer_cast<ecore::EObject>(_contents->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_contents" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> _detailsList = obj.getDetails();
	for(std::shared_ptr<ecore::EStringToStringMapEntry> _details : *_detailsList)
	{
		this->getDetails()->add(std::shared_ptr<ecore::EStringToStringMapEntry>(std::dynamic_pointer_cast<ecore::EStringToStringMapEntry>(_details->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_details" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

		/*Subset*/
		m_contents->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(m_eContens)" << std::endl;
		#endif
	
	

	
	
}

std::shared_ptr<ecore::EObject>  EAnnotationImpl::copy() const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl(*this));
	element->setThisEAnnotationPtr(element);
	return element;
}

std::shared_ptr<EClass> EAnnotationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEAnnotation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EAnnotationImpl::setSource(std::string _source)
{
	m_source = _source;
} 

std::string EAnnotationImpl::getSource() const 
{
	return m_source;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> EAnnotationImpl::getContents() const
{

    return m_contents;
}


std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> EAnnotationImpl::getDetails() const
{

    return m_details;
}


std::weak_ptr<ecore::EModelElement > EAnnotationImpl::getEModelElement() const
{

    return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(std::shared_ptr<ecore::EModelElement> _eModelElement)
{
    m_eModelElement = _eModelElement;
}

std::shared_ptr<Bag<ecore::EObject>> EAnnotationImpl::getReferences() const
{

    return m_references;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EAnnotationImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EAnnotation> EAnnotationImpl::getThisEAnnotationPtr() const
{
	return m_thisEAnnotationPtr.lock();
}
void EAnnotationImpl::setThisEAnnotationPtr(std::weak_ptr<EAnnotation> thisEAnnotationPtr)
{
	m_thisEAnnotationPtr = thisEAnnotationPtr;
	setThisEModelElementPtr(thisEAnnotationPtr);
}
std::shared_ptr<ecore::EObject> EAnnotationImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eModelElement.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EAnnotationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_EREFERENCE_CONTENTS:
			return eAny(getContents()); //16
		case EcorePackage::EANNOTATION_EREFERENCE_DETAILS:
			return eAny(getDetails()); //14
		case EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT:
			return eAny(getEModelElement()); //15
		case EcorePackage::EANNOTATION_EREFERENCE_REFERENCES:
			return eAny(getReferences()); //17
		case EcorePackage::EANNOTATION_EATTRIBUTE_SOURCE:
			return eAny(getSource()); //13
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}
bool EAnnotationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_EREFERENCE_CONTENTS:
			return getContents() != nullptr; //16
		case EcorePackage::EANNOTATION_EREFERENCE_DETAILS:
			return getDetails() != nullptr; //14
		case EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT:
			return getEModelElement().lock() != nullptr; //15
		case EcorePackage::EANNOTATION_EREFERENCE_REFERENCES:
			return getReferences() != nullptr; //17
		case EcorePackage::EANNOTATION_EATTRIBUTE_SOURCE:
			return getSource() != ""; //13
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool EAnnotationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EModelElement> _eModelElement = newValue->get<std::shared_ptr<ecore::EModelElement>>();
			setEModelElement(_eModelElement); //15
			return true;
		}
		case EcorePackage::EANNOTATION_EATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::string _source = newValue->get<std::string>();
			setSource(_source); //13
			return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EAnnotationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EAnnotationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSource(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("references");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("references")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EModelElementImpl::loadAttributes(loadHandler, attr_list);
}

void EAnnotationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("contents") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EObject";
			}
			std::shared_ptr<ecore::EObject> contents = std::dynamic_pointer_cast<ecore::EObject>(modelFactory->create(typeName));
			if (contents != nullptr)
			{
				std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> list_contents = this->getContents();
				list_contents->push_back(contents);
				loadHandler->handleChild(contents);
			}
			return;
		}

		if ( nodeName.compare("details") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EStringToStringMapEntry";
			}
			std::shared_ptr<ecore::EStringToStringMapEntry> details = std::dynamic_pointer_cast<ecore::EStringToStringMapEntry>(modelFactory->create(typeName));
			if (details != nullptr)
			{
				std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> list_details = this->getDetails();
				list_details->push_back(details);
				loadHandler->handleChild(details);
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

	EModelElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EAnnotationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case EcorePackage::EANNOTATION_EREFERENCE_EMODELELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EModelElement> _eModelElement = std::dynamic_pointer_cast<ecore::EModelElement>( references.front() );
				setEModelElement(_eModelElement);
			}
			
			return;
		}

		case EcorePackage::EANNOTATION_EREFERENCE_REFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> _references = getReferences();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EObject> _r = std::dynamic_pointer_cast<ecore::EObject>(ref);
				if (_r != nullptr)
				{
					_references->push_back(_r);
				}				
			}
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EAnnotationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void EAnnotationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

		// Save 'contents'
		for (std::shared_ptr<ecore::EObject> contents : *this->getContents()) 
		{
			saveHandler->addReference(contents, "contents", contents->eClass() != package->getEObject_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getEAnnotation_EAttribute_source()) )
		{
			saveHandler->addAttribute("source", this->getSource());
		}

		// Add references
		std::shared_ptr<Bag<ecore::EObject>> references_list = this->getReferences();
		for (std::shared_ptr<ecore::EObject > object : *references_list)
		{ 
			saveHandler->addReferences("references", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'details'
		std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> list_details = this->getDetails();
		for (std::shared_ptr<ecore::EStringToStringMapEntry> details : *list_details) 
		{
			saveHandler->addReference(details, "details", details->eClass() != package->getEStringToStringMapEntry_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "ecore/impl/EEnumImpl.hpp"

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

#include "ecore/EDataType.hpp"

#include "ecore/EEnumLiteral.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EPackage.hpp"

#include "ecore/ETypeParameter.hpp"

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
EEnumImpl::EEnumImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_eLiterals.reset(new Subset<ecore::EEnumLiteral, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_eLiterals->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(m_eContens)" << std::endl;
		#endif
	
	
}

EEnumImpl::~EEnumImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnum "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EObject > par_eContainer)
			:EEnumImpl()
			{
			    m_eContainer = par_eContainer;
			}





//Additional constructor for the containments back reference
			EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EPackage > par_ePackage)
			:EEnumImpl()
			{
			    m_ePackage = par_ePackage;
			}






EEnumImpl::EEnumImpl(const EEnumImpl & obj):EEnumImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnum "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_defaultValue = obj.getDefaultValue();
	m_instanceClass = obj.getInstanceClass();
	m_instanceClassName = obj.getInstanceClassName();
	m_instanceTypeName = obj.getInstanceTypeName();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();
	m_serializable = obj.isSerializable();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

	m_ePackage  = obj.getEPackage();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EEnumLiteral>> _eLiteralsList = obj.getELiterals();
	for(std::shared_ptr<ecore::EEnumLiteral> _eLiterals : *_eLiteralsList)
	{
		this->getELiterals()->add(std::shared_ptr<ecore::EEnumLiteral>(std::dynamic_pointer_cast<ecore::EEnumLiteral>(_eLiterals->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eLiterals" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(std::dynamic_pointer_cast<ecore::ETypeParameter>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

		/*Subset*/
		m_eLiterals->initSubset(m_eContens);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(m_eContens)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  EEnumImpl::copy() const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl(*this));
	element->setThisEEnumPtr(element);
	return element;
}

std::shared_ptr<EClass> EEnumImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEEnum_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(std::string name) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getName()==name)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();
	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(int value) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getValue()==value)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();

	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteralByLiteral(std::string literal) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getLiteral()==literal)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>  ();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> EEnumImpl::getELiterals() const
{

    return m_eLiterals;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EEnumImpl::getEContens() const
{
	return m_eContens;
}


std::shared_ptr<EEnum> EEnumImpl::getThisEEnumPtr() const
{
	return m_thisEEnumPtr.lock();
}
void EEnumImpl::setThisEEnumPtr(std::weak_ptr<EEnum> thisEEnumPtr)
{
	m_thisEEnumPtr = thisEEnumPtr;
	setThisEDataTypePtr(thisEEnumPtr);
}
std::shared_ptr<ecore::EObject> EEnumImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EEnumImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EENUM_ATTRIBUTE_ELITERALS:
			return eAny(getELiterals()); //2012
	}
	return EDataTypeImpl::eGet(featureID, resolve, coreType);
}
bool EEnumImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EENUM_ATTRIBUTE_ELITERALS:
			return getELiterals() != nullptr; //2012
	}
	return EDataTypeImpl::internalEIsSet(featureID);
}
bool EEnumImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return EDataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EEnumImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EEnumImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EDataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void EEnumImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("eLiterals") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EEnumLiteral";
			}
			std::shared_ptr<ecore::EObject> eLiterals = modelFactory->create(typeName, loadHandler->getCurrentObject(), EcorePackage::EENUMLITERAL_ATTRIBUTE_EENUM);
			if (eLiterals != nullptr)
			{
				loadHandler->handleChild(eLiterals);
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

	EDataTypeImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EEnumImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	EDataTypeImpl::resolveReferences(featureID, references);
}

void EEnumImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EDataTypeImpl::saveContent(saveHandler);
	
	EClassifierImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void EEnumImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

		// Save 'eLiterals'
		for (std::shared_ptr<ecore::EEnumLiteral> eLiterals : *this->getELiterals()) 
		{
			saveHandler->addReference(eLiterals, "eLiterals", eLiterals->eClass() != package->getEEnumLiteral_Class());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


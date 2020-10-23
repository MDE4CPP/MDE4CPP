#include "ecore/impl/EParameterImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/ETypedElement.hpp"

//Factories an Package includes
#include "ecore/impl/EcoreFactoryImpl.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EParameterImpl::EParameterImpl()
{	
}

EParameterImpl::~EParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EParameterImpl::EParameterImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EParameterImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EParameterImpl::EParameterImpl(std::weak_ptr<ecore::EOperation > par_eOperation)
:EParameterImpl()
{
	m_eOperation = par_eOperation;
}


EParameterImpl::EParameterImpl(const EParameterImpl & obj):EParameterImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

	m_eOperation  = obj.getEOperation();

	m_eType  = obj.getEType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EParameterImpl::copy() const
{
	std::shared_ptr<EParameterImpl> element(new EParameterImpl(*this));
	element->setThisEParameterPtr(element);
	return element;
}

std::shared_ptr<EClass> EParameterImpl::eStaticClass() const
{
	return ecore::EcorePackage::eInstance()->getEParameter_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference eOperation
*/
std::weak_ptr<ecore::EOperation > EParameterImpl::getEOperation() const
{

    return m_eOperation;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EParameterImpl::getEContens() const
{
	if(m_eContens == nullptr)
	{
		/*Union*/
		m_eContens.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContens - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContens;
}




std::shared_ptr<EParameter> EParameterImpl::getThisEParameterPtr() const
{
	return m_thisEParameterPtr.lock();
}
void EParameterImpl::setThisEParameterPtr(std::weak_ptr<EParameter> thisEParameterPtr)
{
	m_thisEParameterPtr = thisEParameterPtr;
	setThisETypedElementPtr(thisEParameterPtr);
}
std::shared_ptr<ecore::EObject> EParameterImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eOperation.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EPARAMETER_ATTRIBUTE_EOPERATION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEOperation().lock())); //4213
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}
bool EParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EPARAMETER_ATTRIBUTE_EOPERATION:
			return getEOperation().lock() != nullptr; //4213
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}
bool EParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get EcoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::EcoreFactory> modelFactory=ecore::EcoreFactory::eInstance();

	//load BasePackage Nodes
	ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void EParameterImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


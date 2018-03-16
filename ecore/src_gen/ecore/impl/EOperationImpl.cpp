#include "ecore/impl/EOperationImpl.hpp"

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
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "ecore/EcoreFactory.hpp"
#include "ecore/EcorePackage.hpp"
#include <exception> // used in Persistence

#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EParameter.hpp"

#include "ecore/ETypeParameter.hpp"

#include "ecore/ETypedElement.hpp"

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
EOperationImpl::EOperationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_eExceptions.reset(new Bag<ecore::EClassifier>());
	
	

		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
	
	

		m_eParameters.reset(new Bag<ecore::EParameter>());
	
	

		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
	
	

	//Init references
	

	
	

	
	

	
	

	
	
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EClass > par_eContainingClass)
			:EOperationImpl()
			{
			    m_eContainingClass = par_eContainingClass;
			}






EOperationImpl::EOperationImpl(const EOperationImpl & obj):EOperationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EOperation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_lowerBound = obj.getLowerBound();
	m_many = obj.isMany();
	m_name = obj.getName();
	m_operationID = obj.getOperationID();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eContainingClass  = obj.getEContainingClass();

	std::shared_ptr<Bag<ecore::EClassifier>> _eExceptions = obj.getEExceptions();
	m_eExceptions.reset(new Bag<ecore::EClassifier>(*(obj.getEExceptions().get())));

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
	std::shared_ptr<Bag<ecore::EGenericType>> _eGenericExceptionsList = obj.getEGenericExceptions();
	for(std::shared_ptr<ecore::EGenericType> _eGenericExceptions : *_eGenericExceptionsList)
	{
		this->getEGenericExceptions()->add(std::shared_ptr<ecore::EGenericType>(std::dynamic_pointer_cast<ecore::EGenericType>(_eGenericExceptions->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericExceptions" << std::endl;
	#endif
	if(obj.getEGenericType()!=nullptr)
	{
		m_eGenericType = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEGenericType()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eGenericType" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EParameter>> _eParametersList = obj.getEParameters();
	for(std::shared_ptr<ecore::EParameter> _eParameters : *_eParametersList)
	{
		this->getEParameters()->add(std::shared_ptr<ecore::EParameter>(std::dynamic_pointer_cast<ecore::EParameter>(_eParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eParameters" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParametersList = obj.getETypeParameters();
	for(std::shared_ptr<ecore::ETypeParameter> _eTypeParameters : *_eTypeParametersList)
	{
		this->getETypeParameters()->add(std::shared_ptr<ecore::ETypeParameter>(std::dynamic_pointer_cast<ecore::ETypeParameter>(_eTypeParameters->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eTypeParameters" << std::endl;
	#endif

	
	

	
	

	
	
}

std::shared_ptr<ecore::EObject>  EOperationImpl::copy() const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl(*this));
	element->setThisEOperationPtr(element);
	return element;
}

std::shared_ptr<EClass> EOperationImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEOperation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void EOperationImpl::setOperationID(int _operationID)
{
	m_operationID = _operationID;
} 

int EOperationImpl::getOperationID() const 
{
	return m_operationID;
}

//*********************************
// Operations
//*********************************
bool EOperationImpl::isOverrideOf(std::shared_ptr<ecore::EOperation>  someOperation)  const 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<ecore::EClass > containingClass = someOperation->getEContainingClass().lock();
	if(nullptr == containingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " containing class not set." << std::endl;
		return false;
	}

	std::shared_ptr<ecore::EClass > thisContainingClass = getEContainingClass().lock();
	if(nullptr == thisContainingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " thisContainingClass not set." << std::endl;
		return false;
	}

	if (containingClass->isSuperTypeOf(thisContainingClass) && (someOperation->getName()==getName()))
    {
        std::shared_ptr< Bag<ecore::EParameter> > parameters = getEParameters();
        std::shared_ptr< Bag<ecore::EParameter> > otherParameters = someOperation->getEParameters();
        if (parameters->size() == otherParameters->size())
        {
            for (Bag<EParameter> ::iterator i = parameters->begin(), j = otherParameters->begin(); i != parameters->end(); ++i,++j )
        	{
            	std::shared_ptr<EParameter> parameter = *i;
            	std::shared_ptr<EParameter> otherParameter = *j;
                if (parameter->getEType().get() != otherParameter->getEType().get())
          		{
                    return false;
        		}
        	}
            return true;
		}
	}
    return false;
	//end of body
}

//*********************************
// References
//*********************************
std::weak_ptr<ecore::EClass > EOperationImpl::getEContainingClass() const
{

    return m_eContainingClass;
}


std::shared_ptr<Bag<ecore::EClassifier>> EOperationImpl::getEExceptions() const
{

    return m_eExceptions;
}


std::shared_ptr<Bag<ecore::EGenericType>> EOperationImpl::getEGenericExceptions() const
{

    return m_eGenericExceptions;
}


std::shared_ptr<Bag<ecore::EParameter>> EOperationImpl::getEParameters() const
{

    return m_eParameters;
}


std::shared_ptr<Bag<ecore::ETypeParameter>> EOperationImpl::getETypeParameters() const
{

    return m_eTypeParameters;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<EOperation> EOperationImpl::getThisEOperationPtr()
{
	return m_thisEOperationPtr.lock();
}
void EOperationImpl::setThisEOperationPtr(std::weak_ptr<EOperation> thisEOperationPtr)
{
	m_thisEOperationPtr = thisEOperationPtr;
	setThisETypedElementPtr(thisEOperationPtr);
}
std::shared_ptr<ecore::EObject> EOperationImpl::eContainer() const
{
	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EOperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EOPERATION_EREFERENCE_ECONTAININGCLASS:
			return getEContainingClass(); //1111
		case EcorePackage::EOPERATION_EREFERENCE_EEXCEPTIONS:
			return getEExceptions(); //1114
		case EcorePackage::EOPERATION_EREFERENCE_EGENERICEXCEPTIONS:
			return getEGenericExceptions(); //1115
		case EcorePackage::EOPERATION_EREFERENCE_EPARAMETERS:
			return getEParameters(); //1113
		case EcorePackage::EOPERATION_EREFERENCE_ETYPEPARAMETERS:
			return getETypeParameters(); //1112
		case EcorePackage::EOPERATION_EATTRIBUTE_OPERATIONID:
			return getOperationID(); //1110
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}
bool EOperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case EcorePackage::EOPERATION_EREFERENCE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //1111
		case EcorePackage::EOPERATION_EREFERENCE_EEXCEPTIONS:
			return getEExceptions() != nullptr; //1114
		case EcorePackage::EOPERATION_EREFERENCE_EGENERICEXCEPTIONS:
			return getEGenericExceptions() != nullptr; //1115
		case EcorePackage::EOPERATION_EREFERENCE_EPARAMETERS:
			return getEParameters() != nullptr; //1113
		case EcorePackage::EOPERATION_EREFERENCE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //1112
		case EcorePackage::EOPERATION_EATTRIBUTE_OPERATIONID:
			return getOperationID() != -1; //1110
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}
bool EOperationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EOperationImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
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

void EOperationImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("operationID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setOperationID(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eExceptions");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eExceptions")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EOperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("eGenericExceptions") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			std::shared_ptr<ecore::EGenericType> eGenericExceptions = std::dynamic_pointer_cast<ecore::EGenericType>(modelFactory->create(typeName));
			if (eGenericExceptions != nullptr)
			{
				std::shared_ptr<Bag<ecore::EGenericType>> list_eGenericExceptions = this->getEGenericExceptions();
				list_eGenericExceptions->push_back(eGenericExceptions);
				loadHandler->handleChild(eGenericExceptions);
			}
			return;
		}

		if ( nodeName.compare("eParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EParameter";
			}
			std::shared_ptr<ecore::EObject> eParameters = modelFactory->create(typeName, loadHandler->getCurrentObject(), EcorePackage::EPARAMETER_EREFERENCE_EOPERATION);
			if (eParameters != nullptr)
			{
				loadHandler->handleChild(eParameters);
			}
			return;
		}

		if ( nodeName.compare("eTypeParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ETypeParameter";
			}
			std::shared_ptr<ecore::ETypeParameter> eTypeParameters = std::dynamic_pointer_cast<ecore::ETypeParameter>(modelFactory->create(typeName));
			if (eTypeParameters != nullptr)
			{
				std::shared_ptr<Bag<ecore::ETypeParameter>> list_eTypeParameters = this->getETypeParameters();
				list_eTypeParameters->push_back(eTypeParameters);
				loadHandler->handleChild(eTypeParameters);
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

	ETypedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void EOperationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case EcorePackage::EOPERATION_EREFERENCE_EEXCEPTIONS:
		{
			std::shared_ptr<Bag<ecore::EClassifier>> _eExceptions = getEExceptions();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EClassifier> _r = std::dynamic_pointer_cast<ecore::EClassifier>(ref);
				if (_r != nullptr)
				{
					_eExceptions->push_back(_r);
				}				
			}
			return;
		}
	}
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EOperationImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void EOperationImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getEOperation_EAttribute_operationID()) )
		{
			saveHandler->addAttribute("operationID", this->getOperationID());
		}

		// Add references
		std::shared_ptr<Bag<ecore::EClassifier>> eExceptions_list = this->getEExceptions();
		for (std::shared_ptr<ecore::EClassifier > object : *eExceptions_list)
		{ 
			saveHandler->addReferences("eExceptions", object);
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eGenericExceptions'
		std::shared_ptr<Bag<ecore::EGenericType>> list_eGenericExceptions = this->getEGenericExceptions();
		for (std::shared_ptr<ecore::EGenericType> eGenericExceptions : *list_eGenericExceptions) 
		{
			saveHandler->addReference(eGenericExceptions, "eGenericExceptions", eGenericExceptions->eClass() != package->getEGenericType_EClass());
		}

		// Save 'eParameters'
		std::shared_ptr<Bag<ecore::EParameter>> list_eParameters = this->getEParameters();
		for (std::shared_ptr<ecore::EParameter> eParameters : *list_eParameters) 
		{
			saveHandler->addReference(eParameters, "eParameters", eParameters->eClass() != package->getEParameter_EClass());
		}

		// Save 'eTypeParameters'
		std::shared_ptr<Bag<ecore::ETypeParameter>> list_eTypeParameters = this->getETypeParameters();
		for (std::shared_ptr<ecore::ETypeParameter> eTypeParameters : *list_eTypeParameters) 
		{
			saveHandler->addReference(eTypeParameters, "eTypeParameters", eTypeParameters->eClass() != package->getETypeParameter_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


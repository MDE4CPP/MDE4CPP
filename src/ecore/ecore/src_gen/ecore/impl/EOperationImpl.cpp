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

#include "ecore/EClass.hpp"

#include "ecore/EClassifier.hpp"

#include "ecore/EGenericType.hpp"

#include "ecore/EObject.hpp"

#include "ecore/EOperation.hpp"

#include "ecore/EParameter.hpp"

#include "ecore/ETypeParameter.hpp"

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
EOperationImpl::EOperationImpl()
{	
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EOperationImpl()
{
	m_eContainer = par_eContainer;
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
	m_metaElementID = obj.getMetaElementID();
	m_name = obj.getName();
	m_operationID = obj.getOperationID();
	m_ordered = obj.isOrdered();
	m_required = obj.isRequired();
	m_unique = obj.isUnique();
	m_upperBound = obj.getUpperBound();

	//copy references with no containment (soft copy)
	
	m_eContainer  = obj.getEContainer();

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

	

	/*Subset*/
	m_eParameters->initSubset(getEContens());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContens())" << std::endl;
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
	return ecore::EcorePackage::eInstance()->getEOperation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute operationID
*/
int EOperationImpl::getOperationID() const 
{
	return m_operationID;
}

void EOperationImpl::setOperationID(int _operationID)
{
	m_operationID = _operationID;
} 



//*********************************
// Operations
//*********************************


bool EOperationImpl::isOverrideOf(std::shared_ptr<ecore::EOperation>  someOperation) const
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
/*
Getter & Setter for reference eContainingClass
*/
std::weak_ptr<ecore::EClass > EOperationImpl::getEContainingClass() const
{

    return m_eContainingClass;
}





/*
Getter & Setter for reference eExceptions
*/
std::shared_ptr<Bag<ecore::EClassifier>> EOperationImpl::getEExceptions() const
{
	if(m_eExceptions == nullptr)
	{
		m_eExceptions.reset(new Bag<ecore::EClassifier>());
		
		
	}

    return m_eExceptions;
}





/*
Getter & Setter for reference eGenericExceptions
*/
std::shared_ptr<Bag<ecore::EGenericType>> EOperationImpl::getEGenericExceptions() const
{
	if(m_eGenericExceptions == nullptr)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
	}

    return m_eGenericExceptions;
}





/*
Getter & Setter for reference eParameters
*/
std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> EOperationImpl::getEParameters() const
{
	if(m_eParameters == nullptr)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_eParameters->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_eParameters;
}





/*
Getter & Setter for reference eTypeParameters
*/
std::shared_ptr<Bag<ecore::ETypeParameter>> EOperationImpl::getETypeParameters() const
{
	if(m_eTypeParameters == nullptr)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
	}

    return m_eTypeParameters;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EOperationImpl::getEContens() const
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




std::shared_ptr<EOperation> EOperationImpl::getThisEOperationPtr() const
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
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EOperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEContainingClass().lock())); //4014
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EClassifier>::iterator iter = m_eExceptions->begin();
			Bag<ecore::EClassifier>::iterator end = m_eExceptions->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4017
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EGenericType>::iterator iter = m_eGenericExceptions->begin();
			Bag<ecore::EGenericType>::iterator end = m_eGenericExceptions->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4018
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EParameter>::iterator iter = m_eParameters->begin();
			Bag<ecore::EParameter>::iterator end = m_eParameters->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4016
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::ETypeParameter>::iterator iter = m_eTypeParameters->begin();
			Bag<ecore::ETypeParameter>::iterator end = m_eTypeParameters->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //4015
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_OPERATIONID:
			return eAny(getOperationID()); //4013
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}
bool EOperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //4014
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
			return getEExceptions() != nullptr; //4017
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
			return getEGenericExceptions() != nullptr; //4018
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
			return getEParameters() != nullptr; //4016
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //4015
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_OPERATIONID:
			return getOperationID() != -1; //4013
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}
bool EOperationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EClassifier>> eExceptionsList(new Bag<ecore::EClassifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eExceptionsList->add(std::dynamic_pointer_cast<ecore::EClassifier>(*iter));
				iter++;
			}
			
			Bag<ecore::EClassifier>::iterator iterEExceptions = m_eExceptions->begin();
			Bag<ecore::EClassifier>::iterator endEExceptions = m_eExceptions->end();
			while (iterEExceptions != endEExceptions)
			{
				if (eExceptionsList->find(*iterEExceptions) == -1)
				{
					m_eExceptions->erase(*iterEExceptions);
				}
				iterEExceptions++;
			}

			iterEExceptions = eExceptionsList->begin();
			endEExceptions = eExceptionsList->end();
			while (iterEExceptions != endEExceptions)
			{
				if (m_eExceptions->find(*iterEExceptions) == -1)
				{
					m_eExceptions->add(*iterEExceptions);
				}
				iterEExceptions++;			
			}
			return true;
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EGenericType>> eGenericExceptionsList(new Bag<ecore::EGenericType>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eGenericExceptionsList->add(std::dynamic_pointer_cast<ecore::EGenericType>(*iter));
				iter++;
			}
			
			Bag<ecore::EGenericType>::iterator iterEGenericExceptions = m_eGenericExceptions->begin();
			Bag<ecore::EGenericType>::iterator endEGenericExceptions = m_eGenericExceptions->end();
			while (iterEGenericExceptions != endEGenericExceptions)
			{
				if (eGenericExceptionsList->find(*iterEGenericExceptions) == -1)
				{
					m_eGenericExceptions->erase(*iterEGenericExceptions);
				}
				iterEGenericExceptions++;
			}

			iterEGenericExceptions = eGenericExceptionsList->begin();
			endEGenericExceptions = eGenericExceptionsList->end();
			while (iterEGenericExceptions != endEGenericExceptions)
			{
				if (m_eGenericExceptions->find(*iterEGenericExceptions) == -1)
				{
					m_eGenericExceptions->add(*iterEGenericExceptions);
				}
				iterEGenericExceptions++;			
			}
			return true;
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EParameter>> eParametersList(new Bag<ecore::EParameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eParametersList->add(std::dynamic_pointer_cast<ecore::EParameter>(*iter));
				iter++;
			}
			
			Bag<ecore::EParameter>::iterator iterEParameters = m_eParameters->begin();
			Bag<ecore::EParameter>::iterator endEParameters = m_eParameters->end();
			while (iterEParameters != endEParameters)
			{
				if (eParametersList->find(*iterEParameters) == -1)
				{
					m_eParameters->erase(*iterEParameters);
				}
				iterEParameters++;
			}

			iterEParameters = eParametersList->begin();
			endEParameters = eParametersList->end();
			while (iterEParameters != endEParameters)
			{
				if (m_eParameters->find(*iterEParameters) == -1)
				{
					m_eParameters->add(*iterEParameters);
				}
				iterEParameters++;			
			}
			return true;
		}
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::ETypeParameter>> eTypeParametersList(new Bag<ecore::ETypeParameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				eTypeParametersList->add(std::dynamic_pointer_cast<ecore::ETypeParameter>(*iter));
				iter++;
			}
			
			Bag<ecore::ETypeParameter>::iterator iterETypeParameters = m_eTypeParameters->begin();
			Bag<ecore::ETypeParameter>::iterator endETypeParameters = m_eTypeParameters->end();
			while (iterETypeParameters != endETypeParameters)
			{
				if (eTypeParametersList->find(*iterETypeParameters) == -1)
				{
					m_eTypeParameters->erase(*iterETypeParameters);
				}
				iterETypeParameters++;
			}

			iterETypeParameters = eTypeParametersList->begin();
			endETypeParameters = eTypeParametersList->end();
			while (iterETypeParameters != endETypeParameters)
			{
				if (m_eTypeParameters->find(*iterETypeParameters) == -1)
				{
					m_eTypeParameters->add(*iterETypeParameters);
				}
				iterETypeParameters++;			
			}
			return true;
		}
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void EOperationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EOperationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void EOperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<ecore::EcoreFactory> modelFactory=ecore::EcoreFactory::eInstance();

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
			std::shared_ptr<ecore::EObject> eParameters = modelFactory->create(typeName, loadHandler->getCurrentObject(), ecore::EcorePackage::EPARAMETER_ATTRIBUTE_EOPERATION);
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
	//load BasePackage Nodes
	ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void EOperationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::EcorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
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

void EOperationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void EOperationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::EcorePackage> package = ecore::EcorePackage::eInstance();

		// Save 'eParameters'
		for (std::shared_ptr<ecore::EParameter> eParameters : *this->getEParameters()) 
		{
			saveHandler->addReference(eParameters, "eParameters", eParameters->eClass() != package->getEParameter_Class());
		}
	
		// Add attributes
		if ( this->eIsSet(package->getEOperation_Attribute_operationID()) )
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
			saveHandler->addReference(eGenericExceptions, "eGenericExceptions", eGenericExceptions->eClass() !=ecore::EcorePackage::eInstance()->getEGenericType_Class());
		}

		// Save 'eTypeParameters'
		std::shared_ptr<Bag<ecore::ETypeParameter>> list_eTypeParameters = this->getETypeParameters();
		for (std::shared_ptr<ecore::ETypeParameter> eTypeParameters : *list_eTypeParameters) 
		{
			saveHandler->addReference(eTypeParameters, "eTypeParameters", eTypeParameters->eClass() !=ecore::EcorePackage::eInstance()->getETypeParameter_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}



#include "ecore/impl/EPackageImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EFactory.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EPackageImpl::EPackageImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EPackageImpl::~EPackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EPackage "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EPackageImpl::EPackageImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EPackageImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EPackageImpl::EPackageImpl(std::weak_ptr<ecore::EPackage> par_eSuperPackage)
:EPackageImpl()
{
	m_eSuperPackage = par_eSuperPackage;
}

EPackageImpl::EPackageImpl(const EPackageImpl & obj): EPackageImpl()
{
	*this = obj;
}

EPackageImpl& EPackageImpl::operator=(const EPackageImpl & obj)
{
	//call overloaded =Operator for each base class
	ENamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EPackage 
	 * which is generated by the compiler (as EPackage is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EPackage::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EPackage "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_nsPrefix = obj.getNsPrefix();
	m_nsURI = obj.getNsURI();

	//copy references with no containment (soft copy)
	m_eFactoryInstance  = obj.getEFactoryInstance();
	m_eSuperPackage  = obj.getESuperPackage();
	//Clone references with containment (deep copy)
	//clone reference 'eClassifiers'
	std::shared_ptr<Subset<ecore::EClassifier, ecore::EObject>> eClassifiersList = obj.getEClassifiers();
	if(eClassifiersList)
	{
		/*Subset*/
		m_eClassifiers.reset(new Subset<ecore::EClassifier, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eClassifiers - Subset<ecore::EClassifier, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEClassifiers()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eClassifiers - Subset<ecore::EClassifier, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EClassifier> eClassifiersindexElem: *eClassifiersList) 
		{
			std::shared_ptr<ecore::EClassifier> temp = std::dynamic_pointer_cast<ecore::EClassifier>((eClassifiersindexElem)->copy());
			m_eClassifiers->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eClassifiers."<< std::endl;)
	}

	//clone reference 'eSubpackages'
	std::shared_ptr<Bag<ecore::EPackage>> eSubpackagesList = obj.getESubpackages();
	if(eSubpackagesList)
	{
		m_eSubpackages.reset(new Bag<ecore::EPackage>());
		
		
		for(const std::shared_ptr<ecore::EPackage> eSubpackagesindexElem: *eSubpackagesList) 
		{
			std::shared_ptr<ecore::EPackage> temp = std::dynamic_pointer_cast<ecore::EPackage>((eSubpackagesindexElem)->copy());
			m_eSubpackages->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eSubpackages."<< std::endl;)
	}
	/*Subset*/
	getEClassifiers()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eClassifiers - Subset<ecore::EClassifier, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> EPackageImpl::copy() const
{
	std::shared_ptr<EPackageImpl> element(new EPackageImpl());
	*element =(*this);
	element->setThisEPackagePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EClassifier> EPackageImpl::getEClassifier(std::string name) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<EClassifier> > classifierList = getEClassifiers();
    for (std::shared_ptr<EClassifier> c : *classifierList)
    {
        if(c->getName()==name)
        {
            return c;
        }
    }
    return nullptr;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute nsPrefix */
std::string EPackageImpl::getNsPrefix() const
{
	return m_nsPrefix;
}
void EPackageImpl::setNsPrefix(std::string _nsPrefix)
{
	m_nsPrefix = _nsPrefix;
	
}

/* Getter & Setter for attribute nsURI */
std::string EPackageImpl::getNsURI() const
{
	return m_nsURI;
}
void EPackageImpl::setNsURI(std::string _nsURI)
{
	m_nsURI = _nsURI;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eClassifiers */
const std::shared_ptr<Subset<ecore::EClassifier, ecore::EObject>>& EPackageImpl::getEClassifiers() const
{
	if(m_eClassifiers == nullptr)
	{
		/*Subset*/
		m_eClassifiers.reset(new Subset<ecore::EClassifier, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eClassifiers - Subset<ecore::EClassifier, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEClassifiers()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eClassifiers - Subset<ecore::EClassifier, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_eClassifiers;
}

/* Getter & Setter for reference eFactoryInstance */
const std::shared_ptr<ecore::EFactory>& EPackageImpl::getEFactoryInstance() const
{
    return m_eFactoryInstance;
}
void EPackageImpl::setEFactoryInstance(const std::shared_ptr<ecore::EFactory>& _eFactoryInstance)
{
    m_eFactoryInstance = _eFactoryInstance;
	
}

/* Getter & Setter for reference eSubpackages */
const std::shared_ptr<Bag<ecore::EPackage>>& EPackageImpl::getESubpackages() const
{
	if(m_eSubpackages == nullptr)
	{
		m_eSubpackages.reset(new Bag<ecore::EPackage>());
		
		
	}
    return m_eSubpackages;
}

/* Getter & Setter for reference eSuperPackage */
std::weak_ptr<ecore::EPackage> EPackageImpl::getESuperPackage() const
{
    return m_eSuperPackage;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EPackageImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EPackageImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eSuperPackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EPackageImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EPackageImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("nsPrefix");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setNsPrefix(value);
		}

		iter = attr_list.find("nsURI");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setNsURI(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eFactoryInstance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eFactoryInstance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ENamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EPackageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eClassifiers") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<ecore::EClassifier>(this->getEClassifiers());  

			return; 
		}

		if ( nodeName.compare("eSubpackages") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EPackage";
			}
			loadHandler->handleChildContainer<ecore::EPackage>(this->getESubpackages());  

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
	ENamedElementImpl::loadNode(nodeName, loadHandler);
}

void EPackageImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EFactory> _eFactoryInstance = std::dynamic_pointer_cast<ecore::EFactory>( references.front() );
				setEFactoryInstance(_eFactoryInstance);
			}
			
			return;
		}
	}
	ENamedElementImpl::resolveReferences(featureID, references);
}

void EPackageImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EPackageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eClassifiers'
		for (std::shared_ptr<ecore::EClassifier> eClassifiers : *this->getEClassifiers()) 
		{
			saveHandler->addReference(eClassifiers, "eClassifiers", eClassifiers->eClass() != package->getEClassifier_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getEPackage_Attribute_nsPrefix()) )
		{
			saveHandler->addAttribute("nsPrefix", this->getNsPrefix());
		}

		if ( this->eIsSet(package->getEPackage_Attribute_nsURI()) )
		{
			saveHandler->addAttribute("nsURI", this->getNsURI());
		}
	// Add references
		saveHandler->addReference(this->getEFactoryInstance(),"eFactoryInstance", getEFactoryInstance()->eClass() != ecore::ecorePackage::eInstance()->getEFactory_Class());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eSubpackages'

		saveHandler->addReferences<ecore::EPackage>("eSubpackages", this->getESubpackages());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<EClass>& EPackageImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEPackage_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EPackageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:
			return eAnyBag(getEClassifiers(),ecore::ecorePackage::ECLASSIFIER_CLASS); //448
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE:
			return eAny(getEFactoryInstance(),ecore::ecorePackage::EFACTORY_CLASS,false); //447
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUBPACKAGES:
			return eAnyBag(getESubpackages(),ecore::ecorePackage::EPACKAGE_CLASS); //449
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUPERPACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getESuperPackage().lock();
			return eAnyObject(returnValue,ecore::ecorePackage::EPACKAGE_CLASS); //4410
		}
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSPREFIX:
			return eAny(getNsPrefix(),ecore::ecorePackage::ESTRING_CLASS,false); //446
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSURI:
			return eAny(getNsURI(),ecore::ecorePackage::ESTRING_CLASS,false); //445
	}
	return ENamedElementImpl::eGet(featureID, resolve, coreType);
}

bool EPackageImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:
			return getEClassifiers() != nullptr; //448
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE:
			return getEFactoryInstance() != nullptr; //447
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUBPACKAGES:
			return getESubpackages() != nullptr; //449
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUPERPACKAGE:
			return getESuperPackage().lock() != nullptr; //4410
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSPREFIX:
			return getNsPrefix() != ""; //446
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSURI:
			return getNsURI() != ""; //445
	}
	return ENamedElementImpl::internalEIsSet(featureID);
}

bool EPackageImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ECLASSIFIERS:
		{
			// CAST Any to Bag<ecore::EClassifier>
			if((newValue->isContainer()) && (ecore::ecorePackage::ECLASSIFIER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EClassifier>> eClassifiersList= newValue->get<std::shared_ptr<Bag<ecore::EClassifier>>>();
					std::shared_ptr<Bag<ecore::EClassifier>> _eClassifiers=getEClassifiers();
					for(const std::shared_ptr<ecore::EClassifier> indexEClassifiers: *_eClassifiers)
					{
						if (eClassifiersList->find(indexEClassifiers) == -1)
						{
							_eClassifiers->erase(indexEClassifiers);
						}
					}

					for(const std::shared_ptr<ecore::EClassifier> indexEClassifiers: *eClassifiersList)
					{
						if (_eClassifiers->find(indexEClassifiers) == -1)
						{
							_eClassifiers->add(indexEClassifiers);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE:
		{
			// CAST Any to ecore::EFactory
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EFactory> _eFactoryInstance = std::dynamic_pointer_cast<ecore::EFactory>(_temp);
			setEFactoryInstance(_eFactoryInstance); //447
			return true;
		}
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_ESUBPACKAGES:
		{
			// CAST Any to Bag<ecore::EPackage>
			if((newValue->isContainer()) && (ecore::ecorePackage::EPACKAGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EPackage>> eSubpackagesList= newValue->get<std::shared_ptr<Bag<ecore::EPackage>>>();
					std::shared_ptr<Bag<ecore::EPackage>> _eSubpackages=getESubpackages();
					for(const std::shared_ptr<ecore::EPackage> indexESubpackages: *_eSubpackages)
					{
						if (eSubpackagesList->find(indexESubpackages) == -1)
						{
							_eSubpackages->erase(indexESubpackages);
						}
					}

					for(const std::shared_ptr<ecore::EPackage> indexESubpackages: *eSubpackagesList)
					{
						if (_eSubpackages->find(indexESubpackages) == -1)
						{
							_eSubpackages->add(indexESubpackages);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSPREFIX:
		{
			// CAST Any to std::string
			std::string _nsPrefix = newValue->get<std::string>();
			setNsPrefix(_nsPrefix); //446
			return true;
		}
		case ecore::ecorePackage::EPACKAGE_ATTRIBUTE_NSURI:
		{
			// CAST Any to std::string
			std::string _nsURI = newValue->get<std::string>();
			setNsURI(_nsURI); //445
			return true;
		}
	}

	return ENamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EPackageImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// ecore::EPackage::getEClassifier(std::string) : ecore::EClassifier {const}: 1015601525
		case ecorePackage::EPACKAGE_OPERATION_GETECLASSIFIER_ESTRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string >();
			result = eAnyObject(this->getEClassifier(incoming_param_name), ecore::ecorePackage::ECLASSIFIER_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ENamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EPackage> EPackageImpl::getThisEPackagePtr() const
{
	return m_thisEPackagePtr.lock();
}
void EPackageImpl::setThisEPackagePtr(std::weak_ptr<ecore::EPackage> thisEPackagePtr)
{
	m_thisEPackagePtr = thisEPackagePtr;
	setThisENamedElementPtr(thisEPackagePtr);
}



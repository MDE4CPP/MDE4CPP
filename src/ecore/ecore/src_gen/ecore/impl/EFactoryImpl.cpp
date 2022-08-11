
#include "ecore/impl/EFactoryImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "ecore/EObjectContainer.hpp"
#include "ecore/EObjectAny.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EOperation.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EModelElement.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EFactoryImpl::EFactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EFactoryImpl::~EFactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EFactory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EFactoryImpl::EFactoryImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EFactoryImpl()
{
	m_eContainer = par_eContainer;
}

EFactoryImpl::EFactoryImpl(const EFactoryImpl & obj): EFactoryImpl()
{
	*this = obj;
}

EFactoryImpl& EFactoryImpl::operator=(const EFactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EFactory 
	 * which is generated by the compiler (as EFactory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EFactory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EFactory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_ePackage  = obj.getEPackage();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EFactoryImpl::copy() const
{
	std::shared_ptr<EFactoryImpl> element(new EFactoryImpl());
	*element =(*this);
	element->setThisEFactoryPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::string EFactoryImpl::convertToString(std::shared_ptr<ecore::EDataType> eDataType, std::shared_ptr<Any> instanceValue) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::ostringstream returnStringStream;
	bool handled=false;
	if(!instanceValue->isEmpty())
	{
		if(instanceValue->isContainer())
		{
			try
			{
				switch (instanceValue->getTypeId())
				{
					case ecore::ecorePackage::EOBJECT_CLASS:
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag;
						try
						{
							eObjectBag= instanceValue->get<std::shared_ptr<Bag<ecore::EObject>>>(); //throws exception
							returnStringStream << "<Bag<EObject>> size: " << eObjectBag->size() <<std::endl;
						}
						catch(...)
						{
							std::shared_ptr<ecore::EcoreContainerAny> anyObjectBag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(instanceValue);
							if(nullptr!=anyObjectBag)// ecore::EcoreContainerAny?
							{
								eObjectBag=anyObjectBag->getAsEObjectContainer();
								returnStringStream << "<ecore::EcoreContainerAny<EObject>> size: " << eObjectBag->size() <<std::endl;
							}
							else
							{
								returnStringStream << "An EObject Container";
							}
						}
						if(nullptr!=eObjectBag)
						{
							for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
							{	// recursive Call of convertToString via new Any EObject Value
								returnStringStream << "\t"<< convertToString(eDataType,eAny(object,ecore::ecorePackage::EOBJECT_CLASS,false));
							}
						}
						handled = true; break;
					}
					case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
					{
						std::shared_ptr<ecore::EObjectContainer> eObjectContainer = instanceValue->get<std::shared_ptr<ecore::EObjectContainer>>();
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
						returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of convertToString via new Any EObject Value
							returnStringStream << "\t"<<convertToString(eDataType,eAny(object,ecore::ecorePackage::EOBJECT_CLASS,false));
						}
						handled = true; break;
					}
					default:
					{
						std::shared_ptr<ecore::EcoreContainerAny> anyObjectBag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(instanceValue);
						if(nullptr!=anyObjectBag)// ecore::EcoreContainerAny?
						{
							std::shared_ptr<Bag<ecore::EObject>> eObjectBag=anyObjectBag->getAsEObjectContainer();
							returnStringStream << "<ecore::EcoreContainerAny> size: " << eObjectBag->size() <<std::endl;
							for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
							{	// recursive Call of convertToString via new Any EObject Value
								returnStringStream << "\t"<<convertToString(eDataType,eAny(object,ecore::ecorePackage::EOBJECT_CLASS,false));
							}
							handled = true; break;
						}
						else // last supported type bag<Any>
						{
							std::shared_ptr<Bag<Any>> anyBag = instanceValue->get<std::shared_ptr<Bag<Any>>>();
							unsigned int size=anyBag->size();
							returnStringStream << "<Bag<Any>> size: " << size<<std::endl;
							for(unsigned int i = 0; i < size; i++)
							{
								returnStringStream << "\t"<< convertToString(eDataType, anyBag->at(i));
							}
							returnStringStream << std::endl;
							handled = true; break;
						}
					}
				}
			}
			catch(...)
			{
				returnStringStream <<""<<std::endl;
			}
		}
		else
		{
			try
			{
				switch(instanceValue->getTypeId())
				{
					case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
					{
						std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
						std::shared_ptr<ecore::ENamedElement> eNamedElement= std::dynamic_pointer_cast<ecore::ENamedElement>(aObject);
						if(nullptr != eNamedElement)
						{
							returnStringStream << "name:"<< eNamedElement->getName() << " :" ;
						}
						else
						{
							returnStringStream << "<EObject>:";
						}
						std::shared_ptr<Any> content = aObject->eAllContents();
						returnStringStream << convertToString(eDataType,content);
						handled = true; break;
					}
					case ecore::ecorePackage::ECLASS_CLASS:
					{
						std::shared_ptr<ecore::EClass> aValue = instanceValue->get<std::shared_ptr<ecore::EClass>>();
						returnStringStream << "<EClass>:" << aValue->getName() << ":"<< aValue->getName()<<std::endl;

						std::shared_ptr<Subset<ecore::EAttribute, ecore::EStructuralFeature>> attributes = aValue->getEAttributes();
						returnStringStream << convertToString(nullptr, eEcoreContainerAny(attributes,ecore::ecorePackage::EATTRIBUTE_CLASS));
						std::shared_ptr<Subset<ecore::EReference, ecore::EStructuralFeature>> references = aValue->getEReferences();
						returnStringStream << convertToString(nullptr, eEcoreContainerAny(references,ecore::ecorePackage::EREFERENCE_CLASS));
						handled = true; break;
					}
					case ecore::ecorePackage::EOBJECTANY_CLASS:
					{
						std::shared_ptr<ecore::EObjectAny> eObjectAny=nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							eObjectAny = std::dynamic_pointer_cast<ecore::EObjectAny>(aObject);
						}
						catch(...) // 2. try
						{
							std::shared_ptr<ecore::EObjectAny> eObjectAny= instanceValue->get<std::shared_ptr<ecore::EObjectAny>>();
						}
						// recursive Call of convertToString via new Any EObject Value
						if(nullptr!=eObjectAny)
						{
							returnStringStream << "Any: " << convertToString(nullptr, eObjectAny->getAny());
							handled = true;
						}
						break;
					}
					case ecore::ecorePackage::EATTRIBUTE_CLASS:
					{
						std::shared_ptr<ecore::EAttribute> aValue =nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							aValue = std::dynamic_pointer_cast<ecore::EAttribute>(aObject);
						}
						catch(...)// 2. try
						{
							aValue = instanceValue->get<std::shared_ptr<ecore::EAttribute>>();
						}
						if(nullptr!=aValue)
						{
					        if(aValue->getUpperBound() > 1 || aValue->getUpperBound() < 0){
					        	returnStringStream << "<EAttribute>:" + aValue->getName() << ":" <<  aValue->getEType()->getName() << "[" << std::to_string(aValue->getLowerBound()) << "..*]" << std::endl;}
					        else{
					        	returnStringStream << "<EAttribute>:" + aValue->getName() << ":" << aValue->getEType()->getName() << "[" <<  std::to_string(aValue->getLowerBound()) << ".." << std::to_string(aValue->getUpperBound()) << "]" << std::endl;}
							handled = true;
						}
						break;
					}
					case ecore::ecorePackage::EREFERENCE_CLASS:
					{
						std::shared_ptr<ecore::EReference> aValue = nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							aValue = std::dynamic_pointer_cast<ecore::EReference>(aObject);
						}
						catch(...)// 2. try
						{
							aValue = instanceValue->get<std::shared_ptr<ecore::EReference>>();
						}
						if(nullptr!=aValue)
						{
					        if(aValue->getUpperBound() > 1 || aValue->getUpperBound() < 0){
					        	returnStringStream << "<EReference>:" << aValue->getName() << ":"<< aValue->getEType()->getName()<< "[" << std::to_string(aValue->getLowerBound()) << "..*]" <<std::endl;}
					        else{
					        	returnStringStream << "<EReference>:" << aValue->getName() << ":"<< aValue->getEType()->getName()<< "[" <<  std::to_string(aValue->getLowerBound()) << ".." << std::to_string(aValue->getUpperBound()) << "]" << std::endl;}
							handled = true;
						}
						break;
					}
					case ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS:
					{
						std::shared_ptr<ecore::EStructuralFeature> aValue =nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							aValue = std::dynamic_pointer_cast<ecore::EStructuralFeature>(aObject);
						}
						catch(...)// 2. try
						{
							aValue= instanceValue->get<std::shared_ptr<ecore::EStructuralFeature>>();
						}
						if(nullptr!=aValue)
						{
					        if(aValue->getUpperBound() > 1 || aValue->getUpperBound() < 0){
					        	returnStringStream << "<EStructuralFeature>:" << aValue->getName() << ":"<< aValue->getEType()->getName()<< "[" << std::to_string(aValue->getLowerBound()) << "..*]" <<std::endl;}
					        else{
					        	returnStringStream << "<EStructuralFeature>:" << aValue->getName() << ":"<< aValue->getEType()->getName()<< "[" <<  std::to_string(aValue->getLowerBound()) << ".." << std::to_string(aValue->getUpperBound()) << "]" << std::endl;}
							handled = true;
						}
						break;
					}
					case ecore::ecorePackage::EOPERATION_CLASS:
					{
						std::shared_ptr<ecore::EOperation> aValue = nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							aValue = std::dynamic_pointer_cast<ecore::EOperation>(aObject);
						}
						catch(...)// 2. try
						{
							aValue = instanceValue->get<std::shared_ptr<ecore::EOperation>>();
						}
						if(nullptr!=aValue)
						{
					        if(aValue->getUpperBound() > 1 || aValue->getUpperBound() < 0){
					        	returnStringStream << "<EOperation>:" << aValue->getName() << "(...):"<< aValue->getEType()->getName()<< "[" << std::to_string(aValue->getLowerBound()) << "..*]" <<std::endl;}
					        else{
					        	returnStringStream << "<EOperation>:" << aValue->getName() << "(...):"<< aValue->getEType()->getName()<< "[" <<  std::to_string(aValue->getLowerBound()) << ".." << std::to_string(aValue->getUpperBound()) << "]" <<std::endl;}
							handled = true;
						}
						break;
					}
					case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
					{
						std::shared_ptr<ecore::EObjectAny> eObjectAny=nullptr;
						try
						{
							std::shared_ptr<ecore::EObjectContainer> eObjectContainer = instanceValue->get<std::shared_ptr<ecore::EObjectContainer>>();
							std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
							returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
							for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
							{	// recursive Call of convertToString via new Any EObject Value
								returnStringStream << "\tType: "<<object->eClass()->getName()<<std::endl;
							}
							handled = true;
						}
						catch(...) // 2. try
						{
							std::shared_ptr<ecore::EObject> eObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							std::shared_ptr<ecore::EObjectContainer> eObjectContainer=std::dynamic_pointer_cast<ecore::EObjectContainer>(eObject);
							if(nullptr!=eObjectContainer)
							{
								std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
								returnStringStream << "<EObjectContainer> size: " << eObjectBag->size() <<std::endl;
								for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
								{	// recursive Call of convertToString via new Any EObject Value
									returnStringStream << "\tType:"<<object->eClass()->getName()<<std::endl;
								}
								handled = true;
							}
						}
						break;
					}
					//bool
					case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
					case ecore::ecorePackage::EBOOLEAN_CLASS:
					{
						bool result = instanceValue->get<bool>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//char
					case ecore::ecorePackage::EBYTE_CLASS:
					case ecore::ecorePackage::EBYTEARRAY_CLASS:
					case ecore::ecorePackage::EBYTEOBJECT_CLASS:
					case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
					case ecore::ecorePackage::ECHAR_CLASS:
					{
						int result = instanceValue->get<char>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//int
					case ecore::ecorePackage::EDATE_CLASS:
					case ecore::ecorePackage::ERESOURCE_CLASS:
					case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
					case ecore::ecorePackage::EBIGINTEGER_CLASS:
					case ecore::ecorePackage::ESHORT_CLASS:
					case ecore::ecorePackage::ESHORTOBJECT_CLASS:
					case ecore::ecorePackage::EINT_CLASS:
					{
						int result = instanceValue->get<int>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//long
					case ecore::ecorePackage::ELONGOBJECT_CLASS:
					case ecore::ecorePackage::ELONG_CLASS:
					{
						int result = instanceValue->get<long>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//float
					case ecore::ecorePackage::EFLOATOBJECT_CLASS:
					case ecore::ecorePackage::EFLOAT_CLASS:
					{
						int result = instanceValue->get<float>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//double
					case ecore::ecorePackage::EBIGDECIMAL_CLASS:
					case ecore::ecorePackage::EDOUBLE_CLASS:
					{
						int result = instanceValue->get<double>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					//std::string
					case ecore::ecorePackage::ESTRING_CLASS:
					{
						std::string result = instanceValue->get<std::string>();
						returnStringStream << result << std::endl;
						handled = true; break;
					}
					case ecore::ecorePackage::EJAVAOBJECT_CLASS:
					case ecore::ecorePackage::EENUMERATOR_CLASS:
					case ecore::ecorePackage::EDIAGNOSTICCHAIN_CLASS:
					case ecore::ecorePackage::ANY_CLASS:
					{
						std::shared_ptr<ecore::EObjectAny> eObjectAny=nullptr;
						try
						{
							std::shared_ptr<ecore::EObject> aObject = instanceValue->get<std::shared_ptr<ecore::EObject>>();
							eObjectAny = std::dynamic_pointer_cast<ecore::EObjectAny>(aObject);
						}
						catch(...) // 2. try
						{
							try
							{
								eObjectAny= instanceValue->get<std::shared_ptr<ecore::EObjectAny>>();
							}
							catch(...) // 2. last try
							{
								std::shared_ptr<Any> anAny= instanceValue->get<std::shared_ptr<Any>>();
								returnStringStream << "Any: " << convertToString(nullptr, anAny);
								handled = true;
							}
						}
						// recursive Call of convertToString via new Any EObject Value
						if(nullptr!=eObjectAny)
						{
							returnStringStream << "Any: " << convertToString(nullptr, eObjectAny->getAny());
							handled = true;
						}
						break;
					}
					default: // unknown or primitive type / or 0--> Try & Error
					{
						break;
					}
				}
			}
			catch (...) { }
			{
			}
		}
		if(false==handled) // last chance try and error
		{
			try {
				bool result = instanceValue->get<bool>();
				returnStringStream << result << std::endl;
				return returnStringStream.str();
			} catch (...) { }
			try {
				int result = instanceValue->get<int>();
				returnStringStream << result << std::endl;
				return returnStringStream.str();
			} catch (...) { }
			try {
				std::string result = instanceValue->get<std::string>();
				returnStringStream << result << std::endl;
				return returnStringStream.str();
			} catch (...) { }
			try {
				double result = instanceValue->get<double>();
				returnStringStream << result << std::endl;
				return returnStringStream.str();
			} catch (...){}
			try {
				std::string result = instanceValue->get<std::string>();
				returnStringStream << result << std::endl;
				return returnStringStream.str();
			} catch (...){}
			try {
				std::shared_ptr<Any> any = instanceValue->get<std::shared_ptr<Any>>();
				returnStringStream << "<Any>:" ;
				returnStringStream << convertToString(eDataType, any);
				return returnStringStream.str();
			} catch (...) { }
			{
				returnStringStream << "Any (typeId: " << instanceValue->getTypeId() <<")";
				return returnStringStream.str();
			}
		}
	}
	return returnStringStream.str();
	//end of body
}

std::shared_ptr<ecore::EObject> EFactoryImpl::create(std::shared_ptr<ecore::EClass> eClass) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Any> EFactoryImpl::createFromString(std::shared_ptr<ecore::EDataType> eDataType, std::string literalValue) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ePackage */
std::shared_ptr<ecore::EPackage> EFactoryImpl::getEPackage() const
{
    return m_ePackage;
}
void EFactoryImpl::setEPackage(std::shared_ptr<ecore::EPackage> _ePackage)
{
    m_ePackage = _ePackage;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EFactoryImpl::getEContentUnion() const
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
std::shared_ptr<ecore::EObject> EFactoryImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EFactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EFactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("ePackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("ePackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EFactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EModelElementImpl::loadNode(nodeName, loadHandler);
}

void EFactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EPackage> _ePackage = std::dynamic_pointer_cast<ecore::EPackage>( references.front() );
				setEPackage(_ePackage);
			}
			
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EFactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EFactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
	// Add references
		saveHandler->addReference(this->getEPackage(),"ePackage", getEPackage()->eClass() != ecore::ecorePackage::eInstance()->getEPackage_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EFactoryImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEFactory_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EFactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
			return eAny(getEPackage(),ecore::ecorePackage::EPACKAGE_CLASS,false); //244
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}

bool EFactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
			return getEPackage() != nullptr; //244
	}
	return EModelElementImpl::internalEIsSet(featureID);
}

bool EFactoryImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EFACTORY_ATTRIBUTE_EPACKAGE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<ecore::EPackage> _ePackage = std::dynamic_pointer_cast<ecore::EPackage>(eObject);
					if(_ePackage)
					{
						setEPackage(_ePackage); //244
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'ePackage'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'ePackage'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EFactoryImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// ecore::EFactory::convertToString(ecore::EDataType, Any) : std::string {const}: 197002689
		case ecorePackage::EFACTORY_OPERATION_CONVERTTOSTRING_EDATATYPE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'eDataType'
			//parameter 0
			std::shared_ptr<ecore::EDataType> incoming_param_eDataType;
			Bag<Any>::const_iterator incoming_param_eDataType_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eDataType_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eDataType = std::dynamic_pointer_cast<ecore::EDataType>(_temp);
					}
					catch(...)
					{
						DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::EcoreAny' for parameter 'eDataType'. Failed to invoke operation 'convertToString'!"<< std::endl;)
						return nullptr;
					}
				}
				else
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for parameter 'eDataType'. Failed to invoke operation 'convertToString'!"<< std::endl;)
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'instanceValue'
			//parameter 1
			std::shared_ptr<Any> incoming_param_instanceValue;
			Bag<Any>::const_iterator incoming_param_instanceValue_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_instanceValue = (*incoming_param_instanceValue_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'instanceValue'. Failed to invoke operation 'convertToString'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->convertToString(incoming_param_eDataType,incoming_param_instanceValue),0,false);
			break;
		}
		// ecore::EFactory::create(ecore::EClass) : ecore::EObject {const}: 3809046360
		case ecorePackage::EFACTORY_OPERATION_CREATE_ECLASS:
		{
			//Retrieve input parameter 'eClass'
			//parameter 0
			std::shared_ptr<ecore::EClass> incoming_param_eClass;
			Bag<Any>::const_iterator incoming_param_eClass_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eClass_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eClass = std::dynamic_pointer_cast<ecore::EClass>(_temp);
					}
					catch(...)
					{
						DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::EcoreAny' for parameter 'eClass'. Failed to invoke operation 'create'!"<< std::endl;)
						return nullptr;
					}
				}
				else
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for parameter 'eClass'. Failed to invoke operation 'create'!"<< std::endl;)
					return nullptr;
				}
			}
		
			result = eEcoreAny(this->create(incoming_param_eClass), ecore::ecorePackage::EOBJECT_CLASS);
			break;
		}
		// ecore::EFactory::createFromString(ecore::EDataType, std::string) : Any {const}: 351752421
		case ecorePackage::EFACTORY_OPERATION_CREATEFROMSTRING_EDATATYPE_ESTRING:
		{
			//Retrieve input parameter 'eDataType'
			//parameter 0
			std::shared_ptr<ecore::EDataType> incoming_param_eDataType;
			Bag<Any>::const_iterator incoming_param_eDataType_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eDataType_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eDataType = std::dynamic_pointer_cast<ecore::EDataType>(_temp);
					}
					catch(...)
					{
						DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::EcoreAny' for parameter 'eDataType'. Failed to invoke operation 'createFromString'!"<< std::endl;)
						return nullptr;
					}
				}
				else
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for parameter 'eDataType'. Failed to invoke operation 'createFromString'!"<< std::endl;)
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'literalValue'
			//parameter 1
			std::string incoming_param_literalValue;
			Bag<Any>::const_iterator incoming_param_literalValue_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_literalValue = (*incoming_param_literalValue_arguments_citer)->get<std::string>();
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for parameter 'literalValue'. Failed to invoke operation 'createFromString'!"<< std::endl;)
				return nullptr;
			}
			
		
			result = eAny(this->createFromString(incoming_param_eDataType,incoming_param_literalValue),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EFactory> EFactoryImpl::getThisEFactoryPtr() const
{
	return m_thisEFactoryPtr.lock();
}
void EFactoryImpl::setThisEFactoryPtr(std::weak_ptr<ecore::EFactory> thisEFactoryPtr)
{
	m_thisEFactoryPtr = thisEFactoryPtr;
	setThisEModelElementPtr(thisEFactoryPtr);
}



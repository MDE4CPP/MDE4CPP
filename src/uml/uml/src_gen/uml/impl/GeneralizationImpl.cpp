
#include "uml/impl/GeneralizationImpl.hpp"
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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/GeneralizationSet.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationImpl::GeneralizationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

GeneralizationImpl::~GeneralizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Generalization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Element> par_owner)
:GeneralizationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Classifier> par_specific)
:GeneralizationImpl()
{
	m_specific = par_specific;
	m_owner = par_specific;
}

GeneralizationImpl::GeneralizationImpl(const GeneralizationImpl & obj): GeneralizationImpl()
{
	*this = obj;
}

GeneralizationImpl& GeneralizationImpl::operator=(const GeneralizationImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Generalization 
	 * which is generated by the compiler (as Generalization is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Generalization::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Generalization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isSubstitutable = obj.getIsSubstitutable();

	//copy references with no containment (soft copy)
	m_generalizationSet  = obj.getGeneralizationSet();
	m_specific  = obj.getSpecific();
	//Clone references with containment (deep copy)
	//clone reference 'general'
	if(obj.getGeneral()!=nullptr)
	{
		m_general = std::dynamic_pointer_cast<uml::Classifier>(obj.getGeneral()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> GeneralizationImpl::copy() const
{
	std::shared_ptr<GeneralizationImpl> element(new GeneralizationImpl());
	*element =(*this);
	element->setThisGeneralizationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isSubstitutable */
bool GeneralizationImpl::getIsSubstitutable() const 
{
	return m_isSubstitutable;
}
void GeneralizationImpl::setIsSubstitutable(bool _isSubstitutable)
{
	m_isSubstitutable = _isSubstitutable;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference general */
std::shared_ptr<uml::Classifier> GeneralizationImpl::getGeneral() const
{
    return m_general;
}
void GeneralizationImpl::setGeneral(std::shared_ptr<uml::Classifier> _general)
{
    m_general = _general;
	
}

/* Getter & Setter for reference generalizationSet */
std::shared_ptr<Bag<uml::GeneralizationSet>> GeneralizationImpl::getGeneralizationSet() const
{
	if(m_generalizationSet == nullptr)
	{
		m_generalizationSet.reset(new Bag<uml::GeneralizationSet>());
		
		
	}
    return m_generalizationSet;
}

/* Getter & Setter for reference specific */
std::weak_ptr<uml::Classifier> GeneralizationImpl::getSpecific() const
{
    return m_specific;
}
void GeneralizationImpl::setSpecific(std::weak_ptr<uml::Classifier> _specific)
{
    m_specific = _specific;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> GeneralizationImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> GeneralizationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> GeneralizationImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> GeneralizationImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSource()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> GeneralizationImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getTarget()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> GeneralizationImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_specific.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void GeneralizationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void GeneralizationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isSubstitutable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSubstitutable(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("general");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("general")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("generalizationSet");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalizationSet")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void GeneralizationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void GeneralizationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _general = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setGeneral(_general);
			}
			
			return;
		}

		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
		{
			std::shared_ptr<Bag<uml::GeneralizationSet>> _generalizationSet = getGeneralizationSet();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralizationSet>  _r = std::dynamic_pointer_cast<uml::GeneralizationSet>(ref);
				if (_r != nullptr)
				{
					_generalizationSet->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _specific = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setSpecific(_specific);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void GeneralizationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void GeneralizationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getGeneralization_Attribute_isSubstitutable()) )
		{
			saveHandler->addAttribute("isSubstitutable", this->getIsSubstitutable());
		}
	// Add references
		saveHandler->addReference(this->getGeneral(), "general", getGeneral()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
		saveHandler->addReferences<uml::GeneralizationSet>("generalizationSet", this->getGeneralizationSet());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> GeneralizationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getGeneralization_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> GeneralizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
			return eAny(getGeneral(),uml::umlPackage::CLASSIFIER_CLASS,false); //1096
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
			return eEcoreContainerAny(getGeneralizationSet(),uml::umlPackage::GENERALIZATIONSET_CLASS); //1097
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
			return eAny(getIsSubstitutable(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1098
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSpecific().lock();
			return eEcoreAny(returnValue,uml::umlPackage::CLASSIFIER_CLASS); //1099
		}
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool GeneralizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
			return getGeneral() != nullptr; //1096
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
			return getGeneralizationSet() != nullptr; //1097
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
			return getIsSubstitutable() != true; //1098
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
			return getSpecific().lock() != nullptr; //1099
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool GeneralizationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Classifier> _general = std::dynamic_pointer_cast<uml::Classifier>(eObject);
					if(_general)
					{
						setGeneral(_general); //1096
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'general'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'general'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::GeneralizationSet>> _generalizationSet = getGeneralizationSet();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::GeneralizationSet> valueToAdd = std::dynamic_pointer_cast<uml::GeneralizationSet>(anEObject);
	
							if (valueToAdd)
							{
								if(_generalizationSet->find(valueToAdd) == -1)
								{
									_generalizationSet->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreContainerAny' for feature 'generalizationSet'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreContainerAny' for feature 'generalizationSet'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
		{
			try
			{
				bool _isSubstitutable = newValue->get<bool>();
				setIsSubstitutable(_isSubstitutable); //1098
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for feature 'isSubstitutable'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
		case uml::umlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Classifier> _specific = std::dynamic_pointer_cast<uml::Classifier>(eObject);
					if(_specific)
					{
						setSpecific(_specific); //1099
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'ecore::ecoreAny' for feature 'specific'. Failed to set feature!"<< std::endl;)
					return false;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'ecore::ecoreAny' for feature 'specific'. Failed to set feature!"<< std::endl;)
				return false;
			}
		return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> GeneralizationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Generalization> GeneralizationImpl::getThisGeneralizationPtr() const
{
	return m_thisGeneralizationPtr.lock();
}
void GeneralizationImpl::setThisGeneralizationPtr(std::weak_ptr<uml::Generalization> thisGeneralizationPtr)
{
	m_thisGeneralizationPtr = thisGeneralizationPtr;
	setThisDirectedRelationshipPtr(thisGeneralizationPtr);
}



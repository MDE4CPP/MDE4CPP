#include "uml/impl/SubstitutionImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OpaqueExpression.hpp"
#include "uml/Package.hpp"
#include "uml/Realization.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SubstitutionImpl::SubstitutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SubstitutionImpl::~SubstitutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Substitution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:SubstitutionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Element> par_owner)
:SubstitutionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Package> par_owningPackage)
:SubstitutionImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:SubstitutionImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

//Additional constructor for the containments back reference
SubstitutionImpl::SubstitutionImpl(std::weak_ptr<uml::Classifier> par_substitutingClassifier)
:SubstitutionImpl()
{
	m_substitutingClassifier = par_substitutingClassifier;
	m_owner = par_substitutingClassifier;
}

SubstitutionImpl::SubstitutionImpl(const SubstitutionImpl & obj): SubstitutionImpl()
{
	*this = obj;
}

SubstitutionImpl& SubstitutionImpl::operator=(const SubstitutionImpl & obj)
{
	//call overloaded =Operator for each base class
	RealizationImpl::operator=(obj);
	Substitution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Substitution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_substitutingClassifier  = obj.getSubstitutingClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'contract'
	if(obj.getContract()!=nullptr)
	{
		m_contract = std::dynamic_pointer_cast<uml::Classifier>(obj.getContract()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> SubstitutionImpl::copy() const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl());
	*element =(*this);
	element->setThisSubstitutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SubstitutionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getSubstitution_Class();
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
Getter & Setter for reference contract
*/
std::shared_ptr<uml::Classifier> SubstitutionImpl::getContract() const
{
    return m_contract;
}
void SubstitutionImpl::setContract(std::shared_ptr<uml::Classifier> _contract)
{
    m_contract = _contract;
	
}


/*
Getter & Setter for reference substitutingClassifier
*/
std::weak_ptr<uml::Classifier> SubstitutionImpl::getSubstitutingClassifier() const
{
    return m_substitutingClassifier;
}
void SubstitutionImpl::setSubstitutingClassifier(std::weak_ptr<uml::Classifier> _substitutingClassifier)
{
    m_substitutingClassifier = _substitutingClassifier;
	
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> SubstitutionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> SubstitutionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> SubstitutionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> SubstitutionImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> SubstitutionImpl::getSource() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> SubstitutionImpl::getTarget() const
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




std::shared_ptr<Substitution> SubstitutionImpl::getThisSubstitutionPtr() const
{
	return m_thisSubstitutionPtr.lock();
}
void SubstitutionImpl::setThisSubstitutionPtr(std::weak_ptr<Substitution> thisSubstitutionPtr)
{
	m_thisSubstitutionPtr = thisSubstitutionPtr;
	setThisRealizationPtr(thisSubstitutionPtr);
}
std::shared_ptr<ecore::EObject> SubstitutionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}

	if(auto wp = m_substitutingClassifier.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SubstitutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_CONTRACT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getContract();
				return eAny(returnValue); //22918
			}
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getSubstitutingClassifier().lock();
				return eAny(returnValue); //22919
			}
	}
	return RealizationImpl::eGet(featureID, resolve, coreType);
}
bool SubstitutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_CONTRACT:
			return getContract() != nullptr; //22918
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER:
			return getSubstitutingClassifier().lock() != nullptr; //22919
	}
	return RealizationImpl::internalEIsSet(featureID);
}
bool SubstitutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_CONTRACT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _contract = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setContract(_contract); //22918
			return true;
		}
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _substitutingClassifier = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setSubstitutingClassifier(_substitutingClassifier); //22919
			return true;
		}
	}

	return RealizationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any SubstitutionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = RealizationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void SubstitutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SubstitutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("contract");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("contract")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	RealizationImpl::loadAttributes(loadHandler, attr_list);
}

void SubstitutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	RealizationImpl::loadNode(nodeName, loadHandler);
}

void SubstitutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_CONTRACT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _contract = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setContract(_contract);
			}
			
			return;
		}

		case uml::umlPackage::SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _substitutingClassifier = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setSubstitutingClassifier(_substitutingClassifier);
			}
			
			return;
		}
	}
	RealizationImpl::resolveReferences(featureID, references);
}

void SubstitutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	RealizationImpl::saveContent(saveHandler);
	
	AbstractionImpl::saveContent(saveHandler);
	
	DependencyImpl::saveContent(saveHandler);
	
	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void SubstitutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getContract(), "contract", getContract()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


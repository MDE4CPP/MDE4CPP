#include "uml/impl/GeneralizationSetImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Generalization.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
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
GeneralizationSetImpl::GeneralizationSetImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

GeneralizationSetImpl::~GeneralizationSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralizationSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Namespace> par_namespace)
:GeneralizationSetImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Element> par_owner)
:GeneralizationSetImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::Package> par_owningPackage)
:GeneralizationSetImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
GeneralizationSetImpl::GeneralizationSetImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:GeneralizationSetImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

GeneralizationSetImpl::GeneralizationSetImpl(const GeneralizationSetImpl & obj): GeneralizationSetImpl()
{
	*this = obj;
}

GeneralizationSetImpl& GeneralizationSetImpl::operator=(const GeneralizationSetImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	GeneralizationSet::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GeneralizationSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isCovering = obj.getIsCovering();
	m_isDisjoint = obj.getIsDisjoint();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Generalization>> _generalization = obj.getGeneralization();
	m_generalization.reset(new Bag<uml::Generalization>(*(obj.getGeneralization().get())));
	m_powertype  = obj.getPowertype();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> GeneralizationSetImpl::copy() const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl());
	*element =(*this);
	element->setThisGeneralizationSetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> GeneralizationSetImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getGeneralizationSet_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isCovering
*/
bool GeneralizationSetImpl::getIsCovering() const 
{
	return m_isCovering;
}
void GeneralizationSetImpl::setIsCovering(bool _isCovering)
{
	m_isCovering = _isCovering;
} 


/*
Getter & Setter for attribute isDisjoint
*/
bool GeneralizationSetImpl::getIsDisjoint() const 
{
	return m_isDisjoint;
}
void GeneralizationSetImpl::setIsDisjoint(bool _isDisjoint)
{
	m_isDisjoint = _isDisjoint;
} 


//*********************************
// Operations
//*********************************
bool GeneralizationSetImpl::generalization_same_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool GeneralizationSetImpl::maps_to_generalization_set(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference generalization
*/
std::shared_ptr<Bag<uml::Generalization>> GeneralizationSetImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		m_generalization.reset(new Bag<uml::Generalization>());
		
		
	}

    return m_generalization;
}



/*
Getter & Setter for reference powertype
*/
std::shared_ptr<uml::Classifier> GeneralizationSetImpl::getPowertype() const
{

    return m_powertype;
}
void GeneralizationSetImpl::setPowertype(std::shared_ptr<uml::Classifier> _powertype)
{
    m_powertype = _powertype;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> GeneralizationSetImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> GeneralizationSetImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> GeneralizationSetImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<GeneralizationSet> GeneralizationSetImpl::getThisGeneralizationSetPtr() const
{
	return m_thisGeneralizationSetPtr.lock();
}
void GeneralizationSetImpl::setThisGeneralizationSetPtr(std::weak_ptr<GeneralizationSet> thisGeneralizationSetPtr)
{
	m_thisGeneralizationSetPtr = thisGeneralizationSetPtr;
	setThisPackageableElementPtr(thisGeneralizationSetPtr);
}
std::shared_ptr<ecore::EObject> GeneralizationSetImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any GeneralizationSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
		{
			return eAny(getGeneralization()); //11015			
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
			return eAny(getIsCovering()); //11012
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
			return eAny(getIsDisjoint()); //11013
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
			return eAny(getPowertype()); //11014
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool GeneralizationSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
			return getGeneralization() != nullptr; //11015
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
			return getIsCovering() != false; //11012
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
			return getIsDisjoint() != false; //11013
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
			return getPowertype() != nullptr; //11014
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool GeneralizationSetImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Generalization>> generalizationList(new Bag<uml::Generalization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalizationList->add(std::dynamic_pointer_cast<uml::Generalization>(*iter));
				iter++;
			}
			
			Bag<uml::Generalization>::iterator iterGeneralization = m_generalization->begin();
			Bag<uml::Generalization>::iterator endGeneralization = m_generalization->end();
			while (iterGeneralization != endGeneralization)
			{
				if (generalizationList->find(*iterGeneralization) == -1)
				{
					m_generalization->erase(*iterGeneralization);
				}
				iterGeneralization++;
			}
 
			iterGeneralization = generalizationList->begin();
			endGeneralization = generalizationList->end();
			while (iterGeneralization != endGeneralization)
			{
				if (m_generalization->find(*iterGeneralization) == -1)
				{
					m_generalization->add(*iterGeneralization);
				}
				iterGeneralization++;			
			}
			return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISCOVERING:
		{
			// BOOST CAST
			bool _isCovering = newValue->get<bool>();
			setIsCovering(_isCovering); //11012
			return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT:
		{
			// BOOST CAST
			bool _isDisjoint = newValue->get<bool>();
			setIsDisjoint(_isDisjoint); //11013
			return true;
		}
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _powertype = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setPowertype(_powertype); //11014
			return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any GeneralizationSetImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 11075
		case umlPackage::GENERALIZATIONSET_OPERATION_GENERALIZATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->generalization_same_classifier(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 11076
		case umlPackage::GENERALIZATIONSET_OPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->maps_to_generalization_set(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
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
void GeneralizationSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GeneralizationSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCovering");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCovering(value);
		}

		iter = attr_list.find("isDisjoint");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDisjoint(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("generalization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertype");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertype")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void GeneralizationSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void GeneralizationSetImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION:
		{
			std::shared_ptr<Bag<uml::Generalization>> _generalization = getGeneralization();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Generalization>  _r = std::dynamic_pointer_cast<uml::Generalization>(ref);
				if (_r != nullptr)
				{
					_generalization->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::GENERALIZATIONSET_ATTRIBUTE_POWERTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _powertype = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setPowertype(_powertype);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void GeneralizationSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void GeneralizationSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getGeneralizationSet_Attribute_isCovering()) )
		{
			saveHandler->addAttribute("isCovering", this->getIsCovering());
		}

		if ( this->eIsSet(package->getGeneralizationSet_Attribute_isDisjoint()) )
		{
			saveHandler->addAttribute("isDisjoint", this->getIsDisjoint());
		}
	// Add references
		saveHandler->addReferences<uml::Generalization>("generalization", this->getGeneralization());
		saveHandler->addReference(this->getPowertype(), "powertype", getPowertype()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


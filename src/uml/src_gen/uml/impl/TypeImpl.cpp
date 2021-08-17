#include "uml/impl/TypeImpl.hpp"

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


#include "uml/Association.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TypeImpl::TypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TypeImpl::~TypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Type "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:TypeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Element> par_owner)
:TypeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:TypeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
TypeImpl::TypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:TypeImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


TypeImpl::TypeImpl(const TypeImpl & obj): TypeImpl()
{
	*this = obj;
}

TypeImpl& TypeImpl::operator=(const TypeImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	Type::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Type "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_package  = obj.getPackage();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TypeImpl::copy() const
{
	std::shared_ptr<TypeImpl> element(new TypeImpl());
	*element =(*this);
	element->setThisTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TypeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TypeImpl::conformsTo(std::shared_ptr<uml::Type> other)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Association> TypeImpl::createAssociation(bool end1IsNavigable,uml::AggregationKind end1Aggregation,std::string end1Name,int end1Lower,int end1Upper,std::shared_ptr<uml::Type> end1Type,bool end2IsNavigable,uml::AggregationKind end2Aggregation,std::string end2Name,int end2Lower,int end2Upper)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Association> > TypeImpl::getAssociations()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference package
*/
std::weak_ptr<uml::Package> TypeImpl::getPackage() const
{
    return m_package;
}
void TypeImpl::setPackage(std::weak_ptr<uml::Package> _package)
{
    m_package = _package;
	
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> TypeImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> TypeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TypeImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Type> TypeImpl::getThisTypePtr() const
{
	return m_thisTypePtr.lock();
}
void TypeImpl::setThisTypePtr(std::weak_ptr<Type> thisTypePtr)
{
	m_thisTypePtr = thisTypePtr;
	setThisPackageableElementPtr(thisTypePtr);
}
std::shared_ptr<ecore::EObject> TypeImpl::eContainer() const
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
	if(auto wp = m_package.lock())
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
Any TypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getPackage().lock();
				return eAny(returnValue); //24412
			}
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool TypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
			return getPackage().lock() != nullptr; //24412
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool TypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _package = std::dynamic_pointer_cast<uml::Package>(_temp);
			setPackage(_package); //24412
			return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any TypeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 24474
		case umlPackage::TYPE_OPERATION_CONFORMSTO_TYPE:
		{
			//Retrieve input parameter 'other'
			//parameter 0
			std::shared_ptr<uml::Type> incoming_param_other;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_other_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_other = (*incoming_param_other_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			result = eAny(this->conformsTo(incoming_param_other));
			break;
		}
		
		// 24472
		case umlPackage::TYPE_OPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'end1IsNavigable'
			//parameter 0
			bool incoming_param_end1IsNavigable;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1IsNavigable_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_end1IsNavigable = (*incoming_param_end1IsNavigable_arguments_citer)->get()->get<bool >();
			//Retrieve input parameter 'end1Aggregation'
			//parameter 1
			uml::AggregationKind incoming_param_end1Aggregation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1Aggregation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_end1Aggregation = (*incoming_param_end1Aggregation_arguments_citer)->get()->get<uml::AggregationKind >();
			//Retrieve input parameter 'end1Name'
			//parameter 2
			std::string incoming_param_end1Name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1Name_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_end1Name = (*incoming_param_end1Name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'end1Lower'
			//parameter 3
			int incoming_param_end1Lower;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1Lower_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_end1Lower = (*incoming_param_end1Lower_arguments_citer)->get()->get<int >();
			//Retrieve input parameter 'end1Upper'
			//parameter 4
			int incoming_param_end1Upper;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1Upper_arguments_citer = std::next(arguments->begin(), 4);
			incoming_param_end1Upper = (*incoming_param_end1Upper_arguments_citer)->get()->get<int >();
			//Retrieve input parameter 'end1Type'
			//parameter 5
			std::shared_ptr<uml::Type> incoming_param_end1Type;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end1Type_arguments_citer = std::next(arguments->begin(), 5);
			incoming_param_end1Type = (*incoming_param_end1Type_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			//Retrieve input parameter 'end2IsNavigable'
			//parameter 6
			bool incoming_param_end2IsNavigable;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end2IsNavigable_arguments_citer = std::next(arguments->begin(), 6);
			incoming_param_end2IsNavigable = (*incoming_param_end2IsNavigable_arguments_citer)->get()->get<bool >();
			//Retrieve input parameter 'end2Aggregation'
			//parameter 7
			uml::AggregationKind incoming_param_end2Aggregation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end2Aggregation_arguments_citer = std::next(arguments->begin(), 7);
			incoming_param_end2Aggregation = (*incoming_param_end2Aggregation_arguments_citer)->get()->get<uml::AggregationKind >();
			//Retrieve input parameter 'end2Name'
			//parameter 8
			std::string incoming_param_end2Name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end2Name_arguments_citer = std::next(arguments->begin(), 8);
			incoming_param_end2Name = (*incoming_param_end2Name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'end2Lower'
			//parameter 9
			int incoming_param_end2Lower;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end2Lower_arguments_citer = std::next(arguments->begin(), 9);
			incoming_param_end2Lower = (*incoming_param_end2Lower_arguments_citer)->get()->get<int >();
			//Retrieve input parameter 'end2Upper'
			//parameter 10
			int incoming_param_end2Upper;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_end2Upper_arguments_citer = std::next(arguments->begin(), 10);
			incoming_param_end2Upper = (*incoming_param_end2Upper_arguments_citer)->get()->get<int >();
			result = eAny(this->createAssociation(incoming_param_end1IsNavigable,incoming_param_end1Aggregation,incoming_param_end1Name,incoming_param_end1Lower,incoming_param_end1Upper,incoming_param_end1Type,incoming_param_end2IsNavigable,incoming_param_end2Aggregation,incoming_param_end2Name,incoming_param_end2Lower,incoming_param_end2Upper));
			break;
		}
		
		// 24473
		case umlPackage::TYPE_OPERATION_GETASSOCIATIONS:
		{
			result = eAny(this->getAssociations());
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
void TypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void TypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void TypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _package = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setPackage(_package);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void TypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void TypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


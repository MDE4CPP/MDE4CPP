#include "uml/impl/MultiplicityElementImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Element.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/ValueSpecification.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MultiplicityElementImpl::MultiplicityElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

MultiplicityElementImpl::~MultiplicityElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MultiplicityElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			MultiplicityElementImpl::MultiplicityElementImpl(std::weak_ptr<uml::Element > par_owner)
			:MultiplicityElementImpl()
			{
			    m_owner = par_owner;
			}






MultiplicityElementImpl::MultiplicityElementImpl(const MultiplicityElementImpl & obj):MultiplicityElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MultiplicityElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

	

	
}

std::shared_ptr<ecore::EObject>  MultiplicityElementImpl::copy() const
{
	std::shared_ptr<MultiplicityElementImpl> element(new MultiplicityElementImpl(*this));
	element->setThisMultiplicityElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> MultiplicityElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getMultiplicityElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void MultiplicityElementImpl::setIsOrdered(bool _isOrdered)
{
	m_isOrdered = _isOrdered;
} 

bool MultiplicityElementImpl::getIsOrdered() const 
{
	return m_isOrdered;
}

void MultiplicityElementImpl::setIsUnique(bool _isUnique)
{
	m_isUnique = _isUnique;
} 

bool MultiplicityElementImpl::getIsUnique() const 
{
	return m_isUnique;
}

void MultiplicityElementImpl::setLower(int _lower)
{
	m_lower = _lower;
} 

int MultiplicityElementImpl::getLower() const 
{
	return m_lower;
}

void MultiplicityElementImpl::setUpper(unsigned int _upper)
{
	m_upper = _upper;
} 

unsigned int MultiplicityElementImpl::getUpper() const 
{
	return m_upper;
}

//*********************************
// Operations
//*********************************
bool MultiplicityElementImpl::compatibleWith(std::shared_ptr<uml::MultiplicityElement>  other)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::includesMultiplicity(std::shared_ptr<uml::MultiplicityElement>  M)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::is(int lowerbound,unsigned int upperbound)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::isMultivalued()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int MultiplicityElementImpl::lowerBound()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::lower_ge_0(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::lower_is_integer(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

unsigned int MultiplicityElementImpl::upperBound()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_ge_lower(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::upper_is_unlimitedNatural(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_constant(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool MultiplicityElementImpl::value_specification_no_side_effects(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > MultiplicityElementImpl::getLowerValue() const
{

    return m_lowerValue;
}
void MultiplicityElementImpl::setLowerValue(std::shared_ptr<uml::ValueSpecification> _lowerValue)
{
    m_lowerValue = _lowerValue;
}

std::shared_ptr<uml::ValueSpecification > MultiplicityElementImpl::getUpperValue() const
{

    return m_upperValue;
}
void MultiplicityElementImpl::setUpperValue(std::shared_ptr<uml::ValueSpecification> _upperValue)
{
    m_upperValue = _upperValue;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> MultiplicityElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<MultiplicityElement> MultiplicityElementImpl::getThisMultiplicityElementPtr() const
{
	return m_thisMultiplicityElementPtr.lock();
}
void MultiplicityElementImpl::setThisMultiplicityElementPtr(std::weak_ptr<MultiplicityElement> thisMultiplicityElementPtr)
{
	m_thisMultiplicityElementPtr = thisMultiplicityElementPtr;
	setThisElementPtr(thisMultiplicityElementPtr);
}
std::shared_ptr<ecore::EObject> MultiplicityElementImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any MultiplicityElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
			return eAny(getIsOrdered()); //1543
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
			return eAny(getIsUnique()); //1544
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
			return eAny(getLower()); //1545
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
			return eAny(getLowerValue()); //1546
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
			return eAny(getUpper()); //1547
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
			return eAny(getUpperValue()); //1548
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool MultiplicityElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
			return getIsOrdered() != false; //1543
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
			return getIsUnique() != true; //1544
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
			return getLower() != 1; //1545
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
			return getLowerValue() != nullptr; //1546
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
			return getUpper() != 1; //1547
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
			return getUpperValue() != nullptr; //1548
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool MultiplicityElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = newValue->get<bool>();
			setIsOrdered(_isOrdered); //1543
			return true;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = newValue->get<bool>();
			setIsUnique(_isUnique); //1544
			return true;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWER:
		{
			// BOOST CAST
			int _lower = newValue->get<int>();
			setLower(_lower); //1545
			return true;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setLowerValue(_lowerValue); //1546
			return true;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPER:
		{
			// BOOST CAST
			unsigned int _upper = newValue->get<unsigned int>();
			setUpper(_upper); //1547
			return true;
		}
		case UmlPackage::MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setUpperValue(_upperValue); //1548
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void MultiplicityElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void MultiplicityElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isOrdered");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsOrdered(value);
		}

		iter = attr_list.find("isUnique");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsUnique(value);
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void MultiplicityElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("lowerValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (lowerValue != nullptr)
			{
				this->setLowerValue(lowerValue);
				loadHandler->handleChild(lowerValue);
			}
			return;
		}

		if ( nodeName.compare("upperValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (upperValue != nullptr)
			{
				this->setUpperValue(upperValue);
				loadHandler->handleChild(upperValue);
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

	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void MultiplicityElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void MultiplicityElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void MultiplicityElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'lowerValue'
		std::shared_ptr<uml::ValueSpecification > lowerValue = this->getLowerValue();
		if (lowerValue != nullptr)
		{
			saveHandler->addReference(lowerValue, "lowerValue", lowerValue->eClass() != package->getValueSpecification_Class());
		}

		// Save 'upperValue'
		std::shared_ptr<uml::ValueSpecification > upperValue = this->getUpperValue();
		if (upperValue != nullptr)
		{
			saveHandler->addReference(upperValue, "upperValue", upperValue->eClass() != package->getValueSpecification_Class());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getMultiplicityElement_Attribute_isOrdered()) )
		{
			saveHandler->addAttribute("isOrdered", this->getIsOrdered());
		}

		if ( this->eIsSet(package->getMultiplicityElement_Attribute_isUnique()) )
		{
			saveHandler->addAttribute("isUnique", this->getIsUnique());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


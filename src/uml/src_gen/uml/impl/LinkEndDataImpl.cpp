#include "uml/impl/LinkEndDataImpl.hpp"

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

#include "uml/InputPin.hpp"

#include "uml/Property.hpp"

#include "uml/QualifierValue.hpp"

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
LinkEndDataImpl::LinkEndDataImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_qualifier.reset(new Subset<uml::QualifierValue, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
	

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

LinkEndDataImpl::~LinkEndDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			LinkEndDataImpl::LinkEndDataImpl(std::weak_ptr<uml::Element > par_owner)
			:LinkEndDataImpl()
			{
			    m_owner = par_owner;
			}






LinkEndDataImpl::LinkEndDataImpl(const LinkEndDataImpl & obj):LinkEndDataImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_end  = obj.getEnd();

	m_owner  = obj.getOwner();

	m_value  = obj.getValue();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::QualifierValue>> _qualifierList = obj.getQualifier();
	for(std::shared_ptr<uml::QualifierValue> _qualifier : *_qualifierList)
	{
		this->getQualifier()->add(std::shared_ptr<uml::QualifierValue>(std::dynamic_pointer_cast<uml::QualifierValue>(_qualifier->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_qualifier" << std::endl;
	#endif

		/*Subset*/
		m_qualifier->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_qualifier - Subset<uml::QualifierValue, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  LinkEndDataImpl::copy() const
{
	std::shared_ptr<LinkEndDataImpl> element(new LinkEndDataImpl(*this));
	element->setThisLinkEndDataPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> LinkEndDataImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getLinkEndData_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::InputPin> > LinkEndDataImpl::allPins()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::end_object_input_pin(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::multiplicity(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::property_is_association_end(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::qualifiers(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool LinkEndDataImpl::same_type(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Property > LinkEndDataImpl::getEnd() const
{
//assert(m_end);
    return m_end;
}
void LinkEndDataImpl::setEnd(std::shared_ptr<uml::Property> _end)
{
    m_end = _end;
}

std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> LinkEndDataImpl::getQualifier() const
{

    return m_qualifier;
}


std::shared_ptr<uml::InputPin > LinkEndDataImpl::getValue() const
{

    return m_value;
}
void LinkEndDataImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> LinkEndDataImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<LinkEndData> LinkEndDataImpl::getThisLinkEndDataPtr() const
{
	return m_thisLinkEndDataPtr.lock();
}
void LinkEndDataImpl::setThisLinkEndDataPtr(std::weak_ptr<LinkEndData> thisLinkEndDataPtr)
{
	m_thisLinkEndDataPtr = thisLinkEndDataPtr;
	setThisElementPtr(thisLinkEndDataPtr);
}
std::shared_ptr<ecore::EObject> LinkEndDataImpl::eContainer() const
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
Any LinkEndDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDATA_ATTRIBUTE_END:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getEnd())); //1363
		case UmlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::QualifierValue>::iterator iter = m_qualifier->begin();
			Bag<uml::QualifierValue>::iterator end = m_qualifier->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1364
		}
		case UmlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getValue())); //1365
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool LinkEndDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDATA_ATTRIBUTE_END:
			return getEnd() != nullptr; //1363
		case UmlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
			return getQualifier() != nullptr; //1364
		case UmlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //1365
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool LinkEndDataImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDATA_ATTRIBUTE_END:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _end = std::dynamic_pointer_cast<uml::Property>(_temp);
			setEnd(_end); //1363
			return true;
		}
		case UmlPackage::LINKENDDATA_ATTRIBUTE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::QualifierValue>> qualifierList(new Bag<uml::QualifierValue>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				qualifierList->add(std::dynamic_pointer_cast<uml::QualifierValue>(*iter));
				iter++;
			}
			
			Bag<uml::QualifierValue>::iterator iterQualifier = m_qualifier->begin();
			Bag<uml::QualifierValue>::iterator endQualifier = m_qualifier->end();
			while (iterQualifier != endQualifier)
			{
				if (qualifierList->find(*iterQualifier) == -1)
				{
					m_qualifier->erase(*iterQualifier);
				}
				iterQualifier++;
			}

			iterQualifier = qualifierList->begin();
			endQualifier = qualifierList->end();
			while (iterQualifier != endQualifier)
			{
				if (m_qualifier->find(*iterQualifier) == -1)
				{
					m_qualifier->add(*iterQualifier);
				}
				iterQualifier++;			
			}
			return true;
		}
		case UmlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setValue(_value); //1365
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void LinkEndDataImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkEndDataImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("end");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("end")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void LinkEndDataImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("qualifier") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "QualifierValue";
			}
			std::shared_ptr<uml::QualifierValue> qualifier = std::dynamic_pointer_cast<uml::QualifierValue>(modelFactory->create(typeName));
			if (qualifier != nullptr)
			{
				std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> list_qualifier = this->getQualifier();
				list_qualifier->push_back(qualifier);
				loadHandler->handleChild(qualifier);
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

void LinkEndDataImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::LINKENDDATA_ATTRIBUTE_END:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _end = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setEnd(_end);
			}
			
			return;
		}

		case UmlPackage::LINKENDDATA_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InputPin> _value = std::dynamic_pointer_cast<uml::InputPin>( references.front() );
				setValue(_value);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void LinkEndDataImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void LinkEndDataImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'qualifier'
		for (std::shared_ptr<uml::QualifierValue> qualifier : *this->getQualifier()) 
		{
			saveHandler->addReference(qualifier, "qualifier", qualifier->eClass() != package->getQualifierValue_Class());
		}
	

		// Add references
		saveHandler->addReference("end", this->getEnd());
		saveHandler->addReference("value", this->getValue());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


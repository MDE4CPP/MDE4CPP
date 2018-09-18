#include "uml/impl/QualifierValueImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/InputPin.hpp"

#include "uml/Property.hpp"

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
QualifierValueImpl::QualifierValueImpl()
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

QualifierValueImpl::~QualifierValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete QualifierValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			QualifierValueImpl::QualifierValueImpl(std::weak_ptr<uml::Element > par_owner)
			:QualifierValueImpl()
			{
			    m_owner = par_owner;
			}






QualifierValueImpl::QualifierValueImpl(const QualifierValueImpl & obj):QualifierValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy QualifierValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	m_qualifier  = obj.getQualifier();

	m_value  = obj.getValue();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  QualifierValueImpl::copy() const
{
	std::shared_ptr<QualifierValueImpl> element(new QualifierValueImpl(*this));
	element->setThisQualifierValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> QualifierValueImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getQualifierValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool QualifierValueImpl::multiplicity_of_qualifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::qualifier_attribute(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool QualifierValueImpl::type_of_qualifier(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Property > QualifierValueImpl::getQualifier() const
{
//assert(m_qualifier);
    return m_qualifier;
}
void QualifierValueImpl::setQualifier(std::shared_ptr<uml::Property> _qualifier)
{
    m_qualifier = _qualifier;
}

std::shared_ptr<uml::InputPin > QualifierValueImpl::getValue() const
{
//assert(m_value);
    return m_value;
}
void QualifierValueImpl::setValue(std::shared_ptr<uml::InputPin> _value)
{
    m_value = _value;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> QualifierValueImpl::getOwnedElement() const
{
	return m_ownedElement;
}


std::shared_ptr<QualifierValue> QualifierValueImpl::getThisQualifierValuePtr() const
{
	return m_thisQualifierValuePtr.lock();
}
void QualifierValueImpl::setThisQualifierValuePtr(std::weak_ptr<QualifierValue> thisQualifierValuePtr)
{
	m_thisQualifierValuePtr = thisQualifierValuePtr;
	setThisElementPtr(thisQualifierValuePtr);
}
std::shared_ptr<ecore::EObject> QualifierValueImpl::eContainer() const
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
Any QualifierValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_QUALIFIER:
			return eAny(getQualifier()); //1274
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_VALUE:
			return eAny(getValue()); //1275
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool QualifierValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_QUALIFIER:
			return getQualifier() != nullptr; //1274
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_VALUE:
			return getValue() != nullptr; //1275
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool QualifierValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_QUALIFIER:
		{
			// BOOST CAST
			std::shared_ptr<uml::Property> _qualifier = newValue->get<std::shared_ptr<uml::Property>>();
			setQualifier(_qualifier); //1274
			return true;
		}
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_VALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InputPin> _value = newValue->get<std::shared_ptr<uml::InputPin>>();
			setValue(_value); //1275
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void QualifierValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void QualifierValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("qualifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("qualifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void QualifierValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void QualifierValueImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::QUALIFIERVALUE_EREFERENCE_QUALIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _qualifier = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setQualifier(_qualifier);
			}
			
			return;
		}

		case UmlPackage::QUALIFIERVALUE_EREFERENCE_VALUE:
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

void QualifierValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void QualifierValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("qualifier", this->getQualifier());
		saveHandler->addReference("value", this->getValue());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


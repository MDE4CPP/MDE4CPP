#include "uml/impl/SlotImpl.hpp"

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

#include "uml/InstanceSpecification.hpp"

#include "uml/StructuralFeature.hpp"

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
SlotImpl::SlotImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

		/*Subset*/
		m_value.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

	

		/*Subset*/
		m_value->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

SlotImpl::~SlotImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Slot "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			SlotImpl::SlotImpl(std::weak_ptr<uml::Element > par_owner)
			:SlotImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			SlotImpl::SlotImpl(std::weak_ptr<uml::InstanceSpecification > par_owningInstance)
			:SlotImpl()
			{
			    m_owningInstance = par_owningInstance;
				m_owner = par_owningInstance;
			}






SlotImpl::SlotImpl(const SlotImpl & obj):SlotImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Slot "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_definingFeature  = obj.getDefiningFeature();

	m_owner  = obj.getOwner();

	m_owningInstance  = obj.getOwningInstance();


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
	std::shared_ptr<Bag<uml::ValueSpecification>> _valueList = obj.getValue();
	for(std::shared_ptr<uml::ValueSpecification> _value : *_valueList)
	{
		this->getValue()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_value->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_value" << std::endl;
	#endif

		/*Subset*/
		m_value->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_value - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  SlotImpl::copy() const
{
	std::shared_ptr<SlotImpl> element(new SlotImpl(*this));
	element->setThisSlotPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SlotImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getSlot_EClass();
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
std::shared_ptr<uml::StructuralFeature > SlotImpl::getDefiningFeature() const
{
//assert(m_definingFeature);
    return m_definingFeature;
}
void SlotImpl::setDefiningFeature(std::shared_ptr<uml::StructuralFeature> _definingFeature)
{
    m_definingFeature = _definingFeature;
}

std::weak_ptr<uml::InstanceSpecification > SlotImpl::getOwningInstance() const
{
//assert(m_owningInstance);
    return m_owningInstance;
}
void SlotImpl::setOwningInstance(std::shared_ptr<uml::InstanceSpecification> _owningInstance)
{
    m_owningInstance = _owningInstance;
}

std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> SlotImpl::getValue() const
{

    return m_value;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> SlotImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > SlotImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Slot> SlotImpl::getThisSlotPtr()
{
	return m_thisSlotPtr.lock();
}
void SlotImpl::setThisSlotPtr(std::weak_ptr<Slot> thisSlotPtr)
{
	m_thisSlotPtr = thisSlotPtr;
	setThisElementPtr(thisSlotPtr);
}
std::shared_ptr<ecore::EObject> SlotImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningInstance.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SlotImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::SLOT_EREFERENCE_DEFININGFEATURE:
			return eAny(getDefiningFeature()); //804
		case UmlPackage::SLOT_EREFERENCE_OWNINGINSTANCE:
			return eAny(getOwningInstance()); //806
		case UmlPackage::SLOT_EREFERENCE_VALUE:
			return eAny(getValue()); //805
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool SlotImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::SLOT_EREFERENCE_DEFININGFEATURE:
			return getDefiningFeature() != nullptr; //804
		case UmlPackage::SLOT_EREFERENCE_OWNINGINSTANCE:
			return getOwningInstance().lock() != nullptr; //806
		case UmlPackage::SLOT_EREFERENCE_VALUE:
			return getValue() != nullptr; //805
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool SlotImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::SLOT_EREFERENCE_DEFININGFEATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StructuralFeature> _definingFeature = newValue->get<std::shared_ptr<uml::StructuralFeature>>();
			setDefiningFeature(_definingFeature); //804
			return true;
		}
		case UmlPackage::SLOT_EREFERENCE_OWNINGINSTANCE:
		{
			// BOOST CAST
			std::shared_ptr<uml::InstanceSpecification> _owningInstance = newValue->get<std::shared_ptr<uml::InstanceSpecification>>();
			setOwningInstance(_owningInstance); //806
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void SlotImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SlotImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("definingFeature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("definingFeature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void SlotImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("value") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> value = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::VALUESPECIFICATION_EREFERENCE_OWNINGSLOT);
			if (value != nullptr)
			{
				loadHandler->handleChild(value);
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

void SlotImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::SLOT_EREFERENCE_DEFININGFEATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeature> _definingFeature = std::dynamic_pointer_cast<uml::StructuralFeature>( references.front() );
				setDefiningFeature(_definingFeature);
			}
			
			return;
		}

		case UmlPackage::SLOT_EREFERENCE_OWNINGINSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InstanceSpecification> _owningInstance = std::dynamic_pointer_cast<uml::InstanceSpecification>( references.front() );
				setOwningInstance(_owningInstance);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void SlotImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void SlotImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'value'
		for (std::shared_ptr<uml::ValueSpecification> value : *this->getValue()) 
		{
			saveHandler->addReference(value, "value", value->eClass() != package->getValueSpecification_EClass());
		}
	

		// Add references
		saveHandler->addReference("definingFeature", this->getDefiningFeature());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


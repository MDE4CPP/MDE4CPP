#include "uml/impl/ElementImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/stereotypestorage.hpp"
#include "uml/Property.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Class.hpp"

#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "ecore/EClass.hpp"

#include "ecore/EModelElement.hpp"

#include "ecore/EObject.hpp"

#include "uml/Element.hpp"

#include "uml/Model.hpp"

#include "uml/Object.hpp"

#include "uml/Package.hpp"

#include "uml/Relationship.hpp"

#include "uml/Stereotype.hpp"

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
ElementImpl::ElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_ownedComment.reset(new Subset<uml::Comment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >()" << std::endl;
		#endif
	
	

		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_ownedComment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	

	
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ElementImpl::ElementImpl(std::weak_ptr<uml::Element > par_owner)
			:ElementImpl()
			{
			    m_owner = par_owner;
			}






ElementImpl::ElementImpl(const ElementImpl & obj):ElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();


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

		/*Subset*/
		m_ownedComment->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ElementImpl::copy() const
{
	std::shared_ptr<ElementImpl> element(new ElementImpl(*this));
	element->setThisElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ElementImpl::addKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Element> > ElementImpl::allOwnedElements() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> ElementImpl::applyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	util::StereotypeStorage::eInstance()->applyStereotype(getThisElementPtr(), stereotype);
	return nullptr;
	//end of body
}

std::shared_ptr<uml::Element> ElementImpl::container() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EAnnotation> ElementImpl::createEAnnotation(std::string source) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::destroy() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getApplicableStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedStereotype(std::string qualifiedName) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotype(getThisElementPtr(), qualifiedName);
	//end of body
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedStereotypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotypes(getThisElementPtr());
	//end of body
}

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedSubstereotype(std::shared_ptr<uml::Stereotype>  stereotype,std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedSubstereotypes(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<std::string> > ElementImpl::getKeywords() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> ElementImpl::getMetaClass() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Model> ElementImpl::getModel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Package> ElementImpl::getNearestPackage() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> > ElementImpl::getRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Relationship> > ElementImpl::getRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> ElementImpl::getRequiredStereotype(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getRequiredStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getSourceDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getSourceDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> ElementImpl::getStereotypeApplication(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > ElementImpl::getStereotypeApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getTargetDirectedRelationships() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getTargetDirectedRelationships(std::shared_ptr<ecore::EClass>  eClass) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

boost::any ElementImpl::getValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::Stereotype> stereoInstance = util::StereotypeStorage::eInstance()->getAppliedStereotype(getThisElementPtr(), stereotype->getQualifiedName());
	if(stereoInstance == nullptr)
	{
	   return boost::any();
	}

	std::shared_ptr<Bag<uml::Property> > propertyList = stereoInstance->getMetaClass()->getAttribute();
	for(std::shared_ptr<uml::Property> p: *propertyList)
	{
		if(p->getName()==propertyName)
		{
			return stereoInstance->get(p);
		}
	}
	return boost::any();
	//end of body
}

bool ElementImpl::hasKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::hasValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::has_owner(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplicable(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplied(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->isStereotypeApplied(getThisElementPtr(), stereotype);
	//end of body
}

bool ElementImpl::isStereotypeRequired(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::mustBeOwned() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::not_own_self(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::removeKeyword(std::string keyword) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::setValue(std::shared_ptr<uml::Stereotype>  stereotype,std::string propertyName,boost::any newValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	uml::NamedElement * elem = dynamic_cast<uml::NamedElement *>(this);
if(elem)
{
    //apply stereotype to map
    //std::vector<uml::Stereotype *> appliedStList = map->find(elem->getQualifiedName())
    //return std::any(appliedStList->cbegin();appliedStList->cend();[stereotype](stereo){return });
}
	//end of body
}

std::shared_ptr<ecore::EObject> ElementImpl::unapplyStereotype(std::shared_ptr<uml::Stereotype>  stereotype) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Comment, uml::Element>> ElementImpl::getOwnedComment() const
{

    return m_ownedComment;
}








//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ElementImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ElementImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Element> ElementImpl::getThisElementPtr()
{
	return m_thisElementPtr.lock();
}
void ElementImpl::setThisElementPtr(std::weak_ptr<Element> thisElementPtr)
{
	m_thisElementPtr = thisElementPtr;
	setThisEModelElementPtr(thisElementPtr);
	setThisObjectPtr(thisElementPtr);
}
std::shared_ptr<ecore::EObject> ElementImpl::eContainer() const
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
boost::any ElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //81
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //82
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //83
	}
	boost::any result;
	result = ecore::EModelElementImpl::internalEIsSet(featureID);
	if (!result.empty())
	{
		return result;
	}
	result = ObjectImpl::internalEIsSet(featureID);
	return result;
}
bool ElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment() != nullptr; //81
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement() != nullptr; //82
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner().lock() != nullptr; //83
	}
	bool result = false;
	result = ecore::EModelElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ObjectImpl::internalEIsSet(featureID);
	return result;
}
bool ElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	bool result = false;
	result = ecore::EModelElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ObjectImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EModelElementImpl::loadAttributes(loadHandler, attr_list);
	ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("ownedComment") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Comment";
			}
			std::shared_ptr<ecore::EObject> ownedComment = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::ELEMENT_EREFERENCE_OWNER);
			if (ownedComment != nullptr)
			{
				loadHandler->handleChild(ownedComment);
			}
			return;
		}

		if ( nodeName.compare("ownedElement") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<ecore::EObject> ownedElement = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::ELEMENT_EREFERENCE_OWNER);
			if (ownedElement != nullptr)
			{
				loadHandler->handleChild(ownedElement);
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

	ecore::EModelElementImpl::loadNode(nodeName, loadHandler, ecore::EcoreFactory::eInstance());
	ObjectImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ElementImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EModelElementImpl::resolveReferences(featureID, references);
	ObjectImpl::resolveReferences(featureID, references);
}

void ElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedComment'
		for (std::shared_ptr<uml::Comment> ownedComment : *this->getOwnedComment()) 
		{
			saveHandler->addReference(ownedComment, "ownedComment", ownedComment->eClass() != package->getComment_EClass());
		}
	


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedElement'
		std::shared_ptr<Union<uml::Element>> list_ownedElement = this->getOwnedElement();
		for (std::shared_ptr<uml::Element> ownedElement : *list_ownedElement) 
		{
			saveHandler->addReference(ownedElement, "ownedElement", ownedElement->eClass() != package->getElement_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


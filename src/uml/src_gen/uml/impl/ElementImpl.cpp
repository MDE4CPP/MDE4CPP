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
#include <sstream>

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "util/stereotypestorage.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Class.hpp"
#include "uml/Comment.hpp"
#include "uml/DirectedRelationship.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EObject.hpp"
#include "uml/Element.hpp"
#include "uml/Model.hpp"
#include "uml/Object.hpp"
#include "uml/Package.hpp"
#include "uml/Relationship.hpp"
#include "uml/Stereotype.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ElementImpl::ElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ElementImpl::ElementImpl(std::weak_ptr<uml::Element> par_owner)
:ElementImpl()
{
	m_owner = par_owner;
}

ElementImpl::ElementImpl(const ElementImpl & obj): ElementImpl()
{
	*this = obj;
}

ElementImpl& ElementImpl::operator=(const ElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectImpl::operator=(obj);
	Element::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_owner  = obj.getOwner();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Comment, uml::Element>> ownedCommentContainer = getOwnedComment();
	if(nullptr != ownedCommentContainer )
	{
		int size = ownedCommentContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedComment=(*ownedCommentContainer)[i];
			if(nullptr != _ownedComment)
			{
				ownedCommentContainer->push_back(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedComment."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedComment."<< std::endl;)
	}
	/*Subset*/
	m_ownedComment->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ElementImpl::copy() const
{
	std::shared_ptr<ElementImpl> element(new ElementImpl());
	*element =(*this);
	element->setThisElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getElement_Class();
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
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Element>> list(new Bag<uml::Element>());
	list->insert(list->begin(), this->getOwnedElement()->begin(), this->getOwnedElement()->end());

	Bag<uml::Element>::iterator iter = this->getOwnedElement()->begin();
	Bag<uml::Element>::iterator end = this->getOwnedElement()->end();
	int i = 0;
	while(iter != end)
	{
		std::shared_ptr<Bag<uml::Element>> elementList = (*iter)->allOwnedElements();
		list->insert(list->end(), elementList->begin(), elementList->end());
		iter++;
		i++;
	}

	return list;
	//end of body
}

std::shared_ptr<ecore::EObject> ElementImpl::applyStereotype(std::shared_ptr<uml::Stereotype> stereotype)
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

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedStereotype(std::string qualifiedName) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotype(getThisElementPtr(), qualifiedName);
	//end of body
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedStereotypes() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->getAppliedStereotypes(getThisElementPtr());
	//end of body
}

std::shared_ptr<uml::Stereotype> ElementImpl::getAppliedSubstereotype(std::shared_ptr<uml::Stereotype> stereotype,std::string qualifiedName)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > ElementImpl::getAppliedSubstereotypes(std::shared_ptr<uml::Stereotype> stereotype)
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

std::shared_ptr<Bag<uml::Relationship> > ElementImpl::getRelationships(std::shared_ptr<ecore::EClass> eClass)
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

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getSourceDirectedRelationships(std::shared_ptr<ecore::EClass> eClass)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EObject> ElementImpl::getStereotypeApplication(std::shared_ptr<uml::Stereotype> stereotype)
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

std::shared_ptr<Bag<uml::DirectedRelationship> > ElementImpl::getTargetDirectedRelationships(std::shared_ptr<ecore::EClass> eClass)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any ElementImpl::getValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::Stereotype> stereoInstance = util::StereotypeStorage::eInstance()->getAppliedStereotype(getThisElementPtr(), stereotype->getQualifiedName());
	if(stereoInstance == nullptr)
	{
	   return Any();
	}

	return stereoInstance->getPropertyValue(propertyName);
	//end of body
}

bool ElementImpl::hasKeyword(std::string keyword)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::hasValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::has_owner(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplicable(std::shared_ptr<uml::Stereotype> stereotype)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::isStereotypeApplied(std::shared_ptr<uml::Stereotype> stereotype)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return util::StereotypeStorage::eInstance()->isStereotypeApplied(getThisElementPtr(), stereotype);
	//end of body
}

bool ElementImpl::isStereotypeRequired(std::shared_ptr<uml::Stereotype> stereotype)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::mustBeOwned()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::not_own_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImpl::removeKeyword(std::string keyword)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ElementImpl::setValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName,Any newValue)
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

std::shared_ptr<ecore::EObject> ElementImpl::unapplyStereotype(std::shared_ptr<uml::Stereotype> stereotype)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference ownedComment
*/
std::shared_ptr<Subset<uml::Comment, uml::Element>> ElementImpl::getOwnedComment() const
{
	if(m_ownedComment == nullptr)
	{
		/*Subset*/
		m_ownedComment.reset(new Subset<uml::Comment, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedComment->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedComment - Subset<uml::Comment, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_ownedComment;
}



/*
Getter & Setter for reference ownedElement
*/




/*
Getter & Setter for reference owner
*/




//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ElementImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ElementImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Element> ElementImpl::getThisElementPtr() const
{
	return m_thisElementPtr.lock();
}
void ElementImpl::setThisElementPtr(std::weak_ptr<Element> thisElementPtr)
{
	m_thisElementPtr = thisElementPtr;
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
Any ElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNEDCOMMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Comment>::iterator iter = getOwnedComment()->begin();
			Bag<uml::Comment>::iterator end = getOwnedComment()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //810			
		}
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Element>::iterator iter = getOwnedElement()->begin();
			Bag<uml::Element>::iterator end = getOwnedElement()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //811			
		}
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getOwner().lock();
				return eAny(returnValue); //812
			}
	}
	return ObjectImpl::eGet(featureID, resolve, coreType);
}
bool ElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNEDCOMMENT:
			return getOwnedComment() != nullptr; //810
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNEDELEMENT:
			return getOwnedElement() != nullptr; //811
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNER:
			return getOwner().lock() != nullptr; //812
	}
	return ObjectImpl::internalEIsSet(featureID);
}
bool ElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ELEMENT_ATTRIBUTE_OWNEDCOMMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Comment>> ownedCommentList(new Bag<uml::Comment>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedCommentList->add(std::dynamic_pointer_cast<uml::Comment>(*iter));
				iter++;
			}
			
			Bag<uml::Comment>::iterator iterOwnedComment = getOwnedComment()->begin();
			Bag<uml::Comment>::iterator endOwnedComment = getOwnedComment()->end();
			while (iterOwnedComment != endOwnedComment)
			{
				if (ownedCommentList->find(*iterOwnedComment) == -1)
				{
					getOwnedComment()->erase(*iterOwnedComment);
				}
				iterOwnedComment++;
			}
 
			iterOwnedComment = ownedCommentList->begin();
			endOwnedComment = ownedCommentList->end();
			while (iterOwnedComment != endOwnedComment)
			{
				if (getOwnedComment()->find(*iterOwnedComment) == -1)
				{
					getOwnedComment()->add(*iterOwnedComment);
				}
				iterOwnedComment++;			
			}
			return true;
		}
	}

	return ObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 8109
		case umlPackage::ELEMENT_OPERATION_ADDKEYWORD_STRING:
		{
			//Retrieve input parameter 'keyword'
			//parameter 0
			std::string incoming_param_keyword;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_keyword_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_keyword = (*incoming_param_keyword_arguments_citer)->get()->get<std::string >();
			result = eAny(this->addKeyword(incoming_param_keyword));
			break;
		}
		
		// 8141
		case umlPackage::ELEMENT_OPERATION_ALLOWNEDELEMENTS:
		{
			result = eAny(this->allOwnedElements());
			break;
		}
		
		// 8110
		case umlPackage::ELEMENT_OPERATION_APPLYSTEREOTYPE_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->applyStereotype(incoming_param_stereotype));
			break;
		}
		
		// 8144
		case umlPackage::ELEMENT_OPERATION_CONTAINER:
		{
			result = eAny(this->container());
			break;
		}
		
		// 8111
		case umlPackage::ELEMENT_OPERATION_CREATEEANNOTATION_STRING:
		{
			//Retrieve input parameter 'source'
			//parameter 0
			std::string incoming_param_source;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_source_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_source = (*incoming_param_source_arguments_citer)->get()->get<std::string >();
			result = eAny(this->createEAnnotation(incoming_param_source));
			break;
		}
		
		// 8112
		case umlPackage::ELEMENT_OPERATION_DESTROY:
		{
			this->destroy();
			break;
		}
		
		// 8114
		case umlPackage::ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPE_STRING:
		{
			//Retrieve input parameter 'qualifiedName'
			//parameter 0
			std::string incoming_param_qualifiedName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_qualifiedName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_qualifiedName = (*incoming_param_qualifiedName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getApplicableStereotype(incoming_param_qualifiedName));
			break;
		}
		
		// 8115
		case umlPackage::ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPES:
		{
			result = eAny(this->getApplicableStereotypes());
			break;
		}
		
		// 8116
		case umlPackage::ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPE_STRING:
		{
			//Retrieve input parameter 'qualifiedName'
			//parameter 0
			std::string incoming_param_qualifiedName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_qualifiedName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_qualifiedName = (*incoming_param_qualifiedName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getAppliedStereotype(incoming_param_qualifiedName));
			break;
		}
		
		// 8117
		case umlPackage::ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPES:
		{
			result = eAny(this->getAppliedStereotypes());
			break;
		}
		
		// 8118
		case umlPackage::ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPE_STEREOTYPE_STRING:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			//Retrieve input parameter 'qualifiedName'
			//parameter 1
			std::string incoming_param_qualifiedName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_qualifiedName_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_qualifiedName = (*incoming_param_qualifiedName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getAppliedSubstereotype(incoming_param_stereotype,incoming_param_qualifiedName));
			break;
		}
		
		// 8119
		case umlPackage::ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPES_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->getAppliedSubstereotypes(incoming_param_stereotype));
			break;
		}
		
		// 8113
		case umlPackage::ELEMENT_OPERATION_GETKEYWORDS:
		{
			result = eAny(this->getKeywords());
			break;
		}
		
		// 8143
		case umlPackage::ELEMENT_OPERATION_GETMETACLASS:
		{
			result = eAny(this->getMetaClass());
			break;
		}
		
		// 8120
		case umlPackage::ELEMENT_OPERATION_GETMODEL:
		{
			result = eAny(this->getModel());
			break;
		}
		
		// 8121
		case umlPackage::ELEMENT_OPERATION_GETNEARESTPACKAGE:
		{
			result = eAny(this->getNearestPackage());
			break;
		}
		
		// 8122
		case umlPackage::ELEMENT_OPERATION_GETRELATIONSHIPS:
		{
			result = eAny(this->getRelationships());
			break;
		}
		
		// 8123
		case umlPackage::ELEMENT_OPERATION_GETRELATIONSHIPS_ECLASS:
		{
			//Retrieve input parameter 'eClass'
			//parameter 0
			std::shared_ptr<ecore::EClass> incoming_param_eClass;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eClass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eClass = (*incoming_param_eClass_arguments_citer)->get()->get<std::shared_ptr<ecore::EClass> >();
			result = eAny(this->getRelationships(incoming_param_eClass));
			break;
		}
		
		// 8124
		case umlPackage::ELEMENT_OPERATION_GETREQUIREDSTEREOTYPE_STRING:
		{
			//Retrieve input parameter 'qualifiedName'
			//parameter 0
			std::string incoming_param_qualifiedName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_qualifiedName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_qualifiedName = (*incoming_param_qualifiedName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getRequiredStereotype(incoming_param_qualifiedName));
			break;
		}
		
		// 8125
		case umlPackage::ELEMENT_OPERATION_GETREQUIREDSTEREOTYPES:
		{
			result = eAny(this->getRequiredStereotypes());
			break;
		}
		
		// 8126
		case umlPackage::ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS:
		{
			result = eAny(this->getSourceDirectedRelationships());
			break;
		}
		
		// 8127
		case umlPackage::ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS_ECLASS:
		{
			//Retrieve input parameter 'eClass'
			//parameter 0
			std::shared_ptr<ecore::EClass> incoming_param_eClass;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eClass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eClass = (*incoming_param_eClass_arguments_citer)->get()->get<std::shared_ptr<ecore::EClass> >();
			result = eAny(this->getSourceDirectedRelationships(incoming_param_eClass));
			break;
		}
		
		// 8128
		case umlPackage::ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATION_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->getStereotypeApplication(incoming_param_stereotype));
			break;
		}
		
		// 8129
		case umlPackage::ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATIONS:
		{
			result = eAny(this->getStereotypeApplications());
			break;
		}
		
		// 8130
		case umlPackage::ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS:
		{
			result = eAny(this->getTargetDirectedRelationships());
			break;
		}
		
		// 8131
		case umlPackage::ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS_ECLASS:
		{
			//Retrieve input parameter 'eClass'
			//parameter 0
			std::shared_ptr<ecore::EClass> incoming_param_eClass;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eClass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eClass = (*incoming_param_eClass_arguments_citer)->get()->get<std::shared_ptr<ecore::EClass> >();
			result = eAny(this->getTargetDirectedRelationships(incoming_param_eClass));
			break;
		}
		
		// 8132
		case umlPackage::ELEMENT_OPERATION_GETVALUE_STEREOTYPE_STRING:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			//Retrieve input parameter 'propertyName'
			//parameter 1
			std::string incoming_param_propertyName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_propertyName_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_propertyName = (*incoming_param_propertyName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getValue(incoming_param_stereotype,incoming_param_propertyName));
			break;
		}
		
		// 8133
		case umlPackage::ELEMENT_OPERATION_HASKEYWORD_STRING:
		{
			//Retrieve input parameter 'keyword'
			//parameter 0
			std::string incoming_param_keyword;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_keyword_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_keyword = (*incoming_param_keyword_arguments_citer)->get()->get<std::string >();
			result = eAny(this->hasKeyword(incoming_param_keyword));
			break;
		}
		
		// 8134
		case umlPackage::ELEMENT_OPERATION_HASVALUE_STEREOTYPE_STRING:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			//Retrieve input parameter 'propertyName'
			//parameter 1
			std::string incoming_param_propertyName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_propertyName_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_propertyName = (*incoming_param_propertyName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->hasValue(incoming_param_stereotype,incoming_param_propertyName));
			break;
		}
		
		// 8107
		case umlPackage::ELEMENT_OPERATION_HAS_OWNER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_owner(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 8135
		case umlPackage::ELEMENT_OPERATION_ISSTEREOTYPEAPPLICABLE_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->isStereotypeApplicable(incoming_param_stereotype));
			break;
		}
		
		// 8136
		case umlPackage::ELEMENT_OPERATION_ISSTEREOTYPEAPPLIED_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->isStereotypeApplied(incoming_param_stereotype));
			break;
		}
		
		// 8137
		case umlPackage::ELEMENT_OPERATION_ISSTEREOTYPEREQUIRED_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->isStereotypeRequired(incoming_param_stereotype));
			break;
		}
		
		// 8142
		case umlPackage::ELEMENT_OPERATION_MUSTBEOWNED:
		{
			result = eAny(this->mustBeOwned());
			break;
		}
		
		// 8108
		case umlPackage::ELEMENT_OPERATION_NOT_OWN_SELF_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->not_own_self(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 8138
		case umlPackage::ELEMENT_OPERATION_REMOVEKEYWORD_STRING:
		{
			//Retrieve input parameter 'keyword'
			//parameter 0
			std::string incoming_param_keyword;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_keyword_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_keyword = (*incoming_param_keyword_arguments_citer)->get()->get<std::string >();
			result = eAny(this->removeKeyword(incoming_param_keyword));
			break;
		}
		
		// 8139
		case umlPackage::ELEMENT_OPERATION_SETVALUE_STEREOTYPE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			//Retrieve input parameter 'propertyName'
			//parameter 1
			std::string incoming_param_propertyName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_propertyName_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_propertyName = (*incoming_param_propertyName_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'newValue'
			//parameter 2
			Any incoming_param_newValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newValue_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_newValue = (*incoming_param_newValue_arguments_citer)->get()->get<Any >();
			this->setValue(incoming_param_stereotype,incoming_param_propertyName,incoming_param_newValue);
			break;
		}
		
		// 8140
		case umlPackage::ELEMENT_OPERATION_UNAPPLYSTEREOTYPE_STEREOTYPE:
		{
			//Retrieve input parameter 'stereotype'
			//parameter 0
			std::shared_ptr<uml::Stereotype> incoming_param_stereotype;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_stereotype_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_stereotype = (*incoming_param_stereotype_arguments_citer)->get()->get<std::shared_ptr<uml::Stereotype> >();
			result = eAny(this->unapplyStereotype(incoming_param_stereotype));
			break;
		}

		default:
		{
			// call superTypes
			result = ObjectImpl::eInvoke(operationID, arguments);
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
void ElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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
			loadHandler->handleChildContainer<uml::Comment>(this->getOwnedComment());  

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
			loadHandler->handleChildContainer<uml::Element>(this->getOwnedElement());  

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
	//load BasePackage Nodes
	ObjectImpl::loadNode(nodeName, loadHandler);
}

void ElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ObjectImpl::resolveReferences(featureID, references);
}

void ElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedComment'
		for (std::shared_ptr<uml::Comment> ownedComment : *this->getOwnedComment()) 
		{
			saveHandler->addReference(ownedComment, "ownedComment", ownedComment->eClass() != package->getComment_Class());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedElement'

		saveHandler->addReferences<uml::Element>("ownedElement", this->getOwnedElement());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


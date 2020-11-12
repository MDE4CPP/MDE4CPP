#include "uml/impl/CommentImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Element.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CommentImpl::CommentImpl()
{	
}

CommentImpl::~CommentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Comment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CommentImpl::CommentImpl(std::weak_ptr<uml::Element > par_owner)
:CommentImpl()
{
	m_owner = par_owner;
}


CommentImpl::CommentImpl(const CommentImpl & obj):CommentImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Comment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Element>> _annotatedElement = obj.getAnnotatedElement();
	m_annotatedElement.reset(new Bag<uml::Element>(*(obj.getAnnotatedElement().get())));

	m_owner  = obj.getOwner();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  CommentImpl::copy() const
{
	std::shared_ptr<CommentImpl> element(new CommentImpl(*this));
	element->setThisCommentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CommentImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getComment_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute body
*/
std::string CommentImpl::getBody() const 
{
	return m_body;
}

void CommentImpl::setBody(std::string _body)
{
	m_body = _body;
} 



//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference annotatedElement
*/
std::shared_ptr<Bag<uml::Element>> CommentImpl::getAnnotatedElement() const
{
	if(m_annotatedElement == nullptr)
	{
		m_annotatedElement.reset(new Bag<uml::Element>());
		
		
	}

    return m_annotatedElement;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> CommentImpl::getOwnedElement() const
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




std::shared_ptr<Comment> CommentImpl::getThisCommentPtr() const
{
	return m_thisCommentPtr.lock();
}
void CommentImpl::setThisCommentPtr(std::weak_ptr<Comment> thisCommentPtr)
{
	m_thisCommentPtr = thisCommentPtr;
	setThisElementPtr(thisCommentPtr);
}
std::shared_ptr<ecore::EObject> CommentImpl::eContainer() const
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
Any CommentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::COMMENT_ATTRIBUTE_ANNOTATEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Element>::iterator iter = m_annotatedElement->begin();
			Bag<uml::Element>::iterator end = m_annotatedElement->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //453
		}
		case uml::UmlPackage::COMMENT_ATTRIBUTE_BODY:
			return eAny(getBody()); //454
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool CommentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::COMMENT_ATTRIBUTE_ANNOTATEDELEMENT:
			return getAnnotatedElement() != nullptr; //453
		case uml::UmlPackage::COMMENT_ATTRIBUTE_BODY:
			return getBody() != ""; //454
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool CommentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::COMMENT_ATTRIBUTE_ANNOTATEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Element>> annotatedElementList(new Bag<uml::Element>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				annotatedElementList->add(std::dynamic_pointer_cast<uml::Element>(*iter));
				iter++;
			}
			
			Bag<uml::Element>::iterator iterAnnotatedElement = m_annotatedElement->begin();
			Bag<uml::Element>::iterator endAnnotatedElement = m_annotatedElement->end();
			while (iterAnnotatedElement != endAnnotatedElement)
			{
				if (annotatedElementList->find(*iterAnnotatedElement) == -1)
				{
					m_annotatedElement->erase(*iterAnnotatedElement);
				}
				iterAnnotatedElement++;
			}

			iterAnnotatedElement = annotatedElementList->begin();
			endAnnotatedElement = annotatedElementList->end();
			while (iterAnnotatedElement != endAnnotatedElement)
			{
				if (m_annotatedElement->find(*iterAnnotatedElement) == -1)
				{
					m_annotatedElement->add(*iterAnnotatedElement);
				}
				iterAnnotatedElement++;			
			}
			return true;
		}
		case uml::UmlPackage::COMMENT_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			std::string _body = newValue->get<std::string>();
			setBody(_body); //454
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CommentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CommentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("body");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setBody(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("annotatedElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("annotatedElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CommentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void CommentImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::COMMENT_ATTRIBUTE_ANNOTATEDELEMENT:
		{
			std::shared_ptr<Bag<uml::Element>> _annotatedElement = getAnnotatedElement();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Element> _r = std::dynamic_pointer_cast<uml::Element>(ref);
				if (_r != nullptr)
				{
					_annotatedElement->push_back(_r);
				}				
			}
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void CommentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void CommentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getComment_Attribute_body()) )
		{
			saveHandler->addAttribute("body", this->getBody());
		}

		// Add references
		std::shared_ptr<Bag<uml::Element>> annotatedElement_list = this->getAnnotatedElement();
		for (std::shared_ptr<uml::Element > object : *annotatedElement_list)
		{ 
			saveHandler->addReferences("annotatedElement", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/TemplateBindingImpl.hpp"

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

#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/TemplateParameterSubstitution.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/TemplateableElement.hpp"

//Factories an Package includes
#include "uml/impl/umlFactoryImpl.hpp"
#include "uml/impl/umlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateBindingImpl::TemplateBindingImpl()
{	
}

TemplateBindingImpl::~TemplateBindingImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateBinding "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateBindingImpl::TemplateBindingImpl(std::weak_ptr<uml::TemplateableElement > par_boundElement)
:TemplateBindingImpl()
{
	m_boundElement = par_boundElement;
	m_owner = par_boundElement;
}

//Additional constructor for the containments back reference
TemplateBindingImpl::TemplateBindingImpl(std::weak_ptr<uml::Element > par_owner)
:TemplateBindingImpl()
{
	m_owner = par_owner;
}


TemplateBindingImpl::TemplateBindingImpl(const TemplateBindingImpl & obj):TemplateBindingImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateBinding "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_boundElement  = obj.getBoundElement();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateParameterSubstitution>> _parameterSubstitutionList = obj.getParameterSubstitution();
	for(std::shared_ptr<uml::TemplateParameterSubstitution> _parameterSubstitution : *_parameterSubstitutionList)
	{
		this->getParameterSubstitution()->add(std::shared_ptr<uml::TemplateParameterSubstitution>(std::dynamic_pointer_cast<uml::TemplateParameterSubstitution>(_parameterSubstitution->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterSubstitution" << std::endl;
	#endif
	if(obj.getSignature()!=nullptr)
	{
		m_signature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_signature" << std::endl;
	#endif

	/*Subset*/
	m_parameterSubstitution->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  TemplateBindingImpl::copy() const
{
	std::shared_ptr<TemplateBindingImpl> element(new TemplateBindingImpl(*this));
	element->setThisTemplateBindingPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateBindingImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateBinding_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateBindingImpl::one_parameter_substitution(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool TemplateBindingImpl::parameter_substitution_formal(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference boundElement
*/
std::weak_ptr<uml::TemplateableElement > TemplateBindingImpl::getBoundElement() const
{
//assert(m_boundElement);
    return m_boundElement;
}

void TemplateBindingImpl::setBoundElement(std::shared_ptr<uml::TemplateableElement> _boundElement)
{
    m_boundElement = _boundElement;
}



/*
Getter & Setter for reference parameterSubstitution
*/
std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> TemplateBindingImpl::getParameterSubstitution() const
{
	if(m_parameterSubstitution == nullptr)
	{
		/*Subset*/
		m_parameterSubstitution.reset(new Subset<uml::TemplateParameterSubstitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_parameterSubstitution->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_parameterSubstitution - Subset<uml::TemplateParameterSubstitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_parameterSubstitution;
}





/*
Getter & Setter for reference signature
*/
std::shared_ptr<uml::TemplateSignature > TemplateBindingImpl::getSignature() const
{
//assert(m_signature);
    return m_signature;
}

void TemplateBindingImpl::setSignature(std::shared_ptr<uml::TemplateSignature> _signature)
{
    m_signature = _signature;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateBindingImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > TemplateBindingImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> TemplateBindingImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> TemplateBindingImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_source->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> TemplateBindingImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_target->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<TemplateBinding> TemplateBindingImpl::getThisTemplateBindingPtr() const
{
	return m_thisTemplateBindingPtr.lock();
}
void TemplateBindingImpl::setThisTemplateBindingPtr(std::weak_ptr<TemplateBinding> thisTemplateBindingPtr)
{
	m_thisTemplateBindingPtr = thisTemplateBindingPtr;
	setThisDirectedRelationshipPtr(thisTemplateBindingPtr);
}
std::shared_ptr<ecore::EObject> TemplateBindingImpl::eContainer() const
{
	if(auto wp = m_boundElement.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateBindingImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBoundElement().lock())); //2308
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::TemplateParameterSubstitution>::iterator iter = m_parameterSubstitution->begin();
			Bag<uml::TemplateParameterSubstitution>::iterator end = m_parameterSubstitution->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2306
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSignature())); //2307
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool TemplateBindingImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
			return getBoundElement().lock() != nullptr; //2308
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
			return getParameterSubstitution() != nullptr; //2306
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
			return getSignature() != nullptr; //2307
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool TemplateBindingImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateableElement> _boundElement = std::dynamic_pointer_cast<uml::TemplateableElement>(_temp);
			setBoundElement(_boundElement); //2308
			return true;
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::TemplateParameterSubstitution>> parameterSubstitutionList(new Bag<uml::TemplateParameterSubstitution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterSubstitutionList->add(std::dynamic_pointer_cast<uml::TemplateParameterSubstitution>(*iter));
				iter++;
			}
			
			Bag<uml::TemplateParameterSubstitution>::iterator iterParameterSubstitution = m_parameterSubstitution->begin();
			Bag<uml::TemplateParameterSubstitution>::iterator endParameterSubstitution = m_parameterSubstitution->end();
			while (iterParameterSubstitution != endParameterSubstitution)
			{
				if (parameterSubstitutionList->find(*iterParameterSubstitution) == -1)
				{
					m_parameterSubstitution->erase(*iterParameterSubstitution);
				}
				iterParameterSubstitution++;
			}

			iterParameterSubstitution = parameterSubstitutionList->begin();
			endParameterSubstitution = parameterSubstitutionList->end();
			while (iterParameterSubstitution != endParameterSubstitution)
			{
				if (m_parameterSubstitution->find(*iterParameterSubstitution) == -1)
				{
					m_parameterSubstitution->add(*iterParameterSubstitution);
				}
				iterParameterSubstitution++;			
			}
			return true;
		}
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>(_temp);
			setSignature(_signature); //2307
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TemplateBindingImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateBindingImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("signature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateBindingImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::umlFactory> modelFactory=uml::umlFactory::eInstance();

	try
	{
		if ( nodeName.compare("parameterSubstitution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateParameterSubstitution";
			}
			std::shared_ptr<ecore::EObject> parameterSubstitution = modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING);
			if (parameterSubstitution != nullptr)
			{
				loadHandler->handleChild(parameterSubstitution);
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
	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void TemplateBindingImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateableElement> _boundElement = std::dynamic_pointer_cast<uml::TemplateableElement>( references.front() );
				setBoundElement(_boundElement);
			}
			
			return;
		}

		case uml::umlPackage::TEMPLATEBINDING_ATTRIBUTE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateSignature> _signature = std::dynamic_pointer_cast<uml::TemplateSignature>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void TemplateBindingImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void TemplateBindingImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();

		// Save 'parameterSubstitution'
		for (std::shared_ptr<uml::TemplateParameterSubstitution> parameterSubstitution : *this->getParameterSubstitution()) 
		{
			saveHandler->addReference(parameterSubstitution, "parameterSubstitution", parameterSubstitution->eClass() != package->getTemplateParameterSubstitution_Class());
		}
	

		// Add references
		saveHandler->addReference("signature", this->getSignature());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


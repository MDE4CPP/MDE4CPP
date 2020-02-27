#include "uml/impl/GeneralizationImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/GeneralizationSet.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationImpl::GeneralizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_generalizationSet.reset(new Bag<uml::GeneralizationSet>());
	
	

	

	//Init references
	

	
	

	
}

GeneralizationImpl::~GeneralizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Generalization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Element > par_owner)
			:GeneralizationImpl()
			{
			    m_owner = par_owner;
			}


//Additional constructor for the containments back reference
			GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Classifier > par_specific)
			:GeneralizationImpl()
			{
			    m_specific = par_specific;
				m_owner = par_specific;
			}



GeneralizationImpl::GeneralizationImpl(const GeneralizationImpl & obj):GeneralizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Generalization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isSubstitutable = obj.getIsSubstitutable();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::GeneralizationSet>> _generalizationSet = obj.getGeneralizationSet();
	m_generalizationSet.reset(new Bag<uml::GeneralizationSet>(*(obj.getGeneralizationSet().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_specific  = obj.getSpecific();


	//Clone references with containment (deep copy)

	if(obj.getGeneral()!=nullptr)
	{
		m_general = std::dynamic_pointer_cast<uml::Classifier>(obj.getGeneral()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_general" << std::endl;
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

std::shared_ptr<ecore::EObject>  GeneralizationImpl::copy() const
{
	std::shared_ptr<GeneralizationImpl> element(new GeneralizationImpl(*this));
	element->setThisGeneralizationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> GeneralizationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getGeneralization_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void GeneralizationImpl::setIsSubstitutable(bool _isSubstitutable)
{
	m_isSubstitutable = _isSubstitutable;
} 

bool GeneralizationImpl::getIsSubstitutable() const 
{
	return m_isSubstitutable;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > GeneralizationImpl::getGeneral() const
{
//assert(m_general);
    return m_general;
}
void GeneralizationImpl::setGeneral(std::shared_ptr<uml::Classifier> _general)
{
    m_general = _general;
}

std::shared_ptr<Bag<uml::GeneralizationSet>> GeneralizationImpl::getGeneralizationSet() const
{

    return m_generalizationSet;
}


std::weak_ptr<uml::Classifier > GeneralizationImpl::getSpecific() const
{
//assert(m_specific);
    return m_specific;
}
void GeneralizationImpl::setSpecific(std::shared_ptr<uml::Classifier> _specific)
{
    m_specific = _specific;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> GeneralizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > GeneralizationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> GeneralizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> GeneralizationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> GeneralizationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<Generalization> GeneralizationImpl::getThisGeneralizationPtr() const
{
	return m_thisGeneralizationPtr.lock();
}
void GeneralizationImpl::setThisGeneralizationPtr(std::weak_ptr<Generalization> thisGeneralizationPtr)
{
	m_thisGeneralizationPtr = thisGeneralizationPtr;
	setThisDirectedRelationshipPtr(thisGeneralizationPtr);
}
std::shared_ptr<ecore::EObject> GeneralizationImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_specific.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any GeneralizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getGeneral())); //1106
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::GeneralizationSet>::iterator iter = m_generalizationSet->begin();
			Bag<uml::GeneralizationSet>::iterator end = m_generalizationSet->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //1107
		}
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
			return eAny(getIsSubstitutable()); //1108
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getSpecific().lock())); //1109
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool GeneralizationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
			return getGeneral() != nullptr; //1106
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
			return getGeneralizationSet() != nullptr; //1107
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
			return getIsSubstitutable() != true; //1108
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
			return getSpecific().lock() != nullptr; //1109
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool GeneralizationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _general = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setGeneral(_general); //1106
			return true;
		}
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralizationSet>> generalizationSetList(new Bag<uml::GeneralizationSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalizationSetList->add(std::dynamic_pointer_cast<uml::GeneralizationSet>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralizationSet>::iterator iterGeneralizationSet = m_generalizationSet->begin();
			Bag<uml::GeneralizationSet>::iterator endGeneralizationSet = m_generalizationSet->end();
			while (iterGeneralizationSet != endGeneralizationSet)
			{
				if (generalizationSetList->find(*iterGeneralizationSet) == -1)
				{
					m_generalizationSet->erase(*iterGeneralizationSet);
				}
				iterGeneralizationSet++;
			}

			iterGeneralizationSet = generalizationSetList->begin();
			endGeneralizationSet = generalizationSetList->end();
			while (iterGeneralizationSet != endGeneralizationSet)
			{
				if (m_generalizationSet->find(*iterGeneralizationSet) == -1)
				{
					m_generalizationSet->add(*iterGeneralizationSet);
				}
				iterGeneralizationSet++;			
			}
			return true;
		}
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE:
		{
			// BOOST CAST
			bool _isSubstitutable = newValue->get<bool>();
			setIsSubstitutable(_isSubstitutable); //1108
			return true;
		}
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _specific = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setSpecific(_specific); //1109
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void GeneralizationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GeneralizationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isSubstitutable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsSubstitutable(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("general");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("general")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("generalizationSet");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("generalizationSet")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void GeneralizationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void GeneralizationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _general = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setGeneral(_general);
			}
			
			return;
		}

		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET:
		{
			std::shared_ptr<Bag<uml::GeneralizationSet>> _generalizationSet = getGeneralizationSet();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralizationSet> _r = std::dynamic_pointer_cast<uml::GeneralizationSet>(ref);
				if (_r != nullptr)
				{
					_generalizationSet->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _specific = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setSpecific(_specific);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void GeneralizationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void GeneralizationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getGeneralization_Attribute_isSubstitutable()) )
		{
			saveHandler->addAttribute("isSubstitutable", this->getIsSubstitutable());
		}

		// Add references
		saveHandler->addReference("general", this->getGeneral());
		std::shared_ptr<Bag<uml::GeneralizationSet>> generalizationSet_list = this->getGeneralizationSet();
		for (std::shared_ptr<uml::GeneralizationSet > object : *generalizationSet_list)
		{ 
			saveHandler->addReferences("generalizationSet", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


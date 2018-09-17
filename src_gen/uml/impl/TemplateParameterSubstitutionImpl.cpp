#include "uml/impl/TemplateParameterSubstitutionImpl.hpp"

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

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

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
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl()
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

TemplateParameterSubstitutionImpl::~TemplateParameterSubstitutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameterSubstitution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateParameterSubstitutionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::TemplateBinding > par_templateBinding)
			:TemplateParameterSubstitutionImpl()
			{
			    m_templateBinding = par_templateBinding;
				m_owner = par_templateBinding;
			}






TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(const TemplateParameterSubstitutionImpl & obj):TemplateParameterSubstitutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameterSubstitution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_actual  = obj.getActual();

	m_formal  = obj.getFormal();

	m_owner  = obj.getOwner();

	m_templateBinding  = obj.getTemplateBinding();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getOwnedActual()!=nullptr)
	{
		m_ownedActual = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedActual()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedActual" << std::endl;
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

std::shared_ptr<ecore::EObject>  TemplateParameterSubstitutionImpl::copy() const
{
	std::shared_ptr<TemplateParameterSubstitutionImpl> element(new TemplateParameterSubstitutionImpl(*this));
	element->setThisTemplateParameterSubstitutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterSubstitutionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateParameterSubstitution_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterSubstitutionImpl::must_be_compatible(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ParameterableElement > TemplateParameterSubstitutionImpl::getActual() const
{
//assert(m_actual);
    return m_actual;
}
void TemplateParameterSubstitutionImpl::setActual(std::shared_ptr<uml::ParameterableElement> _actual)
{
    m_actual = _actual;
}

std::shared_ptr<uml::TemplateParameter > TemplateParameterSubstitutionImpl::getFormal() const
{
//assert(m_formal);
    return m_formal;
}
void TemplateParameterSubstitutionImpl::setFormal(std::shared_ptr<uml::TemplateParameter> _formal)
{
    m_formal = _formal;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterSubstitutionImpl::getOwnedActual() const
{

    return m_ownedActual;
}
void TemplateParameterSubstitutionImpl::setOwnedActual(std::shared_ptr<uml::ParameterableElement> _ownedActual)
{
    m_ownedActual = _ownedActual;
}

std::weak_ptr<uml::TemplateBinding > TemplateParameterSubstitutionImpl::getTemplateBinding() const
{
//assert(m_templateBinding);
    return m_templateBinding;
}
void TemplateParameterSubstitutionImpl::setTemplateBinding(std::shared_ptr<uml::TemplateBinding> _templateBinding)
{
    m_templateBinding = _templateBinding;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateParameterSubstitutionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TemplateParameterSubstitutionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TemplateParameterSubstitution> TemplateParameterSubstitutionImpl::getThisTemplateParameterSubstitutionPtr() const
{
	return m_thisTemplateParameterSubstitutionPtr.lock();
}
void TemplateParameterSubstitutionImpl::setThisTemplateParameterSubstitutionPtr(std::weak_ptr<TemplateParameterSubstitution> thisTemplateParameterSubstitutionPtr)
{
	m_thisTemplateParameterSubstitutionPtr = thisTemplateParameterSubstitutionPtr;
	setThisElementPtr(thisTemplateParameterSubstitutionPtr);
}
std::shared_ptr<ecore::EObject> TemplateParameterSubstitutionImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_templateBinding.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any TemplateParameterSubstitutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_ACTUAL:
			return eAny(getActual()); //224
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_FORMAL:
			return eAny(getFormal()); //225
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_OWNEDACTUAL:
			return eAny(getOwnedActual()); //226
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_TEMPLATEBINDING:
			return eAny(getTemplateBinding()); //227
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool TemplateParameterSubstitutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_ACTUAL:
			return getActual() != nullptr; //224
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_FORMAL:
			return getFormal() != nullptr; //225
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_OWNEDACTUAL:
			return getOwnedActual() != nullptr; //226
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding().lock() != nullptr; //227
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool TemplateParameterSubstitutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_ACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _actual = newValue->get<std::shared_ptr<uml::ParameterableElement>>();
			setActual(_actual); //224
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_FORMAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _formal = newValue->get<std::shared_ptr<uml::TemplateParameter>>();
			setFormal(_formal); //225
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_OWNEDACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedActual = newValue->get<std::shared_ptr<uml::ParameterableElement>>();
			setOwnedActual(_ownedActual); //226
			return true;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_TEMPLATEBINDING:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateBinding> _templateBinding = newValue->get<std::shared_ptr<uml::TemplateBinding>>();
			setTemplateBinding(_templateBinding); //227
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TemplateParameterSubstitutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateParameterSubstitutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("actual");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("actual")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("formal");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("formal")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void TemplateParameterSubstitutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("ownedActual") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ParameterableElement> ownedActual = std::dynamic_pointer_cast<uml::ParameterableElement>(modelFactory->create(typeName));
			if (ownedActual != nullptr)
			{
				this->setOwnedActual(ownedActual);
				loadHandler->handleChild(ownedActual);
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

void TemplateParameterSubstitutionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_ACTUAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ParameterableElement> _actual = std::dynamic_pointer_cast<uml::ParameterableElement>( references.front() );
				setActual(_actual);
			}
			
			return;
		}

		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_FORMAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateParameter> _formal = std::dynamic_pointer_cast<uml::TemplateParameter>( references.front() );
				setFormal(_formal);
			}
			
			return;
		}

		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_TEMPLATEBINDING:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateBinding> _templateBinding = std::dynamic_pointer_cast<uml::TemplateBinding>( references.front() );
				setTemplateBinding(_templateBinding);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateParameterSubstitutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void TemplateParameterSubstitutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'ownedActual'
		std::shared_ptr<uml::ParameterableElement > ownedActual = this->getOwnedActual();
		if (ownedActual != nullptr)
		{
			saveHandler->addReference(ownedActual, "ownedActual", ownedActual->eClass() != package->getParameterableElement_EClass());
		}
	

		// Add references
		saveHandler->addReference("actual", this->getActual());
		saveHandler->addReference("formal", this->getFormal());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


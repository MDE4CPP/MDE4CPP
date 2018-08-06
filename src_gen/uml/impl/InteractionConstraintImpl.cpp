#include "uml/impl/InteractionConstraintImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

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
InteractionConstraintImpl::InteractionConstraintImpl()
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

InteractionConstraintImpl::~InteractionConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:InteractionConstraintImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
					m_context = par_Namespace;
					m_namespace = par_Namespace;
					 return;
				case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
					m_namespace = par_Namespace;
					m_owner = par_Namespace;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:InteractionConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:InteractionConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:InteractionConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






InteractionConstraintImpl::InteractionConstraintImpl(const InteractionConstraintImpl & obj):InteractionConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Bag<uml::Element>> _constrainedElement = obj.getConstrainedElement();
	m_constrainedElement.reset(new Bag<uml::Element>(*(obj.getConstrainedElement().get())));

	m_context  = obj.getContext();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getMaxint()!=nullptr)
	{
		m_maxint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMaxint()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_maxint" << std::endl;
	#endif
	if(obj.getMinint()!=nullptr)
	{
		m_minint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMinint()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_minint" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specification" << std::endl;
	#endif

	

	
}

std::shared_ptr<ecore::EObject>  InteractionConstraintImpl::copy() const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(*this));
	element->setThisInteractionConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInteractionConstraint_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionConstraintImpl::dynamic_variables(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::global_data(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_greater_equal_minint(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_positive(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_maxint(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_non_negative(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMaxint() const
{

    return m_maxint;
}
void InteractionConstraintImpl::setMaxint(std::shared_ptr<uml::ValueSpecification> _maxint)
{
    m_maxint = _maxint;
}

std::shared_ptr<uml::ValueSpecification > InteractionConstraintImpl::getMinint() const
{

    return m_minint;
}
void InteractionConstraintImpl::setMinint(std::shared_ptr<uml::ValueSpecification> _minint)
{
    m_minint = _minint;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > InteractionConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> InteractionConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > InteractionConstraintImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<InteractionConstraint> InteractionConstraintImpl::getThisInteractionConstraintPtr() const
{
	return m_thisInteractionConstraintPtr.lock();
}
void InteractionConstraintImpl::setThisInteractionConstraintPtr(std::weak_ptr<InteractionConstraint> thisInteractionConstraintPtr)
{
	m_thisInteractionConstraintPtr = thisInteractionConstraintPtr;
	setThisConstraintPtr(thisInteractionConstraintPtr);
}
std::shared_ptr<ecore::EObject> InteractionConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
	{
		return wp;
	}
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}


	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InteractionConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MAXINT:
			return eAny(getMaxint()); //21916
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MININT:
			return eAny(getMinint()); //21917
	}
	return ConstraintImpl::eGet(featureID, resolve, coreType);
}
bool InteractionConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MAXINT:
			return getMaxint() != nullptr; //21916
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MININT:
			return getMinint() != nullptr; //21917
	}
	return ConstraintImpl::internalEIsSet(featureID);
}
bool InteractionConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MAXINT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _maxint = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setMaxint(_maxint); //21916
			return true;
		}
		case UmlPackage::INTERACTIONCONSTRAINT_EREFERENCE_MININT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _minint = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setMinint(_minint); //21917
			return true;
		}
	}

	return ConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InteractionConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("maxint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> maxint = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (maxint != nullptr)
			{
				this->setMaxint(maxint);
				loadHandler->handleChild(maxint);
			}
			return;
		}

		if ( nodeName.compare("minint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> minint = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (minint != nullptr)
			{
				this->setMinint(minint);
				loadHandler->handleChild(minint);
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

	ConstraintImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void InteractionConstraintImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ConstraintImpl::resolveReferences(featureID, references);
}

void InteractionConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void InteractionConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'maxint'
		std::shared_ptr<uml::ValueSpecification > maxint = this->getMaxint();
		if (maxint != nullptr)
		{
			saveHandler->addReference(maxint, "maxint", maxint->eClass() != package->getValueSpecification_EClass());
		}

		// Save 'minint'
		std::shared_ptr<uml::ValueSpecification > minint = this->getMinint();
		if (minint != nullptr)
		{
			saveHandler->addReference(minint, "minint", minint->eClass() != package->getValueSpecification_EClass());
		}
	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


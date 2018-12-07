#include "uml/impl/DurationConstraintImpl.hpp"

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

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/IntervalConstraint.hpp"

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
DurationConstraintImpl::DurationConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_firstEvent.reset(new Bag<bool>());
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

DurationConstraintImpl::~DurationConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DurationConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:DurationConstraintImpl()
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
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:DurationConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:DurationConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			DurationConstraintImpl::DurationConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:DurationConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






DurationConstraintImpl::DurationConstraintImpl(const DurationConstraintImpl & obj):DurationConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DurationConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_firstEvent = obj.getFirstEvent();
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

std::shared_ptr<ecore::EObject>  DurationConstraintImpl::copy() const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(*this));
	element->setThisDurationConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DurationConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDurationConstraint_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************


std::shared_ptr<Bag<bool> > DurationConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool DurationConstraintImpl::first_event_multiplicity(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool DurationConstraintImpl::has_one_or_two_constrainedElements(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > DurationConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> DurationConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DurationConstraintImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<DurationConstraint> DurationConstraintImpl::getThisDurationConstraintPtr() const
{
	return m_thisDurationConstraintPtr.lock();
}
void DurationConstraintImpl::setThisDurationConstraintPtr(std::weak_ptr<DurationConstraint> thisDurationConstraintPtr)
{
	m_thisDurationConstraintPtr = thisDurationConstraintPtr;
	setThisIntervalConstraintPtr(thisDurationConstraintPtr);
}
std::shared_ptr<ecore::EObject> DurationConstraintImpl::eContainer() const
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
Any DurationConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::DURATIONCONSTRAINT_EATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //7816
	}
	return IntervalConstraintImpl::eGet(featureID, resolve, coreType);
}
bool DurationConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::DURATIONCONSTRAINT_EATTRIBUTE_FIRSTEVENT:
			return !getFirstEvent()->empty(); //7816
	}
	return IntervalConstraintImpl::internalEIsSet(featureID);
}
bool DurationConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return IntervalConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void DurationConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DurationConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	IntervalConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void DurationConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{
	try
	{
		if (nodeName.compare("firstEvent") == 0)
		{
			std::cout << "| ERROR    | unhandled attribute with upperbound <> 1" << std::endl;
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


	IntervalConstraintImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void DurationConstraintImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	IntervalConstraintImpl::resolveReferences(featureID, references);
}

void DurationConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	IntervalConstraintImpl::saveContent(saveHandler);
	
	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void DurationConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getDurationConstraint_EAttribute_firstEvent()) )
		{
			for (std::shared_ptr<bool> value : *m_firstEvent)
			{
				saveHandler->addAttributeAsNode("firstEvent", std::to_string(*value));
			}
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


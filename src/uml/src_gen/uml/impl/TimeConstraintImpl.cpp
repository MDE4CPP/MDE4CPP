#include "uml/impl/TimeConstraintImpl.hpp"

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
TimeConstraintImpl::TimeConstraintImpl()
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

TimeConstraintImpl::~TimeConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:TimeConstraintImpl()
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
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeConstraintImpl::TimeConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






TimeConstraintImpl::TimeConstraintImpl(const TimeConstraintImpl & obj):TimeConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  TimeConstraintImpl::copy() const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(*this));
	element->setThisTimeConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeConstraint_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void TimeConstraintImpl::setFirstEvent(bool _firstEvent)
{
	m_firstEvent = _firstEvent;
} 

bool TimeConstraintImpl::getFirstEvent() const 
{
	return m_firstEvent;
}

//*********************************
// Operations
//*********************************
bool TimeConstraintImpl::has_one_constrainedElement(Any diagnostics,std::map <   Any, Any >  context)
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
std::weak_ptr<uml::Namespace > TimeConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> TimeConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeConstraintImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TimeConstraint> TimeConstraintImpl::getThisTimeConstraintPtr() const
{
	return m_thisTimeConstraintPtr.lock();
}
void TimeConstraintImpl::setThisTimeConstraintPtr(std::weak_ptr<TimeConstraint> thisTimeConstraintPtr)
{
	m_thisTimeConstraintPtr = thisTimeConstraintPtr;
	setThisIntervalConstraintPtr(thisTimeConstraintPtr);
}
std::shared_ptr<ecore::EObject> TimeConstraintImpl::eContainer() const
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
Any TimeConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TIMECONSTRAINT_EATTRIBUTE_FIRSTEVENT:
			return eAny(getFirstEvent()); //25516
	}
	return IntervalConstraintImpl::eGet(featureID, resolve, coreType);
}
bool TimeConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TIMECONSTRAINT_EATTRIBUTE_FIRSTEVENT:
			return getFirstEvent() != true; //25516
	}
	return IntervalConstraintImpl::internalEIsSet(featureID);
}
bool TimeConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TIMECONSTRAINT_EATTRIBUTE_FIRSTEVENT:
		{
			// BOOST CAST
			bool _firstEvent = newValue->get<bool>();
			setFirstEvent(_firstEvent); //25516
			return true;
		}
	}

	return IntervalConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TimeConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("firstEvent");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setFirstEvent(value);
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

	IntervalConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void TimeConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	IntervalConstraintImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void TimeConstraintImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	IntervalConstraintImpl::resolveReferences(featureID, references);
}

void TimeConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void TimeConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getTimeConstraint_EAttribute_firstEvent()) )
		{
			saveHandler->addAttribute("firstEvent", this->getFirstEvent());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


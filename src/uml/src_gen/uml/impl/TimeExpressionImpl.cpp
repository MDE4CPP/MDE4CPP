#include "uml/impl/TimeExpressionImpl.hpp"

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

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Observation.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

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
TimeExpressionImpl::TimeExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_observation.reset(new Bag<uml::Observation>());
	
	

	//Init references
	

	
	
}

TimeExpressionImpl::~TimeExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeExpressionImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeExpressionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:TimeExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
				m_owner = par_owningSlot;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






TimeExpressionImpl::TimeExpressionImpl(const TimeExpressionImpl & obj):TimeExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::Observation>> _observation = obj.getObservation();
	m_observation.reset(new Bag<uml::Observation>(*(obj.getObservation().get())));

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	if(obj.getExpr()!=nullptr)
	{
		m_expr = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getExpr()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_expr" << std::endl;
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

	
}

std::shared_ptr<ecore::EObject>  TimeExpressionImpl::copy() const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(*this));
	element->setThisTimeExpressionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> TimeExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeExpression_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TimeExpressionImpl::no_expr_requires_observation(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > TimeExpressionImpl::getExpr() const
{

    return m_expr;
}
void TimeExpressionImpl::setExpr(std::shared_ptr<uml::ValueSpecification> _expr)
{
    m_expr = _expr;
}

std::shared_ptr<Bag<uml::Observation>> TimeExpressionImpl::getObservation() const
{

    return m_observation;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> TimeExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeExpressionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<TimeExpression> TimeExpressionImpl::getThisTimeExpressionPtr() const
{
	return m_thisTimeExpressionPtr.lock();
}
void TimeExpressionImpl::setThisTimeExpressionPtr(std::weak_ptr<TimeExpression> thisTimeExpressionPtr)
{
	m_thisTimeExpressionPtr = thisTimeExpressionPtr;
	setThisValueSpecificationPtr(thisTimeExpressionPtr);
}
std::shared_ptr<ecore::EObject> TimeExpressionImpl::eContainer() const
{
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

	if(auto wp = m_owningSlot.lock())
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
Any TimeExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_EXPR:
			return eAny(getExpr()); //23814
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_OBSERVATION:
			return eAny(getObservation()); //23815
	}
	return ValueSpecificationImpl::eGet(featureID, resolve, coreType);
}
bool TimeExpressionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_EXPR:
			return getExpr() != nullptr; //23814
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_OBSERVATION:
			return getObservation() != nullptr; //23815
	}
	return ValueSpecificationImpl::internalEIsSet(featureID);
}
bool TimeExpressionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_EXPR:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _expr = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setExpr(_expr); //23814
			return true;
		}
	}

	return ValueSpecificationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void TimeExpressionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TimeExpressionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("observation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("observation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ValueSpecificationImpl::loadAttributes(loadHandler, attr_list);
}

void TimeExpressionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("expr") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			std::shared_ptr<uml::ValueSpecification> expr = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (expr != nullptr)
			{
				this->setExpr(expr);
				loadHandler->handleChild(expr);
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

	ValueSpecificationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void TimeExpressionImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::TIMEEXPRESSION_ATTRIBUTE_OBSERVATION:
		{
			std::shared_ptr<Bag<uml::Observation>> _observation = getObservation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Observation> _r = std::dynamic_pointer_cast<uml::Observation>(ref);
				if (_r != nullptr)
				{
					_observation->push_back(_r);
				}				
			}
			return;
		}
	}
	ValueSpecificationImpl::resolveReferences(featureID, references);
}

void TimeExpressionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ValueSpecificationImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void TimeExpressionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'expr'
		std::shared_ptr<uml::ValueSpecification > expr = this->getExpr();
		if (expr != nullptr)
		{
			saveHandler->addReference(expr, "expr", expr->eClass() != package->getValueSpecification_Class());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Observation>> observation_list = this->getObservation();
		for (std::shared_ptr<uml::Observation > object : *observation_list)
		{ 
			saveHandler->addReferences("observation", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


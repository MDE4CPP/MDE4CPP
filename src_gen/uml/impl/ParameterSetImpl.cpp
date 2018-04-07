#include "uml/impl/ParameterSetImpl.hpp"

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
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
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

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Parameter.hpp"

#include "uml/StringExpression.hpp"

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
ParameterSetImpl::ParameterSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
	
	

		m_parameter.reset(new Bag<uml::Parameter>());
	
	

	//Init references
		/*Subset*/
		m_condition->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	
}

ParameterSetImpl::~ParameterSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ParameterSetImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Element > par_owner)
			:ParameterSetImpl()
			{
			    m_owner = par_owner;
			}






ParameterSetImpl::ParameterSetImpl(const ParameterSetImpl & obj):ParameterSetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Bag<uml::Parameter>> _parameter = obj.getParameter();
	m_parameter.reset(new Bag<uml::Parameter>(*(obj.getParameter().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Constraint>> _conditionList = obj.getCondition();
	for(std::shared_ptr<uml::Constraint> _condition : *_conditionList)
	{
		this->getCondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_condition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_condition" << std::endl;
	#endif
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

		/*Subset*/
		m_condition->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ParameterSetImpl::copy() const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl(*this));
	element->setThisParameterSetPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ParameterSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameterSet_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterSetImpl::input(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::same_parameterized_entity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::two_parameter_sets(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Constraint, uml::Element>> ParameterSetImpl::getCondition() const
{

    return m_condition;
}


std::shared_ptr<Bag<uml::Parameter>> ParameterSetImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ParameterSetImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ParameterSetImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ParameterSet> ParameterSetImpl::getThisParameterSetPtr()
{
	return m_thisParameterSetPtr.lock();
}
void ParameterSetImpl::setThisParameterSetPtr(std::weak_ptr<ParameterSet> thisParameterSetPtr)
{
	m_thisParameterSetPtr = thisParameterSetPtr;
	setThisNamedElementPtr(thisParameterSetPtr);
}
std::shared_ptr<ecore::EObject> ParameterSetImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
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
boost::any ParameterSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PARAMETERSET_EREFERENCE_CONDITION:
			return getCondition(); //5210
		case UmlPackage::PARAMETERSET_EREFERENCE_PARAMETER:
			return getParameter(); //5211
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool ParameterSetImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PARAMETERSET_EREFERENCE_CONDITION:
			return getCondition() != nullptr; //5210
		case UmlPackage::PARAMETERSET_EREFERENCE_PARAMETER:
			return getParameter() != nullptr; //5211
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool ParameterSetImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ParameterSetImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterSetImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterSetImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("condition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			std::shared_ptr<uml::Constraint> condition = std::dynamic_pointer_cast<uml::Constraint>(modelFactory->create(typeName));
			if (condition != nullptr)
			{
				std::shared_ptr<Subset<uml::Constraint, uml::Element>> list_condition = this->getCondition();
				list_condition->push_back(condition);
				loadHandler->handleChild(condition);
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ParameterSetImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PARAMETERSET_EREFERENCE_PARAMETER:
		{
			std::shared_ptr<Bag<uml::Parameter>> _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Parameter> _r = std::dynamic_pointer_cast<uml::Parameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}				
			}
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void ParameterSetImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ParameterSetImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'condition'
		for (std::shared_ptr<uml::Constraint> condition : *this->getCondition()) 
		{
			saveHandler->addReference(condition, "condition", condition->eClass() != package->getConstraint_EClass());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Parameter>> parameter_list = this->getParameter();
		for (std::shared_ptr<uml::Parameter > object : *parameter_list)
		{ 
			saveHandler->addReferences("parameter", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


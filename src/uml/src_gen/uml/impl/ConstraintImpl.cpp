#include "uml/impl/ConstraintImpl.hpp"

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
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConstraintImpl::ConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConstraintImpl::~ConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Constraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:ConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:ConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ConstraintImpl::ConstraintImpl(const ConstraintImpl & obj): ConstraintImpl()
{
	*this = obj;
}

ConstraintImpl& ConstraintImpl::operator=(const ConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	Constraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Constraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Element>> _constrainedElement = obj.getConstrainedElement();
	m_constrainedElement.reset(new Bag<uml::Element>(*(obj.getConstrainedElement().get())));
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ConstraintImpl::copy() const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl());
	*element =(*this);
	element->setThisConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConstraint_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ConstraintImpl::boolean_value(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::no_side_effects(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::not_apply_to_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference constrainedElement
*/
std::shared_ptr<Bag<uml::Element>> ConstraintImpl::getConstrainedElement() const
{
	if(m_constrainedElement == nullptr)
	{
		m_constrainedElement.reset(new Bag<uml::Element>());
		
		
	}

    return m_constrainedElement;
}



/*
Getter & Setter for reference context
*/
std::weak_ptr<uml::Namespace> ConstraintImpl::getContext() const
{

    return m_context;
}
void ConstraintImpl::setContext(std::weak_ptr<uml::Namespace> _context)
{
    m_context = _context;
}


/*
Getter & Setter for reference specification
*/
std::shared_ptr<uml::ValueSpecification> ConstraintImpl::getSpecification() const
{
//assert(m_specification);
    return m_specification;
}
void ConstraintImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ConstraintImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConstraintImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConstraintImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Constraint> ConstraintImpl::getThisConstraintPtr() const
{
	return m_thisConstraintPtr.lock();
}
void ConstraintImpl::setThisConstraintPtr(std::weak_ptr<Constraint> thisConstraintPtr)
{
	m_thisConstraintPtr = thisConstraintPtr;
	setThisPackageableElementPtr(thisConstraintPtr);
}
std::shared_ptr<ecore::EObject> ConstraintImpl::eContainer() const
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
Any ConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Element>::iterator iter = m_constrainedElement->begin();
			Bag<uml::Element>::iterator end = m_constrainedElement->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5712			
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
			return eAny(getContext().lock()); //5713
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification()); //5714
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool ConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
			return getConstrainedElement() != nullptr; //5712
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
			return getContext().lock() != nullptr; //5713
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //5714
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool ConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Element>> constrainedElementList(new Bag<uml::Element>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				constrainedElementList->add(std::dynamic_pointer_cast<uml::Element>(*iter));
				iter++;
			}
			
			Bag<uml::Element>::iterator iterConstrainedElement = m_constrainedElement->begin();
			Bag<uml::Element>::iterator endConstrainedElement = m_constrainedElement->end();
			while (iterConstrainedElement != endConstrainedElement)
			{
				if (constrainedElementList->find(*iterConstrainedElement) == -1)
				{
					m_constrainedElement->erase(*iterConstrainedElement);
				}
				iterConstrainedElement++;
			}
 
			iterConstrainedElement = constrainedElementList->begin();
			endConstrainedElement = constrainedElementList->end();
			while (iterConstrainedElement != endConstrainedElement)
			{
				if (m_constrainedElement->find(*iterConstrainedElement) == -1)
				{
					m_constrainedElement->add(*iterConstrainedElement);
				}
				iterConstrainedElement++;			
			}
			return true;
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Namespace> _context = std::dynamic_pointer_cast<uml::Namespace>(_temp);
			setContext(_context); //5713
			return true;
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSpecification(_specification); //5714
			return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ConstraintImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5774
		case umlPackage::CONSTRAINT_OPERATION_BOOLEAN_VALUE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->boolean_value(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5775
		case umlPackage::CONSTRAINT_OPERATION_NO_SIDE_EFFECTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_side_effects(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5776
		case umlPackage::CONSTRAINT_OPERATION_NOT_APPLY_TO_SELF_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->not_apply_to_self(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
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
void ConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("constrainedElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("constrainedElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void ConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("specification") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getSpecification()); 

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
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void ConstraintImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
		{
			std::shared_ptr<Bag<uml::Element>> _constrainedElement = getConstrainedElement();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Element>  _r = std::dynamic_pointer_cast<uml::Element>(ref);
				if (_r != nullptr)
				{
					_constrainedElement->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Namespace> _context = std::dynamic_pointer_cast<uml::Namespace>( references.front() );
				setContext(_context);
			}
			
			return;
		}
	}
	PackageableElementImpl::resolveReferences(featureID, references);
}

void ConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'specification'
		std::shared_ptr<uml::ValueSpecification> specification = this->getSpecification();
		if (specification != nullptr)
		{
			saveHandler->addReference(specification, "specification", specification->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Element>("constrainedElement", this->getConstrainedElement());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


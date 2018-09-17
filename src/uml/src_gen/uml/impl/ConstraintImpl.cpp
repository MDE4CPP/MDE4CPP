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

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/PackageableElement.hpp"

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
ConstraintImpl::ConstraintImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_constrainedElement.reset(new Bag<uml::Element>());
	
	

	

	

	//Init references
	
	

	

	
}

ConstraintImpl::~ConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Constraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id)
			:ConstraintImpl()
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
			ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Element > par_owner)
			:ConstraintImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:ConstraintImpl()
			{
			    m_owningPackage = par_owningPackage;
				m_namespace = par_owningPackage;
			}





//Additional constructor for the containments back reference
			ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ConstraintImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






ConstraintImpl::ConstraintImpl(const ConstraintImpl & obj):ConstraintImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Constraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

std::shared_ptr<ecore::EObject>  ConstraintImpl::copy() const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(*this));
	element->setThisConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConstraintImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConstraint_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ConstraintImpl::boolean_value(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::no_side_effects(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConstraintImpl::not_apply_to_self(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Element>> ConstraintImpl::getConstrainedElement() const
{

    return m_constrainedElement;
}


std::weak_ptr<uml::Namespace > ConstraintImpl::getContext() const
{

    return m_context;
}
void ConstraintImpl::setContext(std::shared_ptr<uml::Namespace> _context)
{
    m_context = _context;
}

std::shared_ptr<uml::ValueSpecification > ConstraintImpl::getSpecification() const
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
std::weak_ptr<uml::Namespace > ConstraintImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> ConstraintImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ConstraintImpl::getOwner() const
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
		case UmlPackage::CONSTRAINT_EREFERENCE_CONSTRAINEDELEMENT:
			return eAny(getConstrainedElement()); //5313
		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
			return eAny(getContext()); //5314
		case UmlPackage::CONSTRAINT_EREFERENCE_SPECIFICATION:
			return eAny(getSpecification()); //5315
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}
bool ConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CONSTRAINT_EREFERENCE_CONSTRAINEDELEMENT:
			return getConstrainedElement() != nullptr; //5313
		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
			return getContext().lock() != nullptr; //5314
		case UmlPackage::CONSTRAINT_EREFERENCE_SPECIFICATION:
			return getSpecification() != nullptr; //5315
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}
bool ConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Namespace> _context = newValue->get<std::shared_ptr<uml::Namespace>>();
			setContext(_context); //5314
			return true;
		}
		case UmlPackage::CONSTRAINT_EREFERENCE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _specification = newValue->get<std::shared_ptr<uml::ValueSpecification>>();
			setSpecification(_specification); //5315
			return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			std::shared_ptr<uml::ValueSpecification> specification = std::dynamic_pointer_cast<uml::ValueSpecification>(modelFactory->create(typeName));
			if (specification != nullptr)
			{
				this->setSpecification(specification);
				loadHandler->handleChild(specification);
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

	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ConstraintImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CONSTRAINT_EREFERENCE_CONSTRAINEDELEMENT:
		{
			std::shared_ptr<Bag<uml::Element>> _constrainedElement = getConstrainedElement();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Element> _r = std::dynamic_pointer_cast<uml::Element>(ref);
				if (_r != nullptr)
				{
					_constrainedElement->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::CONSTRAINT_EREFERENCE_CONTEXT:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'specification'
		std::shared_ptr<uml::ValueSpecification > specification = this->getSpecification();
		if (specification != nullptr)
		{
			saveHandler->addReference(specification, "specification", specification->eClass() != package->getValueSpecification_EClass());
		}
	

		// Add references
		std::shared_ptr<Bag<uml::Element>> constrainedElement_list = this->getConstrainedElement();
		for (std::shared_ptr<uml::Element > object : *constrainedElement_list)
		{ 
			saveHandler->addReferences("constrainedElement", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


#include "uml/impl/OperationImpl.hpp"

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

#include "uml/Behavior.hpp"

#include "uml/BehavioralFeature.hpp"

#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/DataType.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Interface.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Operation.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Parameter.hpp"

#include "uml/ParameterSet.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/TemplateableElement.hpp"

#include "uml/Type.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationImpl::OperationImpl()
{	
}

OperationImpl::~OperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Operation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Class > par_class)
:OperationImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::DataType > par_datatype)
:OperationImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Interface > par_interface)
:OperationImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Namespace > par_namespace)
:OperationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Element > par_owner)
:OperationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
:OperationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


OperationImpl::OperationImpl(const OperationImpl & obj):OperationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Operation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isQuery = obj.getIsQuery();
	m_isStatic = obj.getIsStatic();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_class  = obj.getClass();

	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_datatype  = obj.getDatatype();

	std::shared_ptr<Union<uml::Classifier>> _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_interface  = obj.getInterface();

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr<Bag<uml::Behavior>> _method = obj.getMethod();
	m_method.reset(new Bag<uml::Behavior>(*(obj.getMethod().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr<Bag<uml::Type>> _raisedException = obj.getRaisedException();
	m_raisedException.reset(new Bag<uml::Type>(*(obj.getRaisedException().get())));

	std::shared_ptr<Union<uml::RedefinableElement>> _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier>> _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	if(obj.getBodyCondition()!=nullptr)
	{
		m_bodyCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getBodyCondition()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_bodyCondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
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
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(std::dynamic_pointer_cast<uml::Parameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(std::dynamic_pointer_cast<uml::ParameterSet>(_ownedParameterSet->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameterSet" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _postconditionList = obj.getPostcondition();
	for(std::shared_ptr<uml::Constraint> _postcondition : *_postconditionList)
	{
		this->getPostcondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_postcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_postcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _preconditionList = obj.getPrecondition();
	for(std::shared_ptr<uml::Constraint> _precondition : *_preconditionList)
	{
		this->getPrecondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_precondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_precondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Operation>> _redefinedOperationList = obj.getRedefinedOperation();
	for(std::shared_ptr<uml::Operation> _redefinedOperation : *_redefinedOperationList)
	{
		this->getRedefinedOperation()->add(std::shared_ptr<uml::Operation>(std::dynamic_pointer_cast<uml::Operation>(_redefinedOperation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedOperation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  OperationImpl::copy() const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(*this));
	element->setThisOperationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OperationImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getOperation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isOrdered
*/
bool OperationImpl::getIsOrdered() const 
{
	return m_isOrdered;
}





/*
Getter & Setter for attribute isQuery
*/
bool OperationImpl::getIsQuery() const 
{
	return m_isQuery;
}

void OperationImpl::setIsQuery(bool _isQuery)
{
	m_isQuery = _isQuery;
} 



/*
Getter & Setter for attribute isUnique
*/
bool OperationImpl::getIsUnique() const 
{
	return m_isUnique;
}





/*
Getter & Setter for attribute lower
*/
int OperationImpl::getLower() const 
{
	return m_lower;
}





/*
Getter & Setter for attribute upper
*/
int OperationImpl::getUpper() const 
{
	return m_upper;
}





//*********************************
// Operations
//*********************************
bool OperationImpl::at_most_one_return(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OperationImpl::getLower()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> OperationImpl::getReturnResult()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->returnResult();
	//end of body
}



int OperationImpl::getUpper()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isOrdered()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isUnique()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::matches(std::shared_ptr<uml::Operation>  comparedOperation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//Checks whether two uml::Operations share the same name and input parameter types (= share same signature)

bool equals = false;

if(this->getName() != comparedOperation->getName()) {return equals;}

std::shared_ptr<Bag<uml::Parameter>> thisParameters = this->getOwnedParameter();
std::shared_ptr<Bag<uml::Parameter>> otherParameters = comparedOperation->getOwnedParameter();

if(thisParameters->size() != otherParameters->size()) {return equals;}

for(unsigned int i = 0; i < thisParameters->size(); i++)
{
	if(thisParameters->at(i)->getType() != otherParameters->at(i)->getType()) {return equals;}
}

equals = true;
return equals;

	//end of body
}

bool OperationImpl::only_body_for_query(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > OperationImpl::returnResult()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Parameter>> ownedParameters = this->getOwnedParameter();
	std::shared_ptr<Bag<uml::Parameter>> returnResult(new Bag<uml::Parameter>);

	for(std::shared_ptr<uml::Parameter> p : *ownedParameters)
	{
		if(p->getDirection() == uml::ParameterDirectionKind::RETURN)
		{
				returnResult->add(p);
				break;
		}
	}
	
	return returnResult;
	//end of body
}

void OperationImpl::setIsOrdered(bool newIsOrdered)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_isOrdered = newIsOrdered;
	//end of body
}

void OperationImpl::setIsUnique(bool newIsUnique)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_isUnique = newIsUnique;
	//end of body
}

void OperationImpl::setLower(int newLower)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_lower = newLower;
	//end of body
}

void OperationImpl::setType(std::shared_ptr<uml::Type>  newType)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_type = newType;
	//end of body
}

void OperationImpl::setUpper(int newUpper)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_upper = newUpper;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference bodyCondition
*/
std::shared_ptr<uml::Constraint > OperationImpl::getBodyCondition() const
{

    return m_bodyCondition;
}

void OperationImpl::setBodyCondition(std::shared_ptr<uml::Constraint> _bodyCondition)
{
    m_bodyCondition = _bodyCondition;
}



/*
Getter & Setter for reference class
*/
std::weak_ptr<uml::Class > OperationImpl::getClass() const
{

    return m_class;
}

void OperationImpl::setClass(std::shared_ptr<uml::Class> _class)
{
    m_class = _class;
}



/*
Getter & Setter for reference datatype
*/
std::weak_ptr<uml::DataType > OperationImpl::getDatatype() const
{

    return m_datatype;
}

void OperationImpl::setDatatype(std::shared_ptr<uml::DataType> _datatype)
{
    m_datatype = _datatype;
}



/*
Getter & Setter for reference interface
*/
std::weak_ptr<uml::Interface > OperationImpl::getInterface() const
{

    return m_interface;
}

void OperationImpl::setInterface(std::shared_ptr<uml::Interface> _interface)
{
    m_interface = _interface;
}



/*
Getter & Setter for reference postcondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> OperationImpl::getPostcondition() const
{
	if(m_postcondition == nullptr)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_postcondition->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}

    return m_postcondition;
}





/*
Getter & Setter for reference precondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> OperationImpl::getPrecondition() const
{
	if(m_precondition == nullptr)
	{
		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_precondition->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}

    return m_precondition;
}





/*
Getter & Setter for reference redefinedOperation
*/
std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> OperationImpl::getRedefinedOperation() const
{
	if(m_redefinedOperation == nullptr)
	{
		/*Subset*/
		m_redefinedOperation.reset(new Subset<uml::Operation, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_redefinedOperation->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedOperation;
}





/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::Type > OperationImpl::getType() const
{

    return m_type;
}





//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> OperationImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

std::shared_ptr<Union<uml::NamedElement>> OperationImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace > OperationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OperationImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> OperationImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element > OperationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OperationImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}

std::shared_ptr<Union<uml::Classifier>> OperationImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}




std::shared_ptr<Operation> OperationImpl::getThisOperationPtr() const
{
	return m_thisOperationPtr.lock();
}
void OperationImpl::setThisOperationPtr(std::weak_ptr<Operation> thisOperationPtr)
{
	m_thisOperationPtr = thisOperationPtr;
	setThisBehavioralFeaturePtr(thisOperationPtr);
	setThisParameterableElementPtr(thisOperationPtr);
	setThisTemplateableElementPtr(thisOperationPtr);
}
std::shared_ptr<ecore::EObject> OperationImpl::eContainer() const
{
	if(auto wp = m_class.lock())
	{
		return wp;
	}

	if(auto wp = m_datatype.lock())
	{
		return wp;
	}

	if(auto wp = m_interface.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getBodyCondition())); //16730
		case uml::UmlPackage::OPERATION_ATTRIBUTE_CLASS:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getClass().lock())); //16731
		case uml::UmlPackage::OPERATION_ATTRIBUTE_DATATYPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getDatatype().lock())); //16732
		case uml::UmlPackage::OPERATION_ATTRIBUTE_INTERFACE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getInterface().lock())); //16733
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISORDERED:
			return eAny(getIsOrdered()); //16734
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISQUERY:
			return eAny(getIsQuery()); //16735
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISUNIQUE:
			return eAny(getIsUnique()); //16736
		case uml::UmlPackage::OPERATION_ATTRIBUTE_LOWER:
			return eAny(getLower()); //16737
		case uml::UmlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = m_postcondition->begin();
			Bag<uml::Constraint>::iterator end = m_postcondition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16738
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = m_precondition->begin();
			Bag<uml::Constraint>::iterator end = m_precondition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16739
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = m_redefinedOperation->begin();
			Bag<uml::Operation>::iterator end = m_redefinedOperation->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16740
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_TYPE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getType())); //16741
		case uml::UmlPackage::OPERATION_ATTRIBUTE_UPPER:
			return eAny(getUpper()); //16742
	}
	Any result;
	result = BehavioralFeatureImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = ParameterableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool OperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
			return getBodyCondition() != nullptr; //16730
		case uml::UmlPackage::OPERATION_ATTRIBUTE_CLASS:
			return getClass().lock() != nullptr; //16731
		case uml::UmlPackage::OPERATION_ATTRIBUTE_DATATYPE:
			return getDatatype().lock() != nullptr; //16732
		case uml::UmlPackage::OPERATION_ATTRIBUTE_INTERFACE:
			return getInterface().lock() != nullptr; //16733
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISORDERED:
			return getIsOrdered() != false; //16734
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISQUERY:
			return getIsQuery() != false; //16735
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISUNIQUE:
			return getIsUnique() != true; //16736
		case uml::UmlPackage::OPERATION_ATTRIBUTE_LOWER:
			return getLower() != 1; //16737
		case uml::UmlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
			return getPostcondition() != nullptr; //16738
		case uml::UmlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
			return getPrecondition() != nullptr; //16739
		case uml::UmlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
			return getRedefinedOperation() != nullptr; //16740
		case uml::UmlPackage::OPERATION_ATTRIBUTE_TYPE:
			return getType() != nullptr; //16741
		case uml::UmlPackage::OPERATION_ATTRIBUTE_UPPER:
			return getUpper() != 1; //16742
	}
	bool result = false;
	result = BehavioralFeatureImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	return result;
}
bool OperationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _bodyCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setBodyCondition(_bodyCondition); //16730
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>(_temp);
			setClass(_class); //16731
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>(_temp);
			setDatatype(_datatype); //16732
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>(_temp);
			setInterface(_interface); //16733
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_ISQUERY:
		{
			// BOOST CAST
			bool _isQuery = newValue->get<bool>();
			setIsQuery(_isQuery); //16735
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> postconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				postconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPostcondition = m_postcondition->begin();
			Bag<uml::Constraint>::iterator endPostcondition = m_postcondition->end();
			while (iterPostcondition != endPostcondition)
			{
				if (postconditionList->find(*iterPostcondition) == -1)
				{
					m_postcondition->erase(*iterPostcondition);
				}
				iterPostcondition++;
			}

			iterPostcondition = postconditionList->begin();
			endPostcondition = postconditionList->end();
			while (iterPostcondition != endPostcondition)
			{
				if (m_postcondition->find(*iterPostcondition) == -1)
				{
					m_postcondition->add(*iterPostcondition);
				}
				iterPostcondition++;			
			}
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> preconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				preconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPrecondition = m_precondition->begin();
			Bag<uml::Constraint>::iterator endPrecondition = m_precondition->end();
			while (iterPrecondition != endPrecondition)
			{
				if (preconditionList->find(*iterPrecondition) == -1)
				{
					m_precondition->erase(*iterPrecondition);
				}
				iterPrecondition++;
			}

			iterPrecondition = preconditionList->begin();
			endPrecondition = preconditionList->end();
			while (iterPrecondition != endPrecondition)
			{
				if (m_precondition->find(*iterPrecondition) == -1)
				{
					m_precondition->add(*iterPrecondition);
				}
				iterPrecondition++;			
			}
			return true;
		}
		case uml::UmlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Operation>> redefinedOperationList(new Bag<uml::Operation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedOperationList->add(std::dynamic_pointer_cast<uml::Operation>(*iter));
				iter++;
			}
			
			Bag<uml::Operation>::iterator iterRedefinedOperation = m_redefinedOperation->begin();
			Bag<uml::Operation>::iterator endRedefinedOperation = m_redefinedOperation->end();
			while (iterRedefinedOperation != endRedefinedOperation)
			{
				if (redefinedOperationList->find(*iterRedefinedOperation) == -1)
				{
					m_redefinedOperation->erase(*iterRedefinedOperation);
				}
				iterRedefinedOperation++;
			}

			iterRedefinedOperation = redefinedOperationList->begin();
			endRedefinedOperation = redefinedOperationList->end();
			while (iterRedefinedOperation != endRedefinedOperation)
			{
				if (m_redefinedOperation->find(*iterRedefinedOperation) == -1)
				{
					m_redefinedOperation->add(*iterRedefinedOperation);
				}
				iterRedefinedOperation++;			
			}
			return true;
		}
	}

	bool result = false;
	result = BehavioralFeatureImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void OperationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isQuery");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsQuery(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("postcondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postcondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("precondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("precondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedOperation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedOperation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehavioralFeatureImpl::loadAttributes(loadHandler, attr_list);
	ParameterableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
}

void OperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	BehavioralFeatureImpl::loadNode(nodeName, loadHandler);
	ParameterableElementImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
}

void OperationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _bodyCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setBodyCondition(_bodyCondition);
			}
			
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_CLASS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClass(_class);
			}
			
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_DATATYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>( references.front() );
				setDatatype(_datatype);
			}
			
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_INTERFACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setInterface(_interface);
			}
			
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<Bag<uml::Constraint>> _postcondition = getPostcondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Constraint> _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_postcondition->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<Bag<uml::Constraint>> _precondition = getPrecondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Constraint> _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_precondition->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			std::shared_ptr<Bag<uml::Operation>> _redefinedOperation = getRedefinedOperation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Operation> _r = std::dynamic_pointer_cast<uml::Operation>(ref);
				if (_r != nullptr)
				{
					_redefinedOperation->push_back(_r);
				}				
			}
			return;
		}
	}
	BehavioralFeatureImpl::resolveReferences(featureID, references);
	ParameterableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
}

void OperationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioralFeatureImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	FeatureImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void OperationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getOperation_Attribute_isQuery()) )
		{
			saveHandler->addAttribute("isQuery", this->getIsQuery());
		}

		// Add references
		saveHandler->addReference("bodyCondition", this->getBodyCondition());
		std::shared_ptr<Bag<uml::Constraint>> postcondition_list = this->getPostcondition();
		for (std::shared_ptr<uml::Constraint > object : *postcondition_list)
		{ 
			saveHandler->addReferences("postcondition", object);
		}
		std::shared_ptr<Bag<uml::Constraint>> precondition_list = this->getPrecondition();
		for (std::shared_ptr<uml::Constraint > object : *precondition_list)
		{ 
			saveHandler->addReferences("precondition", object);
		}
		std::shared_ptr<Bag<uml::Operation>> redefinedOperation_list = this->getRedefinedOperation();
		for (std::shared_ptr<uml::Operation > object : *redefinedOperation_list)
		{ 
			saveHandler->addReferences("redefinedOperation", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


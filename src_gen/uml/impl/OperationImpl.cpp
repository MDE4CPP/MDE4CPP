#include "OperationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "BehavioralFeature.hpp"

#include "Class.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "Constraint.hpp"

#include "DataType.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "Interface.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "Operation.hpp"

#include "PackageImport.hpp"

#include "PackageableElement.hpp"

#include "Parameter.hpp"

#include "ParameterSet.hpp"

#include "ParameterableElement.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"

#include "TemplateBinding.hpp"

#include "TemplateParameter.hpp"

#include "TemplateSignature.hpp"

#include "TemplateableElement.hpp"

#include "Type.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationImpl::OperationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	

	

		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedOperation.reset(new Subset<uml::Operation, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

	

	//Init references
	

	

	

	

		/*Subset*/
		m_postcondition->initSubset(m_ownedRule);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(m_ownedRule)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_precondition->initSubset(m_ownedRule);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(m_ownedRule)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_redefinedOperation->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

	
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
			}





//Additional constructor for the containments back reference
			OperationImpl::OperationImpl(std::weak_ptr<uml::DataType > par_datatype)
			:OperationImpl()
			{
			    m_datatype = par_datatype;
			}





//Additional constructor for the containments back reference
			OperationImpl::OperationImpl(std::weak_ptr<uml::Interface > par_interface)
			:OperationImpl()
			{
			    m_interface = par_interface;
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

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_datatype  = obj.getDatatype();

	std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_interface  = obj.getInterface();

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr< Bag<uml::Behavior> > _method = obj.getMethod();
	m_method.reset(new Bag<uml::Behavior>(*(obj.getMethod().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	std::shared_ptr< Bag<uml::Type> > _raisedException = obj.getRaisedException();
	m_raisedException.reset(new Bag<uml::Type>(*(obj.getRaisedException().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


    
	//Clone references with containment (deep copy)

	if(obj.getBodyCondition()!=nullptr)
	{
		m_bodyCondition.reset(dynamic_cast<uml::Constraint*>(obj.getBodyCondition()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_bodyCondition" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(dynamic_cast<uml::Parameter*>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(dynamic_cast<uml::ParameterSet*>(_ownedParameterSet->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameterSet" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _postconditionList = obj.getPostcondition();
	for(std::shared_ptr<uml::Constraint> _postcondition : *_postconditionList)
	{
		this->getPostcondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_postcondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_postcondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _preconditionList = obj.getPrecondition();
	for(std::shared_ptr<uml::Constraint> _precondition : *_preconditionList)
	{
		this->getPrecondition()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_precondition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_precondition" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Operation>> _redefinedOperationList = obj.getRedefinedOperation();
	for(std::shared_ptr<uml::Operation> _redefinedOperation : *_redefinedOperationList)
	{
		this->getRedefinedOperation()->add(std::shared_ptr<uml::Operation>(dynamic_cast<uml::Operation*>(_redefinedOperation->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_redefinedOperation" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif


}

ecore::EObject *  OperationImpl::copy() const
{
	return new OperationImpl(*this);
}

std::shared_ptr<ecore::EClass> OperationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOperation();
}

//*********************************
// Attribute Setter Getter
//*********************************


bool OperationImpl::getIsOrdered() const 
{
	return m_isOrdered;
}

void OperationImpl::setIsQuery(bool _isQuery)
{
	m_isQuery = _isQuery;
} 

bool OperationImpl::getIsQuery() const 
{
	return m_isQuery;
}



bool OperationImpl::getIsUnique() const 
{
	return m_isUnique;
}



int OperationImpl::getLower() const 
{
	return m_lower;
}



int OperationImpl::getUpper() const 
{
	return m_upper;
}

//*********************************
// Operations
//*********************************
bool OperationImpl::at_most_one_return(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
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

bool OperationImpl::only_body_for_query(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > OperationImpl::returnResult() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setIsOrdered(bool newIsOrdered) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setIsUnique(bool newIsUnique) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setLower(int newLower) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setType(std::shared_ptr<uml::Type>  newType) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OperationImpl::setUpper(int newUpper) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Constraint > OperationImpl::getBodyCondition() const
{

    return m_bodyCondition;
}
void OperationImpl::setBodyCondition(std::shared_ptr<uml::Constraint> _bodyCondition)
{
    m_bodyCondition = _bodyCondition;
}

std::weak_ptr<uml::Class > OperationImpl::getClass() const
{

    return m_class;
}
void OperationImpl::setClass(std::shared_ptr<uml::Class> _class)
{
    m_class = _class;
}

std::weak_ptr<uml::DataType > OperationImpl::getDatatype() const
{

    return m_datatype;
}
void OperationImpl::setDatatype(std::shared_ptr<uml::DataType> _datatype)
{
    m_datatype = _datatype;
}

std::weak_ptr<uml::Interface > OperationImpl::getInterface() const
{

    return m_interface;
}
void OperationImpl::setInterface(std::shared_ptr<uml::Interface> _interface)
{
    m_interface = _interface;
}

std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > > OperationImpl::getPostcondition() const
{

    return m_postcondition;
}


std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > > OperationImpl::getPrecondition() const
{

    return m_precondition;
}


std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement > > OperationImpl::getRedefinedOperation() const
{

    return m_redefinedOperation;
}


std::shared_ptr<uml::Type > OperationImpl::getType() const
{

    return m_type;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier> > OperationImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::shared_ptr<Union<uml::NamedElement> > OperationImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<uml::Namespace > OperationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > OperationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<Union<uml::RedefinableElement> > OperationImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > OperationImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > OperationImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > OperationImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OperationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::OPERATION_BODYCONDITION:
			return getBodyCondition(); //4731
		case UmlPackage::OPERATION_CLASS:
			return getClass(); //4732
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //474
		case UmlPackage::BEHAVIORALFEATURE_CONCURRENCY:
			return getConcurrency(); //4721
		case UmlPackage::OPERATION_DATATYPE:
			return getDatatype(); //4733
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //470
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //4711
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4713
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //4714
		case UmlPackage::OPERATION_INTERFACE:
			return getInterface(); //4734
		case UmlPackage::BEHAVIORALFEATURE_ISABSTRACT:
			return getIsAbstract(); //4722
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //4710
		case UmlPackage::OPERATION_ISORDERED:
			return getIsOrdered(); //4735
		case UmlPackage::OPERATION_ISQUERY:
			return getIsQuery(); //4736
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //4714
		case UmlPackage::OPERATION_ISUNIQUE:
			return getIsUnique(); //4737
		case UmlPackage::OPERATION_LOWER:
			return getLower(); //4738
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //4715
		case UmlPackage::BEHAVIORALFEATURE_METHOD:
			return getMethod(); //4723
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //475
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //476
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //477
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //471
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //472
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //4713
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETER:
			return getOwnedParameter(); //4724
		case UmlPackage::BEHAVIORALFEATURE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //4725
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //4710
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //475
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //473
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //474
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //4712
		case UmlPackage::OPERATION_POSTCONDITION:
			return getPostcondition(); //4739
		case UmlPackage::OPERATION_PRECONDITION:
			return getPrecondition(); //4740
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //478
		case UmlPackage::BEHAVIORALFEATURE_RAISEDEXCEPTION:
			return getRaisedException(); //4726
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //4711
		case UmlPackage::OPERATION_REDEFINEDOPERATION:
			return getRedefinedOperation(); //4741
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4712
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //474
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //475
		case UmlPackage::OPERATION_TYPE:
			return getType(); //4742
		case UmlPackage::OPERATION_UPPER:
			return getUpper(); //4743
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //479
	}
	return boost::any();
}

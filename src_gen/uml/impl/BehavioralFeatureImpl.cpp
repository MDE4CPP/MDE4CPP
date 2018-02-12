#include "uml/impl/BehavioralFeatureImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Behavior.hpp"

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ElementImport.hpp"

#include "uml/Feature.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageImport.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/Parameter.hpp"

#include "uml/ParameterSet.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Type.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BehavioralFeatureImpl::BehavioralFeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		m_method.reset(new Bag<uml::Behavior>());
	
	

		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::Parameter, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet.reset(new Subset<uml::ParameterSet, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >()" << std::endl;
		#endif
	
	

		m_raisedException.reset(new Bag<uml::Type>());
	
	

	//Init references
	
	

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

	
	
}

BehavioralFeatureImpl::~BehavioralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BehavioralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:BehavioralFeatureImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			BehavioralFeatureImpl::BehavioralFeatureImpl(std::weak_ptr<uml::Element > par_owner)
			:BehavioralFeatureImpl()
			{
			    m_owner = par_owner;
			}






BehavioralFeatureImpl::BehavioralFeatureImpl(const BehavioralFeatureImpl & obj):BehavioralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BehavioralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_concurrency = obj.getConcurrency();
	m_isAbstract = obj.getIsAbstract();
	m_isLeaf = obj.getIsLeaf();
	m_isStatic = obj.getIsStatic();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	std::shared_ptr< Bag<uml::Behavior> > _method = obj.getMethod();
	m_method.reset(new Bag<uml::Behavior>(*(obj.getMethod().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr< Bag<uml::Type> > _raisedException = obj.getRaisedException();
	m_raisedException.reset(new Bag<uml::Type>(*(obj.getRaisedException().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif

		/*Subset*/
		m_ownedParameter->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::Parameter, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedParameterSet->initSubset(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameterSet - Subset<uml::ParameterSet, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  BehavioralFeatureImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new BehavioralFeatureImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> BehavioralFeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getBehavioralFeature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void BehavioralFeatureImpl::setConcurrency(CallConcurrencyKind _concurrency)
{
	m_concurrency = _concurrency;
} 

CallConcurrencyKind BehavioralFeatureImpl::getConcurrency() const 
{
	return m_concurrency;
}

void BehavioralFeatureImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
} 

bool BehavioralFeatureImpl::getIsAbstract() const 
{
	return m_isAbstract;
}

//*********************************
// Operations
//*********************************
bool BehavioralFeatureImpl::abstract_no_method(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> BehavioralFeatureImpl::createReturnResult(std::string name,std::shared_ptr<uml::Type>  type) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::inputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Parameter> > BehavioralFeatureImpl::outputParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<uml::Behavior> > BehavioralFeatureImpl::getMethod() const
{

    return m_method;
}


std::shared_ptr<Subset<uml::Parameter, uml::NamedElement > > BehavioralFeatureImpl::getOwnedParameter() const
{

    return m_ownedParameter;
}


std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement > > BehavioralFeatureImpl::getOwnedParameterSet() const
{

    return m_ownedParameterSet;
}


std::shared_ptr< Bag<uml::Type> > BehavioralFeatureImpl::getRaisedException() const
{

    return m_raisedException;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement> > BehavioralFeatureImpl::getMember() const
{
	return m_member;
}
std::shared_ptr<Union<uml::Element> > BehavioralFeatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > BehavioralFeatureImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > BehavioralFeatureImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> BehavioralFeatureImpl::eContainer() const
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
boost::any BehavioralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //484
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY:
			return getConcurrency(); //4821
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //480
		case UmlPackage::NAMESPACE_EREFERENCE_ELEMENTIMPORT:
			return getElementImport(); //4811
		case UmlPackage::FEATURE_EREFERENCE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4813
		case UmlPackage::NAMESPACE_EREFERENCE_IMPORTEDMEMBER:
			return getImportedMember(); //4814
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT:
			return getIsAbstract(); //4822
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //4810
		case UmlPackage::FEATURE_EATTRIBUTE_ISSTATIC:
			return getIsStatic(); //4814
		case UmlPackage::NAMESPACE_EREFERENCE_MEMBER:
			return getMember(); //4815
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_METHOD:
			return getMethod(); //4823
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //485
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //486
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //487
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //481
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //482
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDMEMBER:
			return getOwnedMember(); //4813
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter(); //4824
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //4825
		case UmlPackage::NAMESPACE_EREFERENCE_OWNEDRULE:
			return getOwnedRule(); //4810
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //483
		case UmlPackage::NAMESPACE_EREFERENCE_PACKAGEIMPORT:
			return getPackageImport(); //4812
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //488
		case UmlPackage::BEHAVIORALFEATURE_EREFERENCE_RAISEDEXCEPTION:
			return getRaisedException(); //4826
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //4811
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4812
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //489
	}
	return boost::any();
}

void BehavioralFeatureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY:
		{
			// BOOST CAST
			CallConcurrencyKind _concurrency = boost::any_cast<CallConcurrencyKind>(newValue);
			setConcurrency(_concurrency); //4821
			break;
		}
		case UmlPackage::BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = boost::any_cast<bool>(newValue);
			setIsAbstract(_isAbstract); //4822
			break;
		}
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //4810
			break;
		}
		case UmlPackage::FEATURE_EATTRIBUTE_ISSTATIC:
		{
			// BOOST CAST
			bool _isStatic = boost::any_cast<bool>(newValue);
			setIsStatic(_isStatic); //4814
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //485
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //486
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //489
			break;
		}
	}
}

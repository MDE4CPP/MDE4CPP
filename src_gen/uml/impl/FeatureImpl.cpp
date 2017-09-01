#include "FeatureImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "RedefinableElement.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FeatureImpl::FeatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
	
	

	//Init references
	
	
}

FeatureImpl::~FeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Feature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			FeatureImpl::FeatureImpl(std::shared_ptr<uml::Namespace > par_namespace)
			:FeatureImpl()
			{
			    m_namespace = par_namespace;
			}






FeatureImpl::FeatureImpl(const FeatureImpl & obj):FeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Feature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
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


}

ecore::EObject *  FeatureImpl::copy() const
{
	return new FeatureImpl(*this);
}

std::shared_ptr<ecore::EClass> FeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFeature();
}

//*********************************
// Attribute Setter Getter
//*********************************
void FeatureImpl::setIsStatic(bool _isStatic)
{
	m_isStatic = _isStatic;
} 

bool FeatureImpl::getIsStatic() const 
{
	return m_isStatic;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier> > FeatureImpl::getFeaturingClassifier() const
{
	return m_featuringClassifier;
}
std::shared_ptr<Union<uml::Element> > FeatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > FeatureImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FeatureImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //494
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //490
		case UmlPackage::FEATURE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //4913
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //4910
		case UmlPackage::FEATURE_ISSTATIC:
			return getIsStatic(); //4914
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //495
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //496
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //497
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //491
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //492
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //493
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //498
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //4911
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //4912
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //499
	}
	return boost::any();
}

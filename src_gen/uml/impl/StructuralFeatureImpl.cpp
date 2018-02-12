#include "uml/impl/StructuralFeatureImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Feature.hpp"

#include "uml/MultiplicityElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Type.hpp"

#include "uml/TypedElement.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StructuralFeatureImpl::StructuralFeatureImpl()
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

StructuralFeatureImpl::~StructuralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			StructuralFeatureImpl::StructuralFeatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StructuralFeatureImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			StructuralFeatureImpl::StructuralFeatureImpl(std::weak_ptr<uml::Element > par_owner)
			:StructuralFeatureImpl()
			{
			    m_owner = par_owner;
			}






StructuralFeatureImpl::StructuralFeatureImpl(const StructuralFeatureImpl & obj):StructuralFeatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_isOrdered = obj.getIsOrdered();
	m_isReadOnly = obj.getIsReadOnly();
	m_isStatic = obj.getIsStatic();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::Classifier> > _featuringClassifier = obj.getFeaturingClassifier();
	m_featuringClassifier.reset(new Union<uml::Classifier>(*(obj.getFeaturingClassifier().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_type  = obj.getType();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getLowerValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
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
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperValue()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  StructuralFeatureImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new StructuralFeatureImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StructuralFeatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStructuralFeature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void StructuralFeatureImpl::setIsReadOnly(bool _isReadOnly)
{
	m_isReadOnly = _isReadOnly;
} 

bool StructuralFeatureImpl::getIsReadOnly() const 
{
	return m_isReadOnly;
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
std::shared_ptr<Union<uml::Element> > StructuralFeatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > StructuralFeatureImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> StructuralFeatureImpl::eContainer() const
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
boost::any StructuralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //734
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //730
		case UmlPackage::FEATURE_EREFERENCE_FEATURINGCLASSIFIER:
			return getFeaturingClassifier(); //7313
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //7310
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
			return getIsOrdered(); //734
		case UmlPackage::STRUCTURALFEATURE_EATTRIBUTE_ISREADONLY:
			return getIsReadOnly(); //7322
		case UmlPackage::FEATURE_EATTRIBUTE_ISSTATIC:
			return getIsStatic(); //7314
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
			return getIsUnique(); //735
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
			return getLower(); //736
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
			return getLowerValue(); //737
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //735
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //736
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //737
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //731
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //732
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //733
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //738
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //7311
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //7312
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
			return getType(); //7310
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
			return getUpper(); //738
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
			return getUpperValue(); //739
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //739
	}
	return boost::any();
}

void StructuralFeatureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //7310
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = boost::any_cast<bool>(newValue);
			setIsOrdered(_isOrdered); //734
			break;
		}
		case UmlPackage::STRUCTURALFEATURE_EATTRIBUTE_ISREADONLY:
		{
			// BOOST CAST
			bool _isReadOnly = boost::any_cast<bool>(newValue);
			setIsReadOnly(_isReadOnly); //7322
			break;
		}
		case UmlPackage::FEATURE_EATTRIBUTE_ISSTATIC:
		{
			// BOOST CAST
			bool _isStatic = boost::any_cast<bool>(newValue);
			setIsStatic(_isStatic); //7314
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE:
		{
			// BOOST CAST
			bool _isUnique = boost::any_cast<bool>(newValue);
			setIsUnique(_isUnique); //735
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_LOWER:
		{
			// BOOST CAST
			int _lower = boost::any_cast<int>(newValue);
			setLower(_lower); //736
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _lowerValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setLowerValue(_lowerValue); //737
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //735
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //736
			break;
		}
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //7310
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EATTRIBUTE_UPPER:
		{
			// BOOST CAST
			int _upper = boost::any_cast<int>(newValue);
			setUpper(_upper); //738
			break;
		}
		case UmlPackage::MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ValueSpecification> _upperValue = boost::any_cast<std::shared_ptr<uml::ValueSpecification>>(newValue);
			setUpperValue(_upperValue); //739
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //739
			break;
		}
	}
}

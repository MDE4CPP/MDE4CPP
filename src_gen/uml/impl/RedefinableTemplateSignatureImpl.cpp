#include "uml/impl/RedefinableTemplateSignatureImpl.hpp"
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

#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/RedefinableTemplateSignature.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/TemplateableElement.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_extendedSignature.reset(new Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedParameter.reset(new Subset<uml::TemplateParameter, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_extendedSignature->initSubset(m_redefinedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_extendedSignature - Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement >(m_redefinedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_inheritedParameter->initSubset(m_parameter);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedParameter - Subset<uml::TemplateParameter, uml::TemplateParameter >(m_parameter)" << std::endl;
		#endif
	
	
}

RedefinableTemplateSignatureImpl::~RedefinableTemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinableTemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:RedefinableTemplateSignatureImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Element > par_owner)
			:RedefinableTemplateSignatureImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement > par_template)
			:RedefinableTemplateSignatureImpl()
			{
			    m_template = par_template;
			}






RedefinableTemplateSignatureImpl::RedefinableTemplateSignatureImpl(const RedefinableTemplateSignatureImpl & obj):RedefinableTemplateSignatureImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinableTemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::TemplateParameter> > _parameter = obj.getParameter();
	m_parameter.reset(new Union<uml::TemplateParameter>(*(obj.getParameter().get())));

	std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new Union<uml::RedefinableElement>(*(obj.getRedefinedElement().get())));

	std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new Union<uml::Classifier>(*(obj.getRedefinitionContext().get())));

	m_template  = obj.getTemplate();


	//Clone references with containment (deep copy)

	if(obj.getClassifier()!=nullptr)
	{
		m_classifier = std::dynamic_pointer_cast<uml::Classifier>(obj.getClassifier()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_classifier" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::RedefinableTemplateSignature>> _extendedSignatureList = obj.getExtendedSignature();
	for(std::shared_ptr<uml::RedefinableTemplateSignature> _extendedSignature : *_extendedSignatureList)
	{
		this->getExtendedSignature()->add(std::shared_ptr<uml::RedefinableTemplateSignature>(std::dynamic_pointer_cast<uml::RedefinableTemplateSignature>(_extendedSignature->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extendedSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateParameter>> _inheritedParameterList = obj.getInheritedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _inheritedParameter : *_inheritedParameterList)
	{
		this->getInheritedParameter()->add(std::shared_ptr<uml::TemplateParameter>(std::dynamic_pointer_cast<uml::TemplateParameter>(_inheritedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_inheritedParameter" << std::endl;
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
	std::shared_ptr<Bag<uml::TemplateParameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::TemplateParameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::TemplateParameter>(std::dynamic_pointer_cast<uml::TemplateParameter>(_ownedParameter->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedParameter" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  RedefinableTemplateSignatureImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new RedefinableTemplateSignatureImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> RedefinableTemplateSignatureImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getRedefinableTemplateSignature_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::TemplateParameter> > RedefinableTemplateSignatureImpl::getInheritedParameters() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RedefinableTemplateSignatureImpl::redefines_parents(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > RedefinableTemplateSignatureImpl::getClassifier() const
{
//assert(m_classifier);
    return m_classifier;
}


std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement > > RedefinableTemplateSignatureImpl::getExtendedSignature() const
{

    return m_extendedSignature;
}


std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter > > RedefinableTemplateSignatureImpl::getInheritedParameter() const
{

    return m_inheritedParameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > RedefinableTemplateSignatureImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > RedefinableTemplateSignatureImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::TemplateParameter> > RedefinableTemplateSignatureImpl::getParameter() const
{
	return m_parameter;
}
std::shared_ptr<Union<uml::RedefinableElement> > RedefinableTemplateSignatureImpl::getRedefinedElement() const
{
	return m_redefinedElement;
}
std::shared_ptr<Union<uml::Classifier> > RedefinableTemplateSignatureImpl::getRedefinitionContext() const
{
	return m_redefinitionContext;
}


std::shared_ptr<ecore::EObject> RedefinableTemplateSignatureImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_template.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any RedefinableTemplateSignatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_EREFERENCE_CLASSIFIER:
			return getClassifier(); //9718
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //974
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //970
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_EREFERENCE_EXTENDEDSIGNATURE:
			return getExtendedSignature(); //9716
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_EREFERENCE_INHERITEDPARAMETER:
			return getInheritedParameter(); //9717
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
			return getIsLeaf(); //9710
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //975
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //976
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //977
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //971
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //972
		case UmlPackage::TEMPLATESIGNATURE_EREFERENCE_OWNEDPARAMETER:
			return getOwnedParameter(); //976
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //973
		case UmlPackage::TEMPLATESIGNATURE_EREFERENCE_PARAMETER:
			return getParameter(); //974
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //978
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT:
			return getRedefinedElement(); //9711
		case UmlPackage::REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //9712
		case UmlPackage::TEMPLATESIGNATURE_EREFERENCE_TEMPLATE:
			return getTemplate(); //975
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //979
	}
	return boost::any();
}

void RedefinableTemplateSignatureImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF:
		{
			// BOOST CAST
			bool _isLeaf = boost::any_cast<bool>(newValue);
			setIsLeaf(_isLeaf); //9710
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //975
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //976
			break;
		}
		case UmlPackage::TEMPLATESIGNATURE_EREFERENCE_TEMPLATE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateableElement> _template = boost::any_cast<std::shared_ptr<uml::TemplateableElement>>(newValue);
			setTemplate(_template); //975
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //979
			break;
		}
	}
}

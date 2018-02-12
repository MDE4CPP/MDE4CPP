#include "uml/impl/StringExpressionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Expression.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/TemplateSignature.hpp"

#include "uml/TemplateableElement.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StringExpressionImpl::StringExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		/*Subset*/
		m_subExpression.reset(new Subset<uml::StringExpression, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
	

		/*Subset*/
		m_subExpression->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

StringExpressionImpl::~StringExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StringExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:StringExpressionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:StringExpressionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::StringExpression > par_owningExpression)
			:StringExpressionImpl()
			{
			    m_owningExpression = par_owningExpression;
			}





//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:StringExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:StringExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:StringExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






StringExpressionImpl::StringExpressionImpl(const StringExpressionImpl & obj):StringExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StringExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_symbol = obj.getSymbol();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningExpression  = obj.getOwningExpression();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

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
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ValueSpecification>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::ValueSpecification> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::ValueSpecification>(std::dynamic_pointer_cast<uml::ValueSpecification>(_operand->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_operand" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::StringExpression>> _subExpressionList = obj.getSubExpression();
	for(std::shared_ptr<uml::StringExpression> _subExpression : *_subExpressionList)
	{
		this->getSubExpression()->add(std::shared_ptr<uml::StringExpression>(std::dynamic_pointer_cast<uml::StringExpression>(_subExpression->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

		/*Subset*/
		m_subExpression->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subExpression - Subset<uml::StringExpression, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  StringExpressionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new StringExpressionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> StringExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStringExpression_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool StringExpressionImpl::operands(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StringExpressionImpl::subexpressions(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::StringExpression > StringExpressionImpl::getOwningExpression() const
{

    return m_owningExpression;
}
void StringExpressionImpl::setOwningExpression(std::shared_ptr<uml::StringExpression> _owningExpression)
{
    m_owningExpression = _owningExpression;
}

std::shared_ptr<Subset<uml::StringExpression, uml::Element > > StringExpressionImpl::getSubExpression() const
{

    return m_subExpression;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > StringExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > StringExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > StringExpressionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> StringExpressionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningExpression.lock())
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
boost::any StringExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //874
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //870
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //875
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //876
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //877
		case UmlPackage::EXPRESSION_EREFERENCE_OPERAND:
			return getOperand(); //8715
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //871
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //872
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //875
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //873
		case UmlPackage::STRINGEXPRESSION_EREFERENCE_OWNINGEXPRESSION:
			return getOwningExpression(); //8719
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //8712
		case UmlPackage::VALUESPECIFICATION_EREFERENCE_OWNINGSLOT:
			return getOwningSlot(); //8714
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //874
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //878
		case UmlPackage::STRINGEXPRESSION_EREFERENCE_SUBEXPRESSION:
			return getSubExpression(); //8720
		case UmlPackage::EXPRESSION_EATTRIBUTE_SYMBOL:
			return getSymbol(); //8716
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING:
			return getTemplateBinding(); //874
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //875
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
			return getType(); //8710
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //879
	}
	return boost::any();
}

void StringExpressionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //875
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //876
			break;
		}
		case UmlPackage::TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature = boost::any_cast<std::shared_ptr<uml::TemplateSignature>>(newValue);
			setOwnedTemplateSignature(_ownedTemplateSignature); //875
			break;
		}
		case UmlPackage::STRINGEXPRESSION_EREFERENCE_OWNINGEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _owningExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setOwningExpression(_owningExpression); //8719
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //8712
			break;
		}
		case UmlPackage::VALUESPECIFICATION_EREFERENCE_OWNINGSLOT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Slot> _owningSlot = boost::any_cast<std::shared_ptr<uml::Slot>>(newValue);
			setOwningSlot(_owningSlot); //8714
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //874
			break;
		}
		case UmlPackage::EXPRESSION_EATTRIBUTE_SYMBOL:
		{
			// BOOST CAST
			std::string _symbol = boost::any_cast<std::string>(newValue);
			setSymbol(_symbol); //8716
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //875
			break;
		}
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //8710
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //879
			break;
		}
	}
}

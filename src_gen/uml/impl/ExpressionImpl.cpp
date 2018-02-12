#include "uml/impl/ExpressionImpl.hpp"
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

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

#include "uml/Slot.hpp"

#include "uml/StringExpression.hpp"

#include "uml/TemplateParameter.hpp"

#include "uml/Type.hpp"

#include "uml/ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionImpl::ExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_operand.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

ExpressionImpl::~ExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Expression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ExpressionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:ExpressionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:ExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:ExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			ExpressionImpl::ExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:ExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






ExpressionImpl::ExpressionImpl(const ExpressionImpl & obj):ExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Expression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
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

		/*Subset*/
		m_operand->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_operand - Subset<uml::ValueSpecification, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ExpressionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExpressionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExpression_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ExpressionImpl::setSymbol(std::string _symbol)
{
	m_symbol = _symbol;
} 

std::string ExpressionImpl::getSymbol() const 
{
	return m_symbol;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > > ExpressionImpl::getOperand() const
{

    return m_operand;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExpressionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ExpressionImpl::eContainer() const
{
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
boost::any ExpressionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY:
			return getClientDependency(); //884
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //880
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
			return getName(); //885
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
			return getNameExpression(); //886
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMESPACE:
			return getNamespace(); //887
		case UmlPackage::EXPRESSION_EREFERENCE_OPERAND:
			return getOperand(); //8815
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //881
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //882
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //883
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
			return getOwningPackage(); //8812
		case UmlPackage::VALUESPECIFICATION_EREFERENCE_OWNINGSLOT:
			return getOwningSlot(); //8814
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //884
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName(); //888
		case UmlPackage::EXPRESSION_EATTRIBUTE_SYMBOL:
			return getSymbol(); //8816
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
			return getTemplateParameter(); //885
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
			return getType(); //8810
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
			return getVisibility(); //889
	}
	return boost::any();
}

void ExpressionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //885
			break;
		}
		case UmlPackage::NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //886
			break;
		}
		case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _owningPackage = boost::any_cast<std::shared_ptr<uml::Package>>(newValue);
			setOwningPackage(_owningPackage); //8812
			break;
		}
		case UmlPackage::VALUESPECIFICATION_EREFERENCE_OWNINGSLOT:
		{
			// BOOST CAST
			std::shared_ptr<uml::Slot> _owningSlot = boost::any_cast<std::shared_ptr<uml::Slot>>(newValue);
			setOwningSlot(_owningSlot); //8814
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setOwningTemplateParameter(_owningTemplateParameter); //884
			break;
		}
		case UmlPackage::EXPRESSION_EATTRIBUTE_SYMBOL:
		{
			// BOOST CAST
			std::string _symbol = boost::any_cast<std::string>(newValue);
			setSymbol(_symbol); //8816
			break;
		}
		case UmlPackage::PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _templateParameter = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setTemplateParameter(_templateParameter); //885
			break;
		}
		case UmlPackage::TYPEDELEMENT_EREFERENCE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Type> _type = boost::any_cast<std::shared_ptr<uml::Type>>(newValue);
			setType(_type); //8810
			break;
		}
		case UmlPackage::NAMEDELEMENT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //889
			break;
		}
	}
}

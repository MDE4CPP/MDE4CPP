#include "StringExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Expression.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "TemplateBinding.hpp"

#include "TemplateParameter.hpp"

#include "TemplateSignature.hpp"

#include "TemplateableElement.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


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
			StringExpressionImpl::StringExpressionImpl(std::weak_ptr<uml::StringExpression > par_owningExpression)
			:StringExpressionImpl()
			{
			    m_owningExpression = par_owningExpression;
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

	m_owner  = obj.getOwner();

	m_owningExpression  = obj.getOwningExpression();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();

	m_type  = obj.getType();


    
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
	std::shared_ptr<Bag<uml::ValueSpecification>> _operandList = obj.getOperand();
	for(std::shared_ptr<uml::ValueSpecification> _operand : *_operandList)
	{
		this->getOperand()->add(std::shared_ptr<uml::ValueSpecification>(dynamic_cast<uml::ValueSpecification*>(_operand->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_operand" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::StringExpression>> _subExpressionList = obj.getSubExpression();
	for(std::shared_ptr<uml::StringExpression> _subExpression : *_subExpressionList)
	{
		this->getSubExpression()->add(std::shared_ptr<uml::StringExpression>(dynamic_cast<uml::StringExpression*>(_subExpression->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_subExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
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

ecore::EObject *  StringExpressionImpl::copy() const
{
	return new StringExpressionImpl(*this);
}

std::shared_ptr<ecore::EClass> StringExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStringExpression();
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
std::weak_ptr<uml::Element > StringExpressionImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > StringExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StringExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //874
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //870
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //875
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //876
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //877
		case UmlPackage::EXPRESSION_OPERAND:
			return getOperand(); //8713
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //871
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //872
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //875
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //873
		case UmlPackage::STRINGEXPRESSION_OWNINGEXPRESSION:
			return getOwningExpression(); //8717
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //874
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //878
		case UmlPackage::STRINGEXPRESSION_SUBEXPRESSION:
			return getSubExpression(); //8718
		case UmlPackage::EXPRESSION_SYMBOL:
			return getSymbol(); //8714
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //874
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //875
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //8710
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //879
	}
	return boost::any();
}

#include "OpaqueExpressionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Behavior.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "Parameter.hpp"

#include "Slot.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueExpressionImpl::OpaqueExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	m_body.reset(new Bag<std::string>());
	m_language.reset(new Bag<std::string>());
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

OpaqueExpressionImpl::~OpaqueExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:OpaqueExpressionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:OpaqueExpressionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:OpaqueExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:OpaqueExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			OpaqueExpressionImpl::OpaqueExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:OpaqueExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






OpaqueExpressionImpl::OpaqueExpressionImpl(const OpaqueExpressionImpl & obj):OpaqueExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_body = obj.getBody();
	m_language = obj.getLanguage();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_behavior  = obj.getBehavior();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningSlot  = obj.getOwningSlot();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_result  = obj.getResult();

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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  OpaqueExpressionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OpaqueExpressionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getOpaqueExpression();
}

//*********************************
// Attribute Setter Getter
//*********************************


std::shared_ptr<Bag<std::string> > OpaqueExpressionImpl::getBody() const 
{
	return m_body;
}



std::shared_ptr<Bag<std::string> > OpaqueExpressionImpl::getLanguage() const 
{
	return m_language;
}

//*********************************
// Operations
//*********************************


bool OpaqueExpressionImpl::isIntegral() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isNonNegative() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::isPositive() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::language_body_size(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::one_return_result_parameter(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OpaqueExpressionImpl::only_return_result_parameters(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OpaqueExpressionImpl::value() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Behavior > OpaqueExpressionImpl::getBehavior() const
{

    return m_behavior;
}
void OpaqueExpressionImpl::setBehavior(std::shared_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
}

std::shared_ptr<uml::Parameter > OpaqueExpressionImpl::getResult() const
{

    return m_result;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > OpaqueExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > OpaqueExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > OpaqueExpressionImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OpaqueExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::OPAQUEEXPRESSION_BEHAVIOR:
			return getBehavior(); //4315
		case UmlPackage::OPAQUEEXPRESSION_BODY:
			return getBody(); //4316
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //434
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //430
		case UmlPackage::OPAQUEEXPRESSION_LANGUAGE:
			return getLanguage(); //4317
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //435
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //436
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //437
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //431
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //432
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //433
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //4312
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //4314
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //434
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //438
		case UmlPackage::OPAQUEEXPRESSION_RESULT:
			return getResult(); //4318
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //435
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //4310
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //439
	}
	return boost::any();
}

#include "TimeExpressionImpl.hpp"
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

#include "Namespace.hpp"

#include "Observation.hpp"

#include "Package.hpp"

#include "Slot.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TimeExpressionImpl::TimeExpressionImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_observation.reset(new Bag<uml::Observation>());
	
	

	//Init references
	

	
	
}

TimeExpressionImpl::~TimeExpressionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TimeExpression "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:TimeExpressionImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Element > par_owner)
			:TimeExpressionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:TimeExpressionImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::Slot > par_owningSlot)
			:TimeExpressionImpl()
			{
			    m_owningSlot = par_owningSlot;
			}





//Additional constructor for the containments back reference
			TimeExpressionImpl::TimeExpressionImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:TimeExpressionImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






TimeExpressionImpl::TimeExpressionImpl(const TimeExpressionImpl & obj):TimeExpressionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TimeExpression "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr< Bag<uml::Observation> > _observation = obj.getObservation();
	m_observation.reset(new Bag<uml::Observation>(*(obj.getObservation().get())));

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
	if(obj.getExpr()!=nullptr)
	{
		m_expr = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getExpr()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_expr" << std::endl;
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

std::shared_ptr<ecore::EObject>  TimeExpressionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TimeExpressionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TimeExpressionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTimeExpression();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TimeExpressionImpl::no_expr_requires_observation(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ValueSpecification > TimeExpressionImpl::getExpr() const
{

    return m_expr;
}
void TimeExpressionImpl::setExpr(std::shared_ptr<uml::ValueSpecification> _expr)
{
    m_expr = _expr;
}

std::shared_ptr< Bag<uml::Observation> > TimeExpressionImpl::getObservation() const
{

    return m_observation;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > TimeExpressionImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > TimeExpressionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TimeExpressionImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TimeExpressionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2034
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2030
		case UmlPackage::TIMEEXPRESSION_EXPR:
			return getExpr(); //20315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2035
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2036
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2037
		case UmlPackage::TIMEEXPRESSION_OBSERVATION:
			return getObservation(); //20316
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2031
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2032
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2033
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //20312
		case UmlPackage::VALUESPECIFICATION_OWNINGSLOT:
			return getOwningSlot(); //20314
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2034
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2038
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2035
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //20310
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2039
	}
	return boost::any();
}

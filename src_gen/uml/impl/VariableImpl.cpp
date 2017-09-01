#include "VariableImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Action.hpp"

#include "Activity.hpp"

#include "Comment.hpp"

#include "ConnectableElement.hpp"

#include "ConnectorEnd.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "MultiplicityElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"

#include "StructuredActivityNode.hpp"

#include "TemplateParameter.hpp"

#include "Type.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
VariableImpl::VariableImpl()
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

VariableImpl::~VariableImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Variable "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::Activity > par_activityScope)
			:VariableImpl()
			{
			    m_activityScope = par_activityScope;
			}





//Additional constructor for the containments back reference
			VariableImpl::VariableImpl(std::weak_ptr<uml::StructuredActivityNode > par_scope)
			:VariableImpl()
			{
			    m_scope = par_scope;
			}






VariableImpl::VariableImpl(const VariableImpl & obj):VariableImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Variable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isOrdered = obj.getIsOrdered();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_upper = obj.getUpper();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_activityScope  = obj.getActivityScope();

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::ConnectorEnd> > _end = obj.getEnd();
	m_end.reset(new Bag<uml::ConnectorEnd>(*(obj.getEnd().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_scope  = obj.getScope();

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
	if(obj.getLowerValue()!=nullptr)
	{
		m_lowerValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getLowerValue()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_lowerValue" << std::endl;
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
	if(obj.getUpperValue()!=nullptr)
	{
		m_upperValue.reset(dynamic_cast<uml::ValueSpecification*>(obj.getUpperValue()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_upperValue" << std::endl;
	#endif


}

ecore::EObject *  VariableImpl::copy() const
{
	return new VariableImpl(*this);
}

std::shared_ptr<ecore::EClass> VariableImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getVariable();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool VariableImpl::isAccessibleBy(std::shared_ptr<uml::Action>  a) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Activity > VariableImpl::getActivityScope() const
{

    return m_activityScope;
}
void VariableImpl::setActivityScope(std::shared_ptr<uml::Activity> _activityScope)
{
    m_activityScope = _activityScope;
}

std::weak_ptr<uml::StructuredActivityNode > VariableImpl::getScope() const
{

    return m_scope;
}
void VariableImpl::setScope(std::shared_ptr<uml::StructuredActivityNode> _scope)
{
    m_scope = _scope;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > VariableImpl::getNamespace() const
{
	return m_namespace;
}
std::weak_ptr<uml::Element > VariableImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > VariableImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any VariableImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::VARIABLE_ACTIVITYSCOPE:
			return getActivityScope(); //12120
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1214
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1210
		case UmlPackage::CONNECTABLEELEMENT_END:
			return getEnd(); //12113
		case UmlPackage::MULTIPLICITYELEMENT_ISORDERED:
			return getIsOrdered(); //1214
		case UmlPackage::MULTIPLICITYELEMENT_ISUNIQUE:
			return getIsUnique(); //1215
		case UmlPackage::MULTIPLICITYELEMENT_LOWER:
			return getLower(); //1216
		case UmlPackage::MULTIPLICITYELEMENT_LOWERVALUE:
			return getLowerValue(); //1217
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1215
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1216
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1217
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1211
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1212
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1213
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1214
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1218
		case UmlPackage::VARIABLE_SCOPE:
			return getScope(); //12121
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1215
		case UmlPackage::TYPEDELEMENT_TYPE:
			return getType(); //12110
		case UmlPackage::MULTIPLICITYELEMENT_UPPER:
			return getUpper(); //1218
		case UmlPackage::MULTIPLICITYELEMENT_UPPERVALUE:
			return getUpperValue(); //1219
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1219
	}
	return boost::any();
}

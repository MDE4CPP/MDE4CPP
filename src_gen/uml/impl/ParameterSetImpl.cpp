#include "uml/impl/ParameterSetImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Parameter.hpp"

#include "uml/StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterSetImpl::ParameterSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_condition.reset(new Subset<uml::Constraint, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >()" << std::endl;
		#endif
	
	

		m_parameter.reset(new Bag<uml::Parameter>());
	
	

	//Init references
		/*Subset*/
		m_condition->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
	
}

ParameterSetImpl::~ParameterSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ParameterSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ParameterSetImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			ParameterSetImpl::ParameterSetImpl(std::weak_ptr<uml::Element > par_owner)
			:ParameterSetImpl()
			{
			    m_owner = par_owner;
			}






ParameterSetImpl::ParameterSetImpl(const ParameterSetImpl & obj):ParameterSetImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ParameterSet "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr< Bag<uml::Parameter> > _parameter = obj.getParameter();
	m_parameter.reset(new Bag<uml::Parameter>(*(obj.getParameter().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Constraint>> _conditionList = obj.getCondition();
	for(std::shared_ptr<uml::Constraint> _condition : *_conditionList)
	{
		this->getCondition()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_condition->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_condition" << std::endl;
	#endif
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

		/*Subset*/
		m_condition->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_condition - Subset<uml::Constraint, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  ParameterSetImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ParameterSetImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ParameterSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getParameterSet();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ParameterSetImpl::input(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::same_parameterized_entity(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterSetImpl::two_parameter_sets(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Constraint, uml::Element > > ParameterSetImpl::getCondition() const
{

    return m_condition;
}


std::shared_ptr< Bag<uml::Parameter> > ParameterSetImpl::getParameter() const
{
//assert(m_parameter);
    return m_parameter;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ParameterSetImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ParameterSetImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> ParameterSetImpl::eContainer() const
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
boost::any ParameterSetImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //524
		case UmlPackage::PARAMETERSET_CONDITION:
			return getCondition(); //5210
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //520
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //525
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //526
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //527
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //521
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //522
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //523
		case UmlPackage::PARAMETERSET_PARAMETER:
			return getParameter(); //5211
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //528
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //529
	}
	return boost::any();
}

void ParameterSetImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_NAME:
		{
			// BOOST CAST
			std::string _name = boost::any_cast<std::string>(newValue);
			setName(_name); //525
			break;
		}
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<uml::StringExpression> _nameExpression = boost::any_cast<std::shared_ptr<uml::StringExpression>>(newValue);
			setNameExpression(_nameExpression); //526
			break;
		}
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = boost::any_cast<VisibilityKind>(newValue);
			setVisibility(_visibility); //529
			break;
		}
	}
}

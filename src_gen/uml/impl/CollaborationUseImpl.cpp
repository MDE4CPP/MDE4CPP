#include "CollaborationUseImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Collaboration.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CollaborationUseImpl::CollaborationUseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_roleBinding.reset(new Subset<uml::Dependency, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_roleBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

CollaborationUseImpl::~CollaborationUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollaborationUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:CollaborationUseImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Element > par_owner)
			:CollaborationUseImpl()
			{
			    m_owner = par_owner;
			}






CollaborationUseImpl::CollaborationUseImpl(const CollaborationUseImpl & obj):CollaborationUseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollaborationUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

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
	std::shared_ptr<Bag<uml::Dependency>> _roleBindingList = obj.getRoleBinding();
	for(std::shared_ptr<uml::Dependency> _roleBinding : *_roleBindingList)
	{
		this->getRoleBinding()->add(std::shared_ptr<uml::Dependency>(std::dynamic_pointer_cast<uml::Dependency>(_roleBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_roleBinding" << std::endl;
	#endif

		/*Subset*/
		m_roleBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  CollaborationUseImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new CollaborationUseImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> CollaborationUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCollaborationUse();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CollaborationUseImpl::client_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::connectors(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::every_role(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Dependency, uml::Element > > CollaborationUseImpl::getRoleBinding() const
{

    return m_roleBinding;
}


std::shared_ptr<uml::Collaboration > CollaborationUseImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void CollaborationUseImpl::setType(std::shared_ptr<uml::Collaboration> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > CollaborationUseImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > CollaborationUseImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CollaborationUseImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //904
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //900
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //905
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //906
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //907
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //901
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //902
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //903
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //908
		case UmlPackage::COLLABORATIONUSE_ROLEBINDING:
			return getRoleBinding(); //9010
		case UmlPackage::COLLABORATIONUSE_TYPE:
			return getType(); //9011
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //909
	}
	return boost::any();
}

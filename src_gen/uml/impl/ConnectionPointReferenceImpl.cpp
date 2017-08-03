#include "ConnectionPointReferenceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Namespace.hpp"

#include "Pseudostate.hpp"

#include "Region.hpp"

#include "State.hpp"

#include "StringExpression.hpp"

#include "Transition.hpp"

#include "Vertex.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_entry.reset(new Bag<uml::Pseudostate>());
	
	

		m_exit.reset(new Bag<uml::Pseudostate>());
	
	

	

	//Init references
	
	

	
	

	
}

ConnectionPointReferenceImpl::~ConnectionPointReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectionPointReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj):ConnectionPointReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectionPointReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));

		std::shared_ptr< Bag<uml::Pseudostate> >
	 _entry = obj.getEntry();
	m_entry.reset(new 	 Bag<uml::Pseudostate> 
	(*(obj.getEntry().get())));

		std::shared_ptr< Bag<uml::Pseudostate> >
	 _exit = obj.getExit();
	m_exit.reset(new 	 Bag<uml::Pseudostate> 
	(*(obj.getExit().get())));

		std::shared_ptr< Bag<uml::Transition> >
	 _incoming = obj.getIncoming();
	m_incoming.reset(new 	 Bag<uml::Transition> 
	(*(obj.getIncoming().get())));

		std::shared_ptr< Bag<uml::Transition> >
	 _outgoing = obj.getOutgoing();
	m_outgoing.reset(new 	 Bag<uml::Transition> 
	(*(obj.getOutgoing().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();


    
	//Clone references with containment (deep copy)

	if(obj.getContainer()!=nullptr)
	{
		m_container.reset(dynamic_cast<uml::Region*>(obj.getContainer()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_container" << std::endl;
	#endif
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
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getState()!=nullptr)
	{
		m_state.reset(dynamic_cast<uml::State*>(obj.getState()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_state" << std::endl;
	#endif


}

ecore::EObject *  ConnectionPointReferenceImpl::copy() const
{
	return new ConnectionPointReferenceImpl(*this);
}

std::shared_ptr<ecore::EClass> ConnectionPointReferenceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectionPointReference();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 ConnectionPointReferenceImpl::entry_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 ConnectionPointReferenceImpl::exit_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Pseudostate> >
 ConnectionPointReferenceImpl::getEntry() const
{

    return m_entry;
}


	std::shared_ptr< Bag<uml::Pseudostate> >
 ConnectionPointReferenceImpl::getExit() const
{

    return m_exit;
}


std::shared_ptr<uml::State > ConnectionPointReferenceImpl::getState() const
{

    return m_state;
}
void ConnectionPointReferenceImpl::setState(std::shared_ptr<uml::State> _state)
{
    m_state = _state;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > ConnectionPointReferenceImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<uml::Namespace > ConnectionPointReferenceImpl::getNamespace() const
{
	return m_namespace;
}
		std::shared_ptr<Union<uml::Element> > ConnectionPointReferenceImpl::getOwnedElement() const
{
	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ConnectionPointReferenceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //644
		case UmlPackage::VERTEX_CONTAINER:
			return getContainer(); //6410
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //640
		case UmlPackage::CONNECTIONPOINTREFERENCE_ENTRY:
			return getEntry(); //6413
		case UmlPackage::CONNECTIONPOINTREFERENCE_EXIT:
			return getExit(); //6414
		case UmlPackage::VERTEX_INCOMING:
			return getIncoming(); //6411
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //645
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //646
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //647
		case UmlPackage::VERTEX_OUTGOING:
			return getOutgoing(); //6412
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //641
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //642
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //643
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //648
		case UmlPackage::CONNECTIONPOINTREFERENCE_STATE:
			return getState(); //6415
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //649
	}
	return boost::any();
}

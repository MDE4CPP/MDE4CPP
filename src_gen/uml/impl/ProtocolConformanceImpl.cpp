#include "ProtocolConformanceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "DirectedRelationship.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "ProtocolStateMachine.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProtocolConformanceImpl::ProtocolConformanceImpl()
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

ProtocolConformanceImpl::~ProtocolConformanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProtocolConformance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::Element > par_owner)
			:ProtocolConformanceImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ProtocolConformanceImpl::ProtocolConformanceImpl(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine)
			:ProtocolConformanceImpl()
			{
			    m_specificMachine = par_specificMachine;
			}






ProtocolConformanceImpl::ProtocolConformanceImpl(const ProtocolConformanceImpl & obj):ProtocolConformanceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProtocolConformance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_specificMachine  = obj.getSpecificMachine();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getGeneralMachine()!=nullptr)
	{
		m_generalMachine = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(obj.getGeneralMachine()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalMachine" << std::endl;
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

std::shared_ptr<ecore::EObject>  ProtocolConformanceImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ProtocolConformanceImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ProtocolConformanceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProtocolConformance();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getGeneralMachine() const
{
//assert(m_generalMachine);
    return m_generalMachine;
}
void ProtocolConformanceImpl::setGeneralMachine(std::shared_ptr<uml::ProtocolStateMachine> _generalMachine)
{
    m_generalMachine = _generalMachine;
}

std::weak_ptr<uml::ProtocolStateMachine > ProtocolConformanceImpl::getSpecificMachine() const
{
//assert(m_specificMachine);
    return m_specificMachine;
}
void ProtocolConformanceImpl::setSpecificMachine(std::shared_ptr<uml::ProtocolStateMachine> _specificMachine)
{
    m_specificMachine = _specificMachine;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > ProtocolConformanceImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ProtocolConformanceImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > ProtocolConformanceImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ProtocolConformanceImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > ProtocolConformanceImpl::getTarget() const
{
	return m_target;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProtocolConformanceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //710
		case UmlPackage::PROTOCOLCONFORMANCE_GENERALMACHINE:
			return getGeneralMachine(); //717
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //711
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //712
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //713
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //714
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //715
		case UmlPackage::PROTOCOLCONFORMANCE_SPECIFICMACHINE:
			return getSpecificMachine(); //718
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //716
	}
	return boost::any();
}

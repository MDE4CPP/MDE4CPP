#include "GeneralizationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp";

#include "Comment.hpp";

#include "DirectedRelationship.hpp";

#include "EAnnotation.hpp";

#include "Element.hpp";

#include "GeneralizationSet.hpp";


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationImpl::GeneralizationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_generalizationSet.reset(new Bag<uml::GeneralizationSet>());
	
	

	

	//Init references
	

	
	

	
}

GeneralizationImpl::~GeneralizationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Generalization "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

GeneralizationImpl::GeneralizationImpl(const GeneralizationImpl & obj):GeneralizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Generalization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isSubstitutable = obj.getIsSubstitutable();

	//copy references with no containment (soft copy)
	
		std::shared_ptr< Bag<uml::GeneralizationSet> >
	 _generalizationSet = obj.getGeneralizationSet();
	m_generalizationSet.reset(new 	 Bag<uml::GeneralizationSet> 
	(*(obj.getGeneralizationSet().get())));

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));

	m_owner  = obj.getOwner();

			std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new 		Union<uml::Element> (*(obj.getRelatedElement().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getGeneral()!=nullptr)
	{
		m_general.reset(dynamic_cast<uml::Classifier*>(obj.getGeneral()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_general" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	if(obj.getSpecific()!=nullptr)
	{
		m_specific.reset(dynamic_cast<uml::Classifier*>(obj.getSpecific()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specific" << std::endl;
	#endif


}

ecore::EObject *  GeneralizationImpl::copy() const
{
	return new GeneralizationImpl(*this);
}

std::shared_ptr<ecore::EClass> GeneralizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralization();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void GeneralizationImpl::setIsSubstitutable (bool _isSubstitutable)
{
	m_isSubstitutable = _isSubstitutable;
} 

bool GeneralizationImpl::getIsSubstitutable() const 
{
	return m_isSubstitutable;
}

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
std::shared_ptr<uml::Classifier > GeneralizationImpl::getGeneral() const
{
//assert(m_general);
    return m_general;
}
void GeneralizationImpl::setGeneral(std::shared_ptr<uml::Classifier> _general)
{
    m_general = _general;
}

	std::shared_ptr< Bag<uml::GeneralizationSet> >
 GeneralizationImpl::getGeneralizationSet() const
{

    return m_generalizationSet;
}


std::shared_ptr<uml::Classifier > GeneralizationImpl::getSpecific() const
{
//assert(m_specific);
    return m_specific;
}
void GeneralizationImpl::setSpecific(std::shared_ptr<uml::Classifier> _specific)
{
    m_specific = _specific;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > GeneralizationImpl::getOwner() const
{
	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 GeneralizationImpl::getTarget() const
{
	return m_target;
}
		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
 GeneralizationImpl::getSource() const
{
	return m_source;
}
		std::shared_ptr<Union<uml::Element> > GeneralizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
		std::shared_ptr<Union<uml::Element> > GeneralizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralizationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //950
		case UmlPackage::GENERALIZATION_GENERAL:
			return getGeneral(); //957
		case UmlPackage::GENERALIZATION_GENERALIZATIONSET:
			return getGeneralizationSet(); //958
		case UmlPackage::GENERALIZATION_ISSUBSTITUTABLE:
			return getIsSubstitutable(); //959
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //951
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //952
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //953
		case UmlPackage::RELATIONSHIP_RELATEDELEMENT:
			return getRelatedElement(); //954
		case UmlPackage::DIRECTEDRELATIONSHIP_SOURCE:
			return getSource(); //955
		case UmlPackage::GENERALIZATION_SPECIFIC:
			return getSpecific(); //9510
		case UmlPackage::DIRECTEDRELATIONSHIP_TARGET:
			return getTarget(); //956
	}
	return boost::any();
}

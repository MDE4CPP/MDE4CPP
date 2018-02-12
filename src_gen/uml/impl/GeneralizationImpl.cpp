#include "uml/impl/GeneralizationImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "uml/DirectedRelationship.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/GeneralizationSet.hpp"


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


//Additional constructor for the containments back reference
			GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Element > par_owner)
			:GeneralizationImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Classifier > par_specific)
			:GeneralizationImpl()
			{
			    m_specific = par_specific;
			}






GeneralizationImpl::GeneralizationImpl(const GeneralizationImpl & obj):GeneralizationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Generalization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_isSubstitutable = obj.getIsSubstitutable();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::GeneralizationSet> > _generalizationSet = obj.getGeneralizationSet();
	m_generalizationSet.reset(new Bag<uml::GeneralizationSet>(*(obj.getGeneralizationSet().get())));

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element> > _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));

	m_specific  = obj.getSpecific();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getGeneral()!=nullptr)
	{
		m_general = std::dynamic_pointer_cast<uml::Classifier>(obj.getGeneral()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_general" << std::endl;
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

std::shared_ptr<ecore::EObject>  GeneralizationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new GeneralizationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> GeneralizationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralization_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void GeneralizationImpl::setIsSubstitutable(bool _isSubstitutable)
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

std::shared_ptr< Bag<uml::GeneralizationSet> > GeneralizationImpl::getGeneralizationSet() const
{

    return m_generalizationSet;
}


std::weak_ptr<uml::Classifier > GeneralizationImpl::getSpecific() const
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
std::shared_ptr<Union<uml::Element> > GeneralizationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > GeneralizationImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element> > GeneralizationImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > GeneralizationImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element > > GeneralizationImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ecore::EObject> GeneralizationImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_specific.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralizationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //950
		case UmlPackage::GENERALIZATION_EREFERENCE_GENERAL:
			return getGeneral(); //957
		case UmlPackage::GENERALIZATION_EREFERENCE_GENERALIZATIONSET:
			return getGeneralizationSet(); //958
		case UmlPackage::GENERALIZATION_EATTRIBUTE_ISSUBSTITUTABLE:
			return getIsSubstitutable(); //959
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDCOMMENT:
			return getOwnedComment(); //951
		case UmlPackage::ELEMENT_EREFERENCE_OWNEDELEMENT:
			return getOwnedElement(); //952
		case UmlPackage::ELEMENT_EREFERENCE_OWNER:
			return getOwner(); //953
		case UmlPackage::RELATIONSHIP_EREFERENCE_RELATEDELEMENT:
			return getRelatedElement(); //954
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE:
			return getSource(); //955
		case UmlPackage::GENERALIZATION_EREFERENCE_SPECIFIC:
			return getSpecific(); //9510
		case UmlPackage::DIRECTEDRELATIONSHIP_EREFERENCE_TARGET:
			return getTarget(); //956
	}
	return boost::any();
}

void GeneralizationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::GENERALIZATION_EREFERENCE_GENERAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _general = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setGeneral(_general); //957
			break;
		}
		case UmlPackage::GENERALIZATION_EATTRIBUTE_ISSUBSTITUTABLE:
		{
			// BOOST CAST
			bool _isSubstitutable = boost::any_cast<bool>(newValue);
			setIsSubstitutable(_isSubstitutable); //959
			break;
		}
		case UmlPackage::GENERALIZATION_EREFERENCE_SPECIFIC:
		{
			// BOOST CAST
			std::shared_ptr<uml::Classifier> _specific = boost::any_cast<std::shared_ptr<uml::Classifier>>(newValue);
			setSpecific(_specific); //9510
			break;
		}
	}
}

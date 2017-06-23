#include "GeneralizationSetImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GeneralizationSetImpl::GeneralizationSetImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
		m_generalization.reset(new Bag<uml::Generalization>());
	
	
	
}

GeneralizationSetImpl::~GeneralizationSetImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete GeneralizationSet "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

GeneralizationSetImpl::GeneralizationSetImpl(const GeneralizationSetImpl & obj)
{
	//create copy of all Attributes
	m_isCovering = obj.getIsCovering();
	m_isDisjoint = obj.getIsDisjoint();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Generalization> >
	 _generalization = obj.getGeneralization();
	m_generalization.reset(new 	 Bag<uml::Generalization> 
	(*(obj.getGeneralization().get())));// this->getGeneralization()->insert(this->getGeneralization()->end(), _generalization->begin(), _generalization->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_powertype  = obj.getPowertype();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
}

ecore::EObject *  GeneralizationSetImpl::copy() const
{
	return new GeneralizationSetImpl(*this);
}

std::shared_ptr<ecore::EClass> GeneralizationSetImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getGeneralizationSet();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void GeneralizationSetImpl::setIsCovering (bool _isCovering)
{
	m_isCovering = _isCovering;
} 

bool GeneralizationSetImpl::getIsCovering() const 
{
	return m_isCovering;
}

void GeneralizationSetImpl::setIsDisjoint (bool _isDisjoint)
{
	m_isDisjoint = _isDisjoint;
} 

bool GeneralizationSetImpl::getIsDisjoint() const 
{
	return m_isDisjoint;
}

//*********************************
// Operations
//*********************************
bool
 GeneralizationSetImpl::generalization_same_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 GeneralizationSetImpl::maps_to_generalization_set(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Generalization> >
 GeneralizationSetImpl::getGeneralization() const
{

    return m_generalization;
}


std::shared_ptr<uml::Classifier > GeneralizationSetImpl::getPowertype() const
{

    return m_powertype;
}
void GeneralizationSetImpl::setPowertype(std::shared_ptr<uml::Classifier> _powertype)
{
    m_powertype = _powertype;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > GeneralizationSetImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > GeneralizationSetImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any GeneralizationSetImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //964
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //960
		case UmlPackage::GENERALIZATIONSET_GENERALIZATION:
			return getGeneralization(); //9615
		case UmlPackage::GENERALIZATIONSET_ISCOVERING:
			return getIsCovering(); //9612
		case UmlPackage::GENERALIZATIONSET_ISDISJOINT:
			return getIsDisjoint(); //9613
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //965
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //966
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //967
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //961
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //962
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //963
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //964
		case UmlPackage::GENERALIZATIONSET_POWERTYPE:
			return getPowertype(); //9614
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //968
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //965
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //969
	}
	return boost::any();
}

#include "uml/impl/TemplateParameterSubstitutionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ParameterableElement.hpp"

#include "uml/TemplateBinding.hpp"

#include "uml/TemplateParameter.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl()
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

TemplateParameterSubstitutionImpl::~TemplateParameterSubstitutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateParameterSubstitution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::Element > par_owner)
			:TemplateParameterSubstitutionImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(std::weak_ptr<uml::TemplateBinding > par_templateBinding)
			:TemplateParameterSubstitutionImpl()
			{
			    m_templateBinding = par_templateBinding;
			}






TemplateParameterSubstitutionImpl::TemplateParameterSubstitutionImpl(const TemplateParameterSubstitutionImpl & obj):TemplateParameterSubstitutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateParameterSubstitution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_actual  = obj.getActual();

	m_formal  = obj.getFormal();

	m_owner  = obj.getOwner();

	m_templateBinding  = obj.getTemplateBinding();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getOwnedActual()!=nullptr)
	{
		m_ownedActual = std::dynamic_pointer_cast<uml::ParameterableElement>(obj.getOwnedActual()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedActual" << std::endl;
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

std::shared_ptr<ecore::EObject>  TemplateParameterSubstitutionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new TemplateParameterSubstitutionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> TemplateParameterSubstitutionImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getTemplateParameterSubstitution();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool TemplateParameterSubstitutionImpl::must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ParameterableElement > TemplateParameterSubstitutionImpl::getActual() const
{
//assert(m_actual);
    return m_actual;
}
void TemplateParameterSubstitutionImpl::setActual(std::shared_ptr<uml::ParameterableElement> _actual)
{
    m_actual = _actual;
}

std::shared_ptr<uml::TemplateParameter > TemplateParameterSubstitutionImpl::getFormal() const
{
//assert(m_formal);
    return m_formal;
}
void TemplateParameterSubstitutionImpl::setFormal(std::shared_ptr<uml::TemplateParameter> _formal)
{
    m_formal = _formal;
}

std::shared_ptr<uml::ParameterableElement > TemplateParameterSubstitutionImpl::getOwnedActual() const
{

    return m_ownedActual;
}
void TemplateParameterSubstitutionImpl::setOwnedActual(std::shared_ptr<uml::ParameterableElement> _ownedActual)
{
    m_ownedActual = _ownedActual;
}

std::weak_ptr<uml::TemplateBinding > TemplateParameterSubstitutionImpl::getTemplateBinding() const
{
//assert(m_templateBinding);
    return m_templateBinding;
}
void TemplateParameterSubstitutionImpl::setTemplateBinding(std::shared_ptr<uml::TemplateBinding> _templateBinding)
{
    m_templateBinding = _templateBinding;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element> > TemplateParameterSubstitutionImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > TemplateParameterSubstitutionImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ecore::EObject> TemplateParameterSubstitutionImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_templateBinding.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any TemplateParameterSubstitutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_ACTUAL:
			return getActual(); //224
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //220
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_FORMAL:
			return getFormal(); //225
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_OWNEDACTUAL:
			return getOwnedActual(); //226
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //221
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //222
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //223
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_TEMPLATEBINDING:
			return getTemplateBinding(); //227
	}
	return boost::any();
}

void TemplateParameterSubstitutionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_ACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _actual = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setActual(_actual); //224
			break;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_FORMAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateParameter> _formal = boost::any_cast<std::shared_ptr<uml::TemplateParameter>>(newValue);
			setFormal(_formal); //225
			break;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_OWNEDACTUAL:
		{
			// BOOST CAST
			std::shared_ptr<uml::ParameterableElement> _ownedActual = boost::any_cast<std::shared_ptr<uml::ParameterableElement>>(newValue);
			setOwnedActual(_ownedActual); //226
			break;
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_TEMPLATEBINDING:
		{
			// BOOST CAST
			std::shared_ptr<uml::TemplateBinding> _templateBinding = boost::any_cast<std::shared_ptr<uml::TemplateBinding>>(newValue);
			setTemplateBinding(_templateBinding); //227
			break;
		}
	}
}

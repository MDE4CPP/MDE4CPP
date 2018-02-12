#include "ecore/impl/EModelElementImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/impl/EcorePackageImpl.hpp"

//Forward declaration includes
#include "ecore/EAnnotation.hpp"


using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EModelElementImpl::EModelElementImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_eAnnotations.reset(new Bag<ecore::EAnnotation>());
	
	

	//Init references
	
	
}

EModelElementImpl::~EModelElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EModelElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj):EModelElementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EModelElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

	
	
}

std::shared_ptr<ecore::EObject>  EModelElementImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EModelElementImpl(*this));
	return element;
}

std::shared_ptr<EClass> EModelElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEModelElement_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EAnnotation> EModelElementImpl::getEAnnotation(std::string source) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for(std::shared_ptr<EAnnotation> a : *m_eAnnotations)
    {
	    if(a->getSource()==source)
	    {
		    return a;
	    }
    }
    return std::shared_ptr<ecore::EAnnotation>();
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr< Bag<ecore::EAnnotation> > EModelElementImpl::getEAnnotations() const
{

    return m_eAnnotations;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> EModelElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EModelElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EREFERENCE_EANNOTATIONS:
			return getEAnnotations(); //80
	}
	return boost::any();
}

void EModelElementImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
	}
}

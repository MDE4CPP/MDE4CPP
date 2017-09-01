#include "EModelElementImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "EcorePackageImpl.hpp"

//Forward declaration includes
#include "EAnnotation.hpp"


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
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif

	
	

}

ecore::EObject *  EModelElementImpl::copy() const
{
	return new EModelElementImpl(*this);
}

std::shared_ptr<EClass> EModelElementImpl::eStaticClass() const
{
	return EcorePackageImpl::eInstance()->getEModelElement();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EAnnotation> EModelElementImpl::getEAnnotation(std::string source) 
{
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


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EModelElementImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //80
	}
	return boost::any();
}

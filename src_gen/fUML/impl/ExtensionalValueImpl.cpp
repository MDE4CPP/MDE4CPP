#include "ExtensionalValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"

//Forward declaration includes
#include "CompoundValue.hpp";

#include "FeatureValue.hpp";

#include "Locus.hpp";


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionalValueImpl::ExtensionalValueImpl()
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

ExtensionalValueImpl::~ExtensionalValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionalValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ExtensionalValueImpl::ExtensionalValueImpl(const ExtensionalValueImpl & obj):ExtensionalValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionalValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif


}

ecore::EObject *  ExtensionalValueImpl::copy() const
{
	return new ExtensionalValueImpl(*this);
}

std::shared_ptr<ecore::EClass> ExtensionalValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExtensionalValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ExtensionalValueImpl::destroy() 
{
	//generated from body annotation
	if(this->getLocus() != nullptr)
    {
		struct null_deleter{void operator()(void const *) const { } };
        this->getLocus()->remove(std::shared_ptr<ExtensionalValue>(this, null_deleter()));
    }
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Locus > ExtensionalValueImpl::getLocus() const
{

    return m_locus;
}
void ExtensionalValueImpl::setLocus(std::shared_ptr<fUML::Locus> _locus)
{
    m_locus = _locus;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionalValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //210
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //211
	}
	return boost::any();
}

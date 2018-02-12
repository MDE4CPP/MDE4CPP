#include "fUML/impl/ExtensionalValueImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "fUML/CompoundValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"


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
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExtensionalValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ExtensionalValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ExtensionalValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getExtensionalValue_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExtensionalValueImpl::destroy() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getLocus() != nullptr)
    {
		struct null_deleter{void operator()(void const *) const { } };
        this->getLocus()->remove(std::shared_ptr<ExtensionalValue>(this, null_deleter()));
    }
	//end of body
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


std::shared_ptr<ecore::EObject> ExtensionalValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ExtensionalValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_EREFERENCE_FEATUREVALUES:
			return getFeatureValues(); //210
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
			return getLocus(); //211
	}
	return boost::any();
}

void ExtensionalValueImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //211
			break;
		}
	}
}

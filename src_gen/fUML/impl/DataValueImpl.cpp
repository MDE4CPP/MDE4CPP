#include "DataValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
#include "DataValue.hpp"
#include "UmlFactory.hpp"
#include "FUMLFactory.hpp"
#include "CompoundValue.hpp"
#include "DataType.hpp"
#include "Classifier.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "CompoundValue.hpp"

#include "DataType.hpp"

#include "FeatureValue.hpp"

#include "Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DataValueImpl::DataValueImpl()
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

DataValueImpl::~DataValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




DataValueImpl::DataValueImpl(const DataValueImpl & obj):DataValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_type  = obj.getType();


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

std::shared_ptr<ecore::EObject>  DataValueImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DataValueImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DataValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataValue();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Classifier> > DataValueImpl::getTypes() 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
    types->push_back(std::dynamic_pointer_cast<uml::Classifier>(this->getType()));
    return types;
	//end of body
}

std::shared_ptr<fUML::Value> DataValueImpl::new_() 
{
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createDataValue());
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::DataType > DataValueImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void DataValueImpl::setType(std::shared_ptr<uml::DataType> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DataValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //340
		case FUMLPackage::DATAVALUE_TYPE:
			return getType(); //341
	}
	return boost::any();
}

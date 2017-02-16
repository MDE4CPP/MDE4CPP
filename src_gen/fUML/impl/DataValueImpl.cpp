#include "DataValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "DataValue.hpp"
#include "UmlFactory.hpp"
#include "FUMLFactory.hpp"
#include "CompoundValue.hpp"
#include "DataType.hpp"
#include "Classifier.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DataValueImpl::DataValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

DataValueImpl::~DataValueImpl()
{
	
}

DataValueImpl::DataValueImpl(const DataValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_type  = obj.getType();


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
}

ecore::EObject *  DataValueImpl::copy() const
{
	return new DataValueImpl(*this);
}

ecore::EClass* DataValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::vector<uml::Classifier * > *  DataValueImpl::getTypes() 
{
	//generated from body annotation
	    std::vector<uml::Classifier * > * types = new std::vector<uml::Classifier * >();
    types->push_back(dynamic_cast<uml::Classifier * >(this->getType()));

    return types;
}

fUML::Value *  DataValueImpl::new_() 
{
	//generated from body annotation
	    return FUMLFactory::eInstance()->createDataValue();
}

//*********************************
// References
//*********************************
uml::DataType *  DataValueImpl::getType() const
{
	//assert(m_type);
	return m_type;
}
void DataValueImpl::setType(uml::DataType *  _type)
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

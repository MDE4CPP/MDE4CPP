#include "FeatureValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "StructuralFeature.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
FeatureValueImpl::FeatureValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_values == nullptr)
	{
		m_values = new std::vector<fUML::Value * >();
	}
}

FeatureValueImpl::~FeatureValueImpl()
{
	if(m_values!=nullptr)
	{
		for(auto c :*m_values)
		{
			delete(c);
			c = 0;
		}
	}
	
}

FeatureValueImpl::FeatureValueImpl(const FeatureValueImpl & obj)
{
	//create copy of all Attributes
	m_position = obj.getPosition();

	//copy references with now containment
	
	m_feature  = obj.getFeature();


	//clone containt lists
	for(fUML::Value * 	_values : *obj.getValues())
	{
		this->getValues()->push_back(dynamic_cast<fUML::Value * >(_values->copy()));
	}
}

ecore::EObject *  FeatureValueImpl::copy() const
{
	return new FeatureValueImpl(*this);
}

ecore::EClass* FeatureValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getFeatureValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void FeatureValueImpl::setPosition (int _position)
{
	m_position = _position;
} 

int FeatureValueImpl::getPosition() const 
{
	return m_position;
}

//*********************************
// Operations
//*********************************
bool FeatureValueImpl::hasEqualValues(fUML::FeatureValue *  other) 
{
	//generated from body annotation
	    bool equal = true;

    if(this->getValues()->size() != other->getValues()->size())
    {
        equal = false;

    }
    else
    {
        uml::StructuralFeature* feature = this->getFeature();
        if(feature->getIsOrdered())
        {
            int i = 1;
            while(equal && (i <= this->getValues()->size()))
            {
                equal = this->getValues()->at(i - 1)->equals(other->getValues()->at(i - 1));
                i = i + 1;
            }

        }
        else
        {
            FeatureValue * otherFeatureValues = FUMLFactory::eInstance()->createFeatureValue();
            std::vector<Value * > * values = other->getValues();
            for(unsigned int i = 0; i < values->size(); i++)
            {
                Value * value = values->at(i);
                otherFeatureValues->getValues()->push_back(value);
            }

            int i = 1;
            while(equal && (i <= this->getValues()->size()))
            {
                bool matched = false;
                int j = 1;
                while(!matched && (j <= otherFeatureValues->getValues()->size()))
                {
                    if(this->getValues()->at(i - 1)->equals(otherFeatureValues->getValues()->at(j - 1)))
                    {
                        matched = true;
                        otherFeatureValues->getValues()->erase(otherFeatureValues->getValues()->begin() + j - 1);
                    }
                    j = j + 1;
                }

                equal = matched;
                i = i + 1;
            }
        }
    }

    return equal;
}

//*********************************
// References
//*********************************
uml::StructuralFeature *  FeatureValueImpl::getFeature() const
{
	//assert(m_feature);
	return m_feature;
}
void FeatureValueImpl::setFeature(uml::StructuralFeature *  _feature)
{
	m_feature = _feature;
}

std::vector<fUML::Value * > *  FeatureValueImpl::getValues() const
{
	
	return m_values;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FeatureValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::FEATUREVALUE_FEATURE:
			return getFeature(); //142
		case FUMLPackage::FEATUREVALUE_POSITION:
			return getPosition(); //141
		case FUMLPackage::FEATUREVALUE_VALUES:
			return getValues(); //140
	}
	return boost::any();
}

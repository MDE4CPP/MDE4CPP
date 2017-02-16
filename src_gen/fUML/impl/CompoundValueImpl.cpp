#include "CompoundValueImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Classifier.hpp"
#include <FUMLFactory.hpp>
#include <cstdio>

#include "StructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CompoundValueImpl::CompoundValueImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	if( m_featureValues == nullptr)
	{
		m_featureValues = new std::vector<fUML::FeatureValue * >();
	}
}

CompoundValueImpl::~CompoundValueImpl()
{
	if(m_featureValues!=nullptr)
	{
		for(auto c :*m_featureValues)
		{
			delete(c);
			c = 0;
		}
	}
	
}

CompoundValueImpl::CompoundValueImpl(const CompoundValueImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
}

ecore::EObject *  CompoundValueImpl::copy() const
{
	return new CompoundValueImpl(*this);
}

ecore::EClass* CompoundValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCompoundValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void CompoundValueImpl::assignFeatureValue(uml::StructuralFeature *  feature,std::vector<fUML::Value * > *  values,int position) 
{
	//generated from body annotation
	    fUML::FeatureValue * featureValue = this->retrieveFeatureValue(feature);

    if(featureValue == nullptr)
    {
        featureValue = FUMLFactory::eInstance()->createFeatureValue();
        this->getFeatureValues()->push_back(featureValue);
    }

    featureValue->setFeature(feature);
    std::vector<fUML::Value*>::iterator i;
    for(i=values->begin();i!=values->end();++i)
    {featureValue->getValues()->push_back(*i);}
    featureValue->setPosition(position);
}

bool CompoundValueImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    bool isEqual = (dynamic_cast<CompoundValue*>(otherValue )!=nullptr);

    if (isEqual) {

        CompoundValue* otherCompoundValue = dynamic_cast<CompoundValue*>(otherValue );

        isEqual = StructuredValueImpl::equals(otherValue)
                && otherCompoundValue->getFeatureValues()->size() == this->getFeatureValues()->size();

        unsigned int i = 1;
        while (isEqual && i <= this->getFeatureValues()->size()) {
            FeatureValue * thisFeatureValue = this->getFeatureValues()->at(i - 1);

            bool matched = false;
            unsigned int j = 1;
            while (!matched && j <= otherCompoundValue->getFeatureValues()->size()) {
                FeatureValue * otherFeatureValue = otherCompoundValue->getFeatureValues()->at(j - 1);
                if (thisFeatureValue->getFeature() == otherFeatureValue->getFeature()) {
                    matched = thisFeatureValue->hasEqualValues(otherFeatureValue);
                }
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
}

void CompoundValueImpl::removeFeatureValues(uml::Classifier *  classifier) 
{
	//generated from body annotation
	std::remove_if(this->getFeatureValues()->begin(),this->getFeatureValues()->end(),[classifier](FeatureValue * featureValue){return featureValue->getFeature()->getType()==classifier;});
}

fUML::FeatureValue *  CompoundValueImpl::retrieveFeatureValue(uml::StructuralFeature *  feature) 
{
	//generated from body annotation
	    fUML::FeatureValue * featureValue = nullptr;
    unsigned int i = 1;
    while(featureValue == nullptr && i <= this->getFeatureValues()->size())
    {
        if(this->getFeatureValues()->at(i - 1)->getFeature() == feature)
        {
            featureValue = this->getFeatureValues()->at(i - 1);
        }
        i = i + 1;
    }

    return featureValue;
}

std::vector<fUML::FeatureValue * > *  CompoundValueImpl::retrieveFeatureValues() 
{
	//generated from body annotation
	 return this->getFeatureValues();
}

std::string CompoundValueImpl::toString() 
{
	//generated from body annotation
	    std::string buffer = "(" + this->objectId() + ":";

    std::vector<uml::Classifier *>* types = this->getTypes();

    unsigned int i = 1;
    while(i <= types->size())
    {
        buffer = buffer + " " + types->at(i - 1)->getName();
        i = i + 1;
    }

    unsigned int k = 1;
    while(k <= this->getFeatureValues()->size())
    {
        FeatureValue * featureValue = this->getFeatureValues()->at(k - 1);
        char buf [11];
        std::sprintf(buf, "%d", featureValue->getPosition(), buf, 10);
        buffer = buffer + "\n\t\t" + featureValue->getFeature()->getName() + "[" + std::string(buf) + "]  =";

        unsigned int j = 1;
        while(j <= featureValue->getValues()->size())
        {
            buffer = buffer + " " + featureValue->getValues()->at(j - 1)->toString();
            j = j + 1;
        }

        k = k + 1;
    }

    return buffer + ")";
}

//*********************************
// References
//*********************************
std::vector<fUML::FeatureValue * > *  CompoundValueImpl::getFeatureValues() const
{
	
	return m_featureValues;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any CompoundValueImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //130
	}
	return boost::any();
}

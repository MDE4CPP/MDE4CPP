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

//Forward declaration includes
#include "Classifier.hpp"

#include "FeatureValue.hpp"

#include "StructuralFeature.hpp"

#include "StructuredValue.hpp"

#include "Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
CompoundValueImpl::CompoundValueImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_featureValues.reset(new Bag<fUML::FeatureValue>());
	
	

	//Init references
	
	
}

CompoundValueImpl::~CompoundValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CompoundValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

CompoundValueImpl::CompoundValueImpl(const CompoundValueImpl & obj):CompoundValueImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CompoundValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

    
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

ecore::EObject *  CompoundValueImpl::copy() const
{
	return new CompoundValueImpl(*this);
}

std::shared_ptr<ecore::EClass> CompoundValueImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getCompoundValue();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 CompoundValueImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position) 
{
	//generated from body annotation
	std::shared_ptr<fUML::FeatureValue> featureValue = this->retrieveFeatureValue(feature);
    if(featureValue == nullptr)
    {
        featureValue.reset(FUMLFactory::eInstance()->createFeatureValue());
        this->getFeatureValues()->push_back(featureValue);
    }
    featureValue->setFeature(feature);
    std::vector<std::shared_ptr<fUML::Value>>::iterator i;
    for(i=values->begin();i!=values->end();++i)
    {
    	featureValue->getValues()->push_back(*i);
    }
    featureValue->setPosition(position);
}

bool
 CompoundValueImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
		std::shared_ptr<CompoundValue> otherCompoundValue = std::dynamic_pointer_cast<CompoundValue>(otherValue);
	bool isEqual = (otherCompoundValue != nullptr);
    if (isEqual)
    {
        isEqual = StructuredValueImpl::equals(otherValue)
                && otherCompoundValue->getFeatureValues()->size() == this->getFeatureValues()->size();

        unsigned int i = 0;
        while (isEqual && i < this->getFeatureValues()->size())
        {
        	std::shared_ptr<FeatureValue> thisFeatureValue = this->getFeatureValues()->at(i);

            bool matched = false;
            unsigned int j = 0;
            while (!matched && j < otherCompoundValue->getFeatureValues()->size())
            {
            	std::shared_ptr<FeatureValue> otherFeatureValue = otherCompoundValue->getFeatureValues()->at(j);
                if (thisFeatureValue->getFeature() == otherFeatureValue->getFeature())
                {
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

void
 CompoundValueImpl::removeFeatureValues(std::shared_ptr<uml::Classifier>  classifier) 
{
	//generated from body annotation
	std::remove_if(this->getFeatureValues()->begin(),this->getFeatureValues()->end(),[classifier](std::shared_ptr<FeatureValue> featureValue){return featureValue->getFeature()->getType()==classifier;});
}

std::shared_ptr<fUML::FeatureValue> 
 CompoundValueImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) 
{
	//generated from body annotation
	    std::shared_ptr<fUML::FeatureValue> featureValue = nullptr;
    unsigned int i = 0;
    while(featureValue == nullptr && i < this->getFeatureValues()->size())
    {
        if(this->getFeatureValues()->at(i)->getFeature() == feature)
        {
            featureValue = this->getFeatureValues()->at(i);
        }
        i = i + 1;
    }
    return featureValue;
}

std::shared_ptr<Bag<fUML::FeatureValue> >
 CompoundValueImpl::retrieveFeatureValues() 
{
	//generated from body annotation
	 return this->getFeatureValues();
}

std::string
 CompoundValueImpl::toString() 
{
	//generated from body annotation
		std::string buffer = "(" + this->objectId() + ":";

	std::shared_ptr<Bag<uml::Classifier> > types = this->getTypes();

    unsigned int i = 0;
    while(i < types->size())
    {
        buffer = buffer + " " + types->at(i)->getName();
        i = i + 1;
    }

    unsigned int k = 0;
    while(k < this->getFeatureValues()->size())
    {
    	std::shared_ptr<FeatureValue> featureValue = this->getFeatureValues()->at(k);
        char buf [11];
        std::sprintf(buf, "%d", featureValue->getPosition());
        buffer = buffer + "\n\t\t" + featureValue->getFeature()->getName() + "[" + std::string(buf) + "]  =";

        unsigned int j = 0;
        while(j < featureValue->getValues()->size())
        {
            buffer = buffer + " " + featureValue->getValues()->at(j)->toString();
            j = j + 1;
        }

        k = k + 1;
    }

    return buffer + ")";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<fUML::FeatureValue> >
 CompoundValueImpl::getFeatureValues() const
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

#include "ReferenceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <Classifier.hpp>
    #include "FUMLFactory.hpp"
    #include "Class.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ReferenceImpl::ReferenceImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
}

ReferenceImpl::~ReferenceImpl()
{
	
}

ReferenceImpl::ReferenceImpl(const ReferenceImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_referent  = obj.getReferent();


	//clone containt lists
}

ecore::EObject *  ReferenceImpl::copy() const
{
	return new ReferenceImpl(*this);
}

ecore::EClass* ReferenceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReference();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ReferenceImpl::assignFeatureValue(uml::StructuralFeature *  feature,std::vector<fUML::Value * > *  values,int position) 
{
	//generated from body annotation
	return this->getReferent()->assignFeatureValue(feature,values,position);
}

void ReferenceImpl::destroy() 
{
	//generated from body annotation
	this->getReferent()->destroy();
}

fUML::Execution *  ReferenceImpl::dispatch(uml::Operation *  operation) 
{
	//generated from body annotation
	return this->getReferent()->dispatch(operation);
}

bool ReferenceImpl::equals(fUML::Value *  otherValue) 
{
	//generated from body annotation
	    std::vector<uml::Classifier*>  * myTypes = nullptr;//this->getTypes();
    std::vector<uml::Classifier*>  * otherTypes = nullptr;//otherValue->getTypes();

    bool isEqual = true;

    // Debug.println("[equals] Value...");
    // Debug.println("[equals] this has " + myTypes.size() +
    // "types, other has " + otherTypes.size() + ".");
    if(myTypes->size() != otherTypes->size())
    {
        isEqual = false;

    }
    else
    {
        // Debug.println("[equals] " + myTypes.size() + " type(s).");

        int i = 1;
        while(isEqual && i <= myTypes->size())
        {

            // Debug.println("[equals] this type = " +
            // myTypes.getValue(i-1).name);

            bool matched = false;
            unsigned int j = 1;
            while(!matched && j <= otherTypes->size())
            {
                // Debug.println("[equals] other type = " +
                // otherTypes.getValue(j-1).name);
                matched = (otherTypes->at(j - 1) == myTypes->at(i - 1));
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
}

std::vector<uml::Classifier * > *  ReferenceImpl::getTypes() 
{
	//generated from body annotation
		return  this->getReferent()->getTypes();
}

fUML::Value *  ReferenceImpl::new_() 
{
	//generated from body annotation
	    return FUMLFactory::eInstance()->createReference();
}

fUML::FeatureValue *  ReferenceImpl::retrieveFeatureValue(uml::StructuralFeature *  feature) 
{
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValue(feature);
}

std::vector<fUML::FeatureValue * > *  ReferenceImpl::retrieveFeatureValues() 
{
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValues();
}

void ReferenceImpl::send(fUML::SignalInstance *  signalInstance) 
{
	//generated from body annotation
	this->getReferent()->send(signalInstance);
}

void ReferenceImpl::startBehavior(uml::Class *  classifier,std::vector<fUML::ParameterValue * > *  inputs) 
{
	//generated from body annotation
	this->getReferent()->startBehavior(classifier,inputs);
}

std::string ReferenceImpl::toString() 
{
	//generated from body annotation
	return "Reference to " + this->getReferent()->toString();
}

//*********************************
// References
//*********************************
fUML::Object *  ReferenceImpl::getReferent() const
{
	//assert(m_referent);
	return m_referent;
}
void ReferenceImpl::setReferent(fUML::Object *  _referent)
{
	m_referent = _referent;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ReferenceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::REFERENCE_REFERENT:
			return getReferent(); //120
	}
	return boost::any();
}

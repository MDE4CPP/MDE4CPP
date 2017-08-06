#include "ReferenceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include <Classifier.hpp>
    #include "FUMLFactory.hpp"
    #include "Class.hpp"

//Forward declaration includes
#include "Class.hpp"

#include "Classifier.hpp"

#include "Execution.hpp"

#include "FeatureValue.hpp"

#include "Object.hpp"

#include "Operation.hpp"

#include "ParameterValue.hpp"

#include "SignalInstance.hpp"

#include "StructuralFeature.hpp"

#include "StructuredValue.hpp"

#include "Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ReferenceImpl::ReferenceImpl()
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

ReferenceImpl::~ReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Reference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ReferenceImpl::ReferenceImpl(const ReferenceImpl & obj):ReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Reference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_referent  = obj.getReferent();


    
	//Clone references with containment (deep copy)



}

ecore::EObject *  ReferenceImpl::copy() const
{
	return new ReferenceImpl(*this);
}

std::shared_ptr<ecore::EClass> ReferenceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReference();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 ReferenceImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position) 
{
	//generated from body annotation
	return this->getReferent()->assignFeatureValue(feature,values,position);
}

void
 ReferenceImpl::destroy() 
{
	//generated from body annotation
	this->getReferent()->destroy();
}

std::shared_ptr<fUML::Execution> 
 ReferenceImpl::dispatch(std::shared_ptr<uml::Operation>  operation) 
{
	//generated from body annotation
	return this->getReferent()->dispatch(operation);
}

bool
 ReferenceImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > myTypes = nullptr;//this->getTypes();
	std::shared_ptr<Bag<uml::Classifier> > otherTypes = nullptr;//otherValue->getTypes();

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
        unsigned int i = 0;
	const unsigned int i_size =  myTypes->size();
        while(isEqual && i < i_size)
        {
            // Debug.println("[equals] this type = " +
            // myTypes.getValue(i).name);

            bool matched = false;
            unsigned int j = 0;
	     const unsigned int j_size = otherTypes->size();
            while(!matched && j < j_size)
            {
                // Debug.println("[equals] other type = " +
                // otherTypes.getValue(j).name);
                matched = (otherTypes->at(j) == myTypes->at(i));
                j = j + 1;
            }

            isEqual = matched;
            i = i + 1;
        }
    }

    return isEqual;
}

std::shared_ptr<Bag<uml::Classifier> >
 ReferenceImpl::getTypes() 
{
	//generated from body annotation
		return  this->getReferent()->getTypes();
}

std::shared_ptr<fUML::Value> 
 ReferenceImpl::new_() 
{
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createReference());
}

std::shared_ptr<fUML::FeatureValue> 
 ReferenceImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) 
{
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValue(feature);
}

std::shared_ptr<Bag<fUML::FeatureValue> >
 ReferenceImpl::retrieveFeatureValues() 
{
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValues();
}

void
 ReferenceImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	//generated from body annotation
	this->getReferent()->send(signalInstance);
}

void
 ReferenceImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	//generated from body annotation
	this->getReferent()->startBehavior(classifier,inputs);
}

std::string
 ReferenceImpl::toString() 
{
	//generated from body annotation
	return "Reference to " + this->getReferent()->toString();
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Object > ReferenceImpl::getReferent() const
{
//assert(m_referent);
    return m_referent;
}
void ReferenceImpl::setReferent(std::shared_ptr<fUML::Object> _referent)
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

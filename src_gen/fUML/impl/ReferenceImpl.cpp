#include "ReferenceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "FUMLPackageImpl.hpp"
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

std::shared_ptr<ecore::EObject>  ReferenceImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ReferenceImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ReferenceImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getReference();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ReferenceImpl::assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->assignFeatureValue(feature,values,position);
	//end of body
}

void ReferenceImpl::destroy() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->destroy();
	//end of body
}

std::shared_ptr<fUML::Execution> ReferenceImpl::dispatch(std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->dispatch(operation);
	//end of body
}

bool ReferenceImpl::equals(std::shared_ptr<fUML::Value>  otherValue) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;
	if (otherValue->eClass()->getClassifierID() == fUML::FUMLPackage::REFERENCE) {
		auto other = std::dynamic_pointer_cast<Reference>(otherValue);
		if (this->getReferent() == nullptr) {
			isEqual = other->getReferent() == nullptr;
		} else {
			isEqual = this->getReferent()->equals(other->getReferent());
		}
	}
	return isEqual;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ReferenceImpl::getTypes() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		return  this->getReferent()->getTypes();
	//end of body
}

std::shared_ptr<fUML::Value> ReferenceImpl::new_() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createReference());
	//end of body
}

std::shared_ptr<fUML::FeatureValue> ReferenceImpl::retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValue(feature);
	//end of body
}

std::shared_ptr<Bag<fUML::FeatureValue> > ReferenceImpl::retrieveFeatureValues() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getReferent()->retrieveFeatureValues();
	//end of body
}

void ReferenceImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->send(signalInstance);
	//end of body
}

void ReferenceImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getReferent()->startBehavior(classifier,inputs);
	//end of body
}

std::string ReferenceImpl::toString() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "Reference to " + this->getReferent()->toString();
	//end of body
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

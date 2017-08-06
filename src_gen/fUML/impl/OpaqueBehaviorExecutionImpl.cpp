#include "OpaqueBehaviorExecutionImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "ParameterValue.hpp"
#include "Behavior.hpp"
#include "Parameter.hpp"
#include "ParameterDirectionKind.hpp"
#include "FUMLFactory.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Execution.hpp"

#include "FeatureValue.hpp"

#include "Locus.hpp"

#include "Object.hpp"

#include "ObjectActivation.hpp"

#include "ParameterValue.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl()
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

OpaqueBehaviorExecutionImpl::~OpaqueBehaviorExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueBehaviorExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

OpaqueBehaviorExecutionImpl::OpaqueBehaviorExecutionImpl(const OpaqueBehaviorExecutionImpl & obj):OpaqueBehaviorExecutionImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueBehaviorExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_context  = obj.getContext();

	m_locus  = obj.getLocus();

		std::shared_ptr< Bag<uml::Classifier> >
	 _types = obj.getTypes();
	m_types.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getTypes().get())));


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation.reset(dynamic_cast<fUML::ObjectActivation*>(obj.getObjectActivation()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(dynamic_cast<fUML::ParameterValue*>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif


}

ecore::EObject *  OpaqueBehaviorExecutionImpl::copy() const
{
	return new OpaqueBehaviorExecutionImpl(*this);
}

std::shared_ptr<ecore::EClass> OpaqueBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOpaqueBehaviorExecution();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void
 OpaqueBehaviorExecutionImpl::doBody(std::shared_ptr<Bag<fUML::ParameterValue> >  inputParameters,std::shared_ptr<Bag<fUML::ParameterValue> >  outputParameters) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void
 OpaqueBehaviorExecutionImpl::execute() 
{
	//generated from body annotation
	DEBUG_MESSAGE(std::cout<<"[execute] Opaque behavior " << this->getBehavior()->getName() << "..."<<std::endl;)

	std::shared_ptr<Bag<ParameterValue> > inputs(new Bag<ParameterValue>());
	std::shared_ptr<Bag<ParameterValue> > outputs(new Bag<ParameterValue>());

	std::shared_ptr<Bag<uml::Parameter> > parameterList = this->getBehavior()->getOwnedParameter();
    for(std::shared_ptr<uml::Parameter> parameter : *parameterList) 
    {
        DEBUG_MESSAGE(std::cout<<parameter->getName()<< " Parameter Direction: " << parameter->getDirection()<<std::endl;)
        if ((parameter->getDirection() == uml::ParameterDirectionKind::IN)
                || (parameter->getDirection() == uml::ParameterDirectionKind::INOUT)) 
        {
            inputs->push_back(this->getParameterValue(parameter));
        }

        if ((parameter->getDirection() == uml::ParameterDirectionKind::INOUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::OUT)
                || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN)) 
        {
        	std::shared_ptr<ParameterValue> parameterValue(fUML::FUMLFactory::eInstance()->createParameterValue());
            parameterValue->setParameter(parameter);

            if(parameter->getDirection() != uml::ParameterDirectionKind::INOUT)
            {
                //Otherwise the input parameter is removed (memory leak).
                this->setParameterValue(parameterValue);
            }

            outputs->push_back(parameterValue);
        }
    }

    this->doBody(inputs, outputs);
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OpaqueBehaviorExecutionImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_CONTEXT:
			return getContext(); //404
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //400
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //401
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
			return getObjectActivation(); //403
		case FUMLPackage::EXECUTION_PARAMETERVALUES:
			return getParameterValues(); //405
		case FUMLPackage::OBJECT_TYPES:
			return getTypes(); //402
	}
	return boost::any();
}

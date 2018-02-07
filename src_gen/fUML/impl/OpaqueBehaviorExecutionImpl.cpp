#include "fUML/impl/OpaqueBehaviorExecutionImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fuml/ParameterValue.hpp"
#include "uml/Behavior.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "fuml/FUMLFactory.hpp"

//Forward declaration includes
#include "uml/Classifier.hpp"

#include "fUML/Execution.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/Object.hpp"

#include "fUML/ObjectActivation.hpp"

#include "fUML/ParameterValue.hpp"


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

	std::shared_ptr< Bag<uml::Classifier> > _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::FeatureValue>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->add(std::shared_ptr<fUML::FeatureValue>(std::dynamic_pointer_cast<fUML::FeatureValue>(_featureValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_featureValues" << std::endl;
	#endif
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_objectActivation" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ParameterValue>> _parameterValuesList = obj.getParameterValues();
	for(std::shared_ptr<fUML::ParameterValue> _parameterValues : *_parameterValuesList)
	{
		this->getParameterValues()->add(std::shared_ptr<fUML::ParameterValue>(std::dynamic_pointer_cast<fUML::ParameterValue>(_parameterValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_parameterValues" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  OpaqueBehaviorExecutionImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new OpaqueBehaviorExecutionImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueBehaviorExecutionImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getOpaqueBehaviorExecution();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void OpaqueBehaviorExecutionImpl::doBody(std::shared_ptr<Bag<fUML::ParameterValue> >  inputParameters,std::shared_ptr<Bag<fUML::ParameterValue> >  outputParameters) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void OpaqueBehaviorExecutionImpl::execute() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
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
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> OpaqueBehaviorExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any OpaqueBehaviorExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void OpaqueBehaviorExecutionImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXECUTION_CONTEXT:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Object> _context = boost::any_cast<std::shared_ptr<fUML::Object>>(newValue);
			setContext(_context); //404
			break;
		}
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //401
			break;
		}
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ObjectActivation> _objectActivation = boost::any_cast<std::shared_ptr<fUML::ObjectActivation>>(newValue);
			setObjectActivation(_objectActivation); //403
			break;
		}
	}
}

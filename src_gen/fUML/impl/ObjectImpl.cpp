#include "fUML/impl/ObjectImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/DispatchStrategy.hpp"
#include "fUML/ExecutionFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/UmlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/EventAccepter.hpp"

#include "fUML/Execution.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/FeatureValue.hpp"

#include "fUML/Locus.hpp"

#include "fUML/ObjectActivation.hpp"

#include "uml/Operation.hpp"

#include "fUML/ParameterValue.hpp"

#include "fUML/SignalInstance.hpp"

#include "fUML/Value.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ObjectImpl::ObjectImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_types.reset(new Bag<uml::Classifier>());
	
	

	//Init references
	

	
	
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}




ObjectImpl::ObjectImpl(const ObjectImpl & obj):ObjectImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_locus  = obj.getLocus();

	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
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

	
}

std::shared_ptr<ecore::EObject>  ObjectImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new ObjectImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObject_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectImpl::_register(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->_register(accepter);
    }
	//end of body
}

void ObjectImpl::destroy() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->stop();
        this->setObjectActivation(nullptr);
    }

    this->getTypes()->clear();
    ExtensionalValueImpl::destroy();
	//end of body
}

std::shared_ptr<fUML::Execution> ObjectImpl::dispatch(std::shared_ptr<uml::Operation>  operation) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	static std::shared_ptr<DispatchStrategy> strategy = std::dynamic_pointer_cast<DispatchStrategy>(this->getLocus()->getFactory()->getStrategy("dispatch"));
	return strategy->dispatch(getThisObjectPtr(), operation);
	//end of body
}

std::shared_ptr<fUML::Value> ObjectImpl::new_() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createObject());
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
	//end of body
}

void ObjectImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getObjectActivation() == nullptr)
    {
        this->setObjectActivation(std::shared_ptr<ObjectActivation>(fUML::FUMLFactory::eInstance()->createObjectActivation()));
        this->getObjectActivation()->setObject(getThisObjectPtr());
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
	//end of body
}

void ObjectImpl::unregister(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->unregister(accepter);
    }
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ObjectActivation > ObjectImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ObjectImpl::setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}

std::shared_ptr<Bag<uml::Classifier>> ObjectImpl::getTypes() const
{

    return m_types;
}


//*********************************
// Union Getter
//*********************************


std::shared_ptr<Object> ObjectImpl::getThisObjectPtr()
{
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<Object>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_EREFERENCE_FEATUREVALUES:
			return getFeatureValues(); //370
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
			return getLocus(); //371
		case FUMLPackage::OBJECT_EREFERENCE_OBJECTACTIVATION:
			return getObjectActivation(); //373
		case FUMLPackage::OBJECT_EREFERENCE_TYPES:
			return getTypes(); //372
	}
	return boost::any();
}

void ObjectImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::EXTENSIONALVALUE_EREFERENCE_LOCUS:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Locus> _locus = boost::any_cast<std::shared_ptr<fUML::Locus>>(newValue);
			setLocus(_locus); //371
			break;
		}
		case FUMLPackage::OBJECT_EREFERENCE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ObjectActivation> _objectActivation = boost::any_cast<std::shared_ptr<fUML::ObjectActivation>>(newValue);
			setObjectActivation(_objectActivation); //373
			break;
		}
	}
}

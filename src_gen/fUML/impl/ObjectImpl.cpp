#include "ObjectImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "FUMLFactory.hpp"
#include "UmlFactory.hpp"
#include "Class.hpp"
#include "Classifier.hpp"

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
	
	m_types.reset(new std::vector<std::shared_ptr<uml::Classifier>>());
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ObjectImpl::ObjectImpl(const ObjectImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> _types = obj.getTypes();
	this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	std::shared_ptr<std::vector<std::shared_ptr<fUML::FeatureValue>>> _featureValuesList = obj.getFeatureValues();
	for(std::shared_ptr<fUML::FeatureValue> _featureValues : *_featureValuesList)
	{
		this->getFeatureValues()->push_back(std::shared_ptr<fUML::FeatureValue>(dynamic_cast<fUML::FeatureValue*>(_featureValues->copy())));
	}
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation.reset(dynamic_cast<fUML::ObjectActivation*>(obj.getObjectActivation()->copy()));
	}
}

ecore::EObject *  ObjectImpl::copy() const
{
	return new ObjectImpl(*this);
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObject();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectImpl::_register(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->_register(accepter);
    }
}

void ObjectImpl::destroy() 
{
	//generated from body annotation
	    if(this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->stop();
        this->setObjectActivation(nullptr);
    }

    this->getTypes()->clear();
    ExtensionalValueImpl::destroy();
}

std::shared_ptr<fUML::Execution>  ObjectImpl::dispatch(std::shared_ptr<uml::Operation>  operation) 
{
	//generated from body annotation
	struct null_deleter{void operator()(void const *) const { } };
	return (std::dynamic_pointer_cast<DispatchStrategy>(this->getLocus()->getFactory()->getStrategy("dispatch")))->dispatch(std::shared_ptr<Object>(this, null_deleter()), operation);
}

std::shared_ptr<fUML::Value>  ObjectImpl::new_() 
{
	//generated from body annotation
	return std::shared_ptr<fUML::Value>(FUMLFactory::eInstance()->createObject());
}

void ObjectImpl::send(std::shared_ptr<fUML::SignalInstance>  signalInstance) 
{
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
}

void ObjectImpl::startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<std::vector<std::shared_ptr<fUML::ParameterValue>>>  inputs) 
{
	//generated from body annotation
	if(this->getObjectActivation() == nullptr)
    {
        this->setObjectActivation(std::shared_ptr<ObjectActivation>(fUML::FUMLFactory::eInstance()->createObjectActivation()));
        struct null_deleter{void operator()(void const *) const { } };
        this->getObjectActivation()->setObject(std::shared_ptr<Object>(this, null_deleter()));
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
}

void ObjectImpl::unregister(std::shared_ptr<fUML::EventAccepter>  accepter) 
{
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->unregister(accepter);
    }
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::ObjectActivation> ObjectImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ObjectImpl::setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}

std::shared_ptr<std::vector<std::shared_ptr<uml::Classifier>>> ObjectImpl::getTypes() const
{

    return m_types;
}


//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::COMPOUNDVALUE_FEATUREVALUES:
			return getFeatureValues(); //370
		case FUMLPackage::EXTENSIONALVALUE_LOCUS:
			return getLocus(); //371
		case FUMLPackage::OBJECT_OBJECTACTIVATION:
			return getObjectActivation(); //373
		case FUMLPackage::OBJECT_TYPES:
			return getTypes(); //372
	}
	return boost::any();
}

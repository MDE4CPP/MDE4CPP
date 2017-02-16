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
	// Reference Members
	//*********************************
	
	if( m_types == nullptr)
	{
		m_types = new std::vector<uml::Classifier * >();
	}
}

ObjectImpl::~ObjectImpl()
{
	if(m_types!=nullptr)
	{
		delete(m_types);
	 	m_types = nullptr;
	}
	if(m_objectActivation!=nullptr)
	{
		if(m_objectActivation)
		{
			delete(m_objectActivation);
			m_objectActivation = nullptr;
		}
	}
	
}

ObjectImpl::ObjectImpl(const ObjectImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	
	m_locus  = obj.getLocus();

	std::vector<uml::Classifier * > *  _types = obj.getTypes();
	this->getTypes()->insert(this->getTypes()->end(), _types->begin(), _types->end());


	//clone containt lists
	for(fUML::FeatureValue * 	_featureValues : *obj.getFeatureValues())
	{
		this->getFeatureValues()->push_back(dynamic_cast<fUML::FeatureValue * >(_featureValues->copy()));
	}
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = dynamic_cast<fUML::ObjectActivation * >(obj.getObjectActivation()->copy());
	}
}

ecore::EObject *  ObjectImpl::copy() const
{
	return new ObjectImpl(*this);
}

ecore::EClass* ObjectImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObject();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void ObjectImpl::_register(fUML::EventAccepter *  accepter) 
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

fUML::Execution *  ObjectImpl::dispatch(uml::Operation *  operation) 
{
	//generated from body annotation
	    return (dynamic_cast<DispatchStrategy * >(this->getLocus()->getFactory()->getStrategy("dispatch")))->dispatch(this, operation);
}

fUML::Value *  ObjectImpl::new_() 
{
	//generated from body annotation
	return FUMLFactory::eInstance()->createObject();
}

void ObjectImpl::send(fUML::SignalInstance *  signalInstance) 
{
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
}

void ObjectImpl::startBehavior(uml::Class *  classifier,std::vector<fUML::ParameterValue * > *  inputs) 
{
	//generated from body annotation
	    if(this->getObjectActivation() == nullptr)
    {
        this->setObjectActivation(fUML::FUMLFactory::eInstance()->createObjectActivation());
        this->getObjectActivation()->setObject(this);
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
}

void ObjectImpl::unregister(fUML::EventAccepter *  accepter) 
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
fUML::ObjectActivation *  ObjectImpl::getObjectActivation() const
{
	
	return m_objectActivation;
}
void ObjectImpl::setObjectActivation(fUML::ObjectActivation *  _objectActivation)
{
	m_objectActivation = _objectActivation;
}

std::vector<uml::Classifier * > *  ObjectImpl::getTypes() const
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

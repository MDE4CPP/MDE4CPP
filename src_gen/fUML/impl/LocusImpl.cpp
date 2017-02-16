#include "LocusImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "fUMLPackageImpl.hpp"
#include "Classifier.hpp"
#include "Behavior.hpp"
#include "Class.hpp"
#include "FUMLFactory.hpp"
#include "ExecutionFactory.hpp"
#include "ExtensionalValue.hpp"
#include "Executor.hpp"
#include "Object.hpp"
#include "Execution.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LocusImpl::LocusImpl()
{
	//*********************************
	// Reference Members
	//*********************************
	
	if( m_extensionalValues == nullptr)
	{
		m_extensionalValues = new std::vector<fUML::ExtensionalValue * >();
	}
	
}

LocusImpl::~LocusImpl()
{
	if(m_executor!=nullptr)
	{
		if(m_executor)
		{
			delete(m_executor);
			m_executor = nullptr;
		}
	}
	if(m_factory!=nullptr)
	{
		if(m_factory)
		{
			delete(m_factory);
			m_factory = nullptr;
		}
	}
	if(m_extensionalValues!=nullptr)
	{
		for(auto c :*m_extensionalValues)
		{
			delete(c);
			c = 0;
		}
	}
	
}

LocusImpl::LocusImpl(const LocusImpl & obj)
{
	//create copy of all Attributes

	//copy references with now containment
	

	//clone containt lists
	if(obj.getExecutor()!=nullptr)
	{
		m_executor = dynamic_cast<fUML::Executor * >(obj.getExecutor()->copy());
	}
	for(fUML::ExtensionalValue * 	_extensionalValues : *obj.getExtensionalValues())
	{
		this->getExtensionalValues()->push_back(dynamic_cast<fUML::ExtensionalValue * >(_extensionalValues->copy()));
	}
	if(obj.getFactory()!=nullptr)
	{
		m_factory = dynamic_cast<fUML::ExecutionFactory * >(obj.getFactory()->copy());
	}
}

ecore::EObject *  LocusImpl::copy() const
{
	return new LocusImpl(*this);
}

ecore::EClass* LocusImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLocus();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
void LocusImpl::add(fUML::ExtensionalValue *  value) 
{
	//generated from body annotation
	value->setLocus(this);
this->getExtensionalValues()->push_back(value);

}

void LocusImpl::assignExecutor(fUML::Executor *  executor) 
{
	//generated from body annotation
	this->setExecutor(executor);
this->getExecutor()->setLocus(this);

}

void LocusImpl::assignFactory(fUML::ExecutionFactory *  factory) 
{
	//generated from body annotation
	this->setFactory(factory);
this->getFactory()->setLocus(this);

}

bool LocusImpl::conforms(uml::Classifier *  type,uml::Classifier *  classifier) 
{
	//generated from body annotation
	    bool doesConform = false;
    if(type == classifier)
    {
        doesConform = true;
    }
    else
    {
        int i = 1;
        while(!doesConform && (i <= type->getGeneral()->size()))
        {
            doesConform = this->conforms(type->getGeneral()->at(i - 1), classifier);
            i = i + 1;
        }
    }
    return doesConform;
}

fUML::Object *  LocusImpl::instantiate(uml::Class *  type) 
{
	//generated from body annotation
	    fUML::Object* object = nullptr;
    
    if(dynamic_cast<uml::Behavior*>(type) != nullptr)
    {
        object = this->getFactory()->createExecution((dynamic_cast<uml::Behavior*> (type)),nullptr);
    }
    else
    {
        object = FUMLFactory::eInstance()->createObject();
        object->getTypes()->push_back(type);
        object->createFeatureValues();
        this->add(object);
    }
    
    return object;
}

void LocusImpl::remove(fUML::ExtensionalValue *  value) 
{
	//generated from body annotation
	value->setLocus(nullptr);
std::remove(this->getExtensionalValues()->begin(),this->getExtensionalValues()->end(),value);
}

std::vector<fUML::ExtensionalValue * > *  LocusImpl::retrieveExtent(uml::Classifier *  classifier) 
{
	//generated from body annotation
	std::vector<fUML::ExtensionalValue *> * extent =this->getExtensionalValues();

std::vector<fUML::ExtensionalValue *> * extensionalValues = this->getExtensionalValues();

for (unsigned int i=0; i < extensionalValues->size();i++)
{
    fUML::ExtensionalValue * value = extensionalValues->at(i);
            std::vector<uml::Classifier *> * types = value->getTypes();
            bool conforms = false;
            unsigned int j = 1;
            while(!conforms && j <= types->size())
                {
                conforms = this->conforms(types->at(j - 1), classifier);
                j = j + 1;
                }
            if(conforms)
                {
                extent->push_back(value);
                }
}
return extent;
}

//*********************************
// References
//*********************************
fUML::Executor *  LocusImpl::getExecutor() const
{
	
	return m_executor;
}
void LocusImpl::setExecutor(fUML::Executor *  _executor)
{
	m_executor = _executor;
}

std::vector<fUML::ExtensionalValue * > *  LocusImpl::getExtensionalValues() const
{
	
	return m_extensionalValues;
}


fUML::ExecutionFactory *  LocusImpl::getFactory() const
{
	//assert(m_factory);
	return m_factory;
}
void LocusImpl::setFactory(fUML::ExecutionFactory *  _factory)
{
	m_factory = _factory;
}

//*********************************
// Union Getter
//*********************************


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LocusImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::LOCUS_EXECUTOR:
			return getExecutor(); //00
		case FUMLPackage::LOCUS_EXTENSIONALVALUES:
			return getExtensionalValues(); //02
		case FUMLPackage::LOCUS_FACTORY:
			return getFactory(); //01
	}
	return boost::any();
}

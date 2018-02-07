#include "fUML/impl/LocusImpl.hpp"
#include <iostream>
#include <cassert>

#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "uml/Classifier.hpp"
#include "uml/Behavior.hpp"
#include "uml/Class.hpp"
#include "fuml/FUMLFactory.hpp"
#include "fuml/ExecutionFactory.hpp"
#include "fuml/ExtensionalValue.hpp"
#include "fuml/Executor.hpp"
#include "fuml/Object.hpp"
#include "fuml/Execution.hpp"


//Forward declaration includes
#include "uml/Class.hpp"

#include "uml/Classifier.hpp"

#include "fUML/ExecutionFactory.hpp"

#include "fUML/Executor.hpp"

#include "fUML/ExtensionalValue.hpp"

#include "fUML/Object.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
LocusImpl::LocusImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_extensionalValues.reset(new Bag<fUML::ExtensionalValue>());
	
	

	

	//Init references
	

	
	

	
}

LocusImpl::~LocusImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Locus "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}




LocusImpl::LocusImpl(const LocusImpl & obj):LocusImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Locus "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	

	//Clone references with containment (deep copy)

	if(obj.getExecutor()!=nullptr)
	{
		m_executor = std::dynamic_pointer_cast<fUML::Executor>(obj.getExecutor()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_executor" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ExtensionalValue>> _extensionalValuesList = obj.getExtensionalValues();
	for(std::shared_ptr<fUML::ExtensionalValue> _extensionalValues : *_extensionalValuesList)
	{
		this->getExtensionalValues()->add(std::shared_ptr<fUML::ExtensionalValue>(std::dynamic_pointer_cast<fUML::ExtensionalValue>(_extensionalValues->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_extensionalValues" << std::endl;
	#endif
	if(obj.getFactory()!=nullptr)
	{
		m_factory = std::dynamic_pointer_cast<fUML::ExecutionFactory>(obj.getFactory()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_factory" << std::endl;
	#endif

	

	
	

	
}

std::shared_ptr<ecore::EObject>  LocusImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new LocusImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> LocusImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getLocus();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void LocusImpl::add(std::shared_ptr<fUML::ExtensionalValue>  value) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		value->setLocus(shared_from_this());
	this->getExtensionalValues()->push_back(value);
	//end of body
}

void LocusImpl::assignExecutor(std::shared_ptr<fUML::Executor>  executor) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		this->setExecutor(executor);
	this->getExecutor()->setLocus(shared_from_this());
	//end of body
}

void LocusImpl::assignFactory(std::shared_ptr<fUML::ExecutionFactory>  factory) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		this->setFactory(factory);
	this->getFactory()->setLocus(shared_from_this());
	//end of body
}

bool LocusImpl::conforms(std::shared_ptr<uml::Classifier>  type,std::shared_ptr<uml::Classifier>  classifier) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool doesConform = false;
    if(type == classifier)
    {
        doesConform = true;
    }
    else
    {
        unsigned int i = 0;
        while(!doesConform && (i < type->getGeneral()->size()))
        {
            doesConform = this->conforms(type->getGeneral()->at(i), classifier);
            i = i + 1;
        }
    }
    return doesConform;
	//end of body
}

std::shared_ptr<fUML::Object> LocusImpl::instantiate(std::shared_ptr<uml::Class>  type) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Object> object = nullptr;
	std::shared_ptr<uml::Behavior> behavior = std::dynamic_pointer_cast<uml::Behavior>(type);
    if(behavior != nullptr)
    {
    	std::shared_ptr<fUML::Object>  context = nullptr;
        object = std::dynamic_pointer_cast<Object>(this->getFactory()->createExecution(behavior, nullptr));
    }
    else
    {
        object = FUMLFactory::eInstance()->createObject();
        object->getTypes()->push_back(type);
        object->createFeatureValues();
        this->add(object);
    }
    
    return object;
	//end of body
}

void LocusImpl::remove(std::shared_ptr<fUML::ExtensionalValue>  value) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	value->setLocus(nullptr);
std::remove(this->getExtensionalValues()->begin(),this->getExtensionalValues()->end(),value);
	//end of body
}

std::shared_ptr<Bag<fUML::ExtensionalValue> > LocusImpl::retrieveExtent(std::shared_ptr<uml::Classifier>  classifier) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<fUML::ExtensionalValue> > extent =this->getExtensionalValues();
	std::shared_ptr<Bag<fUML::ExtensionalValue> > extensionalValues = this->getExtensionalValues();

	for (unsigned int i=0; i < extensionalValues->size();i++)
	{
		std::shared_ptr<fUML::ExtensionalValue> value = extensionalValues->at(i);
		std::shared_ptr<Bag<uml::Classifier> > types = value->getTypes();
		bool conforms = false;
		unsigned int j = 0;
		while(!conforms && j < types->size())
		{
			conforms = this->conforms(types->at(j), classifier);
			j = j + 1;
		}
		if(conforms)
		{
			extent->push_back(value);
		}
	}
	return extent;
	//end of body
}

//*********************************
// References
//*********************************
std::shared_ptr<fUML::Executor > LocusImpl::getExecutor() const
{

    return m_executor;
}
void LocusImpl::setExecutor(std::shared_ptr<fUML::Executor> _executor)
{
    m_executor = _executor;
}

std::shared_ptr< Bag<fUML::ExtensionalValue> > LocusImpl::getExtensionalValues() const
{

    return m_extensionalValues;
}


std::shared_ptr<fUML::ExecutionFactory > LocusImpl::getFactory() const
{
//assert(m_factory);
    return m_factory;
}
void LocusImpl::setFactory(std::shared_ptr<fUML::ExecutionFactory> _factory)
{
    m_factory = _factory;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ecore::EObject> LocusImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any LocusImpl::eGet(int featureID, bool resolve, bool coreType) const
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

void LocusImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::LOCUS_EXECUTOR:
		{
			// BOOST CAST
			std::shared_ptr<fUML::Executor> _executor = boost::any_cast<std::shared_ptr<fUML::Executor>>(newValue);
			setExecutor(_executor); //00
			break;
		}
		case FUMLPackage::LOCUS_FACTORY:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ExecutionFactory> _factory = boost::any_cast<std::shared_ptr<fUML::ExecutionFactory>>(newValue);
			setFactory(_factory); //01
			break;
		}
	}
}

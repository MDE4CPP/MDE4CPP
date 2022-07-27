#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueListImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/LinkImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/RedefinitionBasedDispatchStrategyImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ReferenceImpl.hpp"

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


using namespace fUML::Semantics::StructuredClassifiers;

std::shared_ptr<StructuredClassifiersFactory> StructuredClassifiersFactory::eInstance()
{
	static std::shared_ptr<StructuredClassifiersFactory> instance;
	if(!instance)
	{
		//create a new Factoryimplementation
		instance.reset(StructuredClassifiersFactoryImpl::create());
	}	
	return instance;
}

//*********************************
// Constructor / Destructor
//*********************************

StructuredClassifiersFactoryImpl::StructuredClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::DispatchStrategy", StructuredClassifiersPackage::DISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::ExtensionalValueList", StructuredClassifiersPackage::EXTENSIONALVALUELIST_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Link", StructuredClassifiersPackage::LINK_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Object", StructuredClassifiersPackage::OBJECT_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy", StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("fUML::Semantics::StructuredClassifiers::Reference", StructuredClassifiersPackage::REFERENCE_CLASS));
}

StructuredClassifiersFactoryImpl::~StructuredClassifiersFactoryImpl()
{
}

StructuredClassifiersFactory* StructuredClassifiersFactoryImpl::create()
{
	return new StructuredClassifiersFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_CLASS:
		{
				return this->createDispatchStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExtensionalValueList(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExtensionalValueList has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createExtensionalValueList_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//ExtensionalValueList has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createExtensionalValueList_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//ExtensionalValueList has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createExtensionalValueList_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//ExtensionalValueList has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createExtensionalValueList_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::LINK_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLink(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Link has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createLink_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//Link has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createLink_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//Link has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createLink_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//Link has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createLink_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::OBJECT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObject(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Object has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createObject_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//Object has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createObject_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//Object has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createObject_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//Object has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createObject_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS:
		{
				return this->createRedefinitionBasedDispatchStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::REFERENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReference(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Reference has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createReference_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//Reference has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createReference_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//Reference has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createReference_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> StructuredClassifiersFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> StructuredClassifiersFactoryImpl::createDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::DispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionalValueListPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisExtensionalValueListPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisExtensionalValueListPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisExtensionalValueListPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> StructuredClassifiersFactoryImpl::createExtensionalValueList_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl> element(new fUML::Semantics::StructuredClassifiers::ExtensionalValueListImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisExtensionalValueListPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisLinkPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisLinkPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisLinkPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> StructuredClassifiersFactoryImpl::createLink_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::LinkImpl> element(new fUML::Semantics::StructuredClassifiers::LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisLinkPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisObjectPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisObjectPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisObjectPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> StructuredClassifiersFactoryImpl::createObject_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ObjectImpl> element(new fUML::Semantics::StructuredClassifiers::ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisObjectPtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> StructuredClassifiersFactoryImpl::createRedefinitionBasedDispatchStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl> element(new fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> StructuredClassifiersFactoryImpl::createReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReferencePtr(element);
	return element;
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> StructuredClassifiersFactoryImpl::createReference_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisReferencePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> StructuredClassifiersFactoryImpl::createReference_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisReferencePtr(element);
	return element;
	
}
std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> StructuredClassifiersFactoryImpl::createReference_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ReferenceImpl> element(new fUML::Semantics::StructuredClassifiers::ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisReferencePtr(element);
	return element;
	
}


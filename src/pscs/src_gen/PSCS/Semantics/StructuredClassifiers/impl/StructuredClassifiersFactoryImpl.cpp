#include "PSCS/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DispatchOperationOfInterfaceStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_InteractionPointImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_LinkImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ReferenceImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"
#include "PSCS/Semantics/StructuredClassifiers/impl/CS_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"

#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Activities/ObjectToken.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"


using namespace PSCS::Semantics::StructuredClassifiers;


//*********************************
// Constructor / Destructor
//*********************************

StructuredClassifiersFactoryImpl::StructuredClassifiersFactoryImpl()
{
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy", StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy", StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint", StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Link", StructuredClassifiersPackage::CS_LINK_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy", StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Object", StructuredClassifiersPackage::CS_OBJECT_CLASS));
	m_idMap.insert(std::make_pair("PSCS::Semantics::StructuredClassifiers::CS_Reference", StructuredClassifiersPackage::CS_REFERENCE_CLASS));
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
		case StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS:
		{
				return this->createCS_DefaultRequestPropagationStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS:
		{
				return this->createCS_DispatchOperationOfInterfaceStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_InteractionPoint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CS_InteractionPoint has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createCS_InteractionPoint_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//CS_InteractionPoint has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createCS_InteractionPoint_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//CS_InteractionPoint has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createCS_InteractionPoint_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::CS_LINK_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_Link(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CS_Link has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createCS_Link_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//CS_Link has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createCS_Link_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//CS_Link has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createCS_Link_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//CS_Link has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createCS_Link_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS:
		{
				return this->createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(metaElementID);
			
			break;
		}
		case StructuredClassifiersPackage::CS_OBJECT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_Object(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CS_Object has extensionalValues as a containment
					case  fUML::Semantics::Loci::LociPackage::LOCUS_ATTRIBUTE_EXTENSIONALVALUES:	
					{
						std::shared_ptr<fUML::Semantics::Loci::Locus> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Loci::Locus> (container);;
						return this->createCS_Object_as_extensionalValues_in_Locus(castedContainer,metaElementID);
					}
					//CS_Object has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createCS_Object_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//CS_Object has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createCS_Object_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//CS_Object has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createCS_Object_as_values_in_ParameterValue(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}	
			}
			break;
		}
		case StructuredClassifiersPackage::CS_REFERENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCS_Reference(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CS_Reference has value as a containment
					case  fUML::Semantics::Activities::ActivitiesPackage::OBJECTTOKEN_ATTRIBUTE_VALUE:	
					{
						std::shared_ptr<fUML::Semantics::Activities::ObjectToken> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::Activities::ObjectToken> (container);;
						return this->createCS_Reference_as_value_in_ObjectToken(castedContainer,metaElementID);
					}
					//CS_Reference has values as a containment
					case  fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::FEATUREVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue> (container);;
						return this->createCS_Reference_as_values_in_FeatureValue(castedContainer,metaElementID);
					}
					//CS_Reference has values as a containment
					case  fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_ATTRIBUTE_VALUES:	
					{
						std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> castedContainer = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue> (container);;
						return this->createCS_Reference_as_values_in_ParameterValue(castedContainer,metaElementID);
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

std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> StructuredClassifiersFactoryImpl::createCS_DefaultRequestPropagationStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DefaultRequestPropagationStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> StructuredClassifiersFactoryImpl::createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_DispatchOperationOfInterfaceStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> StructuredClassifiersFactoryImpl::createCS_InteractionPoint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_InteractionPointPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> StructuredClassifiersFactoryImpl::createCS_InteractionPoint_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisCS_InteractionPointPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> StructuredClassifiersFactoryImpl::createCS_InteractionPoint_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisCS_InteractionPointPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> StructuredClassifiersFactoryImpl::createCS_InteractionPoint_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_InteractionPointImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisCS_InteractionPointPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_LinkPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisCS_LinkPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisCS_LinkPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisCS_LinkPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> StructuredClassifiersFactoryImpl::createCS_Link_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_LinkImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_LinkImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisCS_LinkPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> StructuredClassifiersFactoryImpl::createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ObjectPtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_Locus)
	{
		par_Locus->getExtensionalValues()->push_back(element);
	}
	
	element->setThisCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> StructuredClassifiersFactoryImpl::createCS_Object_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ObjectImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisCS_ObjectPtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> StructuredClassifiersFactoryImpl::createCS_Reference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCS_ReferencePtr(element);
	return element;
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> StructuredClassifiersFactoryImpl::createCS_Reference_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ObjectToken)
	{
		par_ObjectToken->setValue(element);
	}
	
	element->setThisCS_ReferencePtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> StructuredClassifiersFactoryImpl::createCS_Reference_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_FeatureValue)
	{
		par_FeatureValue->getValues()->push_back(element);
	}
	
	element->setThisCS_ReferencePtr(element);
	return element;
	
}
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> StructuredClassifiersFactoryImpl::createCS_Reference_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID) const
{
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl> element(new PSCS::Semantics::StructuredClassifiers::CS_ReferenceImpl());
	element->setMetaElementID(metaElementID);
	if(nullptr != par_ParameterValue)
	{
		par_ParameterValue->getValues()->push_back(element);
	}
	
	element->setThisCS_ReferencePtr(element);
	return element;
	
}


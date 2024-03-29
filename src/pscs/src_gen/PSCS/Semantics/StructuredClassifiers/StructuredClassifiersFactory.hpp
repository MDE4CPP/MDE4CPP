//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORY_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORY_HPP
// namespace macro header include
#include "PSCS/PSCS.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}



namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API StructuredClassifiersFactory : virtual public ecore::EFactory 
	{
		private:    
			StructuredClassifiersFactory(StructuredClassifiersFactory const&) = delete;
			StructuredClassifiersFactory& operator=(StructuredClassifiersFactory const&) = delete;
		protected:
			StructuredClassifiersFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<StructuredClassifiersFactory> instance;
			public:
				static std::shared_ptr<StructuredClassifiersFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> createCS_DefaultRequestPropagationStrategy(const int metaElementID = StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID = StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint(const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link(const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID = StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object(const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference(const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORY_HPP */

//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::MDE4CPP_Extensions
{
	class FUML_Object;
}
namespace uml
{
	class DirectedRelationship;
}



namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API CommonBehaviorFactory : virtual public ecore::EFactory 
	{
		private:    
			CommonBehaviorFactory(CommonBehaviorFactory const&) = delete;
			CommonBehaviorFactory& operator=(CommonBehaviorFactory const&) = delete;
		protected:
			CommonBehaviorFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<CommonBehaviorFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution(const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution_as_classifierBehaviorExecutions_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence(const int metaElementID = CommonBehaviorPackage::EVENTOCCURRENCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID = CommonBehaviorPackage::EVENTOCCURRENCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> createFIFOGetNextEventStrategy(const int metaElementID = CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> createObjectActivation(const int metaElementID = CommonBehaviorPackage::OBJECTACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> createObjectActivation_as_objectActivation_in_FUML_Object(std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> par_FUML_Object, const int metaElementID = CommonBehaviorPackage::OBJECTACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue(const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue_as_parameterValues_in_Execution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> par_Execution, const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> createSignalEventOccurrence(const int metaElementID = CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> createSignalEventOccurrence_as_eventPool_in_ObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> par_ObjectActivation, const int metaElementID = CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORFACTORY_HPP */

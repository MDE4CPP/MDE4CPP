//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCE_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
	class Execution;
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
	class SignalInstance;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Operation;
	class StructuralFeature;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"




//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	
	class FUML_API Reference: virtual public fUML::Semantics::SimpleClassifiers::StructuredValue
	{
		public:
 			Reference(const Reference &) {}

		protected:
			Reference(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Reference() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0;
			virtual void assignFeatureValue(const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<Bag<fUML::Semantics::Values::Value>>& values, int position) = 0;
			virtual void destroy() = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(const std::shared_ptr<uml::Operation>& operation) = 0;
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Values::Value>& otherValue) = 0;
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getValues(const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>>& featureValues) = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() = 0;
			virtual void removeValue(const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<fUML::Semantics::Values::Value>& value) = 0;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(const std::shared_ptr<uml::StructuralFeature>& feature) = 0;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > retrieveFeatureValues() = 0;
			virtual void send(const std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>& signalInstance) = 0;
			virtual void send(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void setFeatureValue(const std::shared_ptr<uml::StructuralFeature>& feature, const std::shared_ptr<Bag<fUML::Semantics::Values::Value>>& values, int position) = 0;
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) = 0;
			virtual std::string toString() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>& getReferent() const = 0;
			virtual void setReferent(const std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>&) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> m_referent;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCE_HPP */

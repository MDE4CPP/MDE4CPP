//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTION_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTION_HPP


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
	class ObjectActivation;
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace ecore 
{
	class EAnnotation;
}
namespace uml 
{
	class Behavior;
	class Classifier;
	class Comment;
	class Parameter;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"




//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API Execution : virtual public fUML::MDE4CPP_Extensions::FUML_Object, virtual public fUML::Semantics::Loci::SemanticVisitor
	{
		public:
 			Execution(const Execution &) {}

		protected:
			Execution(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Execution() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> _copy() = 0;
			virtual void destroy() = 0;
			virtual void execute() = 0;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getOutputParameterValues() = 0;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> getParameterValue(const std::shared_ptr<uml::Parameter>& parameter) = 0;
			virtual std::shared_ptr<Any> new_() = 0;
			virtual void setParameterValue(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& parameterValue) = 0;
			virtual void terminate() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::Behavior>& getBehavior() const = 0;
			virtual void setBehavior(const std::shared_ptr<uml::Behavior>&) = 0;
			virtual const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& getContext() const = 0;
			virtual void setContext(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>&) = 0;
			virtual const std::shared_ptr<fUML::Semantics::Loci::Locus>& getLocus() const = 0;
			virtual void setLocus(const std::shared_ptr<fUML::Semantics::Loci::Locus>&) = 0;
			
			virtual const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& getParameterValues() const = 0;
			virtual const std::shared_ptr<Bag<uml::Classifier>>& getTypes() const = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<uml::Behavior> m_behavior;
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> m_context;
			std::shared_ptr<fUML::Semantics::Loci::Locus> m_locus;
			
			mutable std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> m_parameterValues;
			mutable std::shared_ptr<Bag<uml::Classifier>> m_types;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTION_HPP */

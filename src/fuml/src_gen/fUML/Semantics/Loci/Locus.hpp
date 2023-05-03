//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_LOCUS_HPP
#define FUML_SEMANTICS_LOCI_LOCUS_HPP


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
namespace fUML::Semantics::Loci 
{
	class ExecutionFactory;
	class Executor;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Element;
}

// namespace macro header include
#include "fUML/fUML.hpp"



#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::Loci 
{
	
	class FUML_API Locus : virtual public ecore::EModelElement
	{
		public:
 			Locus(const Locus &) {}

		protected:
			Locus(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Locus() {}

			//*********************************
			// Operations
			//*********************************
			virtual void add(const std::shared_ptr<uml::Element>& value) = 0;
			virtual void assignExecutor(const std::shared_ptr<fUML::Semantics::Loci::Executor>& executor) = 0;
			virtual void assignFactory(const std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>& factory) = 0;
			virtual bool conforms(const std::shared_ptr<uml::Classifier>& type, const std::shared_ptr<uml::Classifier>& classifier) = 0;
			virtual std::shared_ptr<uml::Element> instantiate(const std::shared_ptr<uml::Class>& type) = 0;
			virtual void remove(const std::shared_ptr<uml::Element>& value) = 0;
			virtual std::shared_ptr<Bag<uml::Element>> retrieveExtent(const std::shared_ptr<uml::Classifier>& classifier) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> getExecutor() const = 0;
			virtual void setExecutor(std::shared_ptr<fUML::Semantics::Loci::Executor>) = 0;
			virtual std::shared_ptr<Bag<uml::Element>> getExtensionalValues() const = 0;
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> getFactory() const = 0;
			virtual void setFactory(std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>) = 0;

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
			std::shared_ptr<fUML::Semantics::Loci::Executor> m_executor;
			mutable std::shared_ptr<Bag<uml::Element>> m_extensionalValues;
			std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> m_factory;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_LOCUS_HPP */

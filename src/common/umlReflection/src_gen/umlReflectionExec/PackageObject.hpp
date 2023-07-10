//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGE_EXECUTION_HPP
#define UML_PACKAGE_EXECUTION_HPP

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "umlReflectionExec/NamespaceObject.hpp"
#include "umlReflectionExec/PackageableElementObject.hpp"
#include "umlReflectionExec/TemplateableElementObject.hpp"

template <class T> 
class Bag;

namespace uml
{
	class Package;
}

namespace uml
{
	class Element;
	class ConnectorEnd;
}

namespace UML 
{
	class PackageObject : virtual public UML::NamespaceObject , virtual public UML::PackageableElementObject , virtual public UML::TemplateableElementObject
	{
		public:
		    //constructors
		    PackageObject(PackageObject &obj);
		    PackageObject(std::shared_ptr<uml::Package>);
		 	PackageObject();
		    //destructor
		    virtual ~PackageObject();
		
		    virtual std::shared_ptr<ecore::EObject> copy();
			PackageObject& operator=(PackageObject const&);

			virtual void destroy();
			
			virtual std::shared_ptr<uml::Package> getPackageValue() const;
			virtual std::shared_ptr<uml::Element> getUmlValue() const;
			virtual void setUmlValue(std::shared_ptr<uml::Element>);
			virtual void setPackageValue(std::shared_ptr<uml::Package>);
			virtual void setThisPackageObjectPtr(std::weak_ptr<PackageObject> thisObjectPtr);
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue);
			virtual std::string toString();
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> getDirectContainers();
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> values);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues);
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature);
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> retrieveFeatureValues();

			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end);

		protected:
			std::shared_ptr<uml::Package> m_PackageValue = nullptr;
	};
}
#endif /* end of include guard: UML_PACKAGE_OBJECT_HPP */